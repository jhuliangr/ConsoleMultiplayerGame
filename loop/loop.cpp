#include <conio.h>
#include <iostream>
#include <windows.h>
#include "../globals/globals.h"
#include "../rendering/render.h"
using namespace std;

void loop()
{
    while (true)
    {
        // input processing
        if (_kbhit())
        {
            char key = _getch();
            player1.controlMapping(key);
            player2.controlMapping(key);

            if (key == 'q' || key == 'Q')
            {
                cout << "Bye...\n";
                break;
            }
        }
        render();
        // ~60 FPS
        Sleep(16);
    }
}