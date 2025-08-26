#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

const int WIDTH = 51;
const int HEIGHT = 21;

char screenBuffer[HEIGHT][WIDTH];
pair<int, int> player1;
int player1Score = 0;
int player2Score = 0;
int totalPoints = 0;
pair<int, int> player2;

void initializeBuffer();
void render();
void loop();
void hideCursor();
void showCursor();
void clearScreen();

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
        cout << screenBuffer[i] << endl;
    }

    // Controls on screen
    cout << "WASD for moving, Q for exit" << endl;
    cout << "Player 1 score: " << player1Score << "\n"
         << "Player 2 score: " << player2Score << endl;
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

void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void showCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void clearScreen()
{
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}
