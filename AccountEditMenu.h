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
	ConsoleMenu* getNextMenu() override;
	static unsigned choice_;
public:
	AccountEditMenu();
	AccountEditMenu(const string& title, const vector<string>& items);
	unsigned selectMode() override;
	void resetChoice() override;
	void showTitle() override;
	void showItems() override;
	~AccountEditMenu();
};


#endif //ACCOUNTEDITMENU_H