#include "UserMenu.h"

unsigned UserMenu::choice_ = UserMenuAction::SHOW_ALL_CARS;

UserMenu::UserMenu()
{
    title_ = "������� ���� ������������: ";
    items_ = { "�������� ��� ����������.", "��������������� ����� ����������.", "��������������� ���������� � ��������.", "�������� ��� ����������������� ������������� ����������.", "�������� ���������� ��������.", "�����, ���������� � ����������.", "�����." };
}

UserMenu::UserMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void UserMenu::resetChoice()
{
    choice_ = UserMenuAction::SHOW_ALL_CARS;
}

ConsoleMenu* UserMenu::getNextMenu()
{
    ConsoleMenu* newMenu = nullptr;

    switch (selectMode())
    {
	case UserMenuAction::SHOW_ALL_CARS :
		CarHandler::showCars();
		newMenu = this;
		break;
	case UserMenuAction::RESERVE_NEW_CAR :
		CarHandler::reserveNewCar();
	    newMenu = this;
		break;
	case UserMenuAction::RESERVE_USED_CAR :
		CarHandler::reserveUsedCar();
        newMenu = this;
		break;
	case UserMenuAction::SHOW_ACCOUNT_RESERVED_CARS :
		CarHandler::showAccountReservedCars();
		newMenu = this;
		break;
	case UserMenuAction::SHOW_ACCOUNT_STATISTICS :
		AccountHandler::showCurrentAccountStatistics();
		newMenu = this;
		break;
	case UserMenuAction::SEARCHING_SORTING_AND_FILTRATION :
		newMenu = new SearchingSortingAndFilteringMenu();
		break;
	case UserMenuAction::BACK :
		this->resetChoice();
		AccountHandler::resetCurrentAccount();
		newMenu = new LoginMenu();
		break;
    default:
        break;
    }

    return newMenu;
}

unsigned UserMenu::selectMode()
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
            case VK_UP :
				if (choice_ < UserMenuAction::RESERVE_NEW_CAR)
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
					choice_ = UserMenuAction::SHOW_ALL_CARS;
				}
				else
				{
					choice_++;
				}
                break;
			case VK_ESCAPE :
				return UserMenuAction::BACK;
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

void UserMenu::showTitle()
{
	cout << title_;
	if (title_ != "")
	{
		cout << endl;
	}
}

void UserMenu::showItems()
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

UserMenu::~UserMenu() = default;