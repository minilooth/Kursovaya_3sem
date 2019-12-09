#include "EngineTypeMenu.h"

unsigned EngineTypeMenu::choice_ = EngineType::PETROL;

EngineTypeMenu::EngineTypeMenu()
{
	title_ = "Тип двигателя: ";
	items_ = { "Бензиновый.", "Дизельный." };
}

EngineTypeMenu::EngineTypeMenu(const string& title, const vector<string>& items)
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
		case VK_DOWN :
			if (choice_ > items_.size() - 1)
			{
				choice_ = EngineType::PETROL;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_UP :
			if (choice_ < EngineType::DIESEL)
			{
				choice_ = items_.size();
			}
			else
			{
				choice_--;
			}
			break;
		case VK_ESCAPE :
			return 0;
		case VK_RETURN :
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

void EngineTypeMenu::showTitle()
{
	cout << title_;
	if (title_ != "")
	{
		cout << endl;
	}
}

void EngineTypeMenu::showItems()
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

EngineTypeMenu::~EngineTypeMenu() = default;