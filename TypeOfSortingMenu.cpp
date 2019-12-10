#include "TypeOfSortingMenu.h"

unsigned TypeOfSortingMenu::choice_ = TypeOfSortingMenuAction::ASCENDING;

TypeOfSortingMenu::TypeOfSortingMenu()
{
	title_ = "Тип сортировки:";
	items_ = { "По возрастанию.", "По убыванию.", "Назад." };
}

TypeOfSortingMenu::TypeOfSortingMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void TypeOfSortingMenu::resetChoice()
{
	choice_ = TypeOfSortingMenuAction::ASCENDING;
}

ConsoleMenu* TypeOfSortingMenu::getNextMenu()
{
	return nullptr;
}

unsigned TypeOfSortingMenu::selectMode()
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
			if (choice_ < TypeOfSortingMenuAction::DESCENDING)
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
				choice_ = TypeOfSortingMenuAction::ASCENDING;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_ESCAPE:
			return TypeOfSortingMenuAction::BACK;
		case VK_RETURN:
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

void TypeOfSortingMenu::showTitle()
{
	cout << title_;
	if (!title_.empty())
	{
		cout << endl;
	}
}

void TypeOfSortingMenu::showItems()
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

TypeOfSortingMenu::~TypeOfSortingMenu() = default;