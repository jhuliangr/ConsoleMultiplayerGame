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
    initializeBuffer();
    loop();
    showCursor();
    return 0;
}
