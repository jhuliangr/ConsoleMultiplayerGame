#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include "globals/globals.h"
#include "loop/loop.h"
#include "rendering/render.h"
#include "utils/utils.h"

using namespace std;

int main()
{
    hideCursor();
    srand(time(0));
    // Initial position
    player1 = {10, 10};
    player2 = {10, 39};
    initializeBuffer();
    loop();
    showCursor();
    return 0;
}
