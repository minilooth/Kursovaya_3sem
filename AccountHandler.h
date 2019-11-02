#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H


#include "AddUserMenu.h"
#include "UserCredentials.h"
#include "EditUserMenu.h"

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
    static UserCredentials* getUserCredentials(string &username);
	static UserCredentials* getUserCredentials(unsigned index);
	static unsigned getUser(string& username);
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
	static void resetUserToEdit();
	static void inputNewUsername();
	static void inputNewPassword();
	static void changeAdminAccess();

	// Functional
	static bool auth();
    static void showUsers();
	static void showEditUser();
    static void addUser();
	static void deleteUser();
	static void editUser();

	// Destructors
    ~AccountHandler();
private:
	static vector<UserCredentials> users_;
	static bool showPasswordStatus_;
	static bool adminAccessStatus_;
	static UserCredentials* userToEdit_;
	const static unsigned passwordLengthInputLimit = 20;
	const static unsigned usernameLengthInputLimit = 20;
};


#endif //ACCOUNTHANDLER_H
