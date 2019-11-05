#ifndef ADDUSERMENU_H
#define ADDUSERMENU_H

#include "ConsoleMenu.h"

namespace AddUserMenuChoice
{
	enum
	{
		GIVE_ADMIN_ACCESS = 1,
		DONT_GIVE_ADMIN_ACCESS
	};
}

class AddUserMenu : public virtual  ConsoleMenu
{
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	AddUserMenu();
	AddUserMenu(string& title, vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~AddUserMenu();
};


#endif //ADDUSERMENU_H