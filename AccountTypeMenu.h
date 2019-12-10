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
	ConsoleMenu* getNextMenu() override;
	static unsigned choice_;
public:
	AccountTypeMenu();
	AccountTypeMenu(const string& title, const vector<string>& items);
	unsigned selectMode() override;
	void resetChoice() override;
	void showTitle() override;
	void showItems() override;
	~AccountTypeMenu();
};


#endif // ACCOUNTTYPEMENU_H