#ifndef ACCOUNTADDMENU_H
#define ACCOUNTADDMENU_H

#include "ConsoleMenu.h"

namespace AccountAddMenuChoice
{
	enum
	{
		GIVE_ADMIN_ACCESS = 1,
		DONT_GIVE_ADMIN_ACCESS
	};
}

class AccountAddMenu : public virtual  ConsoleMenu
{
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	AccountAddMenu();
	AccountAddMenu(string& title, vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~AccountAddMenu();
};


#endif //ACCOUNTADDMENU_H