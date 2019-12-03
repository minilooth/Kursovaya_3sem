#ifndef FIVEDOORHATCHBACK_H
#define FIVEDOORHATCHBACK_H


#include "CarHandler.h"

class FiveDoorHatchback : public Car
{
public:
	FiveDoorHatchback();
	FiveDoorHatchback(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDriveType,
					  string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
					  double price, bool reserveStatus, string& reserverUsername);
	FiveDoorHatchback(Car& car);

	~FiveDoorHatchback();
};


#endif // FIVEDOORHATCHBACK_H