#include "CarEditMenu.h"

using namespace menu;

unsigned CarEditMenu::choice_ = Action::EDIT_BRAND;

CarEditMenu::CarEditMenu()
{
	title_ = "���� �������������� ����������:";
	items_ = { 
			   "������������� �����.", "������������� ������.", "������������� ��� �������.", "������������� ��� ������.", "������������� ��� ���.", 
			   "������������� ��� ������.", "������������� ��� ���������.", "������������� ����� ���������.", "������������� ���� ������.", "������������� ���� ������.", 
			   "������������� �������� ������.", "������������� ������.", "������������� ����.", "������������� ������ �������.", "������������� ������������� �������.", "�����." 
			 };
}

CarEditMenu::CarEditMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void CarEditMenu::resetChoice()
{
	choice_ = Action::EDIT_BRAND;
}

ConsoleMenu* CarEditMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case Action::EDIT_BRAND :
		car::CarHandler::editBrand();
		newMenu = this;
		break;
	case Action::EDIT_MODEL :
		car::CarHandler::editModel();
		newMenu = this;
		break;
	case Action::EDIT_YEAR_OF_PRODUCTION :
		car::CarHandler::editYearOfProduction();
		newMenu = this;
		break;
	case Action::EDIT_BODY_TYPE :
		car::CarHandler::editBodyType();
		newMenu = this;
		break;
	case Action::EDIT_TRANSMISSION_TYPE :
		car::CarHandler::editTransmissionType();
		newMenu = this;
		break;
	case Action::EDIT_WHEEL_DRIVE_TYPE :
		car::CarHandler::editWheelDriveType();
		newMenu = this;
		break;
	case Action::EDIT_ENGINE_TYPE :
		car::CarHandler::editEngineType();
		newMenu = this;
		break;
	case Action::EDIT_ENGINE_VOLUME :
		car::CarHandler::editEngineVolume();
		newMenu = this;
		break;
	case Action::EDIT_BODY_COLOR :
		car::CarHandler::editBodyColor();
		newMenu = this;
		break;
	case Action::EDIT_INTERIOR_COLOR :
		car::CarHandler::editInteriorColor();
		newMenu = this;
		break;
	case Action::EDIT_INTERIOR_MATERIAL :
		car::CarHandler::editInteriorMaterial();
		newMenu = this;
		break;
	case Action::EDIT_MILEAGE :
		car::CarHandler::editMileage();
		newMenu = this;
		break;
	case Action::EDIT_PRICE :
		car::CarHandler::editPrice();
		newMenu = this;
		break;
	case Action::EDIT_RESERVE_STATUS :
		car::CarHandler::editReserveStatus();
		newMenu = this;
		break;
	case Action::EDIT_RESERVER_USERNAME :
		car::CarHandler::editReserverUsername();
		newMenu = this;
		break;
	case Action::BACK:
		this->resetChoice();
		break;
	default:
		break;
	}

	return newMenu;
}

unsigned CarEditMenu::selectMode()
{
	KEY_EVENT_RECORD key;

	system("cls");

	car::CarHandler::showEditCar();

	while (true)
	{
		showTitle();

		showItems();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_UP :
			if (choice_ < Action::EDIT_MODEL)
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
				choice_ = Action::EDIT_MODEL;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_ESCAPE :
			return Action::BACK;
		case VK_RETURN :
			return choice_;
		default:
			break;
		}

		if (items_.size() + 1)
		{
			clearNLines(items_.size() + 1);
		}
		else
		{
			clearNLines(items_.size());
		}
	}
}

void CarEditMenu::showTitle()
{
	cout << title_;
	if (!title_.empty())
	{
		cout << endl;
	}
}

void CarEditMenu::showItems()
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

CarEditMenu::~CarEditMenu() = default;