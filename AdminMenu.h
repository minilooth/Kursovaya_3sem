#ifndef ADMINMENU_H
#define ADMINMENU_H


#include "AccountManagementMenu.h"

namespace AdminMenuAction
{
	enum
	{
		ACCOUNT_MANAGEMENT = 1,
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
	AdminMenu(string& title, vector<string>& items);
    unsigned selectMode();
    void resetChoice();
	void showTitle();
    void showItems();
    ~AdminMenu();
};


#endif //ADMINMENU_H
