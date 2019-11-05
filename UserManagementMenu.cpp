#include "UserManagementMenu.h"

unsigned UserManagementMenu::choice_ = UserManagementMenuAction::SHOW_USERS;

UserManagementMenu::UserManagementMenu()
{
	title_ = "User management menu:";
	items_ = { "Show users.", "Add user.", "Delete user.", "Edit user.", "Back." };
}

UserManagementMenu::UserManagementMenu(string& title, vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void UserManagementMenu::resetChoice()
{
	choice_ = UserManagementMenuAction::SHOW_USERS;
}

ConsoleMenu* UserManagementMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case UserManagementMenuAction::SHOW_USERS:
		newMenu = new ShowUserMenu();
		break;
	case UserManagementMenuAction::ADD_USER:
		AccountHandler::addUser();
		newMenu = this;
		break;
	case UserManagementMenuAction::DELETE_USER:
		AccountHandler::deleteUser();
		newMenu = this;
		break;
	case UserManagementMenuAction::EDIT_USER:
		AccountHandler::editUser();
		newMenu = this;
		AccountHandler::resetUserToEdit();
		break;
	case UserManagementMenuAction::BACK:
		this->resetChoice();
		newMenu = new AdminMenu();
		break;
	default:
		break;
	}

	return newMenu;
}

unsigned UserManagementMenu::selectMode()
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
			if (choice_ < UserManagementMenuAction::ADD_USER)
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
				choice_ = UserManagementMenuAction::SHOW_USERS;
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

void UserManagementMenu::showTitle()
{
	cout << title_ << endl;
}

void UserManagementMenu::showItems()
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

UserManagementMenu::~UserManagementMenu() = default;
