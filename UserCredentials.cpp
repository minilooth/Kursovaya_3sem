#include "AccountHandler.h"

UserCredentials::UserCredentials() = default;

UserCredentials::UserCredentials(string& username, string& password, bool& adminAccess)
{
	username_ = username;
	password_ = password;
	adminAccess_ = adminAccess;
}

void UserCredentials::setUsername(string username)
{
    username_ = username;
};

void UserCredentials::setPassword(string password)
{
    password_ = password;
}

void UserCredentials::setAdminAccess(bool adminAccess)
{
    adminAccess_ = adminAccess;
}

string UserCredentials::getUsername()
{
    return username_;
}

string UserCredentials::getPassword()
{
    return password_;
}

bool UserCredentials::getAdminAccess()
{
    return adminAccess_;
}

ostream& operator<<(ostream& out, const UserCredentials& userCredentials)
{
	out << "| " << setw(AccountHandler::calculateUsernameMaxLength() < 9 ? 8 : AccountHandler::calculateUsernameMaxLength()) << left << userCredentials.username_
		<< " | " << setw(AccountHandler::calculatePasswordMaxLength() < 9 ? 8 : AccountHandler::calculatePasswordMaxLength()) << left << makeMaskedString(userCredentials.password_)
		<< " | " << setw(12) << left << (userCredentials.adminAccess_ ? "Yes" : "No") << " |";

	return out;
}

UserCredentials::~UserCredentials() = default;