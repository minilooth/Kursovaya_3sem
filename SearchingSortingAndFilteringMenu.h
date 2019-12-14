#ifndef SEARCHINGSORTINGANDFILTERINGMENU_H
#define SEARCHINGSORTINGANDFILTERINGMENU_H


#include "AccountHandler.h"

#include "SearchingMenu.h"
#include "SortingMenu.h"
#include "FilteringMenu.h"


namespace menu
{

	/*namespace SearchingSortingAndFilteringMenuAction
	{
		enum
		{
			SEARCHING = 1,
			SORTING,
			FILTERING,
			BACK
		};
	}*/

	class SearchingSortingAndFilteringMenu : virtual public ConsoleMenu
	{
		ConsoleMenu* getNextMenu() override;
		static unsigned choice_;
	public:

		enum Action
		{
			SEARCHING = 1,
			SORTING,
			FILTERING,
			BACK
		};

		SearchingSortingAndFilteringMenu();
		SearchingSortingAndFilteringMenu(const string& title, const vector<string>& items);
		unsigned selectMode() override;
		void resetChoice() override;
		void showTitle() override;
		void showItems() override;
		~SearchingSortingAndFilteringMenu();
	};

}

#endif // SEARCHINGSORTINGANDFILTERINGMENU_H