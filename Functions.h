#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>

using namespace std;

namespace Color
{
	enum
	{
		BLACK,
		BLUE,
		GREEN,
		CYAN,
		RED,
		MAGENTA,
		BROWN,
		LIGHT_GRAY,
		DARK_GRAY,
		LIGHT_BLUE,
		LIGHT_GREEN,
		LIGHT_CYAN,
		LIGHT_RED,
		LIGHT_MAGENTA,
		YELLOW,
		WHITE
	};
}

void clearLine();
void moveCursorUpToNLines(int n);
void setTextColor(int textColor);
bool VP_GetCh(KEY_EVENT_RECORD& krec);
void stringSplitter(string source, string& username, string& password, bool& adminRights);
string makeMaskedString(const string &inputString);
string makeSpaceString(unsigned countOfSpaces);
string makeCenteredString(const string& inputString, unsigned width);
void drawSolidLine(unsigned width);
void maskedPasswordInput(string &password, unsigned limit);
void limitedInput(string &input, unsigned limit);


#endif //FUNCTIONS_H