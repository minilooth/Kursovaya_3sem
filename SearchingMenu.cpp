#include "SearchingMenu.h"

using namespace menu;

unsigned SearchingMenu::choice_ = Action::SEARCH_BY_BRAND;

SearchingMenu::SearchingMenu()
{
	title_ = "Поиск:";
	items_ = { "Поиск по марке.", "Поиск по модели.", "Поиск по году выпуска.", "Поиск по типу двигателя.", "Назад." };
}

SearchingMenu::SearchingMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void SearchingMenu::resetChoice()
{
	choice_ = Action::SEARCH_BY_BRAND;
}

ConsoleMenu* SearchingMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case Action::SEARCH_BY_BRAND :
		CarHandler::searchByBrand();
		newMenu = this;
		break;
	case Action::SEARCH_BY_MODEL :
		CarHandler::searchByModel();
		newMenu = this;
		break;
	case Action::SEARCH_BY_YEAR_OF_PRODUCTION :
		CarHandler::searchByYearOfProduction();
		newMenu = this;
		break;
	case Action::SEARCH_BY_ENGINE_TYPE :
		CarHandler::searchByEngineType();
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

unsigned SearchingMenu::selectMode()
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
			if (choice_ < Action::SEARCH_BY_MODEL)
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
				choice_ = Action::SEARCH_BY_BRAND;
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

void SearchingMenu::showTitle()
{
	cout << title_;
	if (!title_.empty())
	{
		cout << endl;
	}
}

void SearchingMenu::showItems()
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

SearchingMenu::~SearchingMenu() = default;