#include "utils.h"
#include "lib/color.h"
#include "startPage.h"

Button A = { {(SCREEN_WIDTH / 2) - 400, (SCREEN_HEIGHT / 2) - 85},
			 {(SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) - 85},
			 {(SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) - 15},
			 {(SCREEN_WIDTH / 2) - 400,  (SCREEN_HEIGHT / 2) - 15}
};

Button B = { {(SCREEN_WIDTH / 2) - 400, (SCREEN_HEIGHT / 2) - 180},
			 {(SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) - 180},
			 {(SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) - 110},
			 {(SCREEN_WIDTH / 2) - 400,  (SCREEN_HEIGHT / 2) - 110}
};

Button C = { {(SCREEN_WIDTH / 2) - 400, (SCREEN_HEIGHT / 2) - 275},
			 {(SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) - 275},
			 {(SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) - 205},
			 {(SCREEN_WIDTH / 2) - 400,  (SCREEN_HEIGHT / 2) - 205}
};

Button D = { {(SCREEN_WIDTH / 2) - 400, (SCREEN_HEIGHT / 2) - 370},
			 {(SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) - 370},
			 {(SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) - 300},
			 {(SCREEN_WIDTH / 2) - 400,  (SCREEN_HEIGHT / 2) - 300}
};

Button questionOverlay = { {(SCREEN_WIDTH / 2) - 400, (SCREEN_HEIGHT / 2) + 100},
					{(SCREEN_WIDTH / 2) + 300, (SCREEN_HEIGHT / 2) + 100},
					{(SCREEN_WIDTH / 2) + 300, (SCREEN_HEIGHT / 2) + 25},
					{(SCREEN_WIDTH / 2) - 400,  (SCREEN_HEIGHT / 2) + 25}
};

void addQuestionOverlay() {
	Color c = Color::white;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(questionOverlay.A.x, questionOverlay.A.y);
	glVertex2d(questionOverlay.B.x, questionOverlay.B.y);
	glVertex2d(questionOverlay.C.x, questionOverlay.C.y);
	glVertex2d(questionOverlay.D.x, questionOverlay.D.y);
	glVertex2d(questionOverlay.A.x, questionOverlay.A.y);
	glEnd();
	glFlush();
}

void addButtonA() {
	Color c = Color::black;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(A.A.x - 10, A.A.y - 10);
	glVertex2d(A.B.x + 10, A.B.y - 10);
	glVertex2d(A.C.x + 10, A.C.y + 10);
	glVertex2d(A.D.x - 10, A.D.y + 10);
	glVertex2d(A.A.x - 10, A.A.y - 10);
	glEnd();
	c = Color::white;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(A.A.x, A.A.y);
	glVertex2d(A.B.x, A.B.y);
	glVertex2d(A.C.x, A.C.y);
	glVertex2d(A.D.x, A.D.y);
	glVertex2d(A.A.x, A.A.y);
	glEnd();
	c = Color::white;
	glBegin(GL_POLYGON);
	glVertex2d(A.A.x + 150, A.A.y);
	glVertex2d(A.B.x + 600, A.B.y);
	glVertex2d(A.C.x + 600, A.C.y);
	glVertex2d(A.D.x + 150, A.D.y);
	glVertex2d(A.A.x + 150, A.A.y);
	glEnd();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "A", (SCREEN_WIDTH / 2) - 360, (SCREEN_HEIGHT / 2) - 60, 1);
	glFlush();
}

void addButtonB() {
	Color c = Color::black;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(B.A.x - 10, B.A.y - 10);
	glVertex2d(B.B.x + 10, B.B.y - 10);
	glVertex2d(B.C.x + 10, B.C.y + 10);
	glVertex2d(B.D.x - 10, B.D.y + 10);
	glVertex2d(B.A.x - 10, B.A.y - 10);
	glEnd();
	c = Color::white;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(B.A.x, B.A.y);
	glVertex2d(B.B.x, B.B.y);
	glVertex2d(B.C.x, B.C.y);
	glVertex2d(B.D.x, B.D.y);
	glVertex2d(B.A.x, B.A.y);
	glEnd();
	c = Color::white;
	glBegin(GL_POLYGON);
	glVertex2d(B.A.x + 150, B.A.y);
	glVertex2d(B.B.x + 600, B.B.y);
	glVertex2d(B.C.x + 600, B.C.y);
	glVertex2d(B.D.x + 150, B.D.y);
	glVertex2d(B.A.x + 150, B.A.y);
	glEnd();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "B", (SCREEN_WIDTH / 2) - 360, (SCREEN_HEIGHT / 2) - 155, 1);
	glFlush();
}

void addButtonC() {
	Color c = Color::black;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(C.A.x - 10, C.A.y - 10);
	glVertex2d(C.B.x + 10, C.B.y - 10);
	glVertex2d(C.C.x + 10, C.C.y + 10);
	glVertex2d(C.D.x - 10, C.D.y + 10);
	glVertex2d(C.A.x - 10, C.A.y - 10);
	glEnd();
	c = Color::white;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(C.A.x, C.A.y);
	glVertex2d(C.B.x, C.B.y);
	glVertex2d(C.C.x, C.C.y);
	glVertex2d(C.D.x, C.D.y);
	glVertex2d(C.A.x, C.A.y);
	glEnd();
	c = Color::white;
	glBegin(GL_POLYGON);
	glVertex2d(C.A.x + 150, C.A.y);
	glVertex2d(C.B.x + 600, C.B.y);
	glVertex2d(C.C.x + 600, C.C.y);
	glVertex2d(C.D.x + 150, C.D.y);
	glVertex2d(C.A.x + 150, C.A.y);
	glEnd();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "C", (SCREEN_WIDTH / 2) - 360, (SCREEN_HEIGHT / 2) - 250, 1);
	glFlush();
}

void addButtonD() {
	Color c = Color::black;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(D.A.x - 10, D.A.y - 10);
	glVertex2d(D.B.x + 10, D.B.y - 10);
	glVertex2d(D.C.x + 10, D.C.y + 10);
	glVertex2d(D.D.x - 10, D.D.y + 10);
	glVertex2d(D.A.x - 10, D.A.y - 10);
	glEnd();
	c = Color::white;
	setcolor3ub(c);
	glBegin(GL_POLYGON);
	glVertex2d(D.A.x, D.A.y);
	glVertex2d(D.B.x, D.B.y);
	glVertex2d(D.C.x, D.C.y);
	glVertex2d(D.D.x, D.D.y);
	glVertex2d(D.A.x, D.A.y);
	glEnd();
	c = Color::white;
	glBegin(GL_POLYGON);
	glVertex2d(D.A.x + 150, D.A.y);
	glVertex2d(D.B.x + 600, D.B.y);
	glVertex2d(D.C.x + 600, D.C.y);
	glVertex2d(D.D.x + 150, D.D.y);
	glVertex2d(D.A.x + 150, D.A.y);
	glEnd();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "D", (SCREEN_WIDTH / 2) - 360, (SCREEN_HEIGHT / 2) - 345, 1);
	glFlush();
}

void displayQuestion1() {
	addOverlay();
	drawLogo();
	addQuestionOverlay();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Q1: How do the majority of wildfires start?", (SCREEN_WIDTH / 2) - 350, (SCREEN_HEIGHT / 2) + 50, 43);
	addButtonA();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Started by Human", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 60, 16);
	addButtonB();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Impact of a Meteor", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 155, 18);
	addButtonC();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Friction of Trees", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 250, 17);
	addButtonD();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Rain", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 345, 4);
}

void displayQuestion2() {
	addOverlay();
	drawLogo();
	addQuestionOverlay();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Q2: A large wildfire is also called a _______.", (SCREEN_WIDTH / 2) - 350, (SCREEN_HEIGHT / 2) + 50, 46);
	addButtonA();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Constellation", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 60, 13);
	addButtonB();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Boondoggle", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 155, 10);
	addButtonC();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Conflagration", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 250, 13);
	addButtonD();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Kerfuffle", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 345, 9);
}

void displayQuestion3() {
	addOverlay();
	drawLogo();
	addQuestionOverlay();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Q3: (True or False) A wildfire, if it is big enough, is capable of", (SCREEN_WIDTH / 2) - 370, (SCREEN_HEIGHT / 2) + 75, 66);
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "modifying the local weather conditions (producing its own weather).", (SCREEN_WIDTH / 2) - 370, (SCREEN_HEIGHT / 2) + 45, 71);
	addButtonA();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "True", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 60, 4);
	addButtonB();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "False", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 155, 5);
}

void displayQuestion4() {
	addOverlay();
	drawLogo();
	addQuestionOverlay();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Q4: Which of the following is NOT a means of putting out a fire?", (SCREEN_WIDTH / 2) - 350, (SCREEN_HEIGHT / 2) + 50, 64);
	addButtonA();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "With a household fire extinguisher", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 60, 34);
	addButtonB();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Air tankers (dropping water from an airplane)", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 155, 45);
	addButtonC();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Directing the fire to a sewer system", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 250, 36);
	addButtonD();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Starting another fire/ a backfire", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 345, 33);
}

void displayQuestion5() {
	addOverlay();
	drawLogo();
	addQuestionOverlay();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Q5: (True or False) Smoke from a fire can travel miles away from the", (SCREEN_WIDTH / 2) - 380, (SCREEN_HEIGHT / 2) + 75, 68);
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "source, but have no impact on air quality outside the affected area", (SCREEN_WIDTH / 2) - 380, (SCREEN_HEIGHT / 2) + 45, 67);
	addButtonA();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "True", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 60, 4);
	addButtonB();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "False", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 155, 5);
}

void displayQuestion6() {
	addOverlay();
	drawLogo();
	addQuestionOverlay();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Q6: Where did the largest Wildfire occur?", (SCREEN_WIDTH / 2) - 350, (SCREEN_HEIGHT / 2) + 50, 41);
	addButtonA();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Amazon Rain Forest (multiple countries)", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 60, 39);
	addButtonB();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "New Brunswick, Canada", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 155, 21);
	addButtonC();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Chicago, United States", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 250, 22);
	addButtonD();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Honshu, Japan", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 345, 13);
}

void displayQuestion7() {
	addOverlay();
	drawLogo();
	addQuestionOverlay();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Q7: How many acres of land are lost to wildfires in the United States?", (SCREEN_WIDTH / 2) - 350, (SCREEN_HEIGHT / 2) + 50, 64);
	addButtonA();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "800 Thousand", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 60, 12);
	addButtonB();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "300 Thousand", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 155, 12);
	addButtonC();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "10 Million", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 250, 10);
	addButtonD();
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "1.2 Million", (SCREEN_WIDTH / 2) - 230, (SCREEN_HEIGHT / 2) - 345, 11);
}

bool checkAnswer(char answer, int gameState) {
	switch (gameState){
	case(QUIZ_1): if (answer == 'a') { return true; } break;
	case(QUIZ_2): if (answer == 'c') { return true; } break;
	case(QUIZ_3): if (answer == 'a') { return true; } break;
	case(QUIZ_4): if (answer == 'd') { return true; } break;
	case(QUIZ_5): if (answer == 'a') { return true; } break;
	case(QUIZ_6): if (answer == 'b') { return true; } break;
	case(QUIZ_7): if (answer == 'd') { return true; } break;
	}
	return false;
}

int updateStatus(int gameState) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
	cout << "Game State " << gameState << endl;
	if (gameState == QUIZ_7) {
		gameState = QUIZ;
	}
	else {
		gameState++;
	}
	return gameState;
}

int quizPageClick(int button, int x, int y, int gameState, int score){
	char answer = 'x';
	bool correct = false;
	y = SCREEN_HEIGHT - y;
	
	if ((((x > A.A.x) && (x < A.B.x)) && ((y > A.A.y && y < A.C.y)))) {
		cout << "Clicked A" << endl;
		answer = 'a';
	}
	if ((((x > B.A.x) && (x < B.B.x)) && ((y > B.A.y && y < B.C.y)))) {
		cout << "Clicked B" << endl;
		answer = 'b';
	}
	if ((((x > C.A.x) && (x < C.B.x)) && ((y > C.A.y && y < C.C.y)))) {
		cout << "Clicked C" << endl;
		answer = 'c';
	}
	if ((((x > D.A.x) && (x < D.B.x)) && ((y > D.A.y && y < D.C.y)))) {
		cout << "Clicked D" << endl;
		answer = 'd';
	}
	correct = checkAnswer(answer, gameState);
	if (correct) {
		score++;
	}
	return score;
}