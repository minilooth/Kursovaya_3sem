#ifndef USER_H
#define USER_H


#include "AccountHandler.h"

class User : public Account
{
public:
	User();
	User(string& username, string& password, bool banStatus);
	User(Account& account);

	~User();
};


#endif // USER_H