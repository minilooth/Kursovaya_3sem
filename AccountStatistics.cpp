#include "AccountStatistics.h"

AccountStatistics::AccountStatistics()
{
	username_ = "";
	totalCarsPurchased_ = 0;
	largestCheck_ = 0.0;
	averageCheck_ = 0.0;
	totalPurchases_ = 0.0;
}

AccountStatistics::AccountStatistics(const string& username)
{
	username_ = username;
	totalCarsPurchased_ = 0;
	largestCheck_ = 0.0;
	averageCheck_ = 0.0;
	totalPurchases_ = 0.0;
}

AccountStatistics::AccountStatistics(const string& username, unsigned totalCarsPurchased, double largestCheck, double averageCheck, double totalPurchases)
{
	username_ = username;
	totalCarsPurchased_ = totalCarsPurchased;
	largestCheck_ = largestCheck;
	averageCheck_ = averageCheck;
	totalPurchases_ = totalPurchases;
}

void AccountStatistics::setUsername(const string& username)
{
	username_ = username;
}

void AccountStatistics::addPurchaseAmount(double purchaseAmount)
{
	if (largestCheck_ < purchaseAmount)
	{
		largestCheck_ = purchaseAmount;
	}

	totalCarsPurchased_++;
	totalPurchases_ += purchaseAmount;
	averageCheck_ = totalPurchases_ / totalCarsPurchased_;
}

string AccountStatistics::getUsername()
{
	return username_;
}

unsigned AccountStatistics::getTotalCarsPurchased()
{
	return totalCarsPurchased_;
}

double AccountStatistics::getLargestCheck()
{
	return largestCheck_;
}

double AccountStatistics::getAverageCheck()
{
	return averageCheck_;
}

double AccountStatistics::getTotalPurchases()
{
	return totalPurchases_;
}

AccountStatistics::~AccountStatistics() = default;