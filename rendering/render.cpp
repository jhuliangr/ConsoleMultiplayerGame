#include <iostream>
#include <windows.h>
#include "../globals/globals.h"

using namespace std;



void render()
{
    // Actual player1 position
    static pair<int, int> prevPos = {-1, -1};

    // Actual player2 position
    static pair<int, int> prevPosP2 = {-1, -1};

    // Restore previous position
    if (prevPos.first != -1 && prevPos.second != -1)
    {
        screenBuffer[prevPos.first][prevPos.second] = '.';
    }
    if (prevPosP2.first != -1 && prevPosP2.second != -1)
    {
        screenBuffer[prevPosP2.first][prevPosP2.second] = '.';
    }

    // check if player gets a point
    if (screenBuffer[player1.first][player1.second] == '*')
    {
        player1Score++;
    }
    if (screenBuffer[player2.first][player2.second] == '*')
    {
        player2Score++;
    }
    // Draw player's new position
    screenBuffer[player1.first][player1.second] = 'X';

    screenBuffer[player2.first][player2.second] = 'H';

    // Move cursor to the start of the screen
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    // Draw buffer
    for (int i = 0; i < HEIGHT; i++)
    {
        cout << screenBuffer[i] << "\n";
    }

    // Controls on screen
    cout << "WASD for moving, Q for exit" << "\n";
    cout << "Player 1 score: " << player1Score << "\n"
         << "Player 2 score: " << player2Score << "\n";
    if (totalPoints/2 < player1Score || totalPoints/2 < player2Score)
    {
        if (player1Score == player2Score)
        {
            cout << "This is a Draw\n";
        }
        else
        {
            cout << "The absolute winner is: Player " << (player1Score > player2Score ? "1" : "2") << "!!\n";
        }
    }

    // saving actual position for the next render
    prevPos = player1;
    prevPosP2 = player2;
}

void initializeBuffer()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if ((i == 0 && j == 0) || (i == HEIGHT - 1 && j == 0) || (i == 0 && j == WIDTH - 2) || (i == HEIGHT - 1 && j == WIDTH - 2))
            {
                screenBuffer[i][j] = 'O';
                continue;
            }

            if (i == 0 || i == HEIGHT - 1)
            {
                screenBuffer[i][j] = '-';
                continue;
            }
            if (j == 0 || j == WIDTH - 2)
            {
                screenBuffer[i][j] = '|';
                continue;
            }
            int mark = rand() % 20 + 1; // number between 1 and 20
            if (mark == 7 && j < WIDTH - 2 && (i != 10 && j != 10) && (i != 10 && j != 39))
            {
                screenBuffer[i][j] = '*';
                totalPoints++;
            }
            else
            {
                screenBuffer[i][j] = '.';
            }
        }
        screenBuffer[i][WIDTH - 1] = '\0'; // endline
    }
}