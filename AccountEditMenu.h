#ifndef ACCOUNTEDITMENU_H
#define ACCOUNTEDITMENU_H


#include "AdminMenu.h"
#include "AccountHandler.h"

namespace AccountEditMenuAction
{
	enum
	{
		EDIT_USERNAME = 1,
		EDIT_PASSWORD,
		EDIT_ADMIN_ACCESS,
		EDIT_BAN_STATUS,
		BACK
	};
}

class AccountEditMenu : virtual public ConsoleMenu
{
private:
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	AccountEditMenu();
	AccountEditMenu(const string& title, const vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~AccountEditMenu();
};


#endif //ACCOUNTEDITMENU_H