#include "Includes.h"
#include "LoginMenu.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    system("color 0B");

	CarHandler* carHandler = new CarHandler();
    AccountHandler *accountHandler = new AccountHandler();
    ConsoleMenu *currentMenu = new LoginMenu();

    while(currentMenu)
    {
        currentMenu = currentMenu->getNextMenu();
    }

    system("pause");

	delete accountHandler;
	delete carHandler;
	delete currentMenu;

    return 0;
}