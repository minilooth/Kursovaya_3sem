#include "AccountTypeMenu.h"

unsigned AccountTypeMenu::choice_ = AccountType::ADMIN;

AccountTypeMenu::AccountTypeMenu()
{
	title_ = "Choose type of account: ";
	items_ = { "Add admin.", "Add user." };
}

AccountTypeMenu::AccountTypeMenu(string& title, vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void AccountTypeMenu::resetChoice()
{
	AccountTypeMenu::choice_ = AccountType::ADMIN;
}

ConsoleMenu* AccountTypeMenu::getNextMenu()
{
	return nullptr;
}

unsigned AccountTypeMenu::selectMode()
{
	KEY_EVENT_RECORD key;

	while (true)
	{
		system("cls");

		showTitle();

		showItems();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_DOWN:
			if (choice_ > items_.size() - 1)
			{
				choice_ = AccountType::ADMIN;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_UP:
			if (choice_ < AccountType::USER)
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
	}
}

void AccountTypeMenu::showTitle()
{
	cout << title_ << endl;
}

void AccountTypeMenu::showItems()
{
	for (unsigned i = 0; i < items_.size(); i++)
	{
		if (choice_ == i + 1)
		{
			setTextColor(Color::WHITE);
			cout << "->" << items_.at(i) << "  " << endl;
			setTextColor(Color::LIGHT_CYAN);
		}
		else
		{
			cout << "  " << items_.at(i) << "  " << endl;
		}
	}
}

AccountTypeMenu::~AccountTypeMenu() = default;