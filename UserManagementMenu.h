#ifndef USERMANAGEMENTMENU_H
#define USERMANAGEMENTMENU_H


#include "ConsoleMenu.h"
#include "LoginMenu.h"
#include "ShowUserMenu.h"
#include "EditUserMenu.h"

namespace UserManagementMenuAction
{
	enum
	{
		SHOW_USERS = 1,
		ADD_USER,
		DELETE_USER,
		EDIT_USER,
		BACK
	};
}

class UserManagementMenu : virtual public ConsoleMenu
{
private:
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	UserManagementMenu();
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~UserManagementMenu();
};


#endif //USERMANAGEMENTMENU_H
