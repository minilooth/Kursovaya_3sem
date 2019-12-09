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
	Account(string& username, string& password, bool adminAccess, bool banStatus);

    void setUsername(string& username);
    void setPassword(string& password);
	void setBanStatus(bool banStatus);

    string getUsername();
    string getPassword();
    bool getAdminAccess();
	bool getBanStatus();

	friend ostream& operator<<(ostream& out, const Account& account);

    ~Account();
};


#endif //ACCOUNT_H
