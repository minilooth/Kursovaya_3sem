#ifndef ACCOUNTTYPEMENU_H
#define ACCOUNTTYPEMENU_H


#include "ConsoleMenu.h"


enum AccountType
{
	ADMIN = 1,
	USER
};


class AccountTypeMenu : virtual public ConsoleMenu
{
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	AccountTypeMenu();
	AccountTypeMenu(string& title, vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~AccountTypeMenu();
};


#endif // ACCOUNTTYPEMENU_H