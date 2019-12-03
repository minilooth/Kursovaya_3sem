#include "AccountEditMenu.h"

unsigned AccountEditMenu::choice_ = AccountEditMenuAction::CHANGE_USERNAME;

AccountEditMenu::AccountEditMenu()
{
	title_ = "Account editing:";
	items_ = { "Edit username.", "Edit password.", "Edit admin access.", "Back." };
}

AccountEditMenu::AccountEditMenu(string& title, vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void AccountEditMenu::resetChoice()
{
	choice_ = AccountEditMenuAction::CHANGE_USERNAME;
}

ConsoleMenu* AccountEditMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case AccountEditMenuAction::CHANGE_USERNAME :
		AccountHandler::editUsername();
		newMenu = this;
		break;
	case AccountEditMenuAction::CHANGE_PASSWORD :
		AccountHandler::editPassword();
		newMenu = this;
		break;
	case AccountEditMenuAction::CHANGE_ADMIN_ACCESS :
		AccountHandler::editAdminAccess();
		newMenu = this;
		break;
	case AccountEditMenuAction::BACK :
		this->resetChoice();
		break;
	default:
		break;
	}

	return newMenu;
}

unsigned AccountEditMenu::selectMode()
{
	KEY_EVENT_RECORD key;
	while (true)
	{
		system("cls");

		AccountHandler::showEditAccount();

		cout << endl;

		showTitle();
		showItems();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_UP :
			if (choice_ < AccountEditMenuAction::CHANGE_PASSWORD)
			{
				choice_ = items_.size();
			}
			else
			{
				choice_--;
			}
			break;
		case VK_DOWN :
			if (choice_ > items_.size() - 1)
			{
				choice_ = AccountEditMenuAction::CHANGE_USERNAME;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_ESCAPE :
			return AccountEditMenuAction::BACK;
		case VK_RETURN :
			return choice_;
		default:
			break;
		}
	}
}

void AccountEditMenu::showTitle()
{
	cout << title_ << endl;
}

void AccountEditMenu::showItems()
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

AccountEditMenu::~AccountEditMenu() = default;