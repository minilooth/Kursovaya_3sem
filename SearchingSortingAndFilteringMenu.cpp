#include "SearchingSortingAndFilteringMenu.h"

unsigned SearchingSortingAndFilteringMenu::choice_ = SearchingSortingAndFilteringMenuAction::SEARCHING;

SearchingSortingAndFilteringMenu::SearchingSortingAndFilteringMenu()
{
	title_ = "Поиск, сортировка и фильтрация:";
	items_ = { "Поиск.", "Сортировка.", "Фильтрация.", "Назад." };
}

SearchingSortingAndFilteringMenu::SearchingSortingAndFilteringMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void SearchingSortingAndFilteringMenu::resetChoice()
{
	choice_ = SearchingSortingAndFilteringMenuAction::SEARCHING;
}

ConsoleMenu* SearchingSortingAndFilteringMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case SearchingSortingAndFilteringMenuAction::SEARCHING :
		newMenu = new SearchingMenu();
		break;
	case SearchingSortingAndFilteringMenuAction::SORTING :
		newMenu = new SortingMenu();
		break;
	case SearchingSortingAndFilteringMenuAction::FILTERING :
		newMenu = new FilteringMenu();
		break;
	case SearchingSortingAndFilteringMenuAction::BACK :
		this->resetChoice();
		if (AccountHandler::getAdminAccessStatus() == true)
		{
			newMenu = new AdminMenu();
		}
		else
		{
			newMenu = new UserMenu();
		}
		break;
	default:
		break;
	}

	return newMenu;
}

unsigned SearchingSortingAndFilteringMenu::selectMode()
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
			if (choice_ < SearchingSortingAndFilteringMenuAction::SORTING)
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
				choice_ = SearchingSortingAndFilteringMenuAction::SEARCHING;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_ESCAPE:
			return SearchingSortingAndFilteringMenuAction::BACK;
		case VK_RETURN:
			return choice_;
		default:
			break;
		}

		if (title_ != "")
		{
			clearNLines(items_.size() + 1);
		}
		else
		{
			clearNLines(items_.size());
		}
	}
}

void SearchingSortingAndFilteringMenu::showTitle()
{
	cout << title_;
	if (title_ != "")
	{
		cout << endl;
	}
}

void SearchingSortingAndFilteringMenu::showItems()
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

SearchingSortingAndFilteringMenu::~SearchingSortingAndFilteringMenu() = default;