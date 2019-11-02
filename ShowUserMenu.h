#ifndef SHOWUSERMENU_H
#define SHOWUSERMENU_H


#include "AccountHandler.h"
#include "AdminMenu.h"

namespace ShowUserMenuAction
{
	enum
	{
		SHOW_OR_HIDE_PASSWORD = 1,
		BACK
	};
}

class ShowUserMenu : virtual public ConsoleMenu
{
private:
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	ShowUserMenu();
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~ShowUserMenu();
};


#endif //SHOWUSERMENU_H