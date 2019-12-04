#include "utils.h"

Button newGame = { {(SCREEN_WIDTH / 2) - 250, (SCREEN_HEIGHT / 2) - 35}, 
					{(SCREEN_WIDTH / 2) + 250, (SCREEN_HEIGHT / 2) - 35}, 
					{(SCREEN_WIDTH / 2) + 250, (SCREEN_HEIGHT / 2) + 35}, 
					{(SCREEN_WIDTH / 2) - 250,  (SCREEN_HEIGHT / 2) + 35} 
};

Button howToPlay = { {(SCREEN_WIDTH / 2) - 250, (SCREEN_HEIGHT / 2) - 165},
					{(SCREEN_WIDTH / 2) + 250, (SCREEN_HEIGHT / 2) - 165},
					{(SCREEN_WIDTH / 2) + 250, (SCREEN_HEIGHT / 2) - 95},
					{(SCREEN_WIDTH / 2) - 250,  (SCREEN_HEIGHT / 2) - 95}
};

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
			glVertex2f((SCREEN_WIDTH / 2) + (10 * x) - 180, (7 * SCREEN_HEIGHT / 8) + (10 * y));
		}
		glEnd();
		c = Gray;
		glColor3ub(c.r, c.g, c.b);
	}
	glFlush();
	inStream.close();
}

void addButtons() {
	// Start Game
	Color c = Gray;
	glColor3ub(c.r, c.g, c.b);
	glBegin(GL_POLYGON);
	glVertex2d(newGame.A.x - 10, newGame.A.y - 10);
	glVertex2d(newGame.B.x + 10, newGame.B.y - 10);
	glVertex2d(newGame.C.x + 10, newGame.C.y + 10);
	glVertex2d(newGame.D.x - 10, newGame.D.y + 10);
	glVertex2d(newGame.A.x - 10, newGame.A.y - 10);
	glEnd();
	c = White;
	glColor3ub(c.r, c.g, c.b);
	glBegin(GL_POLYGON);
	glVertex2d(newGame.A.x, newGame.A.y);
	glVertex2d(newGame.B.x, newGame.B.y);
	glVertex2d(newGame.C.x, newGame.C.y);
	glVertex2d(newGame.D.x, newGame.D.y);
	glVertex2d(newGame.A.x, newGame.A.y);
	glEnd();
	drawString(GLUT_BITMAP_HELVETICA_18, "New Game", (SCREEN_WIDTH / 2) - 45, (SCREEN_HEIGHT / 2), 8);
	c = Gray;
	glColor3ub(c.r, c.g, c.b);
	glBegin(GL_POLYGON);
	glVertex2d(howToPlay.A.x - 10, howToPlay.A.y - 10);
	glVertex2d(howToPlay.B.x + 10, howToPlay.B.y - 10);
	glVertex2d(howToPlay.C.x + 10, howToPlay.C.y + 10);
	glVertex2d(howToPlay.D.x - 10, howToPlay.D.y + 10);
	glVertex2d(howToPlay.A.x - 10, howToPlay.A.y - 10);
	glEnd();
	c = White;
	glColor3ub(c.r, c.g, c.b);
	glBegin(GL_POLYGON);
	glVertex2d(howToPlay.A.x, howToPlay.A.y);
	glVertex2d(howToPlay.B.x, howToPlay.B.y);
	glVertex2d(howToPlay.C.x, howToPlay.C.y);
	glVertex2d(howToPlay.D.x, howToPlay.D.y);
	glVertex2d(howToPlay.A.x, howToPlay.A.y);
	glEnd();
	drawString(GLUT_BITMAP_HELVETICA_18, "How to Play!", (SCREEN_WIDTH / 2) - 50, (SCREEN_HEIGHT / 2) - 130, 12);
	glFlush();
}

void homeScreen() {
	addOverlay();
	drawLogo();
	addButtons();
}

void howToPage() {
	addOverlay();
	drawLogo();
	addButtons();
}
void startPageIdle(void) {
	//check click
	//otherwise change the background
	//cout << "Spread Fire" << endl;
	spreadFire();
	glutPostRedisplay();
	std::this_thread::sleep_for(0.2s);
}

int startPageClick(int button, int x, int y) {
	//Check if New Game button was pressed
	y = SCREEN_HEIGHT - y;
	if (((x > newGame.A.x) && (x < newGame.B.x)) && ((y > newGame.A.y && y < newGame.C.y))) {
		cout << "Clicked New Game" << endl;
		return PLAY_GAME;
	}
	//Check if How to Play is Pressed
	if (((x > howToPlay.A.x) && (x < howToPlay.B.x)) && ((y > howToPlay.A.y && y < howToPlay.C.y))) {
		cout << "Clicked How to Play" << endl;
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glutSwapBuffers();
		return HOW_TO_PLAY;
	}
	return START_PAGE;
}
