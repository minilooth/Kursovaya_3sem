#include "SearchingSortingAndFilteringMenu.h"

unsigned menu::SearchingSortingAndFilteringMenu::choice_ = Action::SEARCHING;

menu::SearchingSortingAndFilteringMenu::SearchingSortingAndFilteringMenu()
{
	title_ = "Поиск, сортировка и фильтрация:";
	items_ = { "Поиск.", "Сортировка.", "Фильтрация.", "Назад." };
}

menu::SearchingSortingAndFilteringMenu::SearchingSortingAndFilteringMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void menu::SearchingSortingAndFilteringMenu::resetChoice()
{
	choice_ = Action::SEARCHING;
}

menu::ConsoleMenu* menu::SearchingSortingAndFilteringMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case Action::SEARCHING :
		newMenu = new SearchingMenu();
		break;
	case Action::SORTING :
		newMenu = new SortingMenu();
		break;
	case Action::FILTERING :
		newMenu = new FilteringMenu();
		break;
	case Action::BACK :
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

unsigned menu::SearchingSortingAndFilteringMenu::selectMode()
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
			if (choice_ < Action::SORTING)
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
				choice_ = Action::SEARCHING;
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

void menu::SearchingSortingAndFilteringMenu::showTitle()
{
	cout << title_;
	if (!title_.empty())
	{
		cout << endl;
	}
}

void menu::SearchingSortingAndFilteringMenu::showItems()
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

menu::SearchingSortingAndFilteringMenu::~SearchingSortingAndFilteringMenu() = default;