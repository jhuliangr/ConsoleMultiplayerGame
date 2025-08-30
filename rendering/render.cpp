#include <iostream>
#include <windows.h>
#include "../globals/globals.h"
#include "../utils/colors.h"

using namespace std;

void moveCursor(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void render()
{
    // Previous positions
    static pair<int, int> prevPos = {-1, -1};
    static pair<int, int> prevPosP2 = {-1, -1};

    if (prevPos != player1.getPosition())
    {
        moveCursor(prevPos.second, prevPos.first);
        cout << '.';
    }
    if (prevPosP2 != player2.getPosition())
    {
        moveCursor(prevPosP2.second, prevPosP2.first);
        cout << '.';
    }

    // Check for collisions with points
    if (screenBuffer[player1.getPosition().first][player1.getPosition().second] == '*')
    {
        player1.addScorePoint();
        screenBuffer[player1.getPosition().first][player1.getPosition().second] = '.';
    }
    if (screenBuffer[player2.getPosition().first][player2.getPosition().second] == '*')
    {
        player2.addScorePoint();
        screenBuffer[player2.getPosition().first][player2.getPosition().second] = '.';
    }

    // Print new positions
    moveCursor(player1.getPosition().second, player1.getPosition().first);
    cout << ConsoleColor::red("X");

    moveCursor(player2.getPosition().second, player2.getPosition().first);
    cout << ConsoleColor::blue("H");

    // Saving actual positions
    prevPos = player1.getPosition();
    prevPosP2 = player2.getPosition();

    // Update scoreboard 
    int p1Score = player1.getScore();
    int p2Score = player2.getScore();

    int hudLine = HEIGHT + 1; // line after the game area
    moveCursor(0, hudLine);
    cout << "WASD for moving, Q for exit";

    moveCursor(0, hudLine + 1);
    cout << ConsoleColor::red("Player 1 score: ") << p1Score;

    moveCursor(0, hudLine + 2);
    cout << ConsoleColor::cyan("Player 2 score: ") << p2Score;

    moveCursor(0, hudLine + 3);
    if (totalPoints / 2 < p1Score || totalPoints / 2 < p2Score)
    {
        if (p1Score == p2Score)
        {
            cout << "This is a Draw   ";
        }
        else
        {
            cout << "The absolute winner is: Player " << (p1Score > p2Score ? ConsoleColor::red("1") : ConsoleColor::cyan("2")) << "!!   ";
        }
    }
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
        screenBuffer[i][WIDTH - 1] = '\0';
    }

    // Prints the initial buffer
    moveCursor(0, 0);
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            cout << screenBuffer[i][j];
        }
        cout << "\n";
    }
}