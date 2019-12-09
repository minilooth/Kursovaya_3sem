#include "StatisticsHandler.h"

vector<AccountStatistics> StatisticsHandler::statistics_;

StatisticsHandler::StatisticsHandler()
{
	string token;

	string username;
	unsigned totalCarsPurchased;
	double largestCheck;
	double averageCheck;
	double totalPurchases;

	AccountStatistics* newStatistics = nullptr;

	ifstream statisticsFile(R"(statistics.txt)");

	if (statisticsFile.is_open())
	{
		while (!statisticsFile.eof())
		{
			if (getline(statisticsFile, token, '\n'))
			{
				auto data = stringSplitter(token);

				username = data.at(0);
				totalCarsPurchased = stoul(data.at(1));
				largestCheck = stod(data.at(2));
				averageCheck = stod(data.at(3));
				totalPurchases = stod(data.at(4));

				newStatistics = new AccountStatistics(username, totalCarsPurchased, largestCheck, averageCheck, totalPurchases);

				statistics_.push_back(*newStatistics);
			}
		}
		statisticsFile.close();
		delete newStatistics;
	}
}

StatisticsHandler::StatisticsHandler(const string& filename)
{
	string token;

	string username;
	unsigned totalCarsPurchased;
	double largestCheck;
	double averageCheck;
	double totalPurchases;

	AccountStatistics* newStatistics = nullptr;

	ifstream statisticsFile(filename);

	if (statisticsFile.is_open())
	{
		while (!statisticsFile.eof())
		{
			if (getline(statisticsFile, token, '\n'))
			{
				auto data = stringSplitter(token);

				username = data.at(0);
				totalCarsPurchased = stoul(data.at(1));
				largestCheck = stod(data.at(2));
				averageCheck = stod(data.at(3));
				totalPurchases = stod(data.at(4));

				newStatistics = new AccountStatistics(username, totalCarsPurchased, largestCheck, averageCheck, totalPurchases);

				statistics_.push_back(*newStatistics);
			}
		}
		statisticsFile.close();
		delete newStatistics;
	}
}

void StatisticsHandler::rewriteStatisticsFile()
{
	ofstream statisticsFile;
	statisticsFile.open(R"(statistics.txt)", ios::trunc);
	if (statisticsFile.is_open())
	{
		for (unsigned i = 0; i < statistics_.size(); i++)
		{
			statisticsFile << statistics_.at(i).getUsername() << ";"
						   << statistics_.at(i).getTotalCarsPurchased() << ";"
						   << statistics_.at(i).getLargestCheck() << ";"
						   << statistics_.at(i).getAverageCheck() << ";"
						   << statistics_.at(i).getTotalPurchases()
						   << endl;
		}
		statisticsFile.close();
	}
}

void StatisticsHandler::createStatistics(const string& username)
{
	AccountStatistics* newStatistics = new AccountStatistics(username);

	statistics_.push_back(*newStatistics);

	rewriteStatisticsFile();
}

void StatisticsHandler::deleteStatistics(const string& username)
{
	statistics_.erase(statistics_.begin() + getStatisticsIndex(username));

	rewriteStatisticsFile();
}

bool StatisticsHandler::checkForStatistics(const string& username)
{
	for (unsigned i = 0; i < statistics_.size(); i++)
	{
		if (statistics_.at(i).getUsername() == username)
		{
			return true;
		}
	}
	return false;
}


unsigned StatisticsHandler::getStatisticsIndex(const string& username)
{
	unsigned index = 0;
	for (unsigned i = 0; i < statistics_.size(); i++)
	{
		if (statistics_.at(i).getUsername() == username)
		{
			index = i;
			break;
		}
	}
	return index;
}

AccountStatistics* StatisticsHandler::getAccountStatistics(unsigned index)
{
	return &(statistics_.at(index));
}

AccountStatistics* StatisticsHandler::getAccountStatistics(const string& username)
{
	for (unsigned i = 0; i < statistics_.size(); i++)
	{
		if (statistics_.at(i).getUsername() == username)
		{
			return &(statistics_.at(i));
		}
	}
	return nullptr;
}

unsigned StatisticsHandler::getSoldCarsQuantity()
{
	unsigned quantity = 0;
	for (unsigned i = 0; i < statistics_.size(); i++)
	{
		quantity += statistics_.at(i).getTotalCarsPurchased();
	}
	return quantity;
}

string StatisticsHandler::getMostBuyedCarsUsername()
{
	unsigned maxQuantity = 0;
	unsigned index = 0;
	for (unsigned i = 0; i < statistics_.size(); i++)
	{
		if (maxQuantity <= statistics_.at(i).getTotalCarsPurchased())
		{
			maxQuantity = statistics_.at(i).getTotalCarsPurchased();
			index = i;
		}
	}
	return statistics_.at(index).getUsername();
}

double StatisticsHandler::getAccountsAverageCheck()
{
	double averageCheck = 0.0;
	for (unsigned i = 0; i < statistics_.size(); i++)
	{
		averageCheck += statistics_.at(i).getAverageCheck();
	}
	return (averageCheck / statistics_.size());
}

double StatisticsHandler::getAccountsLargestCheck()
{
	double check = 0.0;
	for (unsigned i = 0; i < statistics_.size(); i++)
	{
		if (check <= statistics_.at(i).getLargestCheck())
		{
			check = statistics_.at(i).getLargestCheck();
		}
	}
	return check;
}

double StatisticsHandler::getAccountsTotalPurchaseAmount()
{
	double totalPurchases = 0.0;
	for (unsigned i = 0; i < statistics_.size(); i++)
	{
		totalPurchases += statistics_.at(i).getTotalPurchases();
	}
	return totalPurchases;
}

StatisticsHandler::~StatisticsHandler() = default;
