#include <iostream>
#ifndef GLOBALS_H
#define GLOBALS_H

//constants
#define WIDTH 51  
#define HEIGHT 21

extern char screenBuffer[HEIGHT][WIDTH];
extern std::pair<int, int> player1;
extern int player1Score;
extern int player2Score;
extern int totalPoints;
extern std::pair<int, int> player2;

#endif