#include "CarEditMenu.h"

unsigned CarEditMenu::choice_ = CarEditMenuAction::EDIT_BRAND;

CarEditMenu::CarEditMenu()
{
	title_ = "Car edit menu:";
	items_ = { 
			   "Edit brand.", "Edit model.", "Edit year of production.", "Edit body type.", "Edit transmission type", 
			   "Edit wheel drive type.", "Edit engine type.", "Edit engine volume.", "Edit body color.", "Edit interior color.", 
			   "Edit interior material.", "Edit mealeage.", "Edit price.", "Edit reserve status.", "Back." 
			 };
}

CarEditMenu::CarEditMenu(string& title, vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void CarEditMenu::resetChoice()
{
	choice_ = CarEditMenuAction::EDIT_BRAND;
}

ConsoleMenu* CarEditMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case CarEditMenuAction::EDIT_BRAND :
		CarHandler::editBrand();
		newMenu = this;
		break;
	case CarEditMenuAction::EDIT_MODEL :
		CarHandler::editModel();
		newMenu = this;
		break;
	case CarEditMenuAction::EDIT_YEAR_OF_PRODUCTION :
		CarHandler::editYearOfProduction();
		newMenu = this;
		break;
	case CarEditMenuAction::EDIT_BODY_TYPE :
		CarHandler::editBodyType();
		newMenu = this;
		break;
	case CarEditMenuAction::EDIT_TRANSMISSION_TYPE :
		CarHandler::editTransmissionType();
		newMenu = this;
		break;
	case CarEditMenuAction::EDIT_WHEEL_DRIVE_TYPE :
		CarHandler::editWheelDriveType();
		newMenu = this;
		break;
	case CarEditMenuAction::EDIT_ENGINE_TYPE :
		CarHandler::editEngineType();
		newMenu = this;
		break;
	case CarEditMenuAction::EDIT_ENGINE_VOLUME :
		CarHandler::editEngineVolume();
		newMenu = this;
		break;
	case CarEditMenuAction::EDIT_BODY_COLOR :
		CarHandler::editBodyColor();
		newMenu = this;
		break;
	case CarEditMenuAction::EDIT_INTERIOR_COLOR :
		CarHandler::editInteriorColor();
		newMenu = this;
		break;
	case CarEditMenuAction::EDIT_INTERIOR_MATERIAL :
		CarHandler::editInteriorMaterial();
		newMenu = this;
		break;
	case CarEditMenuAction::EDIT_MEALEAGE :
		CarHandler::editMealeage();
		newMenu = this;
		break;
	case CarEditMenuAction::EDIT_PRICE :
		CarHandler::editPrice();
		newMenu = this;
		break;
	case CarEditMenuAction::EDIT_RESERVE_STATUS :
		CarHandler::editReserveStatus();
		newMenu = this;
		break;
	case CarEditMenuAction::BACK:
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
	while (true)
	{
		system("cls");

		CarHandler::showEditCar();

		showTitle();

		showItems();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_UP :
			if (choice_ < CarEditMenuAction::EDIT_MODEL)
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
				choice_ = CarEditMenuAction::EDIT_MODEL;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_ESCAPE :
			return CarEditMenuAction::BACK;
		case VK_RETURN :
			return choice_;
		default:
			break;
		}
	}
}

void CarEditMenu::showTitle()
{
	cout << title_ << endl;
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