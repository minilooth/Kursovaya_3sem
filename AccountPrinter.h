#ifndef ACCOUNTPRINTER_H
#define ACCOUNTPRINTER_H


#include "Includes.h"
#include "AccountHandler.h"

class AccountPrinter
{
	static unsigned usernameLabelLength_;
	static unsigned passwordLabelLength_;
	static unsigned adminAccessLabelLength_;
	static unsigned banStatusLabelLength_;

	static unsigned solidLineLength_;

	static unsigned calculateUsernameMaxLength();
	static unsigned calculatePasswordMaxLength();

	static void refresh();

	AccountPrinter();
public:
	static unsigned getUsernameLabelLength();
	static unsigned getPasswordLabelLength();
	static unsigned getAdminAccessLabelLength();
	static unsigned getBanStatusLabelLength();

	static unsigned getSolidLineLength();

	static void showHeader();

	~AccountPrinter();
};


#endif // ACCOUNTPRINTER_H