#include "AccountShowMenu.h"

unsigned AccountShowMenu::choice_ = AccountShowMenuAction::SHOW_OR_HIDE_PASSWORD;
unsigned AccountShowMenu::currentPage_ = 1;
unsigned AccountShowMenu::maxPages_ = 1;

AccountShowMenu::AccountShowMenu()
{
	title_ = "Все аккаунты:";
	items_ = { AccountHandler::getShowPasswordStatus() ? "Скрыть пароль." : "Показать пароль." , "Назад." };
	tooltip_ = "Подсказка:\nНажмите -> чтобы перейти на следующую страницу.\nНажмите <- чтобы перейти на предыдущую страницу.\nНажмите ESC или \"Назад\" чтобы вернуться назад.";
	pageSize_ = 10;

	maxPages_ = AccountHandler::countAccounts() / pageSize_;

	if (AccountHandler::countAccounts() % pageSize_ != 0)
	{
		maxPages_++;
	}
}

AccountShowMenu::AccountShowMenu(const string& title, const vector<string>& items, const string& tooltip, unsigned pageSize)
{
	title_ = title;
	items_ = items;
	tooltip_ = tooltip;
	pageSize_ = pageSize;

	maxPages_ = AccountHandler::countAccounts() / pageSize_;

	if (AccountHandler::countAccounts() % pageSize_ != 0)
	{
		maxPages_++;
	}
}

ConsoleMenu* AccountShowMenu::getNextMenu()
{
	ConsoleMenu* newMenu = nullptr;

	switch (selectMode())
	{
	case AccountShowMenuAction::SHOW_OR_HIDE_PASSWORD :
		AccountHandler::invertShowPasswordStatus();
		newMenu = new AccountShowMenu();
		break;
	case AccountShowMenuAction::BACK :
		this->resetChoice();
		AccountHandler::resetShowPasswordStatus();
		resetChoice();
		resetCurrentPage();
		resetMaxPages();
		newMenu = new AccountManagementMenu();
		break;
	default:
		break;
	}

	return newMenu;
}

void AccountShowMenu::nextPage()
{
	if (currentPage_ < maxPages_)
	{
		currentPage_++;
	}
}

void AccountShowMenu::previousPage()
{
	if (currentPage_ > 1)
	{
		currentPage_--;
	}
}

void AccountShowMenu::resetCurrentPage()
{
	currentPage_ = 1;
}

void AccountShowMenu::resetMaxPages()
{
	maxPages_ = 1;
}

unsigned AccountShowMenu::selectMode()
{
	KEY_EVENT_RECORD key;

	while (true)
	{
		system("cls");

		showTitle();
		cout << endl;

		showCurrentPageNumber();

		AccountHandler::showAccounts((pageSize_ * (currentPage_ - 1)), (pageSize_ * currentPage_));

		cout << endl;
		showItems();

		cout << endl;
		showTooltip();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_UP:
			if (choice_ < AccountShowMenuAction::BACK)
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
				choice_ = AccountShowMenuAction::SHOW_OR_HIDE_PASSWORD;
			}
			else
			{
				choice_++;
			}
			break;
		case VK_RIGHT :
			nextPage();
			break;
		case VK_LEFT :
			previousPage();
			break;
		case VK_RETURN:
			return choice_;
		case VK_ESCAPE:
			return AccountShowMenuAction::BACK;
		default:
			break;
		}
	}
}

void AccountShowMenu::showCurrentPageNumber()
{
	cout << "Страница " << currentPage_ << " из " << maxPages_ << endl;
}

void AccountShowMenu::showTooltip() const
{
	cout << tooltip_ << endl;
}

void AccountShowMenu::showTitle()
{
	cout << title_ << endl;
}

void AccountShowMenu::showItems()
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

void AccountShowMenu::resetChoice()
{
	choice_ = AccountShowMenuAction::SHOW_OR_HIDE_PASSWORD;
}

AccountShowMenu::~AccountShowMenu() = default;