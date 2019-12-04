#include "utils.h"

Color c = Red;

enum Tile { Grass, LightGrass, DarkGrass, Water, Fire }; // tile types

// constants
const int numTilesHoriz = 30;
const int numTilesVert = 20;
const double tileW = SCREEN_WIDTH / numTilesHoriz;
const double tileH = SCREEN_HEIGHT / numTilesVert;
const double tileChance = 0.01;
const double emberChance = 0.00001;

// globals
Tile tiles[numTilesHoriz][numTilesVert];
Tile tilesPrevious[numTilesHoriz][numTilesVert];

void resetTiles() {
	for (int i = 0; i < numTilesHoriz; i++) {
		for (int j = 0; j < numTilesVert; j++) {
			if (i >= numTilesHoriz / 2 - 1 && i <= numTilesHoriz / 2 + 1 &&
				j >= numTilesVert / 2 - 1 && j <= numTilesVert / 2 + 1)
				tiles[i][j] = Fire;
			else {
				double r = (double)rand() / RAND_MAX;
				if (r < 0.95)
					tiles[i][j] = Grass;
				else if (r < 0.97)
					tiles[i][j] = LightGrass;
				else
					tiles[i][j] = DarkGrass;
			}
		}
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
	gluOrtho2D(0.0, SCREEN_WIDTH, 0.0, SCREEN_HEIGHT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// initialize tiles
	resetTiles();
}

void drawTile(double left, double bottom) {
	double right = left + tileW;
	double top = bottom + tileH;
	glBegin(GL_POLYGON);
	glVertex2i(left, bottom);
	glVertex2i(right, bottom);
	glVertex2i(right, top);
	glVertex2i(left, top);
	glEnd();
}

void setTileColor(Tile tile) {
	double r = (double)rand() / RAND_MAX;
	switch (tile) {
	case Fire:
		if (r < 0.5)
			setColor(DarkOrange);
		else if (r < 0.6)
			setColor(Orange);
		else
			setColor(Red);
		break;
	case Water:
		glColor3f(0, 0, 1);
		break;
	case Grass:
		setColor(LightGreen);
		break;
	case LightGrass:
		setColor(YellowGreen);
		break;
	case DarkGrass:
		setColor(Green);
		break;
	default:
		glColor3f(0, 0, 0);
		break;
	}
}

void renderTiles(void) {
	for (int i = 0; i < numTilesHoriz; i++) {
		for (int j = 0; j < numTilesVert; j++) {
			setTileColor(tiles[i][j]);
			drawTile(i * tileW, j * tileH);
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
	glColor4f(1, 1, 1, 0.6);
	// vertical lines
	for (int i = 0; i <= numTilesHoriz; i++) {
		drawLine(i * tileW, 0, i * tileW, SCREEN_HEIGHT);
	}
	// horizontal lines
	for (int i = 0; i <= numTilesVert; i++) {
		drawLine(0, i * tileH, SCREEN_WIDTH, i * tileH);
	}
}

void myMouse(int button, int state, int x, int y) {
	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON)
			switch (gameState) {
			case(START_PAGE): gameState = startPageClick(button, x, y); cout << gameState << endl; break;
				case(HOW_TO_PLAY): break;
				case(PLAY_GAME): break;
			}
	}
}

int checkNeighboringTiles(int i, int j, int range) {
	int count = 0;
	for (int k = i - range; k <= i + range; k++) {
		if (k < 0 || k >= numTilesHoriz)
			continue;
		for (int l = j - range; l <= j + range; l++) {
			if (l < 0 || l >= numTilesVert || (i == k && j == l))
				continue;
			if (tilesPrevious[k][l] == Fire) {
				count++;
			}
		}
	}
	return count;
}

void spreadFire() {
	// copy tiles to base fire spreading off previous state
	for (int i = 0; i < numTilesHoriz; i++) {
		for (int j = 0; j < numTilesVert; j++) {
			tilesPrevious[i][j] = tiles[i][j];
		}
	}


	for (int i = 0; i < numTilesHoriz; i++) {
		for (int j = 0; j < numTilesVert; j++) {
			if (tilesPrevious[i][j] == Fire)
				continue;
			int numNeighbors = checkNeighboringTiles(i, j, 1);
			int numNeighborsEmber = checkNeighboringTiles(i, j, 10);
			double chance = tileChance * numNeighbors;
			double chanceEmber = emberChance * numNeighborsEmber;
			double r = (double)rand() / RAND_MAX;
			if (r < chance) {
				tiles[i][j] = Fire;
			}
			r = (double)rand() / RAND_MAX;
			if (r < chanceEmber) {
				tiles[i][j] = Fire;
			}
		}
	}
}
/* Move this into a utility file whenever we have the chance */


void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {
	switch (theKey) {
	case 'f':
		spreadFire();
		glutPostRedisplay();
		break;
	case 'r':
		resetTiles();
		glutPostRedisplay();
	default: break;
	}
	glutPostRedisplay();
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	cout << gameState << endl;
	switch (gameState) {
	case(START_PAGE): renderTiles(); drawGrid(); homeScreen(); glutSwapBuffers(); break;
	case(HOW_TO_PLAY): renderTiles(); drawGrid(); homeScreen(); glutSwapBuffers(); break;
	case(PLAY_GAME): break;
	}
}

void idleEvents(void) {
	switch (gameState) {
		case(START_PAGE): startPageIdle(); break;
		case(HOW_TO_PLAY): break;
		case(PLAY_GAME): break;
	}
}

int main(int argc, char** argv) {
	gameState = 1;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Fire Simulation");

	// register the callback functions
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);
	glutIdleFunc(idleEvents);
	myInit();
	
	glutMainLoop();
}