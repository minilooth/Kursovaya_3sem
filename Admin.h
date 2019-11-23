#ifndef ADMIN_H
#define ADMIN_H


#include "AccountHandler.h"

class Admin : public Account
{
public:
	Admin();
	Admin(string& username, string& password);
	Admin(Account& account);

	~Admin();
};


#endif // ADMIN_H