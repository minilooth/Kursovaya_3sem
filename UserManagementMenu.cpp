#include "UserManagementMenu.h"

unsigned UserManagementMenu::choice_ = UserManagementMenuAction::SHOW_USERS;

UserManagementMenu::UserManagementMenu()
{
	title_ = "User management menu:";
	items_ = { "Show users.", "Add user.", "Delete user.", "Edit user.", "Back." };
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
			choice_ < UserManagementMenuAction::ADD_USER ? choice_ = items_.size() : choice_--;
			break;
		case VK_DOWN:
			choice_ > items_.size() - 1 ? choice_ = UserManagementMenuAction::SHOW_USERS : choice_++;
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
		}
		choice_ == i + 1 ? cout << "->" << items_.at(i) << endl : cout << "  " << items_.at(i) << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
}

UserManagementMenu::~UserManagementMenu() = default;
