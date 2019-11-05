#include "AddUserMenu.h"

unsigned AddUserMenu::choice_ = AddUserMenuChoice::GIVE_ADMIN_ACCESS;

AddUserMenu::AddUserMenu()
{
	title_ = "Give admin access? ";
	items_ = { "Yes", "No" };
}

AddUserMenu::AddUserMenu(string& title, vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void AddUserMenu::resetChoice()
{
	AddUserMenu::choice_ = AddUserMenuChoice::GIVE_ADMIN_ACCESS;
}

ConsoleMenu* AddUserMenu::getNextMenu()
{
	return nullptr;
}

unsigned AddUserMenu::selectMode()
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
			if (choice_ < AddUserMenuChoice::DONT_GIVE_ADMIN_ACCESS)
			{
				choice_ = items_.size();
			}
			else
			{
				choice_--;
			}
			break;
		case VK_LEFT:
			if (choice_ > items_.size() - 1)
			{
				choice_ = AddUserMenuChoice::GIVE_ADMIN_ACCESS;
			}
			else
			{
				choice_++;
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

void AddUserMenu::showTitle()
{
	cout << title_;
}

void AddUserMenu::showItems()
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

AddUserMenu::~AddUserMenu() = default;