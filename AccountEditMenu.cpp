#include "AccountEditMenu.h"

using namespace menu;

unsigned AccountEditMenu::choice_ = Action::EDIT_USERNAME;

AccountEditMenu::AccountEditMenu()
{
	title_ = "Редактирование аккаунта:";
	items_ = { "Редактировать имя аккаунта.", "Редактировать пароль.", "Редактировать права администратора.", "Редактировать статус блокировки.", "Назад." };
}

AccountEditMenu::AccountEditMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void AccountEditMenu::resetChoice()
{
	choice_ = Action::EDIT_USERNAME;
}

ConsoleMenu* AccountEditMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case Action::EDIT_USERNAME :
		account::AccountHandler::editUsername();
		newMenu = this;
		break;
	case Action::EDIT_PASSWORD :
		account::AccountHandler::editPassword();
		newMenu = this;
		break;
	case Action::EDIT_ADMIN_ACCESS :
		account::AccountHandler::editAdminAccess();
		newMenu = this;
		break;
	case Action::EDIT_BAN_STATUS :
		account::AccountHandler::editBanStatus();
		newMenu = this;
		break;
	case Action::BACK :
		this->resetChoice();
		break;
	default:
		break;
	}

	return newMenu;
}

unsigned AccountEditMenu::selectMode()
{
	KEY_EVENT_RECORD key;

	system("cls");

	account::AccountHandler::showEditAccount();
	
	cout << endl;

	while (true)
	{
		showTitle();
		showItems();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_UP :
			if (choice_ < Action::EDIT_PASSWORD)
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
				choice_ = Action::EDIT_USERNAME;
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

		if (!title_.empty())
		{
			clearNLines(items_.size() + 1);
		}
		else
		{
			clearNLines(items_.size());
		}
	}
}

void AccountEditMenu::showTitle()
{
	cout << title_;
	if (!title_.empty())
	{
		cout << endl;
	}
}

void AccountEditMenu::showItems()
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

AccountEditMenu::~AccountEditMenu() = default;