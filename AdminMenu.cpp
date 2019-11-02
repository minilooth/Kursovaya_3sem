#include "AdminMenu.h"

unsigned AdminMenu::choice_ = AdminMenuAction::SHOW_USERS;

AdminMenu::AdminMenu()
{
    title_ = "Admin main menu:";
    items_ = { "Show users.", "Add user.", "Delete user.", "Edit user.", "Back." };
}

void AdminMenu::resetChoice()
{
    choice_ = AdminMenuAction::SHOW_USERS;
}

ConsoleMenu* AdminMenu::getNextMenu()
{
    ConsoleMenu* newMenu = nullptr;

    switch (selectMode())
    {
		case AdminMenuAction::SHOW_USERS :
            newMenu = new ShowUserMenu();
            break;
		case AdminMenuAction::ADD_USER :
			AccountHandler::addUser();
			newMenu = this;
            break;
		case AdminMenuAction::DELETE_USER :
			AccountHandler::deleteUser();
			newMenu = this;
			break;
		case AdminMenuAction::EDIT_USER :
			AccountHandler::editUser();
			newMenu = this;
			AccountHandler::resetUserToEdit();
			break;
		case AdminMenuAction::BACK :
            this->resetChoice();
            newMenu = new LoginMenu();
            break;
        default:
            break;
    }

    return newMenu;
}

unsigned AdminMenu::selectMode()
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
                choice_ < AdminMenuAction::ADD_USER ? choice_ = items_.size() : choice_--;
                break;
            case VK_DOWN:
                choice_ > items_.size() - 1 ? choice_ = AdminMenuAction::SHOW_USERS : choice_++;
                break;
            case VK_RETURN:
                return choice_;
            default:
                break;
        }
    }
}

void AdminMenu::showTitle()
{
	cout << title_ << endl;
}

void AdminMenu::showItems()
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

AdminMenu::~AdminMenu() = default;