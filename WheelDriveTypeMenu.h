#ifndef WHEELDRIVETYPEMENU_H
#define WHEELDRIVETYPEMENU_H


#include "ConsoleMenu.h"

enum WheelDriveType
{
	FWD = 1,
	RWD,
	AWD
};

namespace menu
{

	class WheelDriveTypeMenu : virtual public ConsoleMenu
	{
		ConsoleMenu* getNextMenu() override;
		static unsigned choice_;
	public:
		WheelDriveTypeMenu();
		WheelDriveTypeMenu(const string& title, const vector<string>& items);
		unsigned selectMode() override;
		void resetChoice() override;
		void showTitle() override;
		void showItems() override;
		~WheelDriveTypeMenu();
	};

}

#endif // WHEELDRIVETYPEMENU_H