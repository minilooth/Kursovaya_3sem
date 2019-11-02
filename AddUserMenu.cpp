#include "AddUserMenu.h"

unsigned AddUserMenu::choice_ = AddUserMenuChoice::GIVE_ADMIN_ACCESS;

AddUserMenu::AddUserMenu()
{
	title_ = "Give admin access? ";
	items_ = { "Yes", "No" };
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
			choice_ < AddUserMenuChoice::DONT_GIVE_ADMIN_ACCESS ? choice_ = items_.size() : choice_--;
			break;
		case VK_LEFT:
			choice_ > items_.size() - 1 ? choice_ = AddUserMenuChoice::GIVE_ADMIN_ACCESS : choice_++;
			break;
		case VK_RETURN:
			return choice_;
		default:
			break;
		}

		cout << "\x1b[2K\r";
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
		}
		choice_ == i + 1 ? cout << "->" << items_.at(i) << " " : cout << "  " << items_.at(i) << " ";
		setTextColor(Color::LIGHT_CYAN);
	}
}

AddUserMenu::~AddUserMenu() = default;