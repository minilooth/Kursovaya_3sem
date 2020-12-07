#ifndef ADMIN_H
#define ADMIN_H


#include "AccountHandler.h"


	class Admin : public Account
	{
	public:
		Admin();
		Admin(const string& username, const string& password, bool banStatus);
		explicit Admin(Account& account);

		~Admin();
	};



#endif // ADMIN_H