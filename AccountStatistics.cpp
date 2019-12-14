#include "AccountStatistics.h"

using namespace account;

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

string AccountStatistics::getUsername() const
{
	return username_;
}

unsigned AccountStatistics::getTotalCarsPurchased() const
{
	return totalCarsPurchased_;
}

double AccountStatistics::getLargestCheck() const
{
	return largestCheck_;
}

double AccountStatistics::getAverageCheck() const
{
	return averageCheck_;
}

double AccountStatistics::getTotalPurchases() const
{
	return totalPurchases_;
}

AccountStatistics::~AccountStatistics() = default;