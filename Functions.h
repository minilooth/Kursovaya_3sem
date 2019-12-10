#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>

using namespace std;


enum Color
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

void clearLine();
void clearNLines(int n);
void moveCursorUpToNLines(int n);
void setTextColor(int textColor);
bool VP_GetCh(KEY_EVENT_RECORD& krec);
vector<string> stringSplitter(string& source);
string makeMaskedString(const string &inputString);
string makeSpaceString(unsigned countOfSpaces);
string makeCenteredString(const string& inputString, unsigned width);
void drawSolidLine(unsigned width);
bool maskedPasswordInput(string &password, unsigned limit);
bool limitedInput(string &input, unsigned limit);
unsigned calculateDoubleLength(double toCalculate, unsigned signsAfterDot);
void showConsoleCursor(bool showFlag);
void setConsoleMaxWidth();

template<typename T>
vector<T> derefenceVectorItems(vector<T*> items);


#endif //FUNCTIONS_H
