#include "BodyTypeMenu.h"

using namespace menu;

unsigned BodyTypeMenu::choice_ = BodyType::CROSSOVER;

BodyTypeMenu::BodyTypeMenu()
{
	title_ = "�������� ��� ������:";
	items_ = { "���������.", 
			   "���������.", 
			   "������� 5 ��.", 
			   "5 �. �������.", 
			   "4 ��. ����.", 
			   "������� �����.", 
			   "�����.", 
			   "7 �. �������.", 
			   "���������.", 
			   "������� 3 ��.", 
			   "2 ��. ����.", 
			   "�����." 
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

		title_.empty() ? clearNLines(items_.size()) : clearNLines(items_.size() + 1);
	}
}

void BodyTypeMenu::showTitle()
{
	cout << title_;
	if (!title_ .empty())
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