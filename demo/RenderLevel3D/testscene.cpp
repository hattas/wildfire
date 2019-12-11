#include "SDL_arch.h"
#include "camera.h"
#include <conio.h>
#include "RGBpixmap.h"
#include <windows.h>
#include "glut.h"
#include <iostream>
#include "lib/tile.h"
#include "lib/level.h"
#include "lib/point.h"
#include "lib/color.h"
#include "camera.h"
#include "utils.h"
#include "startPage.h"

/********************************GLOBALS*************************************/
using namespace std;

void homeDisplay(void);
void myDisplay();

Color c = Color::red;
int gameState = 1; 
int score = 0;
int ticks = 0; //for animating the start screen
int home; //for storing the start screen window
int game; //for storing the game screen
int view = 0; //for tracking camera view

// constants
const int numTilesHoriz = 30;
const int numTilesVert = 20;
const double tileW = SCREEN_WIDTH / numTilesHoriz;
const double tileH = SCREEN_HEIGHT / numTilesVert;
const double tileChance = 0.01;
const double emberChance = 0.00001;
const float TILE_W = 1;
const float TILE_H = 1;
const float GRID_W = 0;
const int maxofEachItem = 2;
const float light_amb[] = { 0.5, 0.5, 0.5, 1.0 };
const float light_dif[] = { 0.25, 0.25, 0.25, 1.0 };
const float light_pos[] = { 30, 10, -40, 1.0 };
float ex, ey, ez, lx, ly, lz, upx, upy, upz;

// global type arrays for start screen
TileType tiles[numTilesHoriz][numTilesVert];
TileType tilesPrevious[numTilesHoriz][numTilesVert];

//global level for game play
Level level(numTilesHoriz, numTilesVert);

//global camera
Camera camera;

float R = SCREEN_WIDTH / SCREEN_HEIGHT;  // Global Aspect Ratio
int l = 0;
int r = 200;
int bottom = 0;
int top = 200;
int change = 200;

float globalMouseX, globalMouseY, globalMouseZ;

struct gamePiece {
	float x;
	float y;
	float z;
};

enum Select {
	none,
	truck,
	chopper,
	boat
};

Select selectedPiece;
int selectedIndex = 0;

Scene truckScene[maxofEachItem];
Scene chopperScene[maxofEachItem];
Scene boatScene[maxofEachItem];

//arrays of game pieces. 
gamePiece TruckPieces[maxofEachItem];
gamePiece ChopperPieces[maxofEachItem];
gamePiece BoatPieces[maxofEachItem];

int truckCount = maxofEachItem;
int chopperCount = maxofEachItem;
int boatCount = maxofEachItem;

/**************************  ADDING FROM 2D code  ***************************/
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

Render render;
Unit newUnit;
Point newDirection = { 1, 0 };
State moveState = getMoveType;

/**********************************Function Library ***********************************/
void resetTiles() {
	for (int i = 0; i < numTilesHoriz; i++) {
		for (int j = 0; j < numTilesVert; j++) {
			if (i >= numTilesHoriz / 2 - 1 && i <= numTilesHoriz / 2 + 1 &&
				j >= numTilesVert / 2 - 1 && j <= numTilesVert / 2 + 1)
				tiles[i][j] = TileType::fire;
			else {
				double r = (double)rand() / RAND_MAX;
				if (r < 0.95)
					tiles[i][j] = TileType::grass;
			}
			
		}
	}
}

void idleEvents(void) {
	//cout << ticks << endl;
	if (ticks % 200 == 0) { 
		resetTiles(); 
	}
	switch (gameState) {
	case(START_PAGE): startPageIdle(); ticks++; break;
	case(HOW_TO_PLAY): startPageIdle(); ticks++; break;
	case(ABOUT): startPageIdle(); ticks++; break;
	case(PLAY_GAME): break;
	}
}

void initLevel() {

	for (int i = 0; i < numTilesHoriz; i++) {
		for (int j = 0; j < numTilesVert; j++) {
			if (i > 13 && i < 17 && j > 8 && j < 12)
				level.tiles[i][j].tileType = TileType::fire;
			else
				level.tiles[i][j].tileType = TileType::grass;
		}
	}

}

void setColor(Color color) {
	int hex = (int)color;
	double r = ((hex >> 16) & 0xff) / 255.0;
	double g = ((hex >> 8) & 0xff) / 255.0;
	double b = (hex & 0xff) / 255.0;
	float amb[] = { r, g, b, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
	glColor3f(r, g, b); //for 2D rendering
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

void drawTile(float i, float j, Color color) {
	float x = i * (TILE_W + GRID_W);
	float z = j * (TILE_W + GRID_W);
	float y = 0;
	setColor(color);
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(TILE_W, TILE_H, TILE_W);
	glutSolidCube(1);
	glPopMatrix();
}

void renderTiles(Level level) {
	Color color;
	for (int i = 0; i < numTilesHoriz; i++) {
		for (int j = 0; j < numTilesVert; j++) {
			color = tileTypeToColor(level.tiles[i][j].tileType);
			drawTile(i, j, color);
		}
	}
}

void setViewport(int left, int right, int bottom, int top)
{
	glViewport(left, bottom, right - left, top - bottom);
}

void doLighting() {
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_dif);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glEnable(GL_LIGHT0);
}

Point getTileIndexFromWorldCoordinates(GLdouble mouseX, GLdouble mouseY, GLdouble mouseZ) {
	Point index;

	index.x = (mouseX + 15);
	index.y = (mouseZ + 15);

	return index;
}

//*****************************************************************************
void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {
	switch (theKey) {
	//Changing camera angles
	case 't': //toggle
		view = (view + 1) % 4;
		if (view == 0) { //default
			camera.set(0, 50, 30, 0, 0, 0, 0, 1, 0);
			
		}
		else if (view == 1) { //left looking right
			camera.set(-50, 10, 0, 0, 0, 0, 0, 1, 0);
		}
		else if (view == 2) { //right looking left
			camera.set(50, 10, 0, 0, 0, 0, 0, 1, 0);
		}
		else if (view == 3) { //front
			camera.set(0, 20, 30, 0, 0, 0, 0, 1, 0);
		}
		break;
	//advancing fire spreading: null turn
	case 'f':
		level.spreadFire();
		level.spreadWater();
		break;
	default: 
		break;
	}
	glutPostRedisplay();
}

/*Right Click used to select objects.  Left clicks used to move objects*/
void myMouse(int button, int state, int x, int y) {
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	//assign global mouse positions
	globalMouseX = posX;
	globalMouseY = posY;
	globalMouseZ = posZ;	

	//check for click actions
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) { //if user is selecting an item
		
		Point index = getTileIndexFromWorldCoordinates(posX, posY, posZ); //get the index of the mouse

		//update grid units
		//need to be able to change index as well as type...
		for (int u = 0; u < level.numUnits; u++) {
			if (level.units[u].position == index) {
				level.removeUnitAtIndex(u);
			}
		}

		double clickTolerance = 1;
	
		for (int i = 0; i <= truckCount; i++) {
			if ( //click touching a truck
				((TruckPieces[i].x > posX - clickTolerance) && (TruckPieces[i].x < posX + clickTolerance))
				&&
				((TruckPieces[i].y > posY - clickTolerance) && (TruckPieces[i].y < posY + clickTolerance))
				) {
				selectedPiece = truck;
				selectedIndex = i;
			}
		}
		for (int i = 0; i <= boatCount; i++) {
			if ( //click touching a boat
				((BoatPieces[i].x > posX - clickTolerance) && (BoatPieces[i].x < posX + clickTolerance))
				&&
				((BoatPieces[i].y > posY - clickTolerance) && (BoatPieces[i].y < posY + clickTolerance))
				) {
				selectedPiece = boat;
				selectedIndex = i;
			}
		}
		for (int i = 0; i <= chopperCount; i++) {
			if ( //click touching the truck
				((ChopperPieces[i].x > posX - clickTolerance) && (ChopperPieces[i].x < posX + clickTolerance))
				&&
				((ChopperPieces[i].y > posY - clickTolerance) && (ChopperPieces[i].y < posY + clickTolerance))
				) {
				selectedPiece = chopper;
				selectedIndex = i;
			}
		}
		

	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { //if user is moving an item

		//translate the object to that space
		switch (selectedPiece) {
		case none:
			break;
		case truck:
			TruckPieces[selectedIndex].x = (double)posX;
			TruckPieces[selectedIndex].y = (double)posY;
			TruckPieces[selectedIndex].z = (double)posZ;
			newUnit.type = UnitType::truck;
			break;
		case chopper:
			ChopperPieces[selectedIndex].x = (double)posX;
			ChopperPieces[selectedIndex].y = (double)posY;
			ChopperPieces[selectedIndex].z = (double)posZ;
			newUnit.type = UnitType::heli;
			break;
		case boat:
			BoatPieces[selectedIndex].x = (double)posX;
			BoatPieces[selectedIndex].y = (double)posY;
			BoatPieces[selectedIndex].z = (double)posZ;
			newUnit.type = UnitType::boat;
			break;
		default:
			break;
		}
		
		if (selectedPiece != none) { //if a piece was just selected
			//update grid unit
			Point index = getTileIndexFromWorldCoordinates(posX, posY, posZ); //get the index of the mouse
			newUnit.position = index;
			level.placeUnit(newUnit);
			level.spreadWater();
			level.spreadFire();
		}
		
		//redraw and reset selection
		glutPostRedisplay();
		selectedPiece = none;
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
			if (tilesPrevious[k][l] == TileType::fire) {
				count++;
			}
		}
	}
	return count;
}

void initGame() {
	//create new window
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(200, 200);
	game = glutCreateWindow("Wild and Smokey: Game");

	//register callback functions
	glutKeyboardFunc(myKeyboard);
	glutMouseFunc(myMouse);
	glutDisplayFunc(myDisplay);

	//set up 3D properties and scene
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	doLighting();

	//generate new level
	initLevel();

	//Viewport and camera initialization
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	camera.set(0, 50, 30, 0, 0, 0, 0, 1, 0); 
	camera.setShape(35.0f, 64.0f / 48.0f, 0.5f, 140.0f);// added for camera use

	//start with all unselected
	selectedPiece = none;

	float unitBar = -10;
	/*Draw any active trucks*/
	for (int i = 0; i < maxofEachItem; i++) {
		truckScene[i].read("truck.txt");
		TruckPieces[i].x = unitBar;
		TruckPieces[i].y = 20;
		TruckPieces[i].z = 0;
		unitBar += 5;
	}

	/*Draw any active helicopters*/
	for (int i = 0; i < maxofEachItem; i++) {
		chopperScene[i].read("chopper.txt");
		ChopperPieces[i].x = unitBar;
		ChopperPieces[i].y = 20;
		ChopperPieces[i].z = 0;
		unitBar += 5;
	}

	/*Draw any cative boats*/
	for (int i = 0; i < maxofEachItem; i++) {
		boatScene[i].read("boat.txt");
		BoatPieces[i].x = unitBar;
		BoatPieces[i].y = 20;
		BoatPieces[i].z = 0;
		unitBar += 5;
	}

	//set up single light
	chopperScene[1].makeLightsOpenGL();
	truckScene[1].makeLightsOpenGL();


	double winHt = 1.0;

}

/***********************************HOME FUNCTIONS**********************************/
void drawHomeTile(double left, double bottom, Color color) {
	double right = left + tileW;
	double top = bottom + tileH;
	setColor(color);
	glBegin(GL_POLYGON);
	glVertex2i(left, bottom);
	glVertex2i(right, bottom);
	glVertex2i(right, top);
	glVertex2i(left, top);
	glEnd();
}

void renderHomeTiles(void) {
	Color color;
	for (int i = 0; i < numTilesHoriz; i++) {
		for (int j = 0; j < numTilesVert; j++) {
			color = tileTypeToColor(tiles[i][j]);
			drawHomeTile(i * tileW, j * tileH, color);
		}
	}
}

void spreadFireHome() {
	// copy tiles to base fire spreading off previous state
	for (int i = 0; i < numTilesHoriz; i++) {
		for (int j = 0; j < numTilesVert; j++) {
			tilesPrevious[i][j] = tiles[i][j];
		}
	}


	for (int i = 0; i < numTilesHoriz; i++) {
		for (int j = 0; j < numTilesVert; j++) {
			if (tilesPrevious[i][j] == TileType::fire)
				continue;
			int numNeighbors = checkNeighboringTiles(i, j, 1);
			int numNeighborsEmber = checkNeighboringTiles(i, j, 10);
			double chance = tileChance * numNeighbors;
			double chanceEmber = emberChance * numNeighborsEmber;
			double r = (double)rand() / RAND_MAX;
			if (r < chance) {
				tiles[i][j] = TileType::fire;
			}
			r = (double)rand() / RAND_MAX;
			if (r < chanceEmber) {
				tiles[i][j] = TileType::fire;
			}
		}
	}
}

void homeKeyboard(unsigned char theKey, int mouseX, int mouseY) {
	switch (theKey) {
	case 'f':
		spreadFireHome();
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void initHome(void) {
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
	renderHomeTiles();
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

void homeDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	switch (gameState) {
	case(START_PAGE):
		renderHomeTiles();
		drawGrid();
		homeScreen();
		break;
	case(HOW_TO_PLAY):
		renderHomeTiles();
		drawGrid();
		howToPage();
		break;
	case(ABOUT):
		renderHomeTiles();
		drawGrid();
		aboutPage();
		break;
	case(QUIZ):
		renderHomeTiles();
		drawGrid();
		quizPage(score);
		break;
	case(PLAY_GAME):
		//call all the game init functions to make new window and game board
		//insert "loading..." into button to tell user it is working on starting the game
		renderHomeTiles();
		drawGrid();
		loading();
		glutSwapBuffers();
		initGame();
		myDisplay();
		glutDestroyWindow(home);
		break;
	case(QUIZ_1):
		score = 0;
		renderHomeTiles();
		drawGrid();
		displayQuestion1();
		break;
	case(QUIZ_2):
		renderHomeTiles();
		drawGrid();
		displayQuestion2();
		break;
	case(QUIZ_3):
		renderHomeTiles();
		drawGrid();
		displayQuestion3();
		break;
	case(QUIZ_4):
		renderHomeTiles();
		drawGrid();
		displayQuestion4();
		break;
	case(QUIZ_5):
		renderHomeTiles();
		drawGrid();
		displayQuestion5();
		break;
	case(QUIZ_6):
		renderHomeTiles();
		drawGrid();
		displayQuestion6();
		break;
	case(QUIZ_7):
		renderHomeTiles();
		drawGrid();
		displayQuestion7();
		break;
	}
	glutSwapBuffers();
}

void homeMouse(int button, int state, int x, int y) {
	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON)
			switch (gameState) {
			case(START_PAGE): gameState = startPageClick(button, x, y, gameState); cout << gameState << endl; break;
			case(HOW_TO_PLAY): gameState = startPageClick(button, x, y, gameState); cout << gameState << endl; break;
			case(ABOUT): gameState = startPageClick(button, x, y, gameState); cout << gameState << endl; break;
			case(QUIZ): gameState = startPageClick(button, x, y, gameState); cout << gameState << endl; break;
			case(QUIZ_1): score = quizPageClick(button, x, y, gameState, score); gameState = updateStatus(gameState); cout << score << endl;  break;
			case(QUIZ_2): score = quizPageClick(button, x, y, gameState, score); gameState = updateStatus(gameState); cout << score << endl; break;
			case(QUIZ_3): score = quizPageClick(button, x, y, gameState, score); gameState = updateStatus(gameState); cout << score << endl; break;
			case(QUIZ_4): score = quizPageClick(button, x, y, gameState, score); gameState = updateStatus(gameState); cout << score << endl; break;
			case(QUIZ_5): score = quizPageClick(button, x, y, gameState, score); gameState = updateStatus(gameState); cout << score << endl; break;
			case(QUIZ_6): score = quizPageClick(button, x, y, gameState, score); gameState = updateStatus(gameState); cout << score << endl; break;
			case(QUIZ_7): score = quizPageClick(button, x, y, gameState, score); gameState = updateStatus(gameState); cout << score << endl; break;
			case(PLAY_GAME): break;
			}
		cout << gameState << endl;
		homeDisplay();
	}
}

void myDisplay()
{
	//if the game is over, close the window and reopen menu
	if (level.isGameLost()) {
		gameState = START_PAGE;
		glutDestroyWindow(game);
		glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
		glutInitWindowPosition(200, 200);
		home = glutCreateWindow("Wild and Smokey: Menu");
		glutDisplayFunc(homeDisplay);
		glutMouseFunc(homeMouse);
		glutKeyboardFunc(homeKeyboard);
		glutIdleFunc(idleEvents);
		initHome();

	}//if the user won, clear the screen..?
	else if (level.isGameWon()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	}
	else {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//draw the level grid
		glPushMatrix();
		glTranslated(-15, -1, -15);
		renderTiles(level);
		glPopMatrix();

		/*Draw any active trucks*/
		for (int i = 0; i < truckCount; i++) {
			glPushMatrix();
			glTranslated(TruckPieces[i].x, TruckPieces[i].y, TruckPieces[i].z);
			truckScene[i].drawSceneOpenGL();
			glPopMatrix();
		}

		/*Draw any active helicopters*/
		for (int i = 0; i < chopperCount; i++) {
			glPushMatrix();
			glTranslated(ChopperPieces[i].x, ChopperPieces[i].y, ChopperPieces[i].z);
			chopperScene[i].drawSceneOpenGL();
			glPopMatrix();
		}

		/*Draw any cative boats*/
		for (int i = 0; i < boatCount; i++) {
			glPushMatrix();
			glTranslated(BoatPieces[i].x, BoatPieces[i].y, BoatPieces[i].z);
			boatScene[i].drawSceneOpenGL();
			glPopMatrix();
		}

		glFlush();
		glutSwapBuffers();
	}
}

//*****************************************************************************
void main( int argc, char** argv )
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(200, 200);
	home = glutCreateWindow("Wild and Smokey: Menu");

	// register the callback functions
	glutDisplayFunc(homeDisplay);
	glutMouseFunc(homeMouse);
	glutKeyboardFunc(homeKeyboard);
	glutIdleFunc(idleEvents);
	initHome();
	glutMainLoop();

}





