#include "LoginMenu.h"

using namespace menu;

unsigned LoginMenu::choice_ = Action::BY_USER;

LoginMenu::LoginMenu()
{
    title_ = "";
    items_ = { "Войти как пользователь.", "Войти как администратор.", "Регистрация.", "Выход." };
}

LoginMenu::LoginMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void LoginMenu::resetChoice()
{
    choice_ = Action::BY_USER;
}

ConsoleMenu* LoginMenu::getNextMenu()
{
    ConsoleMenu* newMenu = nullptr;

    switch (selectMode())
    {
		case Action::BY_USER :
			account::AccountHandler::setAdminAccessStatus(false);
			if (account::AccountHandler::auth())
			{
				newMenu = new UserMenu();
			}
			else
			{
				newMenu = this;
			}
            break;
		case Action::BY_ADMIN :
			account::AccountHandler::setAdminAccessStatus(true);
            if(account::AccountHandler::auth())
            {
                newMenu = new AdminMenu();
            }
			else
			{
				newMenu = this;
			}
            break;
		case Action::REGISTRATION :
			account::AccountHandler::registration();
			newMenu = this;
			break;
		case Action::QUIT :
            break;
        default:
            break;
    }

    return newMenu;
}

unsigned LoginMenu::selectMode()
{
	KEY_EVENT_RECORD key;

	system("cls");

    while (true)
    {
        showItems();

		VP_GetCh(key);

        switch (key.wVirtualKeyCode)
        {
            case VK_UP :
				if (choice_ < Action::BY_ADMIN)
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
					choice_ = Action::BY_USER;
				}
				else
				{
					choice_++;
				}
                break;
			case VK_ESCAPE :
				return 0;
            case VK_RETURN :
                return choice_;
            default:
                break;
        }

		if (title_.empty())
		{
			clearNLines(items_.size() + 1);
		}
		else
		{
			clearNLines(items_.size());
		}
    }
}

void LoginMenu::showTitle()
{
	cout << title_;
	if (title_.empty())
	{
		cout << endl;
	}
}

void LoginMenu::showItems()
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

LoginMenu::~LoginMenu() = default;