#include "LoginMenu.h"

unsigned LoginMenu::choice_ = LoginMenuAction::BY_USER;

LoginMenu::LoginMenu()
{
    title_ = "Login Menu:";
    items_ = { "Login by user.", "Login by admin.", "Quit." };
}

void LoginMenu::resetChoice()
{
    choice_ = LoginMenuAction::BY_USER;
}

ConsoleMenu* LoginMenu::getNextMenu()
{
    ConsoleMenu* newMenu = nullptr;

    switch (selectMode())
    {
		case LoginMenuAction::BY_USER :
			AccountHandler::setAdminAccessStatus(false);
			if (AccountHandler::auth())
			{
				newMenu = new UserMenu();
			}
			else
			{
				newMenu = this;
			}
            break;
		case LoginMenuAction::BY_ADMIN :
			AccountHandler::setAdminAccessStatus(true);
            if(AccountHandler::auth())
            {
                newMenu = new AdminMenu();
            }
			else
			{
				newMenu = this;
			}
            break;
		case LoginMenuAction::QUIT :
            break;
        default:
            break;
    }

    return newMenu;
}

unsigned LoginMenu::selectMode()
{
	KEY_EVENT_RECORD key;
    while (true)
    {
        system("cls");

		LoginMenu::showTitle();
        LoginMenu::showItems();

		VP_GetCh(key);

        switch (key.wVirtualKeyCode)
        {
            case VK_UP:
                choice_ < LoginMenuAction::BY_ADMIN ? choice_ = items_.size() : choice_--;
                break;
            case VK_DOWN:
                choice_ > items_.size() - 1 ? choice_ = LoginMenuAction::BY_USER : choice_++;
                break;
            case VK_RETURN:
                return choice_;
            default:
                break;
        }
    }
}

void LoginMenu::showTitle()
{
	cout << title_ << endl;
}

void LoginMenu::showItems()
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

LoginMenu::~LoginMenu() = default;