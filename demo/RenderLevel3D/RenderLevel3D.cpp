#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include "lib/tile.h"
#include "lib/level.h"
#include "lib/point.h"
#include "camera.h"

using namespace std;

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

// constants
const int SCREEN_W = 600;
const int SCREEN_H = 600;
const float TILE_W = 2;
const float TILE_H = 1;
const float GRID_W = 0.5;

// globals
int numTilesX = 8;
int numTilesY = 8;
Camera* camera;
const float light_amb[] = { 0.5, 0.5, 0.5, 1.0 };
const float light_dif[] = { 0.25, 0.25, 0.25, 1.0 };
const float light_pos[] = { 30, 10, -40, 1.0 };
float ex, ey, ez, lx, ly, lz, upx, upy, upz;

enum Color {
	Green,
	LightGreen,
	YellowGreen,
	Red,
	DarkOrange,
	Orange,
	DarkYellow,
	Yellow,
	Black,
	White,
	Blue
};


Level level(numTilesX, numTilesY);

void initLevel() {
	for (int i = 0; i < numTilesX; i++) {
		for (int j = 0; j < numTilesY; j++) {
			if ((i % 2) == (j % 2))
				level.tiles[i][j].tileType = Fire;
			else
				level.tiles[i][j].tileType = Grass;
		}
	}
}

int colorToHex(Color color) {

	switch (color) {
	case Green:
		return GREEN;
		break;
	case LightGreen:
		return LIGHT_GREEN;
		break;
	case Red:
		return RED;
		break;
	case DarkOrange:
		return DARK_ORANGE;
		break;
	case Orange:
		return ORANGE;
		break;
	case DarkYellow:
		return DARK_YELLOW;
		break;
	case Yellow:
		return YELLOW;
		break;
	case Black:
		return BLACK;
		break;
	case White:
		return WHITE;
		break;
	case Blue:
		return BLUE;
		break;
	default:
		return BLACK;
		break;
	}
}

void setColor(int hex) {
	double r = ((hex >> 16) & 0xff) / 255.0;
	double g = ((hex >> 8) & 0xff) / 255.0;
	double b = (hex & 0xff) / 255.0;
	float amb[] = { r, g, b, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
}

void setColor(Color color) {
	setColor(colorToHex(color));
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

void drawTile(float i, float j) {
	float x = i * (TILE_W + GRID_W);
	float z = j * (TILE_W + GRID_W);
	float y = 0;

	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(TILE_W, TILE_H, TILE_W);
	glutSolidCube(1);
	glPopMatrix();
}

void renderTiles(void) {
	Color color;
	for (int i = 0; i < numTilesX; i++) {
		for (int j = 0; j < numTilesY; j++) {
			color = tileTypeToColor(level.tiles[i][j].tileType);
			setColor(color);
			drawTile(i, j);
		}
	}
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	// rotate entire grid
	glRotatef(45, 0, 1, 0);

	renderTiles();

	glPopMatrix();
	glutSwapBuffers();
}

void set_camera(int position) {

	ex = 10;
	ey = 3;
	ez = 10;

	lx = numTilesX * (TILE_W + GRID_W) / 2;
	ly = 3;
	lx = numTilesY * (TILE_W + GRID_W) / 2;

	// camera up vector
	upx = 0;
	upy = -1;
	upz = 0;

	camera->set(ex, ey, ez, lx, ly, lz, upx, upy, upz);
}

void doLighting() {
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_dif);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	glEnable(GL_LIGHT0);
}

void init() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

	// enable depth testing
	glEnable(GL_DEPTH_TEST);

	camera = new Camera();
	set_camera(1);

	doLighting();
	initLevel();

	glOrtho(-1, 1, -1, 1, -1, 1);

	myDisplay();
}

void kb_input(unsigned char key, int x, int y) {

	switch (key) {

	case 'a': camera->slide(-1.0, 0.0, 0.0); break;
	case 'd': camera->slide(1.0, 0.0, 0.0); break;
	case 's': camera->slide(0.0, 0.0, 1.0); break;
	case 'w': camera->slide(0.0, 0.0, -1.0); break;
	case 'q': camera->slide(0.0, 1.0, 0.0); break;
	case 'e': camera->slide(0.0, -1.0, 0.0); break;

	default:	break;
	}

	if (key >= '0' && key <= '9') {
		if (key == '0') // make 0 into 10 to reflect keyboard order
			key += 10;
		set_camera(key - '0');
	}

	glutPostRedisplay();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);

	glutInitWindowSize(SCREEN_W, SCREEN_H);

	glutInitWindowPosition(100, 150);
	glutCreateWindow("Render Level 3D");

	glutKeyboardFunc(kb_input);
	glutDisplayFunc(myDisplay);
	init();
	glutMainLoop();
}