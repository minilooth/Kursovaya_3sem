#ifndef LOGINMENU_H
#define LOGINMENU_H


#include "AccountHandler.h"
#include "AdminMenu.h"
#include "UserMenu.h"

namespace LoginMenuAction
{
	enum
	{
		BY_USER = 1,
		BY_ADMIN,
		REGISTRATION,
		QUIT
	};
}

class LoginMenu : virtual public ConsoleMenu
{
private:
    ConsoleMenu* getNextMenu();
    static unsigned choice_;
public:
    LoginMenu();
	LoginMenu(string& title, vector<string>& items);
    unsigned selectMode();
    void resetChoice();
	void showTitle();
    void showItems();
    ~LoginMenu();
};




#endif //LOGINMENU_H
