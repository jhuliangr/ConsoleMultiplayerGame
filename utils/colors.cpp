#include "colors.h"
#include <string>
using namespace std;

const string ConsoleColor::ESC = "\033[";
const string ConsoleColor::RESET = "\033[0m";

string ConsoleColor::color(const string &text, int colorCode)
{
    return ESC + to_string(colorCode) + "m" + text + RESET;
}
string ConsoleColor::color(const char &character, int colorCode)
{
    return ESC + to_string(colorCode) + "m" + character + RESET;
}

string ConsoleColor::red(const string &text) { return color(text, 31); }
string ConsoleColor::green(const string &text) { return color(text, 32); }
string ConsoleColor::yellow(const string &text) { return color(text, 33); }
string ConsoleColor::blue(const string &text) { return color(text, 34); }
string ConsoleColor::magenta(const string &text) { return color(text, 35); }
string ConsoleColor::cyan(const string &text) { return color(text, 36); }

string ConsoleColor::bold(const string &text) { return ESC + "1m" + text + RESET; }
string ConsoleColor::underline(const string &text) { return ESC + "4m" + text + RESET; }

string ConsoleColor::red(const char &character) { return color(character, 31); }
string ConsoleColor::green(const char &character) { return color(character, 32); }
string ConsoleColor::yellow(const char &character) { return color(character, 33); }
string ConsoleColor::blue(const char &character) { return color(character, 34); }
string ConsoleColor::magenta(const char &character) { return color(character, 35); }
string ConsoleColor::cyan(const char &character) { return color(character, 36); }

string ConsoleColor::bold(const char &character) { return ESC + "1m" + character + RESET; }
string ConsoleColor::underline(const char &character) { return ESC + "4m" + character + RESET; }