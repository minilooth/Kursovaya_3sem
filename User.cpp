#include "User.h"

User::User()
{
	username_ = "";
	password_ = "";
	adminAccess_ = false;
	banStatus_ = false;
}

User::User(string& username, string& password, bool banStatus)
{
	username_ = username;
	password_ = password;
	adminAccess_ = false;
	banStatus_ = banStatus;
}

User::User(Account& account)
{
	username_ = account.getUsername();
	password_ = account.getPassword();
	adminAccess_ = false;
	banStatus_ = account.getBanStatus();
}

User::~User() = default;