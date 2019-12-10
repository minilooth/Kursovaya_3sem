#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H


#include "ItemSelection.h"
#include "AccountEditMenu.h"
#include "AccountTypeMenu.h"

#include "Account.h"
#include "Admin.h"
#include "User.h"

#include "AccountPrinter.h"

#include "StatisticsHandler.h"

using namespace std;

const unsigned passwordLengthInputLimit = 20;
const unsigned usernameLengthInputLimit = 20;

class AccountHandler
{
public:
	// Constructors
    AccountHandler();
	explicit AccountHandler(const string& fileName);

	// Find
	static bool findUser(const string& username);

	// Gets
    static Account* getAccount(const string& username);
	static Account* getAccount(unsigned index);
	static Account* getCurrentAccount();
	static vector<Account> getAccounts();
	static vector<Account> getAccounts(unsigned from, unsigned to);
	static vector<Account> getUsers();
	static unsigned getAccountIndex(const string& username);
	static unsigned getAccountIndex(const Account& account);
	static bool getShowPasswordStatus();
	static bool getAdminAccessStatus();

	// Count
	static unsigned countAccounts();
	static unsigned countAdmins();
	static unsigned countNotBannedAdmins();
	static unsigned countBannedAdmins();
	static unsigned countUsers();

	// Sets
	static void setAdminAccessStatus(bool adminAccessStatus);
	static void setShowPasswordStatus(bool showPasswordStatus);

	// Change
	static void invertShowPasswordStatus();
	static void resetShowPasswordStatus();
	static void resetAccountToEdit();
	static void resetCurrentAccount();

	// Edit
	static void editUsername();
	static void editPassword();
	static void editAdminAccess();
	static void editBanStatus();

	// Functional
	static bool auth();
	static void registration();
    static void showAccounts();
	static void showAccounts(unsigned from, unsigned to);
	static void showEditAccount();
    static void addAccount();
	static void deleteAccount();
	static void editAccount();
	static void showCurrentAccountStatistics();
	static void showTotalStatistics();

	// Destructors
    ~AccountHandler();
private:
	static vector<Account> accounts_;
	static bool showPasswordStatus_;
	static bool adminAccessStatus_;
	static Account* accountToEdit_;
	static Account* currentAccount_;

	// Files
	static void rewriteAccountsFile();
};


#endif //ACCOUNTHANDLER_H
