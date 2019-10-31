#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include "../../Development/tile.h"
#include "../../Development/level.h"
#include "../../Development/geometry.h"

// constants
const int SCREEN_W = 600;
const int SCREEN_H = 600;
const int X = 2;
const int Y = 3;

enum Color {
	Green = 0x4caf50,
	LightGreen = 0x8bc34a,
	YellowGreen = 0xcddc39,
	Red = 0xf44336,
	DarkOrange = 0xff5722,
	Orange = 0xff9800,
	DarkYellow = 0xffc107,
	Yellow = 0xffeb3b,
	Black = 0,
	White = 0xffffff,
	Blue = 0x03a9f4
};

struct Render {
	Point tileSize;
	Point viewport;
	Point start;
};

Level level(X, Y);
Render render;

void initLevel() {
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			level.tiles[i][j].tileType = Grass;
		}
	}
}

void initRender() {
	float maxTileW, maxTileH;

	render.tileSize.x = 1 / level.numTiles.x;
	render.tileSize.y = 1 / level.numTiles.y;

	maxTileW = SCREEN_W / level.numTiles.x;
	maxTileH = SCREEN_H / level.numTiles.y;

	if (maxTileW > maxTileH) {
		render.viewport.x = maxTileH * level.numTiles.x;
		render.viewport.y = SCREEN_H;
		render.start.x = (SCREEN_W - render.viewport.x) / 2;
		render.start.y = 0;
	}
	else {
		render.viewport.x = SCREEN_W;
		render.viewport.y = maxTileW * level.numTiles.y;
		render.start.x = 0;
		render.start.y = (SCREEN_H - render.viewport.y) / 2;
	}
}

// set up coordinate system, point size, background color, drawing color
void myInit(void) {
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 1);
	glPointSize(2);
	glLineWidth(1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(1, 0, 1, 0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	initLevel();

	initRender();
}

void hexColor(Color hex) {
	int intHex = (int)hex;
	double r = ((intHex >> 16) & 0xff) / 255.0;
	double g = ((intHex >> 8) & 0xff) / 255.0;
	double b = (intHex & 0xff) / 255.0;
	glColor3d(r, g, b);
}

void drawTile(float left, float bottom, Color color) {
	float right = left + render.tileSize.x;
	float top = bottom + render.tileSize.y;
	hexColor(color);
	glBegin(GL_POLYGON);
	glVertex2f(left, bottom);
	glVertex2f(right, bottom);
	glVertex2f(right, top);
	glVertex2f(left, top);
	glEnd();
}

Color tileTypeToColor(TileType type) {
	switch (type) {
	case Grass:
		return Green;
		break;
	case Water:
		return Blue;
		break;
	case Fire:
		return Red;
		break;
	default:
		return Black;
		break;
	}
}

void renderTiles(void) {
	Color color;
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			color = tileTypeToColor(level.tiles[i][j].tileType);
			drawTile(i * render.tileSize.x, j * render.tileSize.y, color);
		}
	}
}

void drawLine(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINE_STRIP);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
}

void drawGrid() {
	glColor4d(1, 1, 1, 0.6);
	// vertical lines
	for (int i = 0; i <= X; i++) {
		drawLine(i * render.tileSize.x, 0, i * render.tileSize.x, render.viewport.y);
	}
	// horizontal lines
	for (int i = 0; i <= Y; i++) {
		drawLine(0, i * render.tileSize.y, render.viewport.x, i * render.tileSize.y);
	}
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport((int) render.start.x, (int) render.start.y, (GLsizei)render.viewport.x, (GLsizei)render.viewport.y);

	renderTiles();

	drawGrid();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(SCREEN_W, SCREEN_H);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Render Level 2D");

	glutDisplayFunc(myDisplay);

	myInit();
	glutMainLoop();
}