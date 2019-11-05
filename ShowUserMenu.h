#ifndef SHOWUSERMENU_H
#define SHOWUSERMENU_H


#include "AccountHandler.h"
#include "AdminMenu.h"

namespace ShowUserMenuAction
{
	enum
	{
		SHOW_OR_HIDE_PASSWORD = 1,
		BACK
	};
}

class ShowUserMenu : virtual public ConsoleMenu
{
private:
	ConsoleMenu* getNextMenu();
	string tooltip_;
	static unsigned choice_;
	static unsigned currentPage_;
	static unsigned maxPages_;
public:
	ShowUserMenu();
	ShowUserMenu(string& title, vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	static void resetMaxPages();
	static void resetCurrentPage();
	static void nextPage();
	static void previousPage();
	void showCurrentPageNumber();
	void showTooltip();
	void showTitle();
	void showItems();
	~ShowUserMenu();
};


#endif //SHOWUSERMENU_H