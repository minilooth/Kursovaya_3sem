#include "ShowUserMenu.h"

unsigned ShowUserMenu::choice_ = ShowUserMenuAction::SHOW_OR_HIDE_PASSWORD;

ShowUserMenu::ShowUserMenu()
{
	title_ = "";
	items_ = { AccountHandler::getShowPasswordStatus() ? "Hide password." : "Show password." , "Back." };
}

ConsoleMenu* ShowUserMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case ShowUserMenuAction::SHOW_OR_HIDE_PASSWORD :
		AccountHandler::invertShowPasswordStatus();
		newMenu = new ShowUserMenu();
		break;
	case ShowUserMenuAction::BACK :
		this->resetChoice();
		AccountHandler::resetShowPasswordStatus();
		newMenu = new AdminMenu();
		break;
	default:
		break;
	}

	return newMenu;
}

unsigned ShowUserMenu::selectMode()
{
	KEY_EVENT_RECORD key;

	while (true)
	{
		system("cls");

		AccountHandler::showUsers();

		cout << endl;

		ShowUserMenu::showItems();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_UP:
			choice_ < ShowUserMenuAction::BACK ? choice_ = items_.size() : choice_--;
			break;
		case VK_DOWN:
			choice_ > items_.size() - 1 ? choice_ = ShowUserMenuAction::SHOW_OR_HIDE_PASSWORD : choice_++;
			break;
		case VK_RETURN:
			return choice_;
		case VK_ESCAPE:
			return choice_;
		default:
			break;
		}
	}
}

void ShowUserMenu::showTitle()
{
	cout << title_ << endl;
}

void ShowUserMenu::showItems()
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

void ShowUserMenu::resetChoice()
{
	choice_ = ShowUserMenuAction::SHOW_OR_HIDE_PASSWORD;
}

ShowUserMenu::~ShowUserMenu() = default;