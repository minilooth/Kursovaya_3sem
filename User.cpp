#include "User.h"

User::User()
{
	username_ = "";
	password_ = "";
	adminAccess_ = false;
}

User::User(string& username, string& password)
{
	username_ = username;
	password_ = password;
	adminAccess_ = false;
}

User::User(Account& account)
{
	username_ = account.getUsername();
	password_ = account.getPassword();
	adminAccess_ = false;
}

User::~User() = default;