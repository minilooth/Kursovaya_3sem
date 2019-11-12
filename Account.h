#ifndef ACCOUNT_H
#define ACCOUNT_H


#include "AccountHandler.h"

using namespace std;

class Account
{
    string username_;
    string password_;
    bool adminAccess_;
public:
    Account();
	Account(string& username, string& password, bool adminAccess);

    void setUsername(string& username);
    void setPassword(string& password);
    void setAdminAccess(bool adminAccess);

    string getUsername();
    string getPassword();
    bool getAdminAccess();

	friend ostream& operator<<(ostream& out, const Account& account);

    ~Account();
};


#endif //ACCOUNT_H
