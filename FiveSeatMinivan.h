#ifndef FIVESEATMINIVAN_H
#define FIVESEATMINIVAN_H


#include "CarHandler.h"


	class FiveSeatMinivan : public Car
	{
	public:
		FiveSeatMinivan();
		FiveSeatMinivan(const string& brand, const string& model, unsigned yearOfProduction, const string& transmissionType, const string& wheelDriveType,
			const string& engineType, double engineVolume, const string& bodyColor, const string& interiorColor, const string& interiorMaterial, double mileage,
			double price, bool reserveStatus, const string& reserverUsername);
		explicit FiveSeatMinivan(Car& car);

		~FiveSeatMinivan();
	};



#endif // FIVESEATMINIVAN_H