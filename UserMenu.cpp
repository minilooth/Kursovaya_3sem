#include "UserMenu.h"

unsigned UserMenu::choice_ = UserMenuAction::NOTHING1;

UserMenu::UserMenu()
{
    title_ = "Main menu: ";
    items_ = { "User do smth...", "User do smth...", "Back" };
}

UserMenu::UserMenu(string& title, vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void UserMenu::resetChoice()
{
    choice_ = UserMenuAction::NOTHING1;
}

ConsoleMenu* UserMenu::getNextMenu()
{
    ConsoleMenu* newMenu = nullptr;

    switch (selectMode())
    {
	case UserMenuAction::NOTHING1 :
            newMenu = this;
            break;
	case UserMenuAction::NOTHING2 :
            newMenu = this;
            break;
	case UserMenuAction::BACK :
            this->resetChoice();
            newMenu = new LoginMenu();
            break;
        default:
            break;
    }

    return newMenu;
}

unsigned UserMenu::selectMode()
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
				if (choice_ < UserMenuAction::NOTHING1)
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
					choice_ = UserMenuAction::NOTHING1;
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

void UserMenu::showTitle()
{
	cout << title_ << endl;
}

void UserMenu::showItems()
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

UserMenu::~UserMenu() = default;