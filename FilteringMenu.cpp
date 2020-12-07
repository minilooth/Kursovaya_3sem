#include "FilteringMenu.h"

using namespace menu;

unsigned FilteringMenu::choice_ = Action::SET_FILTER_BY_BODY_TYPE;

FilteringMenu::FilteringMenu()
{
	title_ = "Фильтрация:";
	items_ = { (CarFiltering::getBodyTypeFilterStatus() == true ? "Удалить фильтр по типу кузова." : "Установить фильтр по типу кузова."),
			   (CarFiltering::getWheelDriveTypeFilterStatus() == true ? "Удалить фильтр по типу привода." : "Установить фильтр по типу привода."), 
			   (CarFiltering::getTransmissionTypeFilterStatus() == true ? "Удалить фильтр по типу КПП." : "Установить фильтр по типу КПП."), "Показать отфильтрованные автомобили.","Назад." };
}

FilteringMenu::FilteringMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void FilteringMenu::resetChoice()
{
	choice_ = Action::SET_FILTER_BY_BODY_TYPE;
}

ConsoleMenu* FilteringMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case Action::SET_FILTER_BY_BODY_TYPE :
		CarHandler::setFilterByBodyType();
		newMenu = new FilteringMenu();
		break;
	case Action::SET_FILTER_BY_WHEEL_DRIVE_TYPE :
		CarHandler::setFilterByWheelDriveType();
		newMenu = new FilteringMenu();
		break;
	case Action::SET_FILTER_BY_TRANSMISSION_TYPE :
		CarHandler::setFilterByTransmissionType();
		newMenu = new FilteringMenu();
		break;
	case Action::SHOW_FILTERED_CARS :
		CarHandler::showFilteredCars();
		newMenu = this;
		break;
	case Action::BACK :
		CarFiltering::resetBodyTypeFilter();
		CarFiltering::resetTransmissionTypeFilter();
		CarFiltering::resetWheelDriveTypeFilter();
		this->resetChoice();
		newMenu = new SearchingSortingAndFilteringMenu();
		break;
	default:
		break;
	}

	return newMenu;
}

unsigned FilteringMenu::selectMode()
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
		case VK_UP:
			if (choice_ < Action::SET_FILTER_BY_WHEEL_DRIVE_TYPE)
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
				choice_ = Action::SET_FILTER_BY_BODY_TYPE;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_ESCAPE:
			return Action::BACK;
		case VK_RETURN:
			return choice_;
		default:
			break;
		}

		title_.empty() ? clearNLines(items_.size()) : clearNLines(items_.size() + 1);
	}
}

void FilteringMenu::showTitle()
{
	cout << title_;
	if (!title_.empty())
	{
		cout << endl;
	}
}

void FilteringMenu::showItems()
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

FilteringMenu::~FilteringMenu() = default;