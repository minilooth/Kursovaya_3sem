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

string makeMaskedString(const string &inputString)
{
    string maskedString;
    for (unsigned i = 0; i < inputString.length(); i++)
    {
        maskedString += "•";
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

	if (width % 2 != 0)
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

void maskedPasswordInput(string &password, unsigned limit)
{
	char ch;
	while (true)
	{
		ch = (char)_getch();
		if (ch == VK_RETURN || ch == VK_TAB)
		{
			cout << '\n';
			break;
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
			cout << '•';
		}
	}
}

void limitedInput(string& input, unsigned limit)
{
	char ch;
	while (true)
	{
		ch = (char)_getch();
		if (ch == VK_RETURN || ch == VK_TAB)
		{
			cout << '\n';
			break;
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