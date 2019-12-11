#pragma once
#include "lib/color.h"

void drawLine(double x1, double y1, double x2, double y2);
void loading(void);
void homeScreen(void);
void howToPage(void);
void aboutPage(void);
void quizPage(int score);
void startPageIdle(void);
void drawLogo(void);
void addOverlay(void);
int startPageClick(int button, int x, int y, int gameState);
void setcolor3ub(Color color);
int quizPageClick(int button, int x, int y, int gameState, int score);
int updateStatus(int gameStatus);
void addQuestionOverlay(void);
void displayQuestion1(void);
void displayQuestion2(void);
void displayQuestion3(void);
void displayQuestion4(void);
void displayQuestion5(void);
void displayQuestion6(void);
void displayQuestion7(void);
