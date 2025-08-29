#include "globals.h"
#include <iostream>
using namespace std;

char screenBuffer[HEIGHT][WIDTH];

Player player1(0, {10, 10}, true);
Player player2(0, {10, 39}, false);
int totalPoints = 0;