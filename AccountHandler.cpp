#include "AccountHandler.h"

// Static initialization
vector<Account> AccountHandler::accounts_;
bool AccountHandler::showPasswordStatus_ = false;
bool AccountHandler::adminAccessStatus_ = false;
Account* AccountHandler::accountToEdit_;
Account* AccountHandler::currentAccount_;

// Constructors
AccountHandler::AccountHandler()
{
	string token;

	string username;
	string password;
	bool adminAccess;

	Account* account = nullptr;

	ifstream accountsFile;

	accountsFile.open(R"(accounts.txt)");

	if (accountsFile.is_open())
	{
		while (!accountsFile.eof())
		{
			if (getline(accountsFile, token, '\n'))
			{
				auto data = stringSplitter(token);

				username = data.at(0);
				password = data.at(1);
				adminAccess = data.at(2) == "1" ? true : false;

				if (adminAccess == true)
				{
					account = new Admin(username, password);
				}
				else
				{
					account = new User(username, password);
				}

				accounts_.push_back(*account);
			}
		}
		accountsFile.close();
		delete account;
	}
}

AccountHandler::AccountHandler(string fileName)
{
	string token;

	string username;
	string password;
	bool adminAccess;

	Account* account = nullptr;

	ifstream accountsFile;

	accountsFile.open(fileName);

	if (accountsFile.is_open())
	{
		while (!accountsFile.eof())
		{
			if (getline(accountsFile, token, '\n'))
			{
				auto data = stringSplitter(token);

				username = data.at(0);
				password = data.at(1);
				adminAccess = data.at(2) == "1" ? true : false;

				if (adminAccess == true)
				{
					account = new Admin(username, password);
				}
				else
				{
					account = new User(username, password);
				}

				accounts_.push_back(*account);
			}
		}
		accountsFile.close();
		delete account;
	}
}

// Files
void AccountHandler::rewriteAccountsFile()
{
	ofstream accountsFile;

	accountsFile.open(R"(accounts.txt)", ios::trunc);
	if (accountsFile.is_open())
	{
		for (unsigned i = 0; i < accounts_.size(); i++)
		{
			accountsFile << accounts_.at(i).getUsername() << ";"
						 << accounts_.at(i).getPassword() << ";"
						 << accounts_.at(i).getAdminAccess()
						 << endl;
		}
		accountsFile.close();
	}
	else
	{
		throw exception("Cannot open accounts file!");
	}
}

// Find
bool AccountHandler::findUser(string &username)
{
    for (unsigned i = 0; i < accounts_.size(); i++)
    {
        if (accounts_.at(i).getUsername() == username)
        {
            return true;
        }
    }
    return false;
}

// Gets
vector<Account> AccountHandler::getAccounts()
{
	return accounts_;
}

vector<Account> AccountHandler::getUsers()
{
	vector<Account> users;
	for (unsigned i = 0; i < accounts_.size(); i++)
	{
		if (accounts_.at(i).getAdminAccess() == false)
		{
			users.push_back(accounts_.at(i));
		}
	}
	return users;
}

Account* AccountHandler::getCurrentAccount()
{
	return currentAccount_;
}

Account* AccountHandler::getAccount(string &username)
{
    Account* account = nullptr;

    for (unsigned i = 0; i < accounts_.size(); i++)
    {
        if (accounts_.at(i).getUsername() == username)
        {
            account = &(accounts_.at(i));
        }
    }

    return account;
}

Account* AccountHandler::getAccount(unsigned index)
{
	return &(accounts_.at(index));
}

unsigned AccountHandler::getAccountIndex(string& username)
{
	unsigned index = 0;
	for (unsigned i = 0; i < accounts_.size(); i++)
	{
		if (accounts_.at(i).getUsername() == username)
		{
			index = i;
			break;
		}
	}
	return index;
}

unsigned AccountHandler::getAccountIndex(Account& account)
{
	unsigned index = 0;
	for (unsigned i = 0; i < accounts_.size(); i++)
	{
		if (accounts_.at(i).getUsername() == account.getUsername())
		{
			index = i;
			break;
		}
	}
	return index;
}

bool AccountHandler::getShowPasswordStatus()
{
	return showPasswordStatus_;
}

bool AccountHandler::getAdminAccessStatus()
{
	return adminAccessStatus_;
}

// Count
unsigned AccountHandler::countAccounts()
{
	return accounts_.size();
}

unsigned AccountHandler::countAdmins()
{
	unsigned counter = 0;
	for (unsigned i = 0; i < accounts_.size(); i++)
	{
		if (accounts_.at(i).getAdminAccess())
		{
			counter++;
		}
	}
	return counter;
}

unsigned AccountHandler::countUsers()
{
	unsigned counter = 0;
	for (unsigned i = 0; i < accounts_.size(); i++)
	{
		if (!(accounts_.at(i).getAdminAccess()))
		{
			counter++;
		}
	}
	return counter;
}

// Sets
void AccountHandler::setAdminAccessStatus(bool adminAccessStatus)
{
	adminAccessStatus_ = adminAccessStatus;
}

void AccountHandler::setShowPasswordStatus(bool showPasswordStatus)
{
	showPasswordStatus_ = showPasswordStatus;
}

// Change
void AccountHandler::invertShowPasswordStatus()
{
	showPasswordStatus_ = !showPasswordStatus_;
}

void AccountHandler::resetShowPasswordStatus()
{
	showPasswordStatus_ = false;
}

void AccountHandler::resetAccountToEdit()
{
	accountToEdit_ = nullptr;
}

void AccountHandler::resetCurrentAccount()
{
	currentAccount_ = nullptr;
}

// Edit
void AccountHandler::editUsername()
{
	string username;

	try
	{
		if (accountToEdit_ == nullptr)
		{
			throw exception("Account to edit not setted up!");
		}

		system("cls");

		showEditAccount();

		cout << endl << "Enter new username: ";
		if (limitedInput(username, usernameLengthInputLimit) == false)
		{
			return;
		}

		if (findUser(username))
		{
			throw exception("User is already exists!");
		}
		if (username.length() < 3)
		{
			throw exception("Username should be at least three characters long!");
		}
		if (username.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("Username should only consists of letters and digits!");
		}

		CarHandler::editReservedCarsReserverUsername(accountToEdit_->getUsername(), username);

		accountToEdit_->setUsername(username);

		system("cls");

		showEditAccount();

		rewriteAccountsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "Username succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditAccount();

		setTextColor(Color::RED);
		cout << endl << ex.what() << endl;
		cout << "Username not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void AccountHandler::editPassword()
{
	string password;

	try
	{
		if (accountToEdit_ == nullptr)
		{
			throw exception("Account to edit not setted up!");
		}

		system("cls");

		showEditAccount();

		cout << endl << "Enter new password: ";
		if (maskedPasswordInput(password, passwordLengthInputLimit) == false)
		{
			return;
		}

		if (password.length() < 3)
		{
			throw exception("Password should be at least three characters long!");
		}
		if (password.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("Password should only consists of letters and digits!");
		}

		accountToEdit_->setPassword(password);

		system("cls");

		showEditAccount();

		rewriteAccountsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "Password succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditAccount();

		setTextColor(Color::RED);
		cout << endl << ex.what() << endl;
		cout << "Password not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void AccountHandler::editAdminAccess()
{
	unsigned index = 0;

	try
	{
		if (accountToEdit_ == nullptr)
		{
			throw exception("Account to edit not setted up!");
		}

		system("cls");

		showEditAccount();

		if (accountToEdit_->getAdminAccess() == true && countAdmins() < 2)
		{
			throw exception("Unable to change admin access of last admin!");
		}
	
		if (accountToEdit_->getAdminAccess() == true)
		{
			CarHandler::resetReservedCarsByUsername(accountToEdit_->getUsername());
			accountToEdit_ = new User(*accountToEdit_);
		}
		else
		{
			accountToEdit_ = new Admin(*accountToEdit_);
		}

		index = getAccountIndex(*accountToEdit_);
		accounts_.erase(accounts_.begin() + index);
		accounts_.insert(accounts_.begin() + index, *accountToEdit_);
		accountToEdit_ = getAccount(index);

		system("cls");

		showEditAccount();

		rewriteAccountsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "Admin access succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception& ex)
	{
		system("cls");

		showEditAccount();

		setTextColor(Color::RED);
		cout << endl << ex.what() << endl;
		cout << "Admin access not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

// Functional
bool AccountHandler::auth()
{
	string username;
	string password;

	int passwordAttempts = 0;

	bool isPasswordCorrect = false;
	
    Account* account = nullptr;

    system("cls");

	try
	{
		cout << "Username: ";
		if (limitedInput(username, usernameLengthInputLimit) == false)
		{
			return false;
		}

		if (findUser(username))
		{
			account = getAccount(username);
		}
		else
		{
			throw exception("User not found!");
		}
	}
	catch (exception &ex)
	{
		setTextColor(Color::RED);
		cout << endl << ex.what() << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		system("pause");

		return false;
	}

	while (!isPasswordCorrect)
	{
		try
		{
			cout << "Password: ";
			if (maskedPasswordInput(password, passwordLengthInputLimit) == false)
			{
				return false;
			}

			if (password.length() == 0)
			{
				passwordAttempts++;
				throw exception(passwordAttempts > 4 ? "Enter at least one character!\nPassword attemps exceeded!" : "Enter at least one character!");
			}

			if (account->getPassword() == password && passwordAttempts < 5)
			{
				isPasswordCorrect = true;
			}
			else
			{
				passwordAttempts++;
				throw exception(passwordAttempts > 4 ? "Wrong password!\nPassword attempts exceeded!" : "Wrong password!");
			}
		}
		catch (exception& ex)
		{
			setTextColor(Color::RED);
			cout << endl << ex.what() << endl << endl;
			setTextColor(Color::LIGHT_CYAN);

			if (passwordAttempts < 5)
			{
				Sleep(1500);

				moveCursorUpToNLines(2);
				clearLine();
				moveCursorUpToNLines(2);
				clearLine();

				password.clear();
			}
			else
			{
				system("pause");

				return false;
			}
		}
	}

    if (account->getAdminAccess() == adminAccessStatus_)
    {
		currentAccount_ = account;

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "Logged in!";

		Sleep(1500);

		clearLine();

		cout << "Welcome, " << account->getUsername() << "!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		system("pause");

		return true;
    }
    else
    {
		setTextColor(Color::RED);
		cout << endl << "Access denied!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		system("pause");

		return false;
    }
}

void AccountHandler::registration()
{
	string username;
	string password;

	Account* newAccount = nullptr;

	system("cls");

	try
	{
		cout << "Enter username: ";
		if (limitedInput(username, usernameLengthInputLimit) == false)
		{
			return;
		}

		if (findUser(username))
		{
			throw exception("User is already exists!");
		}

		if (username.length() < 3)
		{
			throw exception("Username should be at least three characters long!");
		}

		if (username.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("Username should only consists of letters and digits!");
		}

		cout << "Enter password: ";
		if (maskedPasswordInput(password, passwordLengthInputLimit) == false)
		{
			return;
		}

		if (password.length() < 3)
		{
			throw exception("Password should be at least three characters long!");
		}

		if (password.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("Password should only consists of letters and digits!");
		}

		newAccount = new User(username, password);

		accounts_.push_back(*(newAccount));

		rewriteAccountsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << endl << "You are succesfully registered!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception& ex)
	{
		setTextColor(Color::RED);
		cout << endl << ex.what() << endl << "You are not registered!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void AccountHandler::showAccounts()
{
	try
	{
		if (accounts_.size() == 0)
		{
			throw exception("Account list is empty");
		}

		AccountPrinter::showHeader();

		for (unsigned i = 0; i < accounts_.size(); i++)
		{
			cout << accounts_.at(i) << endl;
		}

		drawSolidLine(AccountPrinter::getSolidLineLength());
	}
	catch (exception & ex)
	{
		system("cls");

		setTextColor(Color::RED);
		cout << ex.what() << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		system("pause");
	}
}

void AccountHandler::showAccounts(unsigned from, unsigned to)
{
	try
	{
		if (accounts_.size() == 0)
		{
			throw exception("Account list is empty");
		}

		AccountPrinter::showHeader();

		for (unsigned i = from; i < to && i < accounts_.size(); i++)
		{
			cout << accounts_.at(i) << endl;
		}

		drawSolidLine(AccountPrinter::getSolidLineLength());
	}
	catch (exception & ex)
	{
		system("cls");

		setTextColor(Color::RED);
		cout << ex.what() << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		system("pause");
	}
}

void AccountHandler::showEditAccount()
{
	try
	{
		if (accountToEdit_ == nullptr)
		{
			throw exception("Account to edit not setted!");
		}

		AccountPrinter::showHeader();

		cout << *accountToEdit_ << endl;

		drawSolidLine(AccountPrinter::getSolidLineLength());
	}
	catch (exception & ex)
	{
		system("cls");

		setTextColor(Color::RED);
		cout << ex.what() << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		system("pause");
	}
}

void AccountHandler::addAccount()
{
    string username;
    string password;

	Account* account = nullptr;

	ConsoleMenu* consoleMenu = new AccountTypeMenu();

	switch (consoleMenu->selectMode())
	{
	case AccountType::ADMIN :
		account = new Admin();
		break;
	case AccountType::USER :
		account = new User();
		break;
	default:
		consoleMenu->resetChoice();
		return;
	}

	consoleMenu->resetChoice();

	system("cls");

	try
	{
		cout << "Username: ";
		if (limitedInput(username, usernameLengthInputLimit) == false)
		{
			return;
		}

		if (findUser(username))
		{
			throw exception("User is already exists!");
		}

		if (username.length() < 3)
		{
			throw exception("Username should be at least three characters long!");
		}

		if (username.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("Username should only consists of letters and digits!");
		}

		account->setUsername(username);

		cout << "Password: ";
		if (maskedPasswordInput(password, passwordLengthInputLimit) == false)
		{
			return;
		}

		if (password.length() < 3)
		{
			throw exception("Password should be at least three characters long!");
		}

		if (password.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("Password should only consists of letters and digits!");
		}

		account->setPassword(password);

		accounts_.push_back(*(account));

		rewriteAccountsFile();

		setTextColor(Color::LIGHT_GREEN);
		if (account->getAdminAccess())
		{
			cout << endl << endl << "Admin succesfully added!" << endl << endl;
		}
		else
		{
			cout << endl << endl << "User succesfully added!" << endl << endl;
		}
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception& ex)
	{
		setTextColor(Color::RED);
		if (account->getAdminAccess())
		{
			cout << endl << ex.what() << endl << "Admin not added!" << endl << endl;
		}
		else
		{
			cout << endl << ex.what() << endl << "User not added!" << endl << endl;
		}
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");

	delete consoleMenu;
}

void AccountHandler::deleteAccount()
{
	ItemSelection<Account>* itemSelection = nullptr;

	unsigned index = 0;

	try
	{
		if (accounts_.size() == 0)
		{
			throw exception("Accounts file is empty!");
		}

		itemSelection = new ItemSelection<Account>("Choose user to delete: ", accounts_);

		index = itemSelection->selectMode();

		if (index == 0)
		{
			delete itemSelection;
			return;
		}
		else
		{
			index -= 1;
		}

		if (getAccount(index)->getAdminAccess() == true && countAdmins() == 1)
		{
			throw exception("Unable to delete last admin!");
		}

		CarHandler::resetReservedCarsByUsername(getAccount(index)->getUsername());

		accounts_.erase(accounts_.begin() + index);

		rewriteAccountsFile();

		system("cls");

		setTextColor(Color::LIGHT_GREEN);
		cout << "User succesfully deleted!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		delete itemSelection;
	}
	catch(exception& ex)
	{
		system("cls");

		setTextColor(Color::RED);
		cout << ex.what() << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		delete itemSelection;
	}

	system("pause");
}

void AccountHandler::editAccount()
{
	ItemSelection<Account>* itemSelection = nullptr;

	unsigned index;

	ConsoleMenu* menu = nullptr;

	try
	{
		if (accounts_.size() == 0)
		{
			throw exception("Account list is empty!");
		}

		itemSelection = new ItemSelection<Account>("Shoose user to edit: ", accounts_);

		index = itemSelection->selectMode();

		if (index == 0)
		{
			return;
		}
		else
		{
			index -= 1;
		}

		accountToEdit_ = getAccount(index);

		menu = new AccountEditMenu();

		while (menu)
		{
			menu = menu->getNextMenu();
		}

		delete itemSelection;
		delete menu;
	}
	catch (exception & ex)
	{
		system("cls");

		setTextColor(Color::RED);
		cout << ex.what() << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		system("pause");
	}
}

// Destructors
AccountHandler::~AccountHandler()
{
	delete accountToEdit_;
}