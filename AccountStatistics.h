#ifndef ACCOUNTSTATISTICS_H
#define ACCOUNTSTATISTICS_H


#include "Includes.h"

class AccountStatistics
{
	string username_;
	unsigned totalCarsPurchased_;
	double largestCheck_;
	double averageCheck_;
	double totalPurchases_;
public:
	AccountStatistics();
	AccountStatistics(const string& username);
	AccountStatistics(const string& username, unsigned totalCarsPurchased, double largestCheck, double averageCheck, double totalPurchases);

	void setUsername(const string& username);

	void addPurchaseAmount(double purchaseAmount);

	string getUsername();
	unsigned getTotalCarsPurchased();
	double getLargestCheck();
	double getAverageCheck();
	double getTotalPurchases();

	~AccountStatistics();
};


#endif // ACCOUNTSTATISTICS_H