#include "utils.h"

void addOverlay() {
	glColor4f(1.0, 1.0, 1.0, 0.6);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glVertex2i(0, 0);
	glVertex2i(0, SCREEN_HEIGHT);
	glVertex2i(SCREEN_WIDTH, SCREEN_HEIGHT);
	glVertex2i(SCREEN_WIDTH, 0);
	glEnd();
	glFlush();
}

void addHeader() {
	//drawString()
}

void drawButton(int x, int y, Color c) {
	int buttonWidth = 100;
	int buttonHeight = 40;
	int border = 5;

	glColor3ub(c.r, c.g, c.b);
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + buttonWidth, y);
	glVertex2i(x + buttonWidth, y + buttonHeight);
	glVertex2i(x, y + buttonHeight);
	glEnd();
	c = Black;
	glColor3ub(c.r, c.g, c.b);
	glVertex2i(x + border, y + border);
	glVertex2i(x + buttonWidth + border, y + border);
	glVertex2i(x + buttonWidth + border, y + buttonHeight + border);
	glVertex2i(x + border, y + buttonHeight + border);
	glEnd();
	glFlush();
}
void drawLogo() {
	Color c = Red;
	glColor3ub(c.r, c.g, c.b);
	fstream inStream;
	inStream.open("logo.dat", ios::in); //open the file

	if (inStream.fail()) return;
	GLint radius, numWords, numPoints, x, y;
	inStream >> radius; 
	inStream >> numWords;

	for (int j = 0; j < numWords; j++) { //read each polyline
		inStream >> numPoints;
		glPointSize(radius);
		glBegin(GL_POINTS);
		for (int i = 0; i < numPoints; i++) {
			inStream >> x >> y; //read the next x, y pair
			glVertex2f((SCREEN_WIDTH / 2) + (10 * x), (7 * SCREEN_HEIGHT / 8) + (10 * y));
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

void homeScreen() {
	addOverlay();
	drawString(GLUT_BITMAP_HELVETICA_18, "Wild & Smokey", 100, 200, 13);
	drawLogo();
}