#include "UserMenu.h"

unsigned UserMenu::choice_ = UserMenuAction::NEW_CARS;

UserMenu::UserMenu()
{
    title_ = "Main menu: ";
    items_ = { "New cars.", "Cars for sale.", "Find car.", "Back." };
}

UserMenu::UserMenu(string& title, vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void UserMenu::resetChoice()
{
    choice_ = UserMenuAction::NEW_CARS;
}

ConsoleMenu* UserMenu::getNextMenu()
{
    ConsoleMenu* newMenu = nullptr;

    switch (selectMode())
    {
	case UserMenuAction::NEW_CARS :
		//CarHandler::showCars();
		CarHandler::showNewCars();
            newMenu = this;
            break;
	case UserMenuAction::CARS_FOR_SALE :
		CarHandler::showCarsForSale();
            newMenu = this;
            break;
	case UserMenuAction::FIND_CAR :
		//CarHandler::findCar();
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
				if (choice_ < UserMenuAction::NEW_CARS)
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
					choice_ = UserMenuAction::NEW_CARS;
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