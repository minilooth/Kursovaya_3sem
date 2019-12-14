#include "UserMenu.h"

using namespace menu;

unsigned UserMenu::choice_ = Action::SHOW_ALL_CARS;

UserMenu::UserMenu()
{
    title_ = "Главное меню пользователя: ";
    items_ = { "Показать все автомобили.", "Зарезервировать новый автомобиль.", "Зарезервировать автомобиль с пробегом.", "Показать все зарезервированные пользователем автомобили.", "Показать статистику аккаунта.", "Поиск, сортировка и фильтрация.", "Назад." };
}

UserMenu::UserMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void UserMenu::resetChoice()
{
    choice_ = Action::SHOW_ALL_CARS;
}

ConsoleMenu* UserMenu::getNextMenu()
{
    ConsoleMenu* newMenu = nullptr;

    switch (selectMode())
    {
	case Action::SHOW_ALL_CARS :
		car::CarHandler::showCars();
		newMenu = this;
		break;
	case Action::RESERVE_NEW_CAR :
		car::CarHandler::reserveNewCar();
	    newMenu = this;
		break;
	case Action::RESERVE_USED_CAR :
		car::CarHandler::reserveUsedCar();
        newMenu = this;
		break;
	case Action::SHOW_ACCOUNT_RESERVED_CARS :
		car::CarHandler::showAccountReservedCars();
		newMenu = this;
		break;
	case Action::SHOW_ACCOUNT_STATISTICS :
		account::AccountHandler::showCurrentAccountStatistics();
		newMenu = this;
		break;
	case Action::SEARCHING_SORTING_AND_FILTRATION :
		newMenu = new SearchingSortingAndFilteringMenu();
		break;
	case Action::BACK :
		this->resetChoice();
		account::AccountHandler::resetCurrentAccount();
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

	system("cls");

    while (true)
    {
		showTitle();
        showItems();

		VP_GetCh(key);

        switch (key.wVirtualKeyCode)
        {
            case VK_UP :
				if (choice_ < Action::RESERVE_NEW_CAR)
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
					choice_ = Action::SHOW_ALL_CARS;
				}
				else
				{
					choice_++;
				}
                break;
			case VK_ESCAPE :
				return Action::BACK;
            case VK_RETURN :
                return choice_;
            default:
                break;
        }

		title_.empty() ? clearNLines(items_.size()) : clearNLines(items_.size() + 1);
    }
}

void UserMenu::showTitle()
{
	cout << title_;
	if (!title_.empty())
	{
		cout << endl;
	}
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