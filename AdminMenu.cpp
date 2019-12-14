#include "AdminMenu.h"

using namespace menu;

unsigned AdminMenu::choice_ = Action::ACCOUNT_MANAGEMENT;

AdminMenu::AdminMenu()
{
    title_ = "Главное меню администратора:";
    items_ = { "Управление аккаунтами.", "Добавить автомобиль.", "Показать все автомобили.", "Удалить автомобиль.", "Редактировать автомобиль.", "Продать автомобиль.", "Показать общую статистику.", "Поиск, сортировка и фильтрация.", "Назад." };
}

AdminMenu::AdminMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void AdminMenu::resetChoice()
{
    choice_ = Action::ACCOUNT_MANAGEMENT;
}

ConsoleMenu* AdminMenu::getNextMenu()
{
    ConsoleMenu* newMenu = nullptr;

    switch (selectMode())
    {
		case Action::ACCOUNT_MANAGEMENT :
            newMenu = new AccountManagementMenu();
            break;
		case Action::ADD_CAR :
			car::CarHandler::addCar();
			newMenu = this;
			break;
		case Action::SHOW_CARS :
			car::CarHandler::showCars();
			newMenu = this;
			break;
		case Action::DELETE_CAR :
			car::CarHandler::deleteCar();
			newMenu = this;
			break;
		case Action::EDIT_CAR :
			car::CarHandler::editCar();
			car::CarHandler::resetCarToEdit();
			newMenu = this;
			break;
		case Action::SELL_CAR :
			car::CarHandler::sellCar();
			newMenu = this;
			break;
		case Action::SHOW_STATISTICS :
			account::AccountHandler::showTotalStatistics();
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

unsigned AdminMenu::selectMode()
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
				if (choice_ < Action::ADD_CAR)
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
					choice_ = Action::ACCOUNT_MANAGEMENT;
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

		if (!title_.empty())
		{
			clearNLines(items_.size() + 1);
		}
		else
		{
			clearNLines(items_.size());
		}
    }
}

void AdminMenu::showTitle()
{
	cout << title_;
	if (!title_.empty())
	{
		cout << endl;
	}
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