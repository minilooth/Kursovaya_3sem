#include "AdminMenu.h"

unsigned AdminMenu::choice_ = AdminMenuAction::ACCOUNT_MANAGEMENT;

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
    choice_ = AdminMenuAction::ACCOUNT_MANAGEMENT;
}

ConsoleMenu* AdminMenu::getNextMenu()
{
    ConsoleMenu* newMenu = nullptr;

    switch (selectMode())
    {
		case AdminMenuAction::ACCOUNT_MANAGEMENT :
            newMenu = new AccountManagementMenu();
            break;
		case AdminMenuAction::ADD_CAR :
			CarHandler::addCar();
			newMenu = this;
			break;
		case AdminMenuAction::SHOW_CARS :
			CarHandler::showCars();
			newMenu = this;
			break;
		case AdminMenuAction::DELETE_CAR :
			CarHandler::deleteCar();
			newMenu = this;
			break;
		case AdminMenuAction::EDIT_CAR :
			CarHandler::editCar();
			CarHandler::resetCarToEdit();
			newMenu = this;
			break;
		case AdminMenuAction::SELL_CAR :
			CarHandler::sellCar();
			newMenu = this;
			break;
		case AdminMenuAction::SHOW_STATISTICS :
			AccountHandler::showTotalStatistics();
			newMenu = this;
			break;
		case AdminMenuAction::SEARCHING_SORTING_AND_FILTRATION :
			newMenu = new SearchingSortingAndFilteringMenu();
			break;
		case AdminMenuAction::BACK :
            this->resetChoice();
			AccountHandler::resetCurrentAccount();
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
				if (choice_ < AdminMenuAction::ADD_CAR)
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
					choice_ = AdminMenuAction::ACCOUNT_MANAGEMENT;
				}
				else
				{
					choice_++;
				}
                break;
			case VK_ESCAPE :
				return AdminMenuAction::BACK;
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