#include "AccountHandler.h"

using namespace account;

Account::Account()
{
	username_ = "";
	password_ = "";
	adminAccess_ = false;
	banStatus_ = false;
}

Account::Account(const string& username, const string& password, bool adminAccess, bool banStatus)
{
	username_ = username;
	password_ = password;
	adminAccess_ = adminAccess;
	banStatus_ = banStatus;
}

void Account::setUsername(const string& username)
{
    username_ = username;
};

void Account::setPassword(const string& password)
{
    password_ = password;
}

void Account::setBanStatus(bool banStatus)
{
	banStatus_ = banStatus;
}

string Account::getUsername() const
{
    return username_;
}

string Account::getPassword() const
{
    return password_;
}

bool Account::getAdminAccess() const
{
    return adminAccess_;
}

bool Account::getBanStatus() const
{
	return banStatus_;
}

ostream& account::operator<<(ostream& out, const Account& account)
{
	out << "| " << setw(AccountPrinter::getUsernameLabelLength()) << left << account.username_
		<< " | " << setw(AccountPrinter::getPasswordLabelLength()) << left
		<< (AccountHandler::getShowPasswordStatus() ? account.password_ : makeMaskedString(account.password_))
		<< " | " << setw(AccountPrinter::getAdminAccessLabelLength()) << left << (account.adminAccess_ ? "Да" : "Нет")
		<< " | " << setw(AccountPrinter::getBanStatusLabelLength()) << left << (account.banStatus_ ? "Да" : "Нет")
		<< " |";

	return out;
}

Account::~Account() = default;