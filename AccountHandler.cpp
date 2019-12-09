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
	bool banStatus;

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
				banStatus = data.at(3) == "1" ? true : false;

				if (adminAccess == true)
				{
					account = new Admin(username, password, banStatus);
				}
				else
				{
					account = new User(username, password, banStatus);
				}

				if (StatisticsHandler::checkForStatistics(account->getUsername()) == false)
				{
					StatisticsHandler::createStatistics(account->getUsername());
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
	bool banStatus;

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
				banStatus = data.at(3) == "1" ? true : false;

				if (adminAccess == true)
				{
					account = new Admin(username, password, banStatus);
				}
				else
				{
					account = new User(username, password, banStatus);
				}

				if (StatisticsHandler::checkForStatistics(account->getUsername()) == false)
				{
					StatisticsHandler::createStatistics(account->getUsername());
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
						 << accounts_.at(i).getAdminAccess() << ";"
						 << accounts_.at(i).getBanStatus()
						 << endl;
		}
		accountsFile.close();
	}
	else
	{
		throw exception("Невозможно открыть файл с аккаунтами!");
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

unsigned AccountHandler::countNotBannedAdmins()
{
	unsigned counter = 0;
	for (unsigned i = 0; i < accounts_.size(); i++)
	{
		if (accounts_.at(i).getAdminAccess() == true && accounts_.at(i).getBanStatus() == false)
		{
			counter++;
		}
	}
	return counter;
}

unsigned AccountHandler::countBannedAdmins()
{
	unsigned counter = 0;
	for (unsigned i = 0; i < accounts_.size(); i++)
	{
		if (accounts_.at(i).getAdminAccess() == true && accounts_.at(i).getBanStatus() == true)
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
			throw exception("Аккаунт для редактирования не установлен!");
		}

		system("cls");

		showEditAccount();

		cout << endl << "Введите новое имя аккаунта: ";
		if (limitedInput(username, usernameLengthInputLimit) == false)
		{
			return;
		}

		if (findUser(username))
		{
			throw exception("Такой аккаунт уже существует!");
		}
		if (username.length() < 3)
		{
			throw exception("Имя аккаунта должно быть как минимум три символа в длину!");
		}
		if (username.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("Имя аккаунта должно состоять только из букв и цифр!");
		}

		CarHandler::editReservedCarsReserverUsername(accountToEdit_->getUsername(), username);

		StatisticsHandler::getAccountStatistics(accountToEdit_->getUsername())->setUsername(username);
		StatisticsHandler::rewriteStatisticsFile();

		accountToEdit_->setUsername(username);

		system("cls");

		showEditAccount();

		rewriteAccountsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "Имя аккаунта успешно изменено!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditAccount();

		setTextColor(Color::RED);
		cout << endl << ex.what() << endl;
		cout << "Имя аккаунта не изменено!" << endl << endl;
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
			throw exception("Аккаунт для редактирования не установлен!");
		}

		system("cls");

		showEditAccount();

		cout << endl << "Введите новый пароль аккаунта: ";
		if (maskedPasswordInput(password, passwordLengthInputLimit) == false)
		{
			return;
		}

		if (password.length() < 3)
		{
			throw exception("Пароль аккаунта должен быть как минимум три символа в длину!");
		}
		if (password.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("Пароль аккаунта должен состоять только из букв и цифр!");
		}

		accountToEdit_->setPassword(password);

		system("cls");

		showEditAccount();

		rewriteAccountsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "Пароль аккаунта успешно изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditAccount();

		setTextColor(Color::RED);
		cout << endl << ex.what() << endl;
		cout << "Пароль аккаунта не изменен!" << endl << endl;
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
			throw exception("Аккаунта для редактирования не установлен!");
		}

		system("cls");

		showEditAccount();

		if (accountToEdit_->getBanStatus() == false && accountToEdit_->getAdminAccess() == true && countNotBannedAdmins() < 2)
		{
			throw exception("Невозможно изменить права администратора последнего не заблокированного администратора!");
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

		rewriteAccountsFile();

		system("cls");

		showEditAccount();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "Права администратора успешно изменены!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception& ex)
	{
		system("cls");

		showEditAccount();

		setTextColor(Color::RED);
		cout << endl << ex.what() << endl;
		cout << "Права администратора не изменены!" << endl << endl;
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
			throw exception("Аккаунт для редактирования не установлен!");
		}

		system("cls");

		showEditAccount();

		if (countNotBannedAdmins() < 2 && accountToEdit_->getAdminAccess() == true && accountToEdit_->getBanStatus() == false)
		{
			throw exception("Невозможно заблокировать последнего адмнистратора!");
		}

		accountToEdit_->setBanStatus(!accountToEdit_->getBanStatus());

		rewriteAccountsFile();

		system("cls");

		showEditAccount();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "Статус блокировки успешно изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditAccount();

		setTextColor(Color::RED);
		cout << endl << ex.what() << endl;
		cout << "Статус блокировки не изменен!" << endl << endl;
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
		cout << "Имя пользователя: ";
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
			throw exception("Аккаунт не найден!");
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
			cout << "Пароль: ";
			if (maskedPasswordInput(password, passwordLengthInputLimit) == false)
			{
				return false;
			}

			if (password.length() == 0)
			{
				passwordAttempts++;
				throw exception(passwordAttempts > 4 ? "Введите хотя бы один символ!\nПревышено число попыток ввода пароля!" : "Введите хотя бы один символ!");
			}

			if (account->getPassword() == password && passwordAttempts < 5)
			{
				isPasswordCorrect = true;
			}
			else
			{
				passwordAttempts++;
				throw exception(passwordAttempts > 4 ? "Неверный пароль!\nПревышено число попыток ввода пароля!" : "Неверный пароль!");
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
		cout << endl << "Вы успешно вошли в систему!";

		Sleep(1500);

		clearLine();

		cout << "Приветствуем, " << account->getUsername() << "!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		system("pause");

		return true;
    }
    else
    {
		setTextColor(Color::RED);
		cout << endl << "Доступ заблокирован!" << endl << endl;
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
		cout << "Введите имя аккаунта: ";
		if (limitedInput(username, usernameLengthInputLimit) == false)
		{
			return;
		}

		if (findUser(username))
		{
			throw exception("Такой аккаунт уже существует!");
		}

		if (username.length() < 3)
		{
			throw exception("Имя аккаунта должно быть как минимум три символа в длину!");
		}

		if (username.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("Имя аккаунта должно состоять только из букв и цифр!");
		}

		cout << "Введите пароль: ";
		if (maskedPasswordInput(password, passwordLengthInputLimit) == false)
		{
			return;
		}

		if (password.length() < 3)
		{
			throw exception("Пароль аккаунта должен быть как минимум три символа в длину!");
		}

		if (password.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("Пароль аккаунта должен состоять только из букв и цифр!");
		}

		newAccount = new User(username, password, false);

		StatisticsHandler::createStatistics(newAccount->getUsername());

		accounts_.push_back(*(newAccount));

		rewriteAccountsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "Вы успешно зарегистрировались!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception& ex)
	{
		setTextColor(Color::RED);
		cout << endl << ex.what() << endl << "Вы не зарегистрировались!" << endl << endl;
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
			throw exception("Список аккаунтов пуст!");
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
			throw exception("Список аккаунтов пуст!");
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
			throw exception("Аккаунт для редактирования не установен!");
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
		cout << "Имя аккаунта: ";
		if (limitedInput(username, usernameLengthInputLimit) == false)
		{
			return;
		}

		if (findUser(username))
		{
			throw exception("Такой аккаунт уже существует!");
		}

		if (username.length() < 3)
		{
			throw exception("Имя аккаунта должно быть как минимум три символа в длину!");
		}

		if (username.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("Имя аккаунта должно состоять только из букв и цифр!");
		}

		account->setUsername(username);

		cout << "Пароль: ";
		if (maskedPasswordInput(password, passwordLengthInputLimit) == false)
		{
			return;
		}

		if (password.length() < 3)
		{
			throw exception("Пароль аккаунта должен быть как мининмум три символа в длину!");
		}

		if (password.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890") != string::npos)
		{
			throw exception("Пароль аккаунта должен состоять только из букв и цирф!");
		}

		account->setPassword(password);

		accounts_.push_back(*(account));

		rewriteAccountsFile();

		StatisticsHandler::createStatistics(account->getUsername());

		setTextColor(Color::LIGHT_GREEN);
		if (account->getAdminAccess())
		{
			cout << endl << "Администратор успешно добавлен!" << endl << endl;
		}
		else
		{
			cout << endl << "Пользователь успешно добавлен!" << endl << endl;
		}
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception& ex)
	{
		setTextColor(Color::RED);
		if (account->getAdminAccess())
		{
			cout << endl << ex.what() << endl << "Администратор не добавлен!" << endl << endl;
		}
		else
		{
			cout << endl << ex.what() << endl << "Пользователь не добавлен!" << endl << endl;
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
			throw exception("Список аккаунтов пуст!");
		}

		itemSelection = new ItemSelection<Account>("Выберете удаляемый аккаунт: ", accounts_);

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
			throw exception("Невозможно удалить последнего администратора!");
		}

		CarHandler::resetReservedCarsByUsername(getAccount(index)->getUsername());

		StatisticsHandler::deleteStatistics(getAccount(index)->getUsername());

		accounts_.erase(accounts_.begin() + index);

		rewriteAccountsFile();

		system("cls");

		setTextColor(Color::LIGHT_GREEN);
		cout << "Аккаунт успешно удален!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		delete itemSelection;
	}
	catch(exception& ex)
	{
		system("cls");

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Аккаунт не удален!" << endl << endl;
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
			throw exception("Список аккаунтов пуст!");
		}

		itemSelection = new ItemSelection<Account>("Выберете аккаунт для редактирования: ", accounts_);

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

void AccountHandler::showCurrentAccountStatistics()
{
	AccountStatistics* statistic = nullptr;
	try
	{
		if (currentAccount_ == nullptr)
		{
			throw exception("Текущий аккаунт не установлен!");
		}
		if (StatisticsHandler::checkForStatistics(currentAccount_->getUsername()) == false)
		{
			throw exception("Статистика для этого аккаунта не найдена!");
		}

		statistic = StatisticsHandler::getAccountStatistics(currentAccount_->getUsername());

		system("cls");

		cout << "Статистика для текущего аккаунта:" << endl << endl
			 << "Имя аккаунта: " << statistic->getUsername() << endl
			 << "Количество купленных автомобилей: " << statistic->getTotalCarsPurchased() << endl
			 << "Наибольший чек: " << statistic->getLargestCheck() << "$" << endl
			 << "Средний чек: " << statistic->getAverageCheck() << "$" << endl
			 << "Общая сумма покупок: " << statistic->getTotalPurchases() << "$" << endl
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

	cout << "Общая статистика:" << endl << endl;

	cout << "Всего продано автомобилей: " << StatisticsHandler::getSoldCarsQuantity() << endl;
	cout << "Аккаунт, купивший наибольшее количество автомобилей: " << StatisticsHandler::getMostBuyedCarsUsername() << endl;
	cout << "Средний чек: " << StatisticsHandler::getAccountsAverageCheck() << "$" << endl;
	cout << "Наибольший чек: " << StatisticsHandler::getAccountsLargestCheck() << "$" << endl;
	cout << "Общая сумма покупок: " << StatisticsHandler::getAccountsTotalPurchaseAmount() << "$" << endl << endl;

	system("pause");
}

// Destructors
AccountHandler::~AccountHandler()
{
	delete accountToEdit_;
	delete currentAccount_;
}