#include "Includes.h"
#include "LoginMenu.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setConsoleMaxWidth();

    system("color 0B");
	
	StatisticsHandler* statisticsHandler = new StatisticsHandler();
	CarHandler* carHandler = new CarHandler();
    AccountHandler *accountHandler = new AccountHandler();
    ConsoleMenu *currentMenu = new LoginMenu();

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