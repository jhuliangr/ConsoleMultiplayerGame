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

            // Player one sprite
            if (key == 'a' || key == 'A')
            {
                player1.move(Direction::LEFT);
            }
            if (key == 'd' || key == 'D')
            {
                player1.move(Direction::RIGHT);
            }
            if (key == 'w' || key == 'W')
            {
                player1.move(Direction::UP);
            }
            if (key == 's' || key == 'S')
            {
                player1.move(Direction::DOWN);
            }

            if (key == 'q' || key == 'Q')
            {
                cout << "Bye...\n";
                break;
            }

            // Player 2 sprite
            if (key == 75)
            { // left
                player2.move(Direction::LEFT);
            }
            if (key == 77)
            { // right

                player2.move(Direction::RIGHT);
            }
            if (key == 72)
            { // up

                player2.move(Direction::UP);
            }
            if (key == 80)
            { // down
                player2.move(Direction::DOWN);
            }
        }
        render();
        // ~60 FPS
        Sleep(16);
    }
}