#include "WheelDriveTypeMenu.h"

unsigned WheelDriveTypeMenu::choice_ = WheelDriveType::FWD;

WheelDriveTypeMenu::WheelDriveTypeMenu()
{
	title_ = "Wheel drive type: ";
	items_ = { "FWD", "RWD", "AWD" };
}

WheelDriveTypeMenu::WheelDriveTypeMenu(string& title, vector<string>& items)
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
		case VK_RIGHT :
			if (choice_ > items_.size() - 1)
			{
				choice_ = WheelDriveType::FWD;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_LEFT :
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

		clearLine();
	}
}

void WheelDriveTypeMenu::showTitle()
{
	cout << title_;
}

void WheelDriveTypeMenu::showItems()
{
	for (unsigned i = 0; i < items_.size(); i++)
	{
		if (choice_ == i + 1)
		{
			setTextColor(Color::WHITE);
			cout << "->" << items_.at(i) << "  ";
			setTextColor(Color::LIGHT_CYAN);
		}
		else
		{
			cout << "  " << items_.at(i) << "  ";
		}
	}
}

WheelDriveTypeMenu::~WheelDriveTypeMenu() = default;