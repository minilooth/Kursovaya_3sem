#ifndef TRANSMISSIONTYPEMENU_H
#define TRANSMISSIONTYPEMENU_H


#include "ConsoleMenu.h"

enum TransmissionType
{
	MANUAL = 1,
	AUTOMATIC
};

namespace menu
{

	class TransmissionTypeMenu : virtual public ConsoleMenu
	{
		ConsoleMenu* getNextMenu() override;
		static unsigned choice_;
	public:
		TransmissionTypeMenu();
		TransmissionTypeMenu(const string& title, const vector<string>& items);
		unsigned selectMode() override;
		void resetChoice() override;
		void showTitle() override;
		void showItems() override;
		~TransmissionTypeMenu();
	};

}


#endif // TRANSMISSIONTYPEMENU_H