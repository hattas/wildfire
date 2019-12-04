#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <fstream>
#include "startPage.h"
#include "Wildfire.h"

#define START_PAGE 1
#define HOW_TO_PLAY 2
#define PLAY_GAME 3

using namespace std;
using namespace std::chrono_literals;

struct Color {
	GLint r;
	GLint g;
	GLint b;
};

struct Point {
	int x;
	int y;
};

struct Button {
	Point A;
	Point B;
	Point C;
	Point D;
};

void drawString(void* font, const char input[], int x, int y, int n);
void setColor(Color c);

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;
extern int gameState;

extern Color White, Blue, Orange, Black, Green, LightGreen, YellowGreen, Red, DarkOrange, Orange, DarkYellow, Yellow, Gray;
