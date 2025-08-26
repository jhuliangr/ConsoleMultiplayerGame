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
                if (player1.second > 1)
                    player1.second--;
            }
            if (key == 'd' || key == 'D')
            {
                if (player1.second < WIDTH - 3)
                    player1.second++; // because of the '\0' character for the endline
            }
            if (key == 'w' || key == 'W')
            {
                if (player1.first > 1)
                    player1.first--;
            }
            if (key == 's' || key == 'S')
            {
                if (player1.first < HEIGHT - 2)
                    player1.first++;
            }
            if (key == 'q' || key == 'Q')
            {
                cout << "Bye...\n";
                break;
            }

            // Player 2 sprite
            if (key == 75)
            { // left
                if (player2.second > 1)
                    player2.second--;
            }
            if (key == 77)
            { // right
                if (player2.second < WIDTH - 3)
                    player2.second++; // because of the '\0' character for the endline
            }
            if (key == 72)
            { // up
                if (player2.first > 1)
                    player2.first--;
            }
            if (key == 80)
            { // down
                if (player2.first < HEIGHT - 2)
                    player2.first++;
            }
        }
        render();
        // ~60 FPS
        Sleep(16);
    }
}