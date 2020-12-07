#ifndef USER_H
#define USER_H


#include "AccountHandler.h"



	class User : public Account
	{
	public:
		User();
		User(const string& username, const string& password, bool banStatus);
		explicit User(Account& account);

		~User();
	};



#endif // USER_H