#ifndef ITEMSELECTION_H
#define ITEMSELECTION_H

#include "AccountHandler.h"

using namespace std;

template<typename T>
class ItemSelection
{
protected:
	string title_;
	vector<T> items_;
	unsigned choice_ = 1;
public:
	ItemSelection();
	ItemSelection(string& title, vector<T>& items);
	ItemSelection(const char* title, vector<T>& items);
	unsigned selectMode();
	void showTitle();
	void showItems();
	~ItemSelection();
};

template<typename T>
ItemSelection<T>::ItemSelection() = default;

template<typename T>
ItemSelection<T>::ItemSelection(string& title, vector<T>& items)
{
	title_ = title;
	items_ = items;
}

template<typename T>
ItemSelection<T>::ItemSelection(const char* title, vector<T>& items)
{
	title_ = title;
	items_ = items;
}

template<typename T>
unsigned ItemSelection<T>::selectMode()
{
	KEY_EVENT_RECORD key;
	while (true)
	{
		system("cls");

		showTitle();

		cout << endl;

		showItems();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_UP:
			choice_ < 2 ? choice_ = items_.size() : choice_--;
			break;
		case VK_DOWN:
			choice_ > items_.size() - 1 ? choice_ = 1 : choice_++;
			break;
		case VK_RETURN:
			return choice_;
		case VK_ESCAPE :
			return 0;
		default:
			break;
		}
	}
}

template<typename T>
void ItemSelection<T>::showTitle()
{
	cout << title_ << endl;
}

template<typename T>
void ItemSelection<T>::showItems()
{
	if (typeid(T) == typeid(UserCredentials))
	{
		unsigned solidLineLength = (AccountHandler::calculateUsernameMaxLength() < 9 ? 8 : AccountHandler::calculateUsernameMaxLength()) +
								   (AccountHandler::calculatePasswordMaxLength() < 9 ? 8 : AccountHandler::calculatePasswordMaxLength()) + 22;

		drawSolidLine(solidLineLength);

		cout << "| " << makeCenteredString("Username", AccountHandler::calculateUsernameMaxLength()) 
			<< " | " << makeCenteredString("Password", AccountHandler::calculatePasswordMaxLength()) 
			<< " | " << "Admin access" << " |" << endl;

		drawSolidLine(solidLineLength);

		for (unsigned i = 0; i < items_.size(); i++)
		{
			if (choice_ == i + 1)
			{
				setTextColor(Color::WHITE);
			}
			choice_ == i + 1 ? cout << items_.at(i) << "<--" << endl : cout << items_.at(i) << endl;
			setTextColor(Color::LIGHT_CYAN);
		}

		drawSolidLine(solidLineLength);
	}
}

template<typename T>
ItemSelection<T>::~ItemSelection() = default;


#endif // ITEMSELECTION_H