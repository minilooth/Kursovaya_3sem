#ifndef FIVESEATMINIVAN_H
#define FIVESEATMINIVAN_H


#include "CarHandler.h"

class FiveSeatMinivan : public Car
{
public:
	FiveSeatMinivan();
	FiveSeatMinivan(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDriveType,
					string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
					double price, bool reserveStatus, string& reserverUsername);
	FiveSeatMinivan(Car& car);

	~FiveSeatMinivan();
};


#endif // FIVESEATMINIVAN_H