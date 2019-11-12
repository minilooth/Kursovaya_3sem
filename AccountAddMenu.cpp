#include "AccountAddMenu.h"

unsigned AccountAddMenu::choice_ = AccountAddMenuChoice::GIVE_ADMIN_ACCESS;

AccountAddMenu::AccountAddMenu()
{
	title_ = "Give admin access? ";
	items_ = { "Yes", "No" };
}

AccountAddMenu::AccountAddMenu(string& title, vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void AccountAddMenu::resetChoice()
{
	AccountAddMenu::choice_ = AccountAddMenuChoice::GIVE_ADMIN_ACCESS;
}

ConsoleMenu* AccountAddMenu::getNextMenu()
{
	return nullptr;
}

unsigned AccountAddMenu::selectMode()
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
			if (choice_ < AccountAddMenuChoice::DONT_GIVE_ADMIN_ACCESS)
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
				choice_ = AccountAddMenuChoice::GIVE_ADMIN_ACCESS;
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

void AccountAddMenu::showTitle()
{
	cout << title_;
}

void AccountAddMenu::showItems()
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

AccountAddMenu::~AccountAddMenu() = default;