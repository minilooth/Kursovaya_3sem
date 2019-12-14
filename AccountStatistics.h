#ifndef ACCOUNTSTATISTICS_H
#define ACCOUNTSTATISTICS_H


#include "Includes.h"


namespace account
{

	class AccountStatistics
	{
		string username_;
		unsigned totalCarsPurchased_;
		double largestCheck_;
		double averageCheck_;
		double totalPurchases_;
	public:
		AccountStatistics();
		explicit AccountStatistics(const string& username);
		AccountStatistics(const string& username, unsigned totalCarsPurchased, double largestCheck, double averageCheck, double totalPurchases);

		void setUsername(const string& username);

		void addPurchaseAmount(double purchaseAmount);

		string getUsername() const;
		unsigned getTotalCarsPurchased() const;
		double getLargestCheck() const;
		double getAverageCheck() const;
		double getTotalPurchases() const;

		~AccountStatistics();
	};

}

#endif // ACCOUNTSTATISTICS_H