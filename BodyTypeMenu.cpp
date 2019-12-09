#include "BodyTypeMenu.h"

unsigned BodyTypeMenu::choice_ = BodyType::CROSSOVER;

BodyTypeMenu::BodyTypeMenu()
{
	title_ = "Выберите тип кузова:";
	items_ = { "Кроссовер.", 
			   "Кабриолет.", 
			   "Хэтчбек 5 дв.", 
			   "5 м. минивен.", 
			   "4 дв. купе.", 
			   "Длинный седан.", 
			   "Седан.", 
			   "7 м. минивен.", 
			   "Универсал.", 
			   "Хэтчбек 3 дв.", 
			   "2 дв. купе.", 
			   "Назад." 
			 };
}

BodyTypeMenu::BodyTypeMenu(const string& title, const vector<string>& items)
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
		showTitle();

		showItems();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_UP :
			if (choice_ < BodyType::CABRIOLET)
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
				choice_ = BodyType::CROSSOVER;
			}
			else
			{
				choice_++;
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

void BodyTypeMenu::showTitle()
{
	cout << title_;
	if (title_ != "")
	{
		cout << endl;
	}
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