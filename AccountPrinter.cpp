#include "AccountPrinter.h"

unsigned AccountPrinter::usernameLabelLength_ = 0;
unsigned AccountPrinter::passwordLabelLength_ = 0;
unsigned AccountPrinter::adminAccessLabelLength_ = 0;
unsigned AccountPrinter::banStatusLabelLength_ = 0;

unsigned AccountPrinter::solidLineLength_ = 0;

AccountPrinter::AccountPrinter()
{
	usernameLabelLength_ = 0;
	passwordLabelLength_ = 0;
	adminAccessLabelLength_ = 0;
	banStatusLabelLength_ = 0;

	solidLineLength_ = 0;
}

void AccountPrinter::refresh()
{
	usernameLabelLength_ = calculateUsernameMaxLength() < 17 ? 16 : calculateUsernameMaxLength();
	passwordLabelLength_ = calculatePasswordMaxLength() < 7 ? 6 : calculatePasswordMaxLength();
	adminAccessLabelLength_ = 20;
	banStatusLabelLength_ = 17;

	solidLineLength_ = usernameLabelLength_ + passwordLabelLength_ + adminAccessLabelLength_ + banStatusLabelLength_ + 13;
}

unsigned AccountPrinter::calculateUsernameMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < AccountHandler::getAccounts().size(); i++)
	{
		if (length < AccountHandler::getAccounts().at(i).getUsername().length())
		{
			length = AccountHandler::getAccounts().at(i).getUsername().length();
		}
	}
	return length;
}

unsigned AccountPrinter::calculatePasswordMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < AccountHandler::getAccounts().size(); i++)
	{
		if (length < AccountHandler::getAccounts().at(i).getPassword().length())
		{
			length = AccountHandler::getAccounts().at(i).getPassword().length();
		}
	}
	return length;
}

unsigned AccountPrinter::getUsernameLabelLength()
{
	return usernameLabelLength_;
}

unsigned AccountPrinter::getPasswordLabelLength()
{
	return passwordLabelLength_;
}

unsigned AccountPrinter::getAdminAccessLabelLength()
{
	return adminAccessLabelLength_;
}

unsigned AccountPrinter::getBanStatusLabelLength()
{
	return banStatusLabelLength_;
}

unsigned AccountPrinter::getSolidLineLength()
{
	return solidLineLength_;
}

void AccountPrinter::showHeader()
{
	refresh();

	drawSolidLine(solidLineLength_);

	cout <<  "| " << makeCenteredString("Имя пользователя", usernameLabelLength_)
		 << " | " << makeCenteredString("Пароль", passwordLabelLength_)
		 << " | " << "Права администратора" 
		 << " | " << "Статус блокировки"
		 << " |"  << endl;

	drawSolidLine(solidLineLength_);
}

void AccountPrinter::showAccounts(const vector<Account>& accounts)
{
	showHeader();
	for(auto& i : accounts)
	{
		cout << i << endl;
	}
	drawSolidLine(solidLineLength_);
}

AccountPrinter::~AccountPrinter() = default;