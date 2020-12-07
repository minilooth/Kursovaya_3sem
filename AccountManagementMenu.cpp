#include "AccountManagementMenu.h"

using namespace menu;

unsigned AccountManagementMenu::choice_ = Action::SHOW_ACCOUNTS;

AccountManagementMenu::AccountManagementMenu()
{
	title_ = "Меню управления аккаунтами:";
	items_ = { "Показать все аккаунты.", "Добавить аккаунт.", "Удалить аккаунт.", "Редактировать аккаунт.", "Назад." };
}

AccountManagementMenu::AccountManagementMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void AccountManagementMenu::resetChoice()
{
	choice_ = Action::SHOW_ACCOUNTS;
}

ConsoleMenu* AccountManagementMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case Action::SHOW_ACCOUNTS:
		newMenu = new AccountShowMenu();
		break;
	case Action::ADD_ACCOUNT:
		AccountHandler::addAccount();
		newMenu = this;
		break;
	case Action::DELETE_ACCOUNT:
		AccountHandler::deleteAccount();
		newMenu = this;
		break;
	case Action::EDIT_ACCOUNT:
		AccountHandler::editAccount();
		AccountHandler::resetAccountToEdit();
		newMenu = this;
		break;
	case Action::BACK:
		this->resetChoice();
		newMenu = new AdminMenu();
		break;
	default:
		break;
	}

	return newMenu;
}

unsigned AccountManagementMenu::selectMode()
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
			if (choice_ < Action::ADD_ACCOUNT)
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
				choice_ = Action::SHOW_ACCOUNTS;
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

void AccountManagementMenu::showTitle()
{
	cout << title_;
	if (!title_.empty())
	{
		cout << endl;
	}
}

void AccountManagementMenu::showItems()
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

AccountManagementMenu::~AccountManagementMenu() = default;