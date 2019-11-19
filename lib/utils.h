#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include "startPage.h"

using namespace std;

struct Color {
	GLint r;
	GLint g;
	GLint b;
};

void drawString(void* font, const char input[], int x, int y, int n);
void setColor(Color c);

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;

extern Color White, Blue, Orange, Black, Green, LightGreen, YellowGreen, Red, DarkOrange, Orange, DarkYellow, Yellow;