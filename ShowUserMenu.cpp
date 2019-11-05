#include "ShowUserMenu.h"

unsigned ShowUserMenu::choice_ = ShowUserMenuAction::SHOW_OR_HIDE_PASSWORD;
unsigned ShowUserMenu::currentPage_ = 1;
unsigned ShowUserMenu::maxPages_ = 1;

ShowUserMenu::ShowUserMenu()
{
	title_ = "";
	items_ = { AccountHandler::getShowPasswordStatus() ? "Hide password." : "Show password." , "Back." };
	tooltip_ = "Tooltip:\nPress -> to go to next page.\nPress <- to go to previous page.\nPress ESC to go back.";

	maxPages_ = AccountHandler::countAccounts() / 10;

	if (AccountHandler::countAccounts() % 10 != 0)
	{
		maxPages_++;
	}
}

ShowUserMenu::ShowUserMenu(string& title, vector<string>& items)
{
	title_ = title;
	items_ = items;

	maxPages_ = AccountHandler::countAccounts() / 10;

	if (AccountHandler::countAccounts() % 10 != 0)
	{
		maxPages_++;
	}
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
		resetChoice();
		resetCurrentPage();
		resetMaxPages();
		newMenu = new UserManagementMenu();
		break;
	default:
		break;
	}

	return newMenu;
}

void ShowUserMenu::nextPage()
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

void ShowUserMenu::previousPage()
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

void ShowUserMenu::resetCurrentPage()
{
	currentPage_ = 1;
}

void ShowUserMenu::resetMaxPages()
{
	maxPages_ = 1;
}

unsigned ShowUserMenu::selectMode()
{
	KEY_EVENT_RECORD key;

	while (true)
	{
		system("cls");

		showCurrentPageNumber();

		AccountHandler::showUsers((10 * (currentPage_ - 1)), (10 * currentPage_));

		cout << endl;

		showItems();

		cout << endl;

		showTooltip();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_UP:
			if (choice_ < ShowUserMenuAction::BACK)
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
				choice_ = ShowUserMenuAction::SHOW_OR_HIDE_PASSWORD;
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
			return ShowUserMenuAction::BACK;
		default:
			break;
		}
	}
}

void ShowUserMenu::showCurrentPageNumber()
{
	cout << "Page " << currentPage_ << " of " << maxPages_ << endl;
}

void ShowUserMenu::showTooltip()
{
	cout << tooltip_ << endl;
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
			cout << "->" << items_.at(i) << endl;
			setTextColor(Color::LIGHT_CYAN);
		}
		else
		{
			cout << "  " << items_.at(i) << endl;
		}
	}
}

void ShowUserMenu::resetChoice()
{
	choice_ = ShowUserMenuAction::SHOW_OR_HIDE_PASSWORD;
}

ShowUserMenu::~ShowUserMenu() = default;