#include <iostream>
#include <windows.h>
#include "../globals/globals.h"
#include "../utils/colors.h"

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
    if (screenBuffer[player1.getPosition().first][player1.getPosition().second] == '*')
    {
        player1.addScorePoint();
    }
    if (screenBuffer[player2.getPosition().first][player2.getPosition().second] == '*')
    {
        player2.addScorePoint();
    }
    // Draw player's new position
    screenBuffer[player1.getPosition().first][player1.getPosition().second] = 'X';

    screenBuffer[player2.getPosition().first][player2.getPosition().second] = 'H';

    // Move cursor to the start of the screen
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    // Draw buffer
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (screenBuffer[i][j] == 'X')
            {
                string s(1, screenBuffer[i][j]);
                cout << ConsoleColor::red(s);
            }
            else if (screenBuffer[i][j] == 'H')
            {
                string s(1, screenBuffer[i][j]);
                cout << ConsoleColor::blue(s);
            }
            else
            {
                cout << screenBuffer[i][j];
            }
            if (j == WIDTH - 1)
            {
                cout << "\n";
            }
        }
    }

    // Controls on screen
    int p1Score = player1.getScore();
    int p2Score = player2.getScore();

    cout << "WASD for moving, Q for exit" << "\n";
    cout << "Player 1 score: " << p1Score << "\n"
         << "Player 2 score: " << p2Score << "\n";
    if (totalPoints / 2 < p1Score || totalPoints / 2 < p2Score)
    {
        if (p1Score == p2Score)
        {
            cout << "This is a Draw\n";
        }
        else
        {
            cout << "The absolute winner is: Player " << (p1Score > p2Score ? "1" : "2") << "!!\n";
        }
    }

    // saving actual position for the next render
    prevPos = player1.getPosition();
    prevPosP2 = player2.getPosition();
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