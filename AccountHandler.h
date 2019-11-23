#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H


#include "ItemSelection.h"
#include "AccountAddMenu.h"
#include "AccountEditMenu.h"
#include "AccountTypeMenu.h"

#include "Account.h"
#include "Admin.h"
#include "User.h"

using namespace std;

class AccountHandler
{
public:
	// Constructors
    AccountHandler();
	AccountHandler(string fileName);

	// Find
	static bool findUser(string& username);

	// Gets
    static Account* getAccount(string &username);
	static Account* getAccount(unsigned index);
	static unsigned getAccountIndex(string& username);
	static unsigned getAccountIndex(Account& account);
	static bool getShowPasswordStatus();
	static bool getAdminAccessStatus();

	// Calculate
	static unsigned calculatePasswordMaxLength();
	static unsigned calculateUsernameMaxLength();

	// Count
	static unsigned countAccounts();
	static unsigned countAdmins();
	static unsigned countUsers();

	// Sets
	static void setAdminAccessStatus(bool adminAccessStatus);
	static void setShowPasswordStatus(bool showPasswordStatus);

	// Change
	static void resetShowPasswordStatus();
	static void invertShowPasswordStatus();
	static void resetAccountToEdit();
	static void inputNewUsername();
	static void inputNewPassword();
	static void changeAdminAccess();

	// Functional
	static bool auth();
	static void registration();
    static void showAccounts();
	static void showAccounts(unsigned from, unsigned to);
	static void showEditAccount();
    static void addAccount();
	static void deleteAccount();
	static void editAccount();

	// Destructors
    ~AccountHandler();
private:
	static vector<Account> accounts_;
	static bool showPasswordStatus_;
	static bool adminAccessStatus_;
	static Account* accountToEdit_;
	const static unsigned passwordLengthInputLimit = 20;
	const static unsigned usernameLengthInputLimit = 20;
};


#endif //ACCOUNTHANDLER_H
