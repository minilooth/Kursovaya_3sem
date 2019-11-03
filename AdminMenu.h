#ifndef ADMINMENU_H
#define ADMINMENU_H


#include "UserManagementMenu.h"

namespace AdminMenuAction
{
	enum
	{
		USER_MANAGEMENT = 1,
		BACK
	};
}

class AdminMenu : virtual public ConsoleMenu
{
private:
    ConsoleMenu* getNextMenu();
    static unsigned choice_;
public:
    AdminMenu();
    unsigned selectMode();
    void resetChoice();
	void showTitle();
    void showItems();
    ~AdminMenu();
};


#endif //ADMINMENU_H
