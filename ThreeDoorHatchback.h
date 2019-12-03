#ifndef THREEDOORHATCHBACK_H
#define THREEDOORHATCHBACK_H


#include "CarHandler.h"

class ThreeDoorHatchback : public Car
{
public:
	ThreeDoorHatchback();
	ThreeDoorHatchback(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDriveType,
					   string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
					   double price, bool reserveStatus, string& reserverUsername);
	ThreeDoorHatchback(Car& car);

	~ThreeDoorHatchback();
};


#endif // THREEDOORHATCHBACK_H