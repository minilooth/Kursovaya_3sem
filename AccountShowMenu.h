#ifndef ACCOUNTSHOWMENU_H
#define ACCOUNTSHOWMENU_H


#include "AccountHandler.h"
#include "AdminMenu.h"

namespace AccountShowMenuAction
{
	enum
	{
		SHOW_OR_HIDE_PASSWORD = 1,
		BACK
	};
}

class AccountShowMenu : virtual public ConsoleMenu
{
private:
	ConsoleMenu* getNextMenu();
	string tooltip_;
	unsigned pageSize_;
	static unsigned choice_;
	static unsigned currentPage_;
	static unsigned maxPages_;
public:
	AccountShowMenu();
	AccountShowMenu(string& title, vector<string>& items, string& tooltip, unsigned pageSize);
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
	~AccountShowMenu();
};


#endif //ACCOUNTSHOWMENU_H