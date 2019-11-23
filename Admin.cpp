#include "Admin.h"

Admin::Admin()
{
	username_ = "";
	password_ = "";
	adminAccess_ = true;
}

Admin::Admin(string& username, string& password)
{
	username_ = username;
	password_ = password;
	adminAccess_ = true;
}

Admin::Admin(Account& account)
{
	username_ = account.getUsername();
	password_ = account.getPassword();
	adminAccess_ = true;
}

Admin::~Admin() = default;