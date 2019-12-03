#include "AccountShowMenu.h"

unsigned AccountShowMenu::choice_ = AccountShowMenuAction::SHOW_OR_HIDE_PASSWORD;
unsigned AccountShowMenu::currentPage_ = 1;
unsigned AccountShowMenu::maxPages_ = 1;

AccountShowMenu::AccountShowMenu()
{
	title_ = "All accounts:";
	items_ = { AccountHandler::getShowPasswordStatus() ? "Hide password." : "Show password." , "Back." };
	tooltip_ = "Tooltip:\nPress -> to go to next page.\nPress <- to go to previous page.\nPress ESC or select \"Back\" to go back.";
	pageSize_ = 10;

	maxPages_ = AccountHandler::countAccounts() / pageSize_;

	if (AccountHandler::countAccounts() % pageSize_ != 0)
	{
		maxPages_++;
	}
}

AccountShowMenu::AccountShowMenu(string& title, vector<string>& items, string& tooltip, unsigned pageSize)
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
	else
	{
		return;
	}
}

void AccountShowMenu::previousPage()
{
	if (currentPage_ > 1)
	{
		currentPage_--;
	}
	else
	{
		return;
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
	cout << "Page " << currentPage_ << " of " << maxPages_ << endl;
}

void AccountShowMenu::showTooltip()
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