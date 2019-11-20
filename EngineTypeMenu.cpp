#include "EngineTypeMenu.h"

unsigned EngineTypeMenu::choice_ = EngineType::PETROL;

EngineTypeMenu::EngineTypeMenu()
{
	title_ = "Engine type: ";
	items_ = { "Petrol", "Diesel" };
}

EngineTypeMenu::EngineTypeMenu(string& title, vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void EngineTypeMenu::resetChoice()
{
	EngineTypeMenu::choice_ = EngineType::PETROL;
}

ConsoleMenu* EngineTypeMenu::getNextMenu()
{
	return this;
}

unsigned EngineTypeMenu::selectMode()
{
	KEY_EVENT_RECORD key;

	while (true)
	{
		showTitle();

		showItems();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_RIGHT:
			if (choice_ > items_.size() - 1)
			{
				choice_ = EngineType::PETROL;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_LEFT:
			if (choice_ < EngineType::DIESEL)
			{
				choice_ = items_.size();
			}
			else
			{
				choice_--;
			}
			break;
		case VK_RETURN:
			return choice_;
		default:
			break;
		}

		clearLine();
	}
}

void EngineTypeMenu::showTitle()
{
	cout << title_;
}

void EngineTypeMenu::showItems()
{
	for (unsigned i = 0; i < items_.size(); i++)
	{
		if (choice_ == i + 1)
		{
			setTextColor(Color::WHITE);
			cout << "->" << items_.at(i) << "  ";
			setTextColor(Color::LIGHT_CYAN);
		}
		else
		{
			cout << "  " << items_.at(i) << "  ";
		}
	}
}

EngineTypeMenu::~EngineTypeMenu() = default;