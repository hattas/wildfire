#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include "lib/tile.h"
#include "lib/level.h"
#include "lib/point.h"
using namespace std;

// constants
const int SCREEN_W = 600;
const int SCREEN_H = 400;
const int X = 5;
const int Y = 10;

#define GREEN 0x4caf50
#define LIGHT_GREEN 0x8bc34a
#define RED 0xf44336
#define DARK_ORANGE 0xff5722
#define ORANGE 0xff9800
#define DARK_YELLOW 0xffc107
#define YELLOW 0xffeb3b
#define BLACK 0
#define WHITE 0xffffff
#define BLUE 0x03a9f4
#define NUM_COLORS 11

struct Render {
	Point tileSize;
	Point viewport;
	Point viewportStart;
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
	double maxTileW, maxTileH;

	render.tileSize = 1.0 / level.numTiles;

	maxTileW = SCREEN_W / level.numTiles.x;
	maxTileH = SCREEN_H / level.numTiles.y;

	if (maxTileW > maxTileH) {
		render.viewport.x = (int)(maxTileH * level.numTiles.x);
		render.viewport.y = SCREEN_H;
		render.viewportStart.x = (SCREEN_W - render.viewport.x) / 2;
		render.viewportStart.y = 0;
	}
	else {
		render.viewport.x = SCREEN_W;
		render.viewport.y = (int)(maxTileW * level.numTiles.y);
		render.viewportStart.x = 0;
		render.viewportStart.y = (SCREEN_H - render.viewport.y) / 2;
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
	gluOrtho2D(0, 1, 1, 0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	initLevel();

	initRender();
}

void setColor(int hex) {
	double r = ((hex >> 16) & 0xff) / 255.0;
	double g = ((hex >> 8) & 0xff) / 255.0;
	double b = (hex & 0xff) / 255.0;
	glColor3d(r, g, b);
}

void drawTile(double left, double bottom, int color) {
	double right = left + render.tileSize.x;
	double top = bottom + render.tileSize.y;
	setColor(color);
	glBegin(GL_POLYGON);
	glVertex2d(left, bottom);
	glVertex2d(right, bottom);
	glVertex2d(right, top);
	glVertex2d(left, top);
	glEnd();
}

int tileTypeToColor(TileType type) {
	switch (type) {
	case Grass:
		return GREEN;
		break;
	case Water:
		return BLUE;
		break;
	case Fire:
		return RED;
		break;
	default:
		return BLACK;
		break;
	}
}

void renderTiles(void) {
	int color;
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			color = tileTypeToColor(level.tiles[i][j].tileType);
			drawTile(i * render.tileSize.x, j * render.tileSize.y, color);
		}
	}
}

void drawLine(double x1, double y1, double x2, double y2) {
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
	glViewport((int)render.viewportStart.x, (int)render.viewportStart.y, (GLsizei)render.viewport.x, (GLsizei)render.viewport.y);

	renderTiles();

	drawGrid();
	glutSwapBuffers();
}

Point getTileIndexFromMousePosition(Point mouse) {
	Point shifted;
	Point scaled;
	Point index;

	shifted = mouse - render.viewportStart;
	scaled = 1.0 * shifted / render.viewport;
	index = scaled / render.tileSize;
	index = index.floor();

	cout << index << endl;

	return index;
}

void myMouse(int button, int state, int x, int y) {
	Point index;

	// left button clicked
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
		index = getTileIndexFromMousePosition({ (double)x, (double)y });
		level.tiles[(int)index.x][(int)index.y].tileType = Water;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(SCREEN_W, SCREEN_H);
	glutInitWindowPosition(600, 150);
	glutCreateWindow("Render Level 2D");

	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);

	myInit();
	glutMainLoop();
}