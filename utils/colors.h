#ifndef COLORS_H
#define COLORS_H

#include <string>
using namespace std;

class ConsoleColor
{
private:
    static const string ESC;
    static const string RESET;

public:
    static string color(const string &text, int colorCode);
    static string color(const char &text, int colorCode);
    static string red(const string &text);
    static string green(const string &text);
    static string yellow(const string &text);
    static string blue(const string &text);
    static string magenta(const string &text);
    static string cyan(const string &text);
    static string bold(const string &text);
    static string underline(const string &text);
    static string red(const char &character);
    static string green(const char &character);
    static string yellow(const char &character);
    static string blue(const char &character);
    static string magenta(const char &character);
    static string cyan(const char &character);
    static string bold(const char &character);
    static string underline(const char &character);
};

#endif