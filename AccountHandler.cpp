#include "AccountHandler.h"

// Static initialization
vector<UserCredentials> AccountHandler::users_;
bool AccountHandler::showPasswordStatus_ = false;
bool AccountHandler::adminAccessStatus_ = false;
UserCredentials* AccountHandler::userToEdit_ = nullptr;

// Constructors
AccountHandler::AccountHandler()
{
	string token;

	string username;
	string password;
	bool adminAccess;

	UserCredentials* userCredentials = nullptr;

	ifstream readableFile(R"(users.txt)");

	if (readableFile.is_open())
	{
		while (!readableFile.eof())
		{
			if (getline(readableFile, token, '\n'))
			{
				stringstream iss(token);
				getline(iss, username, ';');
				getline(iss, password, ';');
				iss >> adminAccess;

				userCredentials = new UserCredentials(username, password, adminAccess);

				users_.push_back(*userCredentials);
			}
		}
		readableFile.close();
		delete userCredentials;
	}
}

AccountHandler::AccountHandler(string fileName)
{
	string token;

	string username;
	string password;
	bool adminAccess;

	UserCredentials* userCredentials = nullptr;

	ifstream readableFile(fileName);

	if (readableFile.is_open())
	{
		while (!readableFile.eof())
		{
			if (getline(readableFile, token, '\n'))
			{
				stringstream iss(token);
				getline(iss, username, ';');
				getline(iss, password, ';');
				iss >> adminAccess;

				userCredentials = new UserCredentials(username, password, adminAccess);

				users_.push_back(*userCredentials);
			}
		}
		readableFile.close();
		delete userCredentials;
	}
}

// Find
bool AccountHandler::findUser(string &username)
{
    for (unsigned i = 0; i < users_.size(); i++)
    {
        if (users_.at(i).getUsername() == username)
        {
            return true;
        }
    }
    return false;
}

// Gets
UserCredentials* AccountHandler::getUserCredentials(string &username)
{
    UserCredentials* user = nullptr;

    for (unsigned i = 0; i < users_.size(); i++)
    {
        if (users_.at(i).getUsername() == username)
        {
            user = &(users_.at(i));
        }
    }

    return user;
}

UserCredentials* AccountHandler::getUserCredentials(unsigned index)
{
	return &(users_.at(index));
}

unsigned AccountHandler::getUser(string& username)
{
	unsigned index = 0;
	for (unsigned i = 0; i < users_.size(); i++)
	{
		if (users_.at(i).getUsername() == username)
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

	for (unsigned i = 0; i < AccountHandler::users_.size(); i++)
	{
		if (length < AccountHandler::users_.at(i).getPassword().length())
		{
			length = AccountHandler::users_.at(i).getPassword().length();
		}
	}

	return length;
}

unsigned AccountHandler::calculateUsernameMaxLength()
{
	unsigned length = 0;

	for (unsigned i = 0; i < AccountHandler::users_.size(); i++)
	{
		if (length < AccountHandler::users_.at(i).getUsername().length())
		{
			length = AccountHandler::users_.at(i).getUsername().length();
		}
	}

	return length;
}

// Count
unsigned AccountHandler::countAccounts()
{
	return users_.size();
}

unsigned AccountHandler::countAdmins()
{
	unsigned counter = 0;
	for (unsigned i = 0; i < users_.size(); i++)
	{
		if (users_.at(i).getAdminAccess())
		{
			counter++;
		}
	}
	return counter;
}

unsigned AccountHandler::countUsers()
{
	unsigned counter = 0;
	for (unsigned i = 0; i < users_.size(); i++)
	{
		if (!(users_.at(i).getAdminAccess()))
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
	AccountHandler::showPasswordStatus_ = !AccountHandler::showPasswordStatus_;
}

void AccountHandler::resetUserToEdit()
{
	userToEdit_ = nullptr;
}

void AccountHandler::inputNewUsername()
{
	string username;

	system("cls");

	showEditUser();

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

		userToEdit_->setUsername(username);

		system("cls");
		showEditUser();

		ofstream writeFile(R"(users.txt)", ios::trunc);
		if (writeFile.is_open())
		{
			for (unsigned i = 0; i < users_.size(); i++)
			{
				writeFile << users_.at(i).getUsername() << ";" << users_.at(i).getPassword() << ";" << users_.at(i).getAdminAccess() << endl;
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
		showEditUser();

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

	system("cls");

	showEditUser();

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

		userToEdit_->setPassword(password);

		system("cls");
		showEditUser();

		ofstream writeFile(R"(users.txt)", ios::trunc);
		if (writeFile.is_open())
		{
			for (unsigned i = 0; i < users_.size(); i++)
			{
				writeFile << users_.at(i).getUsername() << ";" << users_.at(i).getPassword() << ";" << users_.at(i).getAdminAccess() << endl;
			}
		}
		writeFile.close();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "Password succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");
		showEditUser();

		setTextColor(Color::RED);
		cout << endl << ex.what() << endl;
		cout << "Password not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void AccountHandler::changeAdminAccess()
{
	system("cls");

	showEditUser();

	try
	{
		if (userToEdit_->getAdminAccess() == true && countAdmins() < 2)
		{
			throw exception("Unable to change admin access of last admin!");
		}

		userToEdit_->setAdminAccess(!(userToEdit_->getAdminAccess()));

		system("cls");
		showEditUser();

		ofstream writeFile(R"(users.txt)", ios::trunc);
		if (writeFile.is_open())
		{
			for (unsigned i = 0; i < users_.size(); i++)
			{
				writeFile << users_.at(i).getUsername() << ";" << users_.at(i).getPassword() << ";" << users_.at(i).getAdminAccess() << endl;
			}
		}
		writeFile.close();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "Admin access succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");
		showEditUser();

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
	bool isUserHasAdminAccess = false;
	
    UserCredentials* receivedUserCredentials = nullptr;

    system("cls");

	try
	{
		cout << "Username: ";
		limitedInput(username, usernameLengthInputLimit);

		if (findUser(username))
		{
			receivedUserCredentials = getUserCredentials(username);
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

			if (receivedUserCredentials->getPassword() == password && passwordAttempts < 5)
			{
				isPasswordCorrect = true;
			}
			else
			{
				passwordAttempts++;
				throw exception(passwordAttempts > 4 ? "Wrong password!\nPassword attempts exceeded!" : "Wrong password!");
			}
		}
		catch (exception &ex)
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

    if (receivedUserCredentials->getAdminAccess() == adminAccessStatus_)
    {
		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "Logged in!";

		Sleep(1500);

		clearLine();

		cout << "Welcome, " << receivedUserCredentials->getUsername() << "!" << endl << endl;
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

void AccountHandler::showUsers()
{
	unsigned solidLineLength = (calculateUsernameMaxLength() < 9 ? 8 : calculateUsernameMaxLength()) +
							   (calculatePasswordMaxLength() < 9 ? 8 : calculatePasswordMaxLength()) + 22;

	drawSolidLine(solidLineLength);

	cout <<  "| " << makeCenteredString("Username", calculateUsernameMaxLength()) 
		 << " | " << makeCenteredString("Password", calculatePasswordMaxLength()) 
		 << " | " << "Admin access" << " |" << endl;

	drawSolidLine(solidLineLength);

    for (unsigned i = 0; i < users_.size(); i++)
    {
        cout <<  "| " << setw(calculateUsernameMaxLength() < 9 ? 8 : calculateUsernameMaxLength()) << left << users_.at(i).getUsername()
			 << " | " << setw(calculatePasswordMaxLength() < 9 ? 8 : calculatePasswordMaxLength()) << left 
					  << (AccountHandler::showPasswordStatus_ ? users_.at(i).getPassword() : makeMaskedString(users_.at(i).getPassword()))
			 << " | " << setw(12) << left << (users_.at(i).getAdminAccess() ? "Yes" : "No") << " |"
			 << endl;
    }

	drawSolidLine(solidLineLength);
}

void AccountHandler::showEditUser()
{
	unsigned solidLineLength = (userToEdit_->getUsername().length() < 9 ? 8 : userToEdit_->getUsername().length()) +
							   (userToEdit_->getPassword().length() < 9 ? 8 : userToEdit_->getPassword().length()) + 22;

	drawSolidLine(solidLineLength);

	cout <<  "| " << makeCenteredString("Username", userToEdit_->getUsername().length()) 
		 << " | " << makeCenteredString("Password", userToEdit_->getPassword().length()) 
		 << " | " << "Admin access" 
		 << " |"  << endl;

	drawSolidLine(solidLineLength);

	cout <<  "| " << setw((userToEdit_->getUsername().length() < 9 ? 8 : userToEdit_->getUsername().length())) << left << userToEdit_->getUsername()
		 << " | " << setw((userToEdit_->getPassword().length() < 9 ? 8 : userToEdit_->getPassword().length())) << left << makeMaskedString(userToEdit_->getPassword())
		 << " | " << setw(12) << left << (userToEdit_->getAdminAccess() ? "Yes" : "No") 
		 << " |"  << endl;

	drawSolidLine(solidLineLength);
}

void AccountHandler::addUser()
{
    string username;
    string password;
    bool adminAccess = false;

	ConsoleMenu* menu = new AddUserMenu();

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

		menu->resetChoice();
		switch (menu->selectMode())
		{
		case AddUserMenuChoice::GIVE_ADMIN_ACCESS:
			adminAccess = true;
			break;
		case AddUserMenuChoice::DONT_GIVE_ADMIN_ACCESS:
			adminAccess = false;
			break;
		default:
			break;
		}

		clearLine();
		cout << "Admin access: " << (adminAccess ? "Yes" : "No");

		UserCredentials newUser(username, password, adminAccess);

		users_.push_back(newUser);

		ofstream writeFile(R"(users.txt)", ios::app);
		if (writeFile.is_open())
		{
			writeFile << newUser.getUsername() << ";" << newUser.getPassword() << ";" << newUser.getAdminAccess() << endl;
		}
		writeFile.close();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << endl << "User succesfully added!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		setTextColor(Color::RED);
		cout << endl << ex.what() << endl << "User not added!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");

	delete menu;
}

void AccountHandler::deleteUser()
{
	string username;

	system("cls");

	ItemSelection<UserCredentials> itemSelection("Choose user to delete: ", users_);

	unsigned index = itemSelection.selectMode();

	if (index == 0)
	{
		return;
	}
	else
	{
		index -= 1;
	}

	users_.erase(users_.begin() + index);

	ofstream writeFile(R"(users.txt)", ios::trunc);
	if (writeFile.is_open())
	{
		for (unsigned i = 0; i < users_.size(); i++)
		{
			writeFile << users_.at(i).getUsername() << ";" << users_.at(i).getPassword() << ";" << users_.at(i).getAdminAccess() << endl;
		}
	}
	writeFile.close();

	system("cls");

	showUsers();

	setTextColor(Color::LIGHT_GREEN);
	cout << endl << "User succesfully deleted!" << endl << endl;
	setTextColor(Color::LIGHT_CYAN);;

	system("pause");
}

void AccountHandler::editUser()
{
	string username;

	ItemSelection<UserCredentials> itemSelection("Shoose user to edit: ", users_);

	system("cls");

	unsigned index = itemSelection.selectMode();

	if (index == 0)
	{
		return;
	}
	else
	{
		index -= 1;
	}

	userToEdit_ = getUserCredentials(index);

	ConsoleMenu* menu = new EditUserMenu();

	while (menu)
	{
		menu = menu->getNextMenu();
	}

	delete menu;
}

// Destructors
AccountHandler::~AccountHandler()
{
	delete userToEdit_;
}