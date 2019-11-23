#ifndef FIVESEATMINIVAN_H
#define FIVESEATMINIVAN_H


#include "CarHandler.h"

class FiveSeatMinivan : public Car
{
public:
	FiveSeatMinivan();
	FiveSeatMinivan(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
					string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
					double price, bool isReserved);

	~FiveSeatMinivan();
};


#endif // FIVESEATMINIVAN_H