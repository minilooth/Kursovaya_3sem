#ifndef EDITUSERMENU_H
#define EDITUSERMENU_H


#include "AdminMenu.h"
#include "AccountHandler.h"

namespace EditUserMenuAction
{
	enum
	{
		CHANGE_USERNAME = 1,
		CHANGE_PASSWORD,
		CHANGE_ADMIN_ACCESS,
		BACK
	};
}

class EditUserMenu : virtual public ConsoleMenu
{
private:
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	EditUserMenu();
	EditUserMenu(string& title, vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~EditUserMenu();
};


#endif //EDITUSERMENU_H