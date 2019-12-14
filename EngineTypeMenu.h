#ifndef ENGINETYPEMENU_H
#define ENGINETYPEMENU_H


#include "ConsoleMenu.h"

enum EngineType
{
	PETROL = 1,
	DIESEL
};


namespace menu
{

	class EngineTypeMenu : virtual public ConsoleMenu
	{
		ConsoleMenu* getNextMenu() override;
		static unsigned choice_;
	public:
		EngineTypeMenu();
		EngineTypeMenu(const string& title, const vector<string>& items);
		unsigned selectMode() override;
		void resetChoice() override;
		void showTitle() override;
		void showItems() override;
		~EngineTypeMenu();
	};

}


#endif // ENGINETYPEMENU_H