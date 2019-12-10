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
	ConsoleMenu* getNextMenu() override;
	string tooltip_;
	unsigned pageSize_;
	static unsigned choice_;
	static unsigned currentPage_;
	static unsigned maxPages_;
public:
	AccountShowMenu();
	AccountShowMenu(const string& title, const vector<string>& items, const string& tooltip, unsigned pageSize);
	unsigned selectMode() override;
	void resetChoice() override;
	static void resetMaxPages();
	static void resetCurrentPage();
	static void nextPage();
	static void previousPage();
	static void showCurrentPageNumber();
	void showTooltip() const;
	void showTitle() override;
	void showItems() override;
	~AccountShowMenu();
};


#endif //ACCOUNTSHOWMENU_H