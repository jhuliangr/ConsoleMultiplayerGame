#include "globals.h"
#include <iostream>
using namespace std;

char screenBuffer[HEIGHT][WIDTH];

Player player1(0, {10, 10}, true); // true for WASD mapping
Player player2(0, {10, 39}, false); // false for arrow keys mapping
int totalPoints = 0;