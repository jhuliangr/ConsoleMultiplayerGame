#include <iostream>
#include "rendering/render.h"
#include "globals/globals.h"
#include "utils/utils.h"
#include "loop/loop.h"

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
