#include "AdminMenu.h"

unsigned AdminMenu::choice_ = AdminMenuAction::USER_MANAGEMENT;

AdminMenu::AdminMenu()
{
    title_ = "Admin main menu:";
    items_ = { "User management.", "Back." };
}

AdminMenu::AdminMenu(string& title, vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void AdminMenu::resetChoice()
{
    choice_ = AdminMenuAction::USER_MANAGEMENT;
}

ConsoleMenu* AdminMenu::getNextMenu()
{
    ConsoleMenu* newMenu = nullptr;

    switch (selectMode())
    {
		case AdminMenuAction::USER_MANAGEMENT :
            newMenu = new UserManagementMenu();
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
				if (choice_ < AdminMenuAction::BACK)
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
					choice_ = AdminMenuAction::USER_MANAGEMENT;
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
			cout << "->" << items_.at(i) << endl;
			setTextColor(Color::LIGHT_CYAN);
        }
		else
		{
			cout << "  " << items_.at(i) << endl;
		}
    }
}

AdminMenu::~AdminMenu() = default;