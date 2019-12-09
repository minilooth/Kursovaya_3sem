#include "TransmissionTypeMenu.h"

unsigned TransmissionTypeMenu::choice_ = TransmissionType::MANUAL;

TransmissionTypeMenu::TransmissionTypeMenu()
{
	title_ = "Тип КПП: ";
	items_ = { "Механическая.", "Автоматическая." };
}

TransmissionTypeMenu::TransmissionTypeMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void TransmissionTypeMenu::resetChoice()
{
	TransmissionTypeMenu::choice_ = TransmissionType::MANUAL;
}

ConsoleMenu* TransmissionTypeMenu::getNextMenu()
{
	return this;
}

unsigned TransmissionTypeMenu::selectMode()
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
				choice_ = TransmissionType::MANUAL;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_UP :
			if (choice_ < TransmissionType::AUTOMATIC)
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

void TransmissionTypeMenu::showTitle()
{
	cout << title_;
	if (title_ != "")
	{
		cout << endl;
	}
}

void TransmissionTypeMenu::showItems()
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

TransmissionTypeMenu::~TransmissionTypeMenu() = default;