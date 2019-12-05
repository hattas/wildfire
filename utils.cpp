#include "utils.h"
Color White = { {255}, {255}, {255} };
Color Blue = { {56}, {96}, {255} };
Color Black = { {0}, {0}, {0} };
Color Green = { {76}, {175}, {80} };
Color LightGreen = { {139}, {195}, {74} };
Color YellowGreen = { {205}, {220}, {57} };
Color Red = { {244}, {67}, {54} };
Color DarkOrange = { {255}, {87}, {34} };
Color Orange = { {255}, {152}, {0} };
Color DarkYellow = { {255}, {193}, {7} };
Color Yellow = { {255}, {235}, {59} };
Color Gray = { {158}, {151}, {150} };

void drawString(void* font, const char input[], int x, int y, int n) {
	int i;
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glRasterPos2i(x, y);
	for (i = 0; i < n; i++) {
		glutBitmapCharacter(font, input[i]);
	}
}

void setColor(Color c) {
	glColor3ub(c.r, c.g, c.b);
}

void drawStrokeText(char* string, int x, int y, int z, Color color)
{
	glColor3ub(color.r, color.g, color.b);
	char* c;
	glPushMatrix();
	glTranslatef(x, y + 8, z);
	glScalef(1.0f, 1.0f, z);

	for (c = string; *c != NULL; c++)
	{
		glutStrokeCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
	glPopMatrix();
}