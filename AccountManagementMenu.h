#ifndef ACCOUNTMANAGEMENTMENU_H
#define ACCOUNTMANAGEMENTMENU_H


#include "LoginMenu.h"
#include "AccountShowMenu.h"
#include "AccountEditMenu.h"

namespace AccountManagementMenuAction
{
	enum
	{
		SHOW_ACCOUNTS = 1,
		ADD_ACCOUNT,
		DELETE_ACCOUNT,
		EDIT_ACCOUNT,
		BACK
	};
}

class AccountManagementMenu : virtual public ConsoleMenu
{
	ConsoleMenu* getNextMenu() override;
	static unsigned choice_;
public:
	AccountManagementMenu();
	AccountManagementMenu(const string& title, const vector<string>& items);
	unsigned selectMode() override;
	void resetChoice() override;
	void showTitle() override;
	void showItems() override;
	~AccountManagementMenu();
};


#endif //USERMANAGEMENTMENU_H
