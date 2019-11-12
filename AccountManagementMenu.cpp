#include "AccountManagementMenu.h"

unsigned AccountManagementMenu::choice_ = AccountManagementMenuAction::ACCOUNTS_SHOW;

AccountManagementMenu::AccountManagementMenu()
{
	title_ = "Account management menu:";
	items_ = { "Show accounts.", "Add account.", "Delete account.", "Edit account.", "Back." };
}

AccountManagementMenu::AccountManagementMenu(string& title, vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void AccountManagementMenu::resetChoice()
{
	choice_ = AccountManagementMenuAction::ACCOUNTS_SHOW;
}

ConsoleMenu* AccountManagementMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case AccountManagementMenuAction::ACCOUNTS_SHOW:
		newMenu = new AccountShowMenu();
		break;
	case AccountManagementMenuAction::ACCOUNT_ADD:
		AccountHandler::addAccount();
		newMenu = this;
		break;
	case AccountManagementMenuAction::ACCOUNT_DELETE:
		AccountHandler::deleteAccount();
		newMenu = this;
		break;
	case AccountManagementMenuAction::ACCOUNT_EDIT:
		AccountHandler::editAccount();
		newMenu = this;
		AccountHandler::resetAccountToEdit();
		break;
	case AccountManagementMenuAction::BACK:
		this->resetChoice();
		newMenu = new AdminMenu();
		break;
	default:
		break;
	}

	return newMenu;
}

unsigned AccountManagementMenu::selectMode()
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
		case VK_UP:
			if (choice_ < AccountManagementMenuAction::ACCOUNT_ADD)
			{
				choice_ = items_.size();
			}
			else
			{
				choice_--;
			}
			break;
		case VK_DOWN:
			if (choice_ > items_.size() - 1)
			{
				choice_ = AccountManagementMenuAction::ACCOUNTS_SHOW;
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
	}
}

void AccountManagementMenu::showTitle()
{
	cout << title_ << endl;
}

void AccountManagementMenu::showItems()
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

AccountManagementMenu::~AccountManagementMenu() = default;