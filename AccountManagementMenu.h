#ifndef ACCOUNTMANAGEMENTMENU_H
#define ACCOUNTMANAGEMENTMENU_H


#include "LoginMenu.h"
#include "AccountShowMenu.h"
#include "AccountEditMenu.h"

namespace AccountManagementMenuAction
{
	enum
	{
		ACCOUNTS_SHOW = 1,
		ACCOUNT_ADD,
		ACCOUNT_DELETE,
		ACCOUNT_EDIT,
		BACK
	};
}

class AccountManagementMenu : virtual public ConsoleMenu
{
private:
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	AccountManagementMenu();
	AccountManagementMenu(string& title, vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~AccountManagementMenu();
};


#endif //USERMANAGEMENTMENU_H
