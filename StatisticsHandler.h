#ifndef STATISTICSHANDLER_H
#define STATISTICSHANDLER_H


#include "AccountStatistics.h"

class StatisticsHandler
{
	static vector<AccountStatistics> statistics_;
public:
	StatisticsHandler();
	StatisticsHandler(const string& filename);

	static void rewriteStatisticsFile();

	static bool checkForStatistics(const string& username);

	static void createStatistics(const string& username);
	static void deleteStatistics(const string& username);

	static unsigned getStatisticsIndex(const string& username);
	static AccountStatistics* getAccountStatistics(unsigned index);
	static AccountStatistics* getAccountStatistics(const string& username);

	static string getMostBuyedCarsUsername();
	static unsigned getSoldCarsQuantity();
	static double getAccountsAverageCheck();
	static double getAccountsLargestCheck();
	static double getAccountsTotalPurchaseAmount();

	~StatisticsHandler();
};


#endif // STATISTICSHANDLER_H