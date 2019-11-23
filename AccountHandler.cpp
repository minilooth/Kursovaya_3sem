#include "AccountHandler.h"

// Static initialization
vector<Account> AccountHandler::accounts_;
bool AccountHandler::showPasswordStatus_ = false;
bool AccountHandler::adminAccessStatus_ = false;
Account* AccountHandler::accountToEdit_;

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

// Calculate
unsigned AccountHandler::calculatePasswordMaxLength()
{
	unsigned length = 0;

	for (unsigned i = 0; i < AccountHandler::accounts_.size(); i++)
	{
		if (length < AccountHandler::accounts_.at(i).getPassword().length())
		{
			length = AccountHandler::accounts_.at(i).getPassword().length();
		}
	}

	return length;
}

unsigned AccountHandler::calculateUsernameMaxLength()
{
	unsigned length = 0;

	for (unsigned i = 0; i < AccountHandler::accounts_.size(); i++)
	{
		if (length < AccountHandler::accounts_.at(i).getUsername().length())
		{
			length = AccountHandler::accounts_.at(i).getUsername().length();
		}
	}

	return length;
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
void AccountHandler::resetShowPasswordStatus()
{
	showPasswordStatus_ = false;
}

void AccountHandler::invertShowPasswordStatus()
{
	showPasswordStatus_ = !showPasswordStatus_;
}

void AccountHandler::resetAccountToEdit()
{
	accountToEdit_ = nullptr;
}

void AccountHandler::inputNewUsername()
{
	string username;

	system("cls");

	showEditAccount();

	try
	{
		cout << endl << "Enter new username: ";
		limitedInput(username, usernameLengthInputLimit);

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

		accountToEdit_->setUsername(username);

		system("cls");

		showEditAccount();

		ofstream writeFile(R"(accounts.txt)", ios::trunc);
		if (writeFile.is_open())
		{
			for (unsigned i = 0; i < accounts_.size(); i++)
			{
				writeFile << accounts_.at(i).getUsername() << ";" << accounts_.at(i).getPassword() << ";" << accounts_.at(i).getAdminAccess() << endl;
			}
		}
		writeFile.close();

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

void AccountHandler::inputNewPassword()
{
	string password;

	ofstream accountsFile;

	system("cls");

	showEditAccount();

	try
	{
		cout << endl << "Enter new password: ";
		maskedPasswordInput(password, passwordLengthInputLimit);

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
		}
		accountsFile.close();

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

void AccountHandler::changeAdminAccess()
{
	string username;
	string password;

	unsigned index = 0;

	ofstream accountsFile;

	system("cls");

	showEditAccount();

	try
	{
		if (accountToEdit_->getAdminAccess() == true && countAdmins() < 2)
		{
			throw exception("Unable to change admin access of last admin!");
		}
		
		username = accountToEdit_->getUsername();
		password = accountToEdit_->getPassword();

		if (accountToEdit_->getAdminAccess() == true)
		{
			accountToEdit_ = new User(username, password);
		}
		else
		{
			accountToEdit_ = new Admin(username, password);
		}

		index = getAccountIndex(*accountToEdit_);
		accounts_.erase(accounts_.begin() + index);
		accounts_.insert(accounts_.begin() + index, *accountToEdit_);

		system("cls");

		showEditAccount();

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
		}
		accountsFile.close();

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
		limitedInput(username, usernameLengthInputLimit);

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
			maskedPasswordInput(password, passwordLengthInputLimit);

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
		limitedInput(username, usernameLengthInputLimit);

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
		maskedPasswordInput(password, passwordLengthInputLimit);

		if (password.length() < 3)
		{
			throw exception("Password should be at least three characters long!");
		}

		if (password.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("Password should only consists of letters and digits!");
		}

		newAccount = new Account(username, password, false);

		accounts_.push_back(*(newAccount));

		ofstream writeFile(R"(accounts.txt)", ios::app);
		if (writeFile.is_open())
		{
			writeFile << newAccount->getUsername() << ";" << newAccount->getPassword() << ";" << newAccount->getAdminAccess() << endl;
		}
		writeFile.close();

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
	unsigned solidLineLength = 0;

	try
	{
		if (accounts_.size() == 0)
		{
			throw exception("Account list is empty");
		}

		solidLineLength = (calculateUsernameMaxLength() < 9 ? 8 : calculateUsernameMaxLength()) +
			(calculatePasswordMaxLength() < 9 ? 8 : calculatePasswordMaxLength()) + 22;

		drawSolidLine(solidLineLength);

		cout << "| " << makeCenteredString("Username", calculateUsernameMaxLength())
			<< " | " << makeCenteredString("Password", calculatePasswordMaxLength())
			<< " | " << "Admin access" << " |" << endl;

		drawSolidLine(solidLineLength);

		for (unsigned i = 0; i < accounts_.size(); i++)
		{
			cout << "| " << setw(calculateUsernameMaxLength() < 9 ? 8 : calculateUsernameMaxLength()) << left << accounts_.at(i).getUsername()
				<< " | " << setw(calculatePasswordMaxLength() < 9 ? 8 : calculatePasswordMaxLength()) << left
				<< (AccountHandler::showPasswordStatus_ ? accounts_.at(i).getPassword() : makeMaskedString(accounts_.at(i).getPassword()))
				<< " | " << setw(12) << left << (accounts_.at(i).getAdminAccess() ? "Yes" : "No") << " |"
				<< endl;
		}

		drawSolidLine(solidLineLength);
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
	unsigned solidLineLength = (calculateUsernameMaxLength() < 9 ? 8 : calculateUsernameMaxLength()) +
		(calculatePasswordMaxLength() < 9 ? 8 : calculatePasswordMaxLength()) + 22;

	drawSolidLine(solidLineLength);

	cout << "| " << makeCenteredString("Username", calculateUsernameMaxLength())
		<< " | " << makeCenteredString("Password", calculatePasswordMaxLength())
		<< " | " << "Admin access" << " |" << endl;

	drawSolidLine(solidLineLength);

	for (unsigned i = from; i < to && i < accounts_.size(); i++)
	{
		cout << "| " << setw(calculateUsernameMaxLength() < 9 ? 8 : calculateUsernameMaxLength()) << left << accounts_.at(i).getUsername()
			<< " | " << setw(calculatePasswordMaxLength() < 9 ? 8 : calculatePasswordMaxLength()) << left
			<< (AccountHandler::showPasswordStatus_ ? accounts_.at(i).getPassword() : makeMaskedString(accounts_.at(i).getPassword()))
			<< " | " << setw(12) << left << (accounts_.at(i).getAdminAccess() ? "Yes" : "No") << " |"
			<< endl;
	}

	drawSolidLine(solidLineLength);
}

void AccountHandler::showEditAccount()
{
	unsigned solidLineLength = (accountToEdit_->getUsername().length() < 9 ? 8 : accountToEdit_->getUsername().length()) +
							   (accountToEdit_->getPassword().length() < 9 ? 8 : accountToEdit_->getPassword().length()) + 22;

	drawSolidLine(solidLineLength);

	cout <<  "| " << makeCenteredString("Username", accountToEdit_->getUsername().length()) 
		 << " | " << makeCenteredString("Password", accountToEdit_->getPassword().length()) 
		 << " | " << "Admin access" 
		 << " |"  << endl;

	drawSolidLine(solidLineLength);

	cout <<  "| " << setw((accountToEdit_->getUsername().length() < 9 ? 8 : accountToEdit_->getUsername().length())) << left << accountToEdit_->getUsername()
		 << " | " << setw((accountToEdit_->getPassword().length() < 9 ? 8 : accountToEdit_->getPassword().length())) << left << makeMaskedString(accountToEdit_->getPassword())
		 << " | " << setw(12) << left << (accountToEdit_->getAdminAccess() ? "Yes" : "No") 
		 << " |"  << endl;

	drawSolidLine(solidLineLength);
}

void AccountHandler::addAccount()
{
    string username;
    string password;

	ofstream accountsFile;

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
		limitedInput(username, usernameLengthInputLimit);

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
		maskedPasswordInput(password, passwordLengthInputLimit);

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

		accountsFile.open(R"(accounts.txt)", ios::app);
		if (accountsFile.is_open())
		{
			accountsFile << account->getUsername() << ";" 
						 << account->getPassword() << ";" 
						 << account->getAdminAccess() 
						 << endl;
		}
		accountsFile.close();

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

	ofstream accountsFile;

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

		accounts_.erase(accounts_.begin() + index);

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
		}
		accountsFile.close();


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