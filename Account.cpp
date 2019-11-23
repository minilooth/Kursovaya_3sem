#include "AccountHandler.h"

Account::Account()
{
	username_ = "";
	password_ = "";
	adminAccess_ = false;
}

Account::Account(string& username, string& password, bool adminAccess)
{
	username_ = username;
	password_ = password;
	adminAccess_ = adminAccess;
}

//Account::Account(Account& account)
//{
//	username_ = account.username_;
//	password_ = account.password_;
//	adminAccess_ = account.adminAccess_;
//}

void Account::setUsername(string& username)
{
    username_ = username;
};

void Account::setPassword(string& password)
{
    password_ = password;
}

string Account::getUsername()
{
    return username_;
}

string Account::getPassword()
{
    return password_;
}

bool Account::getAdminAccess()
{
    return adminAccess_;
}

ostream& operator<<(ostream& out, const Account& account)
{
	out << "| " << setw(AccountHandler::calculateUsernameMaxLength() < 9 ? 8 : AccountHandler::calculateUsernameMaxLength()) << left << account.username_
		<< " | " << setw(AccountHandler::calculatePasswordMaxLength() < 9 ? 8 : AccountHandler::calculatePasswordMaxLength()) << left << makeMaskedString(account.password_)
		<< " | " << setw(12) << left << (account.adminAccess_ ? "Yes" : "No") << " |";

	return out;
}

Account::~Account() = default;