#ifndef FIVEDOORHATCHBACK_H
#define FIVEDOORHATCHBACK_H


#include "CarHandler.h"

class FiveDoorHatchback : public Car
{
public:
	FiveDoorHatchback();
	FiveDoorHatchback(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
		string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
		double price, bool isReserved);

	~FiveDoorHatchback();
};


#endif // FIVEDOORHATCHBACK_H