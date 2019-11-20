#ifndef BODYTYPEMENU_H
#define BODYTYPEMENU_H


#include "ConsoleMenu.h"

enum BodyType
{
	CROSSOVER = 1,
	CABRIOLET,
	FIVE_DOOR_HATCHBACK,
	FIVE_SEAT_MINIVAN,
	FOUR_DOOR_COUPE,
	LONG_WHEEL_BASE_SEDAN,
	SEDAN,
	SEVEN_SEAT_MINIVAN,
	STATION_WAGON,
	THREE_DOOR_HATCHBACK,
	TWO_DOOR_COUPE
};

class BodyTypeMenu : virtual public ConsoleMenu
{
private:
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	BodyTypeMenu();
	BodyTypeMenu(string& title, vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~BodyTypeMenu();
};


#endif // BODYTYPEMENU_H