#ifndef ACCOUNTMANAGEMENTMENU_H
#define ACCOUNTMANAGEMENTMENU_H


#include "LoginMenu.h"
#include "AccountShowMenu.h"
#include "AccountEditMenu.h"

namespace menu
{

	class AccountManagementMenu : virtual public ConsoleMenu
	{
		ConsoleMenu* getNextMenu() override;
		static unsigned choice_;
	public:

		enum Action
		{
			SHOW_ACCOUNTS = 1,
			ADD_ACCOUNT,
			DELETE_ACCOUNT,
			EDIT_ACCOUNT,
			BACK
		};

		AccountManagementMenu();
		AccountManagementMenu(const string& title, const vector<string>& items);
		unsigned selectMode() override;
		void resetChoice() override;
		void showTitle() override;
		void showItems() override;
		~AccountManagementMenu();
	};

}


#endif //USERMANAGEMENTMENU_H
