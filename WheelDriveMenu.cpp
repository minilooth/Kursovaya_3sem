#include "WheelDriveMenu.h"

unsigned WheelDriveMenu::choice_ = WheelDrive::FWD;

WheelDriveMenu::WheelDriveMenu()
{
	title_ = "Wheel drive: ";
	items_ = { "FWD", "RWD", "AWD" };
}

WheelDriveMenu::WheelDriveMenu(string& title, vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void WheelDriveMenu::resetChoice()
{
	WheelDriveMenu::choice_ = WheelDrive::FWD;
}

ConsoleMenu* WheelDriveMenu::getNextMenu()
{
	return this;
}

unsigned WheelDriveMenu::selectMode()
{
	KEY_EVENT_RECORD key;

	while (true)
	{
		showTitle();

		showItems();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_RIGHT:
			if (choice_ > items_.size() - 1)
			{
				choice_ = WheelDrive::FWD;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_LEFT:
			if (choice_ < WheelDrive::RWD)
			{
				choice_ = items_.size();
			}
			else
			{
				choice_--;
			}
			break;
		case VK_RETURN:
			return choice_;
		default:
			break;
		}

		clearLine();
	}
}

void WheelDriveMenu::showTitle()
{
	cout << title_;
}

void WheelDriveMenu::showItems()
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

WheelDriveMenu::~WheelDriveMenu() = default;