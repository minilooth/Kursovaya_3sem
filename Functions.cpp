#include "Functions.h"


void moveCursorUpToNLines(int n)
{
	string message = "\x1b[" + to_string(n) + "A";

	cout << message;
}

void clearLine()
{
	cout << "\x1b[2K\r";
}

void clearNLines(int n)
{
	for (unsigned i = 0; i < n; i++)
	{
		clearLine();
		moveCursorUpToNLines(1);
	}
}

void setTextColor(int textColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
}

bool VP_GetCh(KEY_EVENT_RECORD& krec)
{
	DWORD cc;
	INPUT_RECORD irec;
	HANDLE h = GetStdHandle(STD_INPUT_HANDLE);

	if (h == NULL)
	{
		return false;
	}

	while (true)
	{
		ReadConsoleInput(h, &irec, 1, &cc);
		if (irec.EventType = KEY_EVENT && ((KEY_EVENT_RECORD&)irec.Event).bKeyDown)
		{
			krec = (KEY_EVENT_RECORD&)irec.Event;
			return true;
		}
	}
	return false;
}


void showConsoleCursor(bool showFlag)
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}


string makeMaskedString(const string &inputString)
{
    string maskedString;
    for (unsigned i = 0; i < inputString.length(); i++)
    {
        maskedString += "�";
    }
    return maskedString;
}

string makeSpaceString(unsigned countOfSpaces)
{
	string spaceString;
	for (unsigned i = 0; i < countOfSpaces; i++)
	{
		spaceString += " ";
	}
	return spaceString;
}

string makeCenteredString(const string& inputString, unsigned width)
{
	string centeredString;
	if (inputString.length() >= width)
	{
		return inputString;
	}

	for (unsigned i = 0; i < (width - inputString.length()) / 2; i++)
	{
		centeredString += " ";
	}

	centeredString += inputString;

	for (unsigned i = 0; i < (width - inputString.length()) / 2; i++)
	{
		centeredString += " ";
	}

	if ((width - inputString.length()) % 2 != 0)
	{
		centeredString += " ";
	}

	return centeredString;
}

void drawSolidLine(unsigned width)
{
	for (unsigned i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << endl;
}

unsigned calculateDoubleLength(double toCalculate, unsigned signsAfterDot)
{
	return (to_string(toCalculate).length() - ((signsAfterDot == 0 ? 7 : 6)  - signsAfterDot));
}

vector<string> stringSplitter(string& source)
{
    size_t pos = 0;
    vector<string> tokenVector;

    while ((pos = source.find(';')) != string::npos)
    {
        tokenVector.push_back(source.substr(0, pos));
        source.erase(0, pos + 1);
    }
    tokenVector.push_back(source);

	return tokenVector;
}

bool maskedPasswordInput(string& password, unsigned limit)
{
	char ch;

	showConsoleCursor(true);

	while (true)
	{
		ch = (char)_getch();
		if (ch == VK_RETURN || ch == VK_TAB)
		{
			cout << '\n';
			showConsoleCursor(false);
			return true;
		}
		else if (ch == VK_ESCAPE)
		{
			password.clear();
			showConsoleCursor(false);
			return false;
		}
		else if (ch == VK_BACK && password.length() > 0)
		{
			password.erase(password.begin() + password.length() - 1);
			cout << "\b \b";
		}
		else if (ch == VK_BACK && password.length() == 0)
		{
			continue;
		}
		else if (password.length() >= limit)
		{
			continue;
		}
		else
		{
			password += ch;
			cout << '�';
		}
	}
}

bool limitedInput(string& input, unsigned limit)
{
	char ch;

	showConsoleCursor(true);

	while (true)
	{
		ch = (char)_getch();
		if (ch == VK_RETURN || ch == VK_TAB)
		{
			cout << '\n';
			showConsoleCursor(false);
			return true;
		}
		else if (ch == VK_ESCAPE)
		{
			input.clear();
			showConsoleCursor(false);
			return false;
		}
		else if (ch == VK_BACK && input.length() > 0)
		{
			input.erase(input.begin() + input.length() - 1);
			cout << "\b \b";
		}
		else if (ch == VK_BACK && input.length() == 0)
		{
			continue;
		}
		else if (input.length() >= limit)
		{
			continue;
		}
		else
		{
			input += ch;
			cout << ch;
		}
	}
}

void setConsoleMaxWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO currentConsoleInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &currentConsoleInfo);

	COORD coord = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));

	SMALL_RECT rect;
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = currentConsoleInfo.srWindow.Bottom;
	rect.Right = coord.X - 1;

	MoveWindow(GetConsoleWindow(), -7, 0, 0, 0, TRUE);
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);
}

template<typename T>
vector<T> dereferenceVectorItems(vector<T*> items)
{
	vector<T> derefencedItems;
	for (unsigned i = 0; i < items.size(); i++)
	{
		derefencedItems.push_back(*items.at(i));
	}
	return;
}