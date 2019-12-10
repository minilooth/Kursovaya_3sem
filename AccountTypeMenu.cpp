#include "AccountTypeMenu.h"

unsigned AccountTypeMenu::choice_ = AccountType::ADMIN;

AccountTypeMenu::AccountTypeMenu()
{
	title_ = "Выберите тип аккаунта: ";
	items_ = { "Добавить администратора.", "Добавить пользователя." };
}

AccountTypeMenu::AccountTypeMenu(const string& title, const vector<string>& items)
{
	title_ = title;
	items_ = items;
}

void AccountTypeMenu::resetChoice()
{
	AccountTypeMenu::choice_ = AccountType::ADMIN;
}

ConsoleMenu* AccountTypeMenu::getNextMenu()
{
	return nullptr;
}

unsigned AccountTypeMenu::selectMode()
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
		case VK_DOWN :
			if (choice_ > items_.size() - 1)
			{
				choice_ = AccountType::ADMIN;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_UP :
			if (choice_ < AccountType::USER)
			{
				choice_ = items_.size();
			}
			else
			{
				choice_--;
			}
			break;
		case VK_ESCAPE :
			return 0;
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

void AccountTypeMenu::showTitle()
{
	cout << title_;
	if (!title_.empty())
	{
		cout << endl;
	}
}

void AccountTypeMenu::showItems()
{
	for (unsigned i = 0; i < items_.size(); i++)
	{
		if (choice_ == i + 1)
		{
			setTextColor(Color::WHITE);
			cout << "->" << items_.at(i) << "  " << endl;
			setTextColor(Color::LIGHT_CYAN);
		}
		else
		{
			cout << "  " << items_.at(i) << "  " << endl;
		}
	}
}

AccountTypeMenu::~AccountTypeMenu() = default;