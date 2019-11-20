#ifndef THREEDOORHATCHBACK_H
#define THREEDOORHATCHBACK_H


#include "Car.h"

class ThreeDoorHatchback : public Car
{
	string bodyType_ = "Three-door hatchback";
public:
	ThreeDoorHatchback();
	ThreeDoorHatchback(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
					   string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
					   double price, bool isReserved);

	string getBodyType();

	~ThreeDoorHatchback();
};


#endif // THREEDOORHATCHBACK_H