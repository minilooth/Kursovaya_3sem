#ifndef ACCOUNT_H
#define ACCOUNT_H


#include "AccountHandler.h"

using namespace std;

	class Account
	{
	protected:
		string username_;
		string password_;
		bool adminAccess_;
		bool banStatus_;
	public:
		Account();
		Account(const string& username, const string& password, bool adminAccess, bool banStatus);

		void setUsername(const string& username);
		void setPassword(const string& password);
		void setBanStatus(bool banStatus);

		string getUsername() const;
		string getPassword() const;
		bool getAdminAccess() const;
		bool getBanStatus() const;

		friend ostream& operator<<(ostream& out, const Account& account);

		~Account();
	};



#endif //ACCOUNT_H
