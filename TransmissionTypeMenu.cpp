#include "TransmissionTypeMenu.h"

unsigned TransmissionTypeMenu::choice_ = TransmissionType::MANUAL;

TransmissionTypeMenu::TransmissionTypeMenu()
{
	title_ = "Transmission type: ";
	items_ = { "Manual", "Automatic" };
}

TransmissionTypeMenu::TransmissionTypeMenu(string& title, vector<string>& items)
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
		case VK_RIGHT:
			if (choice_ > items_.size() - 1)
			{
				choice_ = TransmissionType::MANUAL;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_LEFT:
			if (choice_ < TransmissionType::AUTOMATIC)
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

void TransmissionTypeMenu::showTitle()
{
	cout << title_;
}

void TransmissionTypeMenu::showItems()
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

TransmissionTypeMenu::~TransmissionTypeMenu() = default;