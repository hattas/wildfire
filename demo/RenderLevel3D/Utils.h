#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <fstream>
#include "startPage.h"
#include "lib/point.h"

#define START_PAGE 1
#define HOW_TO_PLAY 2
#define ABOUT 3
#define QUIZ 4
#define PLAY_GAME 5
#define QUIZ_1 6
#define QUIZ_2 7
#define QUIZ_3 8
#define QUIZ_4 9
#define QUIZ_5 10
#define QUIZ_6 11
#define QUIZ_7 12


using namespace std;
using namespace std::chrono_literals;

struct Button {
	Point A;
	Point B;
	Point C;
	Point D;
};
void spreadFireHome(void);
void drawStrokeText(char* string, int x, int y, int z, Color color);
void drawString(void* font, const char input[], int x, int y, int n);

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;