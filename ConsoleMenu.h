#ifndef CONSOLEMENU_H
#define CONSOLEMENU_H


#include "Includes.h"

using namespace std;

namespace menu 
{

	class ConsoleMenu
	{
	protected:
		string title_;
		vector<string> items_;
	public:
		ConsoleMenu();
		virtual ConsoleMenu* getNextMenu() = 0;
		virtual unsigned selectMode() = 0;
		virtual void resetChoice() = 0;
		virtual void showTitle() = 0;
		virtual void showItems() = 0;
		virtual ~ConsoleMenu() = 0;
	};

}


#endif //CONSOLEMENU_H