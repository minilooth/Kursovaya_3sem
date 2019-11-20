#ifndef FIVEDOORHATCHBACK_H
#define FIVEDOORHATCHBACK_H


#include "Car.h"

class FiveDoorHatchback : public Car
{
	string bodyType_ = "Five-door hatchback";
public:
	FiveDoorHatchback();
	FiveDoorHatchback(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
		string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
		double price, bool isReserved);

	string getBodyType();

	~FiveDoorHatchback();
};


#endif // FIVEDOORHATCHBACK_H