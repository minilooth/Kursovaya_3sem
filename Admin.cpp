#include "Admin.h"

Admin::Admin()
{
	username_ = "";
	password_ = "";
	adminAccess_ = true;
	banStatus_ = false;
}

Admin::Admin(const string& username, const string& password, bool banStatus)
{
	username_ = username;
	password_ = password;
	adminAccess_ = true;
	banStatus_ = banStatus;
}

Admin::Admin(Account& account)
{
	username_ = account.getUsername();
	password_ = account.getPassword();
	adminAccess_ = true;
	banStatus_ = account.getBanStatus();
}

Admin::~Admin() = default;