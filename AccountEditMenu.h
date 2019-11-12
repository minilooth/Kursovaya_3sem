#ifndef ACCOUNTEDITMENU_H
#define ACCOUNTEDITMENU_H


#include "AdminMenu.h"
#include "AccountHandler.h"

namespace AccountEditMenuAction
{
	enum
	{
		CHANGE_USERNAME = 1,
		CHANGE_PASSWORD,
		CHANGE_ADMIN_ACCESS,
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
	AccountEditMenu(string& title, vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~AccountEditMenu();
};


#endif //ACCOUNTEDITMENU_H