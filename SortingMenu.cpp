#include "SortingMenu.h"

using namespace menu;

unsigned SortingMenu::choice_ = Action::SORT_BY_YEAR_OF_PRODUCTION;

SortingMenu::SortingMenu()
{
	title_ = "Сортировка:";
	items_ = { "Сортировка по году выпуска.", "Сортировка по объему двигателя.", "Сортировка по цене.", "Назад."};
}

SortingMenu::SortingMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void SortingMenu::resetChoice()
{
	choice_ = Action::SORT_BY_YEAR_OF_PRODUCTION;
}

ConsoleMenu* SortingMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case Action::SORT_BY_YEAR_OF_PRODUCTION :
		car::CarHandler::sortByYearOfProduction();
		newMenu = this;
		break;
	case Action::SORT_BY_ENGINE_VOLUME :
		car::CarHandler::sortByEngineVolume();
		newMenu = this;
		break;
	case Action::SORT_BY_PRICE :
		car::CarHandler::sortByPrice();
		newMenu = this;
		break;
	case Action::BACK :
		this->resetChoice();
		newMenu = new SearchingSortingAndFilteringMenu();
		break;
	default:
		break;
	}

	return newMenu;
}

unsigned SortingMenu::selectMode()
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
			if (choice_ < Action::SORT_BY_ENGINE_VOLUME)
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
				choice_ = Action::SORT_BY_YEAR_OF_PRODUCTION;
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

void SortingMenu::showTitle()
{
	cout << title_;
	if (!title_.empty())
	{
		cout << endl;
	}
}

void SortingMenu::showItems()
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

SortingMenu::~SortingMenu() = default;