#ifndef USERMENU_H
#define USERMENU_H


#include "ConsoleMenu.h"
#include "LoginMenu.h"

namespace UserMenuAction
{
	enum
	{
		NOTHING1 = 1,
		NOTHING2,
		BACK
	};
}

class UserMenu : virtual public ConsoleMenu
{
private:
    ConsoleMenu* getNextMenu();
    static unsigned choice_;
public:
    UserMenu();
	UserMenu(string& title, vector<string>& items);
    unsigned selectMode();
    void resetChoice();
	void showTitle();
    void showItems();
    ~UserMenu();
};


#endif //USERMENU_H
