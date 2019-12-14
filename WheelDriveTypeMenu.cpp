#include "WheelDriveTypeMenu.h"

using namespace menu;

unsigned WheelDriveTypeMenu::choice_ = WheelDriveType::FWD;

WheelDriveTypeMenu::WheelDriveTypeMenu()
{
	title_ = "Тип привода: ";
	items_ = { "Передний", "Задний", "Полный" };
}

WheelDriveTypeMenu::WheelDriveTypeMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void WheelDriveTypeMenu::resetChoice()
{
	WheelDriveTypeMenu::choice_ = WheelDriveType::FWD;
}

ConsoleMenu* WheelDriveTypeMenu::getNextMenu()
{
	return this;
}

unsigned WheelDriveTypeMenu::selectMode()
{
	KEY_EVENT_RECORD key;

	while (true)
	{
		showTitle();
		showItems();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_DOWN :
			if (choice_ > items_.size() - 1)
			{
				choice_ = WheelDriveType::FWD;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_UP :
			if (choice_ < WheelDriveType::RWD)
			{
				choice_ = items_.size();
			}
			else
			{
				choice_--;
			}
			break;
		case VK_ESCAPE : 
			return 0;
		case VK_RETURN :
			return choice_;
		default:
			break;
		}

		title_.empty() ? clearNLines(items_.size()) : clearNLines(items_.size() + 1);
	}
}

void WheelDriveTypeMenu::showTitle()
{
	cout << title_;
	if (title_ != "")
	{
		cout << endl;
	}
}

void WheelDriveTypeMenu::showItems()
{
	for (unsigned i = 0; i < items_.size(); i++)
	{
		if (choice_ == i + 1)
		{
			setTextColor(Color::WHITE);
			cout << "->" << items_.at(i) << endl;
			setTextColor(Color::LIGHT_CYAN);
		}
		else
		{
			cout << "  " << items_.at(i) << endl;
		}
	}
}

WheelDriveTypeMenu::~WheelDriveTypeMenu() = default;