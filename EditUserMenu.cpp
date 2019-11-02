#include "EditUserMenu.h"

unsigned EditUserMenu::choice_ = EditUserMenuAction::CHANGE_USERNAME;

EditUserMenu::EditUserMenu()
{
	title_ = "";
	items_ = { "Change username.", "Change password.", "Change admin access.", "Back." };
}

void EditUserMenu::resetChoice()
{
	choice_ = EditUserMenuAction::CHANGE_USERNAME;
}

ConsoleMenu* EditUserMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case EditUserMenuAction::CHANGE_USERNAME :
		AccountHandler::inputNewUsername();
		newMenu = this;
		break;
	case EditUserMenuAction::CHANGE_PASSWORD :
		AccountHandler::inputNewPassword();
		newMenu = this;
		break;
	case EditUserMenuAction::CHANGE_ADMIN_ACCESS :
		AccountHandler::changeAdminAccess();
		newMenu = this;
		break;
	case EditUserMenuAction::BACK :
		this->resetChoice();
		break;
	default:
		break;
	}

	return newMenu;
}

unsigned EditUserMenu::selectMode()
{
	KEY_EVENT_RECORD key;
	while (true)
	{
		system("cls");

		AccountHandler::showEditUser();
		cout << endl;
		showItems();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_UP:
			choice_ < EditUserMenuAction::CHANGE_PASSWORD ? choice_ = items_.size() : choice_--;
			break;
		case VK_DOWN:
			choice_ > items_.size() - 1 ? choice_ = EditUserMenuAction::CHANGE_USERNAME : choice_++;
			break;
		case VK_RETURN:
			return choice_;
		default:
			break;
		}
	}
}

void EditUserMenu::showTitle()
{
	cout << title_ << endl;
}

void EditUserMenu::showItems()
{
	for (unsigned i = 0; i < items_.size(); i++)
	{
		if (choice_ == i + 1)
		{
			setTextColor(Color::WHITE);
		}
		choice_ == i + 1 ? cout << "->" << items_.at(i) << endl : cout << "  " << items_.at(i) << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
}

EditUserMenu::~EditUserMenu() = default;