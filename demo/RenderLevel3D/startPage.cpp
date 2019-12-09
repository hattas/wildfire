#include "utils.h"
#include "lib/color.h"

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

Button About = { {(SCREEN_WIDTH / 2) - 250, (SCREEN_HEIGHT / 2) - 295},
					{(SCREEN_WIDTH / 2) + 250, (SCREEN_HEIGHT / 2) - 295},
					{(SCREEN_WIDTH / 2) + 250, (SCREEN_HEIGHT / 2) - 225},
					{(SCREEN_WIDTH / 2) - 250,  (SCREEN_HEIGHT / 2) - 225}
};

Button Back = { {(SCREEN_WIDTH / 2) - 550, (SCREEN_HEIGHT / 2) - 320},
					{(SCREEN_WIDTH / 2) - 400, (SCREEN_HEIGHT / 2) - 320},
					{(SCREEN_WIDTH / 2) - 400, (SCREEN_HEIGHT / 2) - 380},
					{(SCREEN_WIDTH / 2) - 550,  (SCREEN_HEIGHT / 2) - 380}
};

Button textOverlay = { {(SCREEN_WIDTH / 2) - 575, (SCREEN_HEIGHT / 2) + 100},
					{(SCREEN_WIDTH / 2) + 575, (SCREEN_HEIGHT / 2) + 100},
					{(SCREEN_WIDTH / 2) + 575, (SCREEN_HEIGHT / 2) - 300},
					{(SCREEN_WIDTH / 2) - 575,  (SCREEN_HEIGHT / 2) - 300}
};

Point W[12] = { {(SCREEN_WIDTH / 2) - 550, (SCREEN_HEIGHT / 2) + 350}, {(SCREEN_WIDTH / 2) - 525, (SCREEN_HEIGHT / 2) + 350},
				{(SCREEN_WIDTH / 2) - 525, (SCREEN_HEIGHT / 2) + 275}, {(SCREEN_WIDTH / 2) - 500, (SCREEN_HEIGHT / 2) + 275},
				{(SCREEN_WIDTH / 2) - 500, (SCREEN_HEIGHT / 2) + 325}, {(SCREEN_WIDTH / 2) - 475, (SCREEN_HEIGHT / 2) + 325},
				{(SCREEN_WIDTH / 2) - 475, (SCREEN_HEIGHT / 2) + 275}, {(SCREEN_WIDTH / 2) - 450, (SCREEN_HEIGHT / 2) + 275},
				{(SCREEN_WIDTH / 2) - 450, (SCREEN_HEIGHT / 2) + 350}, {(SCREEN_WIDTH / 2) - 425, (SCREEN_HEIGHT / 2) + 350},
				{(SCREEN_WIDTH / 2) - 425, (SCREEN_HEIGHT / 2) + 250}, {(SCREEN_WIDTH / 2) - 550, (SCREEN_HEIGHT / 2) + 250} };

Point I[12] = { {(SCREEN_WIDTH / 2) - 400, (SCREEN_HEIGHT / 2) + 350}, {(SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) + 350},
				{(SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) + 325}, {(SCREEN_WIDTH / 2) - 330, (SCREEN_HEIGHT / 2) + 325},
				{(SCREEN_WIDTH / 2) - 330, (SCREEN_HEIGHT / 2) + 275}, {(SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) + 275},
				{(SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) + 250}, {(SCREEN_WIDTH / 2) - 400, (SCREEN_HEIGHT / 2) + 250},
				{(SCREEN_WIDTH / 2) - 400, (SCREEN_HEIGHT / 2) + 275}, {(SCREEN_WIDTH / 2) - 370, (SCREEN_HEIGHT / 2) + 275},
				{(SCREEN_WIDTH / 2) - 370, (SCREEN_HEIGHT / 2) + 325}, {(SCREEN_WIDTH / 2) - 400, (SCREEN_HEIGHT / 2) + 325} };

Point L[6] = { {(SCREEN_WIDTH / 2) - 275, (SCREEN_HEIGHT / 2) + 350}, {(SCREEN_WIDTH / 2) - 235, (SCREEN_HEIGHT / 2) + 350 },
				{(SCREEN_WIDTH / 2) - 235, (SCREEN_HEIGHT / 2) + 275}, {(SCREEN_WIDTH / 2) - 175, (SCREEN_HEIGHT / 2) + 275 },
				{(SCREEN_WIDTH / 2) - 175, (SCREEN_HEIGHT / 2) + 250}, {(SCREEN_WIDTH / 2) - 275, (SCREEN_HEIGHT / 2) + 250} };

Point D[6] = { {(SCREEN_WIDTH / 2) - 150, (SCREEN_HEIGHT / 2) + 350}, {(SCREEN_WIDTH / 2) - 75, (SCREEN_HEIGHT / 2) + 350 },
				{(SCREEN_WIDTH / 2) - 50, (SCREEN_HEIGHT / 2) + 325}, {(SCREEN_WIDTH / 2) - 50, (SCREEN_HEIGHT / 2) + 275 },
				{(SCREEN_WIDTH / 2) - 75, (SCREEN_HEIGHT / 2) + 250}, {(SCREEN_WIDTH / 2) - 150, (SCREEN_HEIGHT / 2) + 250} };

Point S[12] = { {(SCREEN_WIDTH / 2) - 275, (SCREEN_HEIGHT / 2) + 225}, {(SCREEN_WIDTH / 2) - 175, (SCREEN_HEIGHT / 2) + 225},
				{(SCREEN_WIDTH / 2) - 175, (SCREEN_HEIGHT / 2) + 205}, {(SCREEN_WIDTH / 2) - 250, (SCREEN_HEIGHT / 2) + 205},
				{(SCREEN_WIDTH / 2) - 250, (SCREEN_HEIGHT / 2) + 185}, {(SCREEN_WIDTH / 2) - 175, (SCREEN_HEIGHT / 2) + 185},
				{(SCREEN_WIDTH / 2) - 175, (SCREEN_HEIGHT / 2) + 125}, {(SCREEN_WIDTH / 2) - 275, (SCREEN_HEIGHT / 2) + 125},
				{(SCREEN_WIDTH / 2) - 275, (SCREEN_HEIGHT / 2) + 145}, {(SCREEN_WIDTH / 2) - 200, (SCREEN_HEIGHT / 2) + 145},
				{(SCREEN_WIDTH / 2) - 200, (SCREEN_HEIGHT / 2) + 165}, {(SCREEN_WIDTH / 2) - 275, (SCREEN_HEIGHT / 2) + 165} };

Point M[12] = { {(SCREEN_WIDTH / 2) - 150, (SCREEN_HEIGHT / 2) + 225}, {(SCREEN_WIDTH / 2) - 25, (SCREEN_HEIGHT / 2) + 225},
				{(SCREEN_WIDTH / 2) - 25, (SCREEN_HEIGHT / 2) + 125}, {(SCREEN_WIDTH / 2) - 50, (SCREEN_HEIGHT / 2) + 125},
				{(SCREEN_WIDTH / 2) - 50, (SCREEN_HEIGHT / 2) + 200}, {(SCREEN_WIDTH / 2) - 75, (SCREEN_HEIGHT / 2) + 200},
				{(SCREEN_WIDTH / 2) - 75, (SCREEN_HEIGHT / 2) + 150}, {(SCREEN_WIDTH / 2) - 100, (SCREEN_HEIGHT / 2) + 150},
				{(SCREEN_WIDTH / 2) - 100, (SCREEN_HEIGHT / 2) + 200}, {(SCREEN_WIDTH / 2) - 125, (SCREEN_HEIGHT / 2) + 200},
				{(SCREEN_WIDTH / 2) - 125, (SCREEN_HEIGHT / 2) + 125}, {(SCREEN_WIDTH / 2) - 150, (SCREEN_HEIGHT / 2) + 125} };

Point O[8] = { {(SCREEN_WIDTH / 2) + 25, (SCREEN_HEIGHT / 2) + 225 }, {(SCREEN_WIDTH / 2) + 75, (SCREEN_HEIGHT / 2) + 225},
				{(SCREEN_WIDTH / 2) + 100, (SCREEN_HEIGHT / 2) + 200}, {(SCREEN_WIDTH / 2) + 100, (SCREEN_HEIGHT / 2) + 150},
				{(SCREEN_WIDTH / 2) + 75, (SCREEN_HEIGHT / 2) + 125},  {(SCREEN_WIDTH / 2) + 25, (SCREEN_HEIGHT / 2) + 125},
				{(SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) + 150}, {(SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) + 200} };

Point K[11] = { {(SCREEN_WIDTH / 2) + 125, (SCREEN_HEIGHT / 2) + 225}, {(SCREEN_WIDTH / 2) + 150, (SCREEN_HEIGHT / 2) + 225},
				{(SCREEN_WIDTH / 2) + 150, (SCREEN_HEIGHT / 2) + 190}, {(SCREEN_WIDTH / 2) + 200, (SCREEN_HEIGHT / 2) + 225},
				{(SCREEN_WIDTH / 2) + 225, (SCREEN_HEIGHT / 2) + 200}, {(SCREEN_WIDTH / 2) + 175, (SCREEN_HEIGHT / 2) + 175},
				{(SCREEN_WIDTH / 2) + 225, (SCREEN_HEIGHT / 2) + 150}, {(SCREEN_WIDTH / 2) + 200, (SCREEN_HEIGHT / 2) + 125},
				{(SCREEN_WIDTH / 2) + 150, (SCREEN_HEIGHT / 2) + 160}, {(SCREEN_WIDTH / 2) + 150, (SCREEN_HEIGHT / 2) + 125},
				{(SCREEN_WIDTH / 2) + 125, (SCREEN_HEIGHT / 2) + 125} };

Point E[12] = { {(SCREEN_WIDTH / 2) + 250, (SCREEN_HEIGHT / 2) + 225}, {(SCREEN_WIDTH / 2) + 350, (SCREEN_HEIGHT / 2) + 225},
				{(SCREEN_WIDTH / 2) + 350, (SCREEN_HEIGHT / 2) + 205}, {(SCREEN_WIDTH / 2) + 275, (SCREEN_HEIGHT / 2) + 205},
				{(SCREEN_WIDTH / 2) + 275, (SCREEN_HEIGHT / 2) + 185}, {(SCREEN_WIDTH / 2) + 325, (SCREEN_HEIGHT / 2) + 185},
				{(SCREEN_WIDTH / 2) + 325, (SCREEN_HEIGHT / 2) + 165}, {(SCREEN_WIDTH / 2) + 275, (SCREEN_HEIGHT / 2) + 165},
				{(SCREEN_WIDTH / 2) + 275, (SCREEN_HEIGHT / 2) + 145}, {(SCREEN_WIDTH / 2) + 350, (SCREEN_HEIGHT / 2) + 145},
				{(SCREEN_WIDTH / 2) + 350, (SCREEN_HEIGHT / 2) + 125}, {(SCREEN_WIDTH / 2) + 250, (SCREEN_HEIGHT / 2) + 125} };

Point Y[9] = { {(SCREEN_WIDTH / 2) + 375, (SCREEN_HEIGHT / 2) + 200}, {(SCREEN_WIDTH / 2) + 400, (SCREEN_HEIGHT / 2) + 225},
				{(SCREEN_WIDTH / 2) + 425, (SCREEN_HEIGHT / 2) + 200}, {(SCREEN_WIDTH / 2) + 450, (SCREEN_HEIGHT / 2) + 225},
				{(SCREEN_WIDTH / 2) + 475, (SCREEN_HEIGHT / 2) + 200}, {(SCREEN_WIDTH / 2) + 440, (SCREEN_HEIGHT / 2) + 175},
				{(SCREEN_WIDTH / 2) + 440, (SCREEN_HEIGHT / 2) + 125}, {(SCREEN_WIDTH / 2) + 410, (SCREEN_HEIGHT / 2) + 125},
				{(SCREEN_WIDTH / 2) + 410, (SCREEN_HEIGHT / 2) + 175} };

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

void setcolor3ub(Color color) {
	int hex = (int)color;
	double r = ((hex >> 16) & 0xff) / 255.0;
	double g = ((hex >> 8) & 0xff) / 255.0;
	double b = (hex & 0xff) / 255.0;
	glColor3f(r,g,b);
}

void addHeader() {
	//drawString()
}

void drawButton(int x, int y, Color c) {
	int buttonWidth = 100;
	int buttonHeight = 40;
	int border = 5;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + buttonWidth, y);
	glVertex2i(x + buttonWidth, y + buttonHeight);
	glVertex2i(x, y + buttonHeight);
	glEnd();
	c = Color::black;
	setcolor3ub(c);
	glVertex2i(x + border, y + border);
	glVertex2i(x + buttonWidth + border, y + border);
	glVertex2i(x + buttonWidth + border, y + buttonHeight + border);
	glVertex2i(x + border, y + buttonHeight + border);
	glEnd();
	glFlush();
}
void drawLogo() {

	Color c = Color::red;
	glLineWidth(10);
	setcolor3ub(c);
	glPointSize(10);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 12; i++) {
		glVertex2f(W[i].x, W[i].y);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 12; i++) {
		glVertex2f(I[i].x, I[i].y);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 6; i++) {
		glVertex2f(L[i].x, L[i].y);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 6; i++) {
		glVertex2f(D[i].x, D[i].y);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 6; i++) {
		glVertex2f(D[i].x * .5 + 250, D[i].y * .5 + 350);
	}
	glEnd();
	glFlush();
	c = Color::gray;
	setcolor3ub(c);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 12; i++) {
		glVertex2f(S[i].x, S[i].y);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 12; i++) {
		glVertex2f(M[i].x, M[i].y);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 8; i++) {
		glVertex2f(O[i].x, O[i].y);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 8; i++) {
		glVertex2f(O[i].x * .5 + 325, O[i].y * .5 + 287);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 11; i++) {
		glVertex2f(K[i].x, K[i].y);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 12; i++) {
		glVertex2f(E[i].x, E[i].y);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 9; i++) {
		glVertex2f(Y[i].x, Y[i].y);
	}
	glEnd();
	glFlush();
	glLineWidth(1);
}

void addButtons() {
	// Start Game
	Color c = Color::black;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(newGame.A.x - 10, newGame.A.y - 10);
	glVertex2d(newGame.B.x + 10, newGame.B.y - 10);
	glVertex2d(newGame.C.x + 10, newGame.C.y + 10);
	glVertex2d(newGame.D.x - 10, newGame.D.y + 10);
	glVertex2d(newGame.A.x - 10, newGame.A.y - 10);
	glEnd();
	c = Color::white;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(newGame.A.x, newGame.A.y);
	glVertex2d(newGame.B.x, newGame.B.y);
	glVertex2d(newGame.C.x, newGame.C.y);
	glVertex2d(newGame.D.x, newGame.D.y);
	glVertex2d(newGame.A.x, newGame.A.y);
	glEnd();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "New Game", (SCREEN_WIDTH / 2) - 50, (SCREEN_HEIGHT / 2), 8);
	c = Color::black;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(howToPlay.A.x - 10, howToPlay.A.y - 10);
	glVertex2d(howToPlay.B.x + 10, howToPlay.B.y - 10);
	glVertex2d(howToPlay.C.x + 10, howToPlay.C.y + 10);
	glVertex2d(howToPlay.D.x - 10, howToPlay.D.y + 10);
	glVertex2d(howToPlay.A.x - 10, howToPlay.A.y - 10);
	glEnd();
	c = Color::white;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(howToPlay.A.x, howToPlay.A.y);
	glVertex2d(howToPlay.B.x, howToPlay.B.y);
	glVertex2d(howToPlay.C.x, howToPlay.C.y);
	glVertex2d(howToPlay.D.x, howToPlay.D.y);
	glVertex2d(howToPlay.A.x, howToPlay.A.y);
	glEnd();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "How to Play!", (SCREEN_WIDTH / 2) - 60, (SCREEN_HEIGHT / 2) - 135, 12);
	c = Color::black;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(About.A.x - 10, About.A.y - 10);
	glVertex2d(About.B.x + 10, About.B.y - 10);
	glVertex2d(About.C.x + 10, About.C.y + 10);
	glVertex2d(About.D.x - 10, About.D.y + 10);
	glVertex2d(About.A.x - 10, About.A.y - 10);
	glEnd();
	c = Color::white;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(About.A.x, About.A.y);
	glVertex2d(About.B.x, About.B.y);
	glVertex2d(About.C.x, About.C.y);
	glVertex2d(About.D.x, About.D.y);
	glVertex2d(About.A.x, About.A.y);
	glEnd();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "About The Game!", (SCREEN_WIDTH / 2) - 90, (SCREEN_HEIGHT / 2) - 265, 15);
	glFlush();
}

void loading() {
	// Start Game
	addOverlay();
	drawLogo();
	Color c = Color::black;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(newGame.A.x - 10, newGame.A.y - 10);
	glVertex2d(newGame.B.x + 10, newGame.B.y - 10);
	glVertex2d(newGame.C.x + 10, newGame.C.y + 10);
	glVertex2d(newGame.D.x - 10, newGame.D.y + 10);
	glVertex2d(newGame.A.x - 10, newGame.A.y - 10);
	glEnd();
	c = Color::white;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(newGame.A.x, newGame.A.y);
	glVertex2d(newGame.B.x, newGame.B.y);
	glVertex2d(newGame.C.x, newGame.C.y);
	glVertex2d(newGame.D.x, newGame.D.y);
	glVertex2d(newGame.A.x, newGame.A.y);
	glEnd();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Loading...", (SCREEN_WIDTH / 2) - 50, (SCREEN_HEIGHT / 2), 10);
	c = Color::black;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(howToPlay.A.x - 10, howToPlay.A.y - 10);
	glVertex2d(howToPlay.B.x + 10, howToPlay.B.y - 10);
	glVertex2d(howToPlay.C.x + 10, howToPlay.C.y + 10);
	glVertex2d(howToPlay.D.x - 10, howToPlay.D.y + 10);
	glVertex2d(howToPlay.A.x - 10, howToPlay.A.y - 10);
	glEnd();
	c = Color::white;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(howToPlay.A.x, howToPlay.A.y);
	glVertex2d(howToPlay.B.x, howToPlay.B.y);
	glVertex2d(howToPlay.C.x, howToPlay.C.y);
	glVertex2d(howToPlay.D.x, howToPlay.D.y);
	glVertex2d(howToPlay.A.x, howToPlay.A.y);
	glEnd();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "How to Play!", (SCREEN_WIDTH / 2) - 60, (SCREEN_HEIGHT / 2) - 135, 12);
	c = Color::black;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(About.A.x - 10, About.A.y - 10);
	glVertex2d(About.B.x + 10, About.B.y - 10);
	glVertex2d(About.C.x + 10, About.C.y + 10);
	glVertex2d(About.D.x - 10, About.D.y + 10);
	glVertex2d(About.A.x - 10, About.A.y - 10);
	glEnd();
	c = Color::white;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(About.A.x, About.A.y);
	glVertex2d(About.B.x, About.B.y);
	glVertex2d(About.C.x, About.C.y);
	glVertex2d(About.D.x, About.D.y);
	glVertex2d(About.A.x, About.A.y);
	glEnd();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "About The Game!", (SCREEN_WIDTH / 2) - 90, (SCREEN_HEIGHT / 2) - 265, 15);
	glFlush();
}

void addTextOverlay() {
	Color c = Color::white;
	c = Color::black;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(Back.A.x - 10, Back.A.y + 10);
	glVertex2d(Back.B.x + 10, Back.B.y + 10);
	glVertex2d(Back.C.x + 10, Back.C.y - 10);
	glVertex2d(Back.D.x - 10, Back.D.y - 10);
	glEnd();
	c = Color::white;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(Back.A.x, Back.A.y);
	glVertex2d(Back.B.x, Back.B.y);
	glVertex2d(Back.C.x, Back.C.y);
	glVertex2d(Back.D.x, Back.D.y);
	glVertex2d(Back.A.x, Back.A.y);
	glEnd();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Back", (SCREEN_WIDTH / 2) - 500, (SCREEN_HEIGHT / 2) - 360, 4);
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(textOverlay.A.x, textOverlay.A.y);
	glVertex2d(textOverlay.B.x, textOverlay.B.y);
	glVertex2d(textOverlay.C.x, textOverlay.C.y);
	glVertex2d(textOverlay.D.x, textOverlay.D.y);
	glVertex2d(textOverlay.A.x, textOverlay.A.y);
	glEnd();
}

void addHowToPlayText() {

	addTextOverlay();

	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Wild and Smokey is a turn-based wildfire fighting game. Players are given various wildfire fighting personal", (SCREEN_WIDTH / 2) - 550, (SCREEN_HEIGHT / 2) + 75, 108);
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "and equipment which will aid them in the battle against the fire. Each turn the player will have the option to move,", (SCREEN_WIDTH / 2) - 550, (SCREEN_HEIGHT / 2) + 50, 116);
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "deploy, or evacuate these assets as the fire rages on.", (SCREEN_WIDTH / 2) - 550, (SCREEN_HEIGHT / 2) + 25, 54);
}

void addAboutText() {
	addTextOverlay();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "This game was created by John Hattas, Russell Reding, Paula Van Camp", (SCREEN_WIDTH / 2) - 400, (SCREEN_HEIGHT / 2) + 75, 68);
}

void homeScreen() {
	addOverlay();
	drawLogo();
	addButtons();
}

void howToPage() {
	addOverlay();
	drawLogo();
	addHowToPlayText();
}

void aboutPage() {
	addOverlay();
	drawLogo();
	addAboutText();
}
void startPageIdle(void) {
	//check click
	//otherwise change the background
	//cout << "Spread Fire" << endl;
	spreadFireHome();
	glutPostRedisplay();
	std::this_thread::sleep_for(0.2s);
}

int startPageClick(int button, int x, int y) {
	cout << x << " " << y << endl;
	//Check if New Game button was pressed
	y = SCREEN_HEIGHT - y;
	if ((x > Back.A.x && x < Back.C.x) && (y < Back.A.y && y > Back.C.y)) {
		cout << "Clicked Start Page" << endl;
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glutSwapBuffers();
		return START_PAGE;
	}
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
	if (((x > About.A.x) && (x < About.B.x)) && ((y > About.A.y && y < About.C.y))) {
		cout << "Clicked About" << endl;
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glutSwapBuffers();
		return ABOUT;
	}
	return START_PAGE;
}