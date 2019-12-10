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
    ConsoleMenu* getNextMenu() override;
    static unsigned choice_;
public:
    LoginMenu();
	LoginMenu(const string& title, const vector<string>& items);
    unsigned selectMode() override;
    void resetChoice() override;
	void showTitle() override;
    void showItems() override;
    ~LoginMenu();
};




#endif //LOGINMENU_H
