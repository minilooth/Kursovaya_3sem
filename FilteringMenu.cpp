#include "FilteringMenu.h"

unsigned FilteringMenu::choice_ = FilteringMenuAction::SET_FILTER_BY_BODY_TYPE;

FilteringMenu::FilteringMenu()
{
	title_ = "����������:";
	items_ = { (CarFiltering::getBodyTypeFilterStatus() == true ? "������� ������ �� ���� ������." : "���������� ������ �� ���� ������."),
			   (CarFiltering::getWheelDriveTypeFilterStatus() == true ? "������� ������ �� ���� �������." : "���������� ������ �� ���� �������."), 
			   (CarFiltering::getTransmissionTypeFilterStatus() == true ? "������� ������ �� ���� ���." : "���������� ������ �� ���� ���."), "�������� ��������������� ����������.","�����." };
}

FilteringMenu::FilteringMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void FilteringMenu::resetChoice()
{
	choice_ = FilteringMenuAction::SET_FILTER_BY_BODY_TYPE;
}

ConsoleMenu* FilteringMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case FilteringMenuAction::SET_FILTER_BY_BODY_TYPE :
		CarHandler::setFilterByBodyType();
		newMenu = new FilteringMenu();
		break;
	case FilteringMenuAction::SET_FILTER_BY_WHEEL_DRIVE_TYPE :
		CarHandler::setFilterByWheelDriveType();
		newMenu = new FilteringMenu();
		break;
	case FilteringMenuAction::SET_FILTER_BY_TRANSMISSION_TYPE :
		CarHandler::setFilterByTransmissionType();
		newMenu = new FilteringMenu();
		break;
	case FilteringMenuAction::SHOW_FILTERED_CARS :
		CarHandler::showFilteredCars();
		newMenu = this;
		break;
	case FilteringMenuAction::BACK :
		CarFiltering::resetBodyTypeFilter();
		CarFiltering::resetTransmissionTypeFilter();
		CarFiltering::resetWheelDriveTypeFilter();
		this->resetChoice();
		newMenu = new SearchingSortingAndFilteringMenu();
		break;
	default:
		break;
	}

	return newMenu;
}

unsigned FilteringMenu::selectMode()
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
			if (choice_ < FilteringMenuAction::SET_FILTER_BY_WHEEL_DRIVE_TYPE)
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
				choice_ = FilteringMenuAction::SET_FILTER_BY_BODY_TYPE;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_ESCAPE:
			return FilteringMenuAction::BACK;
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

void FilteringMenu::showTitle()
{
	cout << title_;
	if (title_ != "")
	{
		cout << endl;
	}
}

void FilteringMenu::showItems()
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

FilteringMenu::~FilteringMenu() = default;