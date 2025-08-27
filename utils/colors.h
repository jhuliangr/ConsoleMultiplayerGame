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
    static string red(const string &text);
    static string green(const string &text);
    static string yellow(const string &text);
    static string blue(const string &text);
    static string magenta(const string &text);
    static string cyan(const string &text);
    static string bold(const string &text);
    static string underline(const string &text);
};

#endif