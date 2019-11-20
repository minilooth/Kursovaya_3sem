#include "BodyTypeMenu.h"

unsigned BodyTypeMenu::choice_ = BodyType::CROSSOVER;

BodyTypeMenu::BodyTypeMenu()
{
	title_ = "Choose body type:";
	items_ = { "Crossover.", 
			   "Cabriolet.", 
			   "Five-door hatchback.", 
			   "Five-seat minivan.", 
			   "Four-door coupe.", 
			   "Long-wheelbase sedan.", 
			   "Sedan.", 
			   "Seven-seat minivan.", 
			   "Station wagon.", 
			   "Three-door hatchback.", 
			   "Two-door coupe.", 
			   "Back." 
			 };
}

BodyTypeMenu::BodyTypeMenu(string& title, vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void BodyTypeMenu::resetChoice()
{
	choice_ = BodyType::CROSSOVER;
}

ConsoleMenu* BodyTypeMenu::getNextMenu()
{
	return this;
}

unsigned BodyTypeMenu::selectMode()
{
	KEY_EVENT_RECORD key;
	while (true)
	{
		system("cls");

		showTitle();

		showItems();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_UP:
			if (choice_ < BodyType::CABRIOLET)
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
				choice_ = BodyType::CROSSOVER;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_RETURN:
			return choice_;
		default:
			break;
		}
	}
}

void BodyTypeMenu::showTitle()
{
	cout << title_ << endl;
}

void BodyTypeMenu::showItems()
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

BodyTypeMenu::~BodyTypeMenu() = default;