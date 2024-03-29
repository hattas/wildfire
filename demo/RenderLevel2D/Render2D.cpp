#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include "lib/tile.h"
#include "lib/level.h"
#include "lib/point.h"
#include "lib/color.h"
using namespace std;

// constants
const int SCREEN_W = 800;
const int SCREEN_H = 800;
const int X = 30;
const int Y = 30;

enum State {
	getMoveType,
	getMoveLocation,
	getPlaceLocation
};

struct Render {
	Point tileSize;
	Point viewport;
	Point viewportStart;
};

Level level(X, Y);
Render render;
Unit newUnit;
Point newDirection = { 1, 0 };
State moveState = getMoveType;

void initLevel() {
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			if (i > 10 && i < 15 && j > 10 && j < 15)
				level.tiles[i][j].tileType = TileType::fire;
			else
				level.tiles[i][j].tileType = TileType::grass;
		}
	}

	/*
	level.placeUnit(UnitType::truck, { 4, 7 }, { 1, 0 });
	level.placeUnit(UnitType::truck, { 20, 4 }, { 0, 1 });
	level.placeUnit(UnitType::truck, { 22, 25 }, { 0, -1 });
	level.placeUnit(UnitType::truck, { 15, 25 }, { -1, 0 });

	level.placeUnit(UnitType::heli, { 15, 15 }, { -1, 0 });

	level.placeUnit(UnitType::boat, { 4, 15 }, { 1, 0 });\*/
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

void setColor(Color color) {
	int hex = (int)color;
	double r = ((hex >> 16) & 0xff) / 255.0;
	double g = ((hex >> 8) & 0xff) / 255.0;
	double b = (hex & 0xff) / 255.0;
	glColor3d(r, g, b);
}

void drawTile(int i, int j, Color color) {
	double left = i * render.tileSize.x;
	double bottom = j * render.tileSize.y;
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

Color tileTypeToColor(TileType type) {
	switch (type) {
	case TileType::grass:
		return Color::green;
		break;
	case TileType::water:
		return Color::blue;
		break;
	case TileType::fire:
		return Color::red;
		break;
	default:
		return Color::black;
		break;
	}
}

void renderTiles(void) {
	Color color;
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			color = tileTypeToColor(level.tiles[i][j].tileType);
			drawTile(i, j, color);
		}
	}
}

void renderUnits(void) {
	Color color;
	int u, i, j, iStart, iEnd, jStart, jEnd;
	Unit unit;
	for (u = 0; u <= level.numUnits; u++) {

		if (u == level.numUnits) {
			unit = newUnit;
			if (moveState != getMoveLocation)
				break;
		}
		else
			unit = level.units[u];

		if (unit.direction.x) {
			iStart = min(unit.position.x, unit.position.x - unit.size.x * unit.direction.x + unit.direction.x);
			iEnd = max(unit.position.x, unit.position.x - unit.size.x * unit.direction.x + unit.direction.x);
			jStart = unit.position.y;
			jEnd = unit.position.y + unit.size.y - 1;
		}
		else {
			jStart = min(unit.position.y, unit.position.y - unit.size.y * unit.direction.y + unit.direction.y);
			jEnd = max(unit.position.y, unit.position.y - unit.size.y * unit.direction.y + unit.direction.y);
			iStart = unit.position.x;
			iEnd = unit.position.x + unit.size.x - 1;
		}
		for (i = iStart; i <= iEnd; i++) {
			for (j = jStart; j <= jEnd; j++) {
				if (u == level.numUnits)
					color = Color::lightGreen;
				else if (unit.type == UnitType::truck)
					color = Color::white;
				else if (unit.type == UnitType::boat)
					color = Color::black;
				else if (unit.type == UnitType::heli)
					color = Color::yellow;
				drawTile(i, j, color);
			}
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
	renderUnits();

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

	//cout << index << endl;

	return index;
}

void myMouse(int button, int state, int x, int y) {
	Point index = getTileIndexFromMousePosition({ (double)x, (double)y });

	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {

		cout << "state=" << moveState << endl;

		if (moveState == getMoveType) {
			// left button clicked
			for (int u = 0; u < level.numUnits; u++) {
				if (level.units[u].position == index) {
					newUnit = level.units[u];
					level.removeUnitAtIndex(u);
					moveState = getMoveLocation;
					cout << "removing unit and moving it" << endl;
					cout << moveState << endl;
					glutPostRedisplay();
					return;
				}
			}
			cout << "no unit selected" << endl;
		}
		else if (moveState == getMoveLocation) {
			cout << "adding the new unit at this location" << endl;
			moveState = getMoveType;
			newUnit.position = index;
			level.placeUnit(newUnit);
			level.spreadWater();
			glutPostRedisplay();
			level.spreadFire();
			glutPostRedisplay();
		}

	}
}

void myMouseMotionPassive(int x, int y) {
	Point index = getTileIndexFromMousePosition({ (double)x, (double)y });

	if (moveState == getMoveLocation) {
		cout << "moving around the new unit" << endl;
		newUnit.position = index;
		glutPostRedisplay();
	}
}

void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {
	Point index = getTileIndexFromMousePosition({ (double)mouseX, (double)mouseY });
	cout << moveState << endl;

	if (moveState == getMoveType) {
		if (theKey == '1') {
			cout << "adding new truck unit" << endl;
			newUnit = Unit(UnitType::truck, index, newDirection);
			moveState = getMoveLocation;
			glutPostRedisplay();
		}
		else if (theKey == '2') {
			cout << "adding new heli unit" << endl;
			newUnit = Unit(UnitType::heli, index, newDirection);
			moveState = getMoveLocation;
			glutPostRedisplay();
		}
		else if (theKey == '3') {
			cout << "adding new boat unit" << endl;
			newUnit = Unit(UnitType::boat, index, newDirection);
			moveState = getMoveLocation;
			glutPostRedisplay();
		}
	}

	else if (moveState == getMoveLocation) {
		if (theKey == 'r') {
			if (newUnit.direction == Point(1, 0)) {
				newUnit.direction = { 0, 1 };
			}
			else if (newUnit.direction == Point(0, 1)) {
				newUnit.direction = { -1, 0 };
			}
			else if (newUnit.direction == Point(-1, 0)) {
				newUnit.direction = { 0, -1 };
			}
			else if (newUnit.direction == Point(0, -1)) {
				newUnit.direction = { 1, 0 };
			}
			glutPostRedisplay();
		}
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
	glutPassiveMotionFunc(myMouseMotionPassive);
	glutKeyboardFunc(myKeyboard);

	myInit();
	glutMainLoop();
}