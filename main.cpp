#include <iostream>
#include "rendering/render.h"
#include "globals/globals.h"
#include "utils/utils.h"
#include "loop/loop.h"

using namespace std;

int main()
{
    cin.tie(nullptr);
    hideCursor();
    srand(time(0));
    initializeBuffer();
    loop();
    showCursor();
    return 0;
}
