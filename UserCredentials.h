#ifndef USERCREDENTIALS_H
#define USERCREDENTIALS_H


#include "Includes.h"
#include "AccountHandler.h"

using namespace std;


class UserCredentials
{
    string username_;
    string password_;
    bool adminAccess_;
public:
    UserCredentials();
	UserCredentials(string& username, string& password, bool& adminAccess);

    void setUsername(string username);
    void setPassword(string password);
    void setAdminAccess(bool adminAccess);

    string getUsername();
    string getPassword();
    bool getAdminAccess();

	friend ostream& operator<<(ostream& out, const UserCredentials& userCredentials);

    ~UserCredentials();
};


#endif //USERCREDENTIALS_H
