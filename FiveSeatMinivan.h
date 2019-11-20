#ifndef FIVESEATMINIVAN_H
#define FIVESEATMINIVAN_H


#include "Car.h"

class FiveSeatMinivan : public Car
{
	string bodyType_ = "Five-seat minivan";
public:
	FiveSeatMinivan();
	FiveSeatMinivan(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
		string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
		double price, bool isReserved);

	string getBodyType();

	~FiveSeatMinivan();
};


#endif // FIVESEATMINIVAN_H