#include "AccountHandler.h"

using namespace account;

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
	bool banStatus;

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
				password = decryptPassword(data.at(1));
				adminAccess = data.at(2) == "1" ? true : false;
				banStatus = data.at(3) == "1" ? true : false;

				if (adminAccess == true)
				{
					accounts_.push_back(Admin(username, password, banStatus));
				}
				else
				{
					accounts_.push_back(User(username, password, banStatus));
				}

				if (StatisticsHandler::checkForStatistics(username) == false)
				{
					StatisticsHandler::createStatistics(username);
				}
			}
		}
		accountsFile.close();
	}
}

AccountHandler::AccountHandler(const string& fileName)
{
	string token;

	string username;
	string password;
	bool adminAccess;
	bool banStatus;

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
				password = decryptPassword(data.at(1));
				adminAccess = data.at(2) == "1" ? true : false;
				banStatus = data.at(3) == "1" ? true : false;

				decryptPassword(password);

				if (adminAccess == true)
				{
					accounts_.push_back(Admin(username, password, banStatus));
				}
				else
				{
					accounts_.push_back(User(username, password, banStatus));
				}

				if (StatisticsHandler::checkForStatistics(username) == false)
				{
					StatisticsHandler::createStatistics(username);
				}
			}
		}
		accountsFile.close();
	}
}

// Files
void AccountHandler::rewriteAccountsFile()
{
	ofstream accountsFile;
	accountsFile.open(R"(accounts.txt)", ios::trunc);
	if (accountsFile.is_open())
	{
		for (auto& i : accounts_)
		{
			accountsFile << i.getUsername() << ";"
						 << encryptPassword(i.getPassword()) << ";"
						 << i.getAdminAccess() << ";"
						 << i.getBanStatus() << endl;
		}
		accountsFile.close();
	}
	else
	{
		throw exception("���������� ������� ���� � ����������!");
	}
}

// Encrypting
string AccountHandler::decryptPassword(string password)
{
	for (auto& i : password)
	{
		i = i - 1;
	}
	return password;
}

string AccountHandler::encryptPassword(string password)
{
	for (auto& i : password)
	{
		i = i + 1;
	}
	return password;
}

// Find
bool AccountHandler::findUser(const string& username)
{
	for (auto& i : accounts_)
	{
		if (i.getUsername() == username)
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

vector<Account> AccountHandler::getAccounts(unsigned from, unsigned to)
{
	vector<Account> accounts;
	for(unsigned i = from; i < to && i < accounts_.size(); i++)
	{
		accounts.push_back(accounts_.at(i));
	}
	return accounts;
}

vector<Account> AccountHandler::getUsers()
{
	vector<Account> users;
	for (auto i : accounts_)
	{
		if (i.getAdminAccess() == false)
		{
			users.push_back(i);
		}
	}
	return users;
}

Account* AccountHandler::getCurrentAccount()
{
	return currentAccount_;
}

Account* AccountHandler::getAccount(const string& username)
{
	for (auto& i : accounts_)
	{
		if (i.getUsername() == username)
		{
			return &i;
		}
	}
	return nullptr;
}

Account* AccountHandler::getAccount(unsigned index)
{
	return &(accounts_.at(index));
}

unsigned AccountHandler::getAccountIndex(const string& username)
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

unsigned AccountHandler::getAccountIndex(const Account& account)
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
	for (auto& i : accounts_)
	{
		if (i.getAdminAccess() == true)
		{
			counter++;
		}
	}
	return counter;
}

unsigned AccountHandler::countNotBannedAdmins()
{
	unsigned counter = 0;
	for (auto& i : accounts_)
	{
		if (i.getAdminAccess() == true && i.getBanStatus() == false)
		{
			counter++;
		}
	}
	return counter;
}

unsigned AccountHandler::countBannedAdmins()
{
	unsigned counter = 0;
	for (auto& i : accounts_)
	{
		if (i.getAdminAccess() == true && i.getBanStatus() == true)
		{
			counter++;
		}
	}
	return counter;
}

unsigned AccountHandler::countUsers()
{
	unsigned counter = 0;
	for (auto& i : accounts_)
	{
		if (i.getAdminAccess() == false)
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
			throw exception("������� ��� �������������� �� ����������!");
		}

		system("cls");

		showEditAccount();

		cout << endl << "������� ����� ��� ��������: ";
		if (limitedInput(username, USERNAME_LENGTH_INPUT_LIMIT) == false)
		{
			return;
		}

		if (findUser(username))
		{
			throw exception("����� ������� ��� ����������!");
		}
		if (username.length() < 3)
		{
			throw exception("��� �������� ������ �������� ��� ������� �� ���� ��������!");
		}
		if (username.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("��� �������� ������ �������� ������ �� ���� � ����!");
		}

		car::CarHandler::editReservedCarsReserverUsername(accountToEdit_->getUsername(), username);

		StatisticsHandler::getAccountStatistics(accountToEdit_->getUsername())->setUsername(username);
		StatisticsHandler::rewriteStatisticsFile();

		accountToEdit_->setUsername(username);

		system("cls");

		showEditAccount();

		rewriteAccountsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "��� �������� ������� ��������!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditAccount();

		setTextColor(Color::RED);
		cout << endl << ex.what() << endl;
		cout << "��� �������� �� ��������!" << endl << endl;
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
			throw exception("������� ��� �������������� �� ����������!");
		}

		system("cls");

		showEditAccount();

		cout << endl << "������� ����� ������ ��������: ";
		if (maskedPasswordInput(password, PASSWORD_LENGTH_INPUT_LIMIT) == false)
		{
			return;
		}

		if (password.length() < 3)
		{
			throw exception("������ �������� ������ �������� ��� ������� �� ���� ��������!");
		}
		if (password.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("������ �������� ������ �������� ������ �� ���� � ����!");
		}

		accountToEdit_->setPassword(password);

		system("cls");

		showEditAccount();

		rewriteAccountsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "������ �������� ������� �������!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditAccount();

		setTextColor(Color::RED);
		cout << endl << ex.what() << endl;
		cout << "������ �������� �� �������!" << endl << endl;
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
			throw exception("�������� ��� �������������� �� ����������!");
		}

		system("cls");

		showEditAccount();

		if (accountToEdit_->getBanStatus() == false && accountToEdit_->getAdminAccess() == true && countNotBannedAdmins() < 2)
		{
			throw exception("���������� �������� ����� �������������� ���������� �� ���������������� ��������������!");
		}
	
		if (accountToEdit_->getAdminAccess() == true)
		{
			car::CarHandler::resetReservedCarsByUsername(accountToEdit_->getUsername());
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

		rewriteAccountsFile();

		system("cls");

		showEditAccount();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "����� �������������� ������� ��������!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception& ex)
	{
		system("cls");

		showEditAccount();

		setTextColor(Color::RED);
		cout << endl << ex.what() << endl;
		cout << "����� �������������� �� ��������!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void AccountHandler::editBanStatus()
{
	try
	{
		if (accountToEdit_ == nullptr)
		{
			throw exception("������� ��� �������������� �� ����������!");
		}

		system("cls");

		showEditAccount();

		if (countNotBannedAdmins() < 2 && accountToEdit_->getAdminAccess() == true && accountToEdit_->getBanStatus() == false)
		{
			throw exception("���������� ������������� ���������� �������������!");
		}

		accountToEdit_->setBanStatus(!accountToEdit_->getBanStatus());

		rewriteAccountsFile();

		system("cls");

		showEditAccount();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "������ ���������� ������� �������!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditAccount();

		setTextColor(Color::RED);
		cout << endl << ex.what() << endl;
		cout << "������ ���������� �� �������!" << endl << endl;
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
		cout << "��� ������������: ";
		if (limitedInput(username, USERNAME_LENGTH_INPUT_LIMIT) == false)
		{
			return false;
		}

		if (findUser(username))
		{
			account = getAccount(username);
		}
		else
		{
			throw exception("������� �� ������!");
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
			cout << "������: ";
			if (maskedPasswordInput(password, PASSWORD_LENGTH_INPUT_LIMIT) == false)
			{
				return false;
			}

			if (password.length() == 0)
			{
				passwordAttempts++;
				throw exception(passwordAttempts > 4 ? "������� ���� �� ���� ������!\n��������� ����� ������� ����� ������!" : "������� ���� �� ���� ������!");
			}

			if (account->getPassword() == password && passwordAttempts < 5)
			{
				isPasswordCorrect = true;
			}
			else
			{
				passwordAttempts++;
				throw exception(passwordAttempts > 4 ? "�������� ������!\n��������� ����� ������� ����� ������!" : "�������� ������!");
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

    if (account->getAdminAccess() == adminAccessStatus_ && account->getBanStatus() == false)
    {
		currentAccount_ = account;

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "�� ������� ����� � �������!";

		Sleep(1500);

		clearLine();

		cout << "������������, " << account->getUsername() << "!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		system("pause");

		return true;
    }
    else
    {
		setTextColor(Color::RED);
		cout << endl << "������ ������������!" << endl << endl;
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
		cout << "������� ��� ��������: ";
		if (limitedInput(username, USERNAME_LENGTH_INPUT_LIMIT) == false)
		{
			return;
		}

		if (findUser(username))
		{
			throw exception("����� ������� ��� ����������!");
		}
		if (username.length() < 3)
		{
			throw exception("��� �������� ������ �������� ��� ������� �� ���� ��������!");
		}
		if (username.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("��� �������� ������ �������� ������ �� ���� � ����!");
		}

		cout << "������� ������: ";
		if (maskedPasswordInput(password, PASSWORD_LENGTH_INPUT_LIMIT) == false)
		{
			return;
		}
		if (password.length() < 3)
		{
			throw exception("������ �������� ������ �������� ��� ������� �� ���� ��������!");
		}
		if (password.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("������ �������� ������ �������� ������ �� ���� � ����!");
		}

		newAccount = new User(username, password, false);

		StatisticsHandler::createStatistics(newAccount->getUsername());

		accounts_.push_back(*(newAccount));

		rewriteAccountsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "�� ������� ������������������!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception& ex)
	{
		setTextColor(Color::RED);
		cout << endl << ex.what() << endl << "�� �� ������������������!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void AccountHandler::showAccounts()
{
	try
	{
		if (accounts_.empty())
		{
			throw exception("������ ��������� ����!");
		}

		AccountPrinter::showAccounts(accounts_);
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
		if (accounts_.empty())
		{
			throw exception("������ ��������� ����!");
		}

		auto accounts = getAccounts(from, to);

		AccountPrinter::showAccounts(accounts);
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
			throw exception("������� ��� �������������� �� ���������!");
		}

		AccountPrinter::showAccounts({ *accountToEdit_ });
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

	menu::ConsoleMenu* consoleMenu = new menu::AccountTypeMenu();

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
		cout << "��� ��������: ";
		if (limitedInput(username, USERNAME_LENGTH_INPUT_LIMIT) == false)
		{
			return;
		}

		if (findUser(username))
		{
			throw exception("����� ������� ��� ����������!");
		}
		if (username.length() < 3)
		{
			throw exception("��� �������� ������ �������� ��� ������� �� ���� ��������!");
		}
		if (username.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("��� �������� ������ �������� ������ �� ���� � ���� ���������� ��������!");
		}

		account->setUsername(username);

		cout << "������: ";
		if (maskedPasswordInput(password, PASSWORD_LENGTH_INPUT_LIMIT) == false)
		{
			return;
		}

		if (password.length() < 3)
		{
			throw exception("������ �������� ������ �������� ��� ������� �� ���� ��������!");
		}
		if (password.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("������ �������� ������ �������� ������ �� ���� � ����!");
		}

		account->setPassword(password);

		accounts_.push_back(*(account));

		rewriteAccountsFile();

		StatisticsHandler::createStatistics(account->getUsername());

		setTextColor(Color::LIGHT_GREEN);
		if (account->getAdminAccess())
		{
			cout << endl << "������������� ������� ��������!" << endl << endl;
		}
		else
		{
			cout << endl << "������������ ������� ��������!" << endl << endl;
		}
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception& ex)
	{
		setTextColor(Color::RED);
		if (account->getAdminAccess())
		{
			cout << endl << ex.what() << endl << "������������� �� ��������!" << endl << endl;
		}
		else
		{
			cout << endl << ex.what() << endl << "������������ �� ��������!" << endl << endl;
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
		if (accounts_.empty())
		{
			throw exception("������ ��������� ����!");
		}

		itemSelection = new ItemSelection<Account>("�������� ��������� �������: ", accounts_);

		index = itemSelection->selectMode();

		if (index == 0)
		{
			delete itemSelection;
			return;
		}

		if (getAccount(index - 1)->getAdminAccess() == true && countAdmins() == 1)
		{
			throw exception("���������� ������� ���������� ��������������!");
		}

		car::CarHandler::resetReservedCarsByUsername(getAccount(index - 1)->getUsername());

		StatisticsHandler::deleteStatistics(getAccount(index - 1)->getUsername());

		accounts_.erase(accounts_.begin() + (index - 1));

		rewriteAccountsFile();

		system("cls");

		setTextColor(Color::LIGHT_GREEN);
		cout << "������� ������� ������!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		delete itemSelection;
	}
	catch(exception& ex)
	{
		system("cls");

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "������� �� ������!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		delete itemSelection;
	}

	system("pause");
}

void AccountHandler::editAccount()
{
	ItemSelection<Account>* itemSelection = nullptr;

	unsigned index = 0;

	menu::ConsoleMenu* menu = nullptr;

	try
	{
		if (accounts_.empty())
		{
			throw exception("������ ��������� ����!");
		}

		itemSelection = new ItemSelection<Account>("�������� ������� ��� ��������������: ", accounts_);

		index = itemSelection->selectMode();

		if (index == 0)
		{
			return;
		}

		accountToEdit_ = getAccount(index - 1);

		menu = new menu::AccountEditMenu();

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

void AccountHandler::showCurrentAccountStatistics()
{
	AccountStatistics* statistic = nullptr;
	try
	{
		if (currentAccount_ == nullptr)
		{
			throw exception("������� ������� �� ����������!");
		}
		if (StatisticsHandler::checkForStatistics(currentAccount_->getUsername()) == false)
		{
			throw exception("���������� ��� ����� �������� �� �������!");
		}

		statistic = StatisticsHandler::getAccountStatistics(currentAccount_->getUsername());

		system("cls");

		cout << "���������� ��� �������� ��������:" << endl << endl
			 << "��� ��������: " << statistic->getUsername() << endl
			 << "���������� ��������� �����������: " << statistic->getTotalCarsPurchased() << endl
			 << "���������� ���: " << statistic->getLargestCheck() << "$" << endl
			 << "������� ���: " << statistic->getAverageCheck() << "$" << endl
			 << "����� ����� �������: " << statistic->getTotalPurchases() << "$" << endl
			 << endl;
	}
	catch (exception & ex)
	{
		system("cls");

		setTextColor(Color::RED);
		cout << ex.what() << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	system("pause");
}

void AccountHandler::showTotalStatistics()
{
	system("cls");

	cout << "����� ����������:" << endl << endl;

	cout << "����� ������� �����������: " << StatisticsHandler::getSoldCarsQuantity() << endl;
	cout << "�������, �������� ���������� ���������� �����������: " << StatisticsHandler::getMostBuyedCarsUsername() << endl;
	cout << "������� ���: " << StatisticsHandler::getAccountsAverageCheck() << "$" << endl;
	cout << "���������� ���: " << StatisticsHandler::getAccountsLargestCheck() << "$" << endl;
	cout << "����� ����� �������: " << StatisticsHandler::getAccountsTotalPurchaseAmount() << "$" << endl << endl;

	system("pause");
}

// Destructors
AccountHandler::~AccountHandler()
{
	delete accountToEdit_;
	delete currentAccount_;
}