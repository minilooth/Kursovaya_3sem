#include "Includes.h"
#include "LoginMenu.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setConsoleMaxWidth();

    system("color 0B");
	
	account::StatisticsHandler* statisticsHandler = new account::StatisticsHandler();
	car::CarHandler* carHandler = new car::CarHandler();
    account::AccountHandler *accountHandler = new account::AccountHandler();
    menu::ConsoleMenu *currentMenu = new menu::LoginMenu();

	showConsoleCursor(false);

    while(currentMenu)
    {
        currentMenu = currentMenu->getNextMenu();
    }

	delete accountHandler;
	delete carHandler;
	delete currentMenu;

    return 0;
}