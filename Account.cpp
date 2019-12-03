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
	/*out << "| " << setw(AccountPrinter::getUsernameLabelLength()) << left << account.username_
		<< " | " << setw(AccountPrinter::getPasswordLabelLength()) << left << makeMaskedString(account.password_)
		<< " | " << setw(12) << left << (account.adminAccess_ ? "Yes" : "No") << " |";*/

	out << "| " << setw(AccountPrinter::getUsernameLabelLength()) << left << account.username_
		<< " | " << setw(AccountPrinter::getPasswordLabelLength()) << left
		<< (AccountHandler::getShowPasswordStatus() ? account.password_ : makeMaskedString(account.password_))
		<< " | " << setw(AccountPrinter::getAdminAccessLabelLength()) << left << (account.adminAccess_ ? "Yes" : "No")
		<< " |";

	return out;
}

Account::~Account() = default;