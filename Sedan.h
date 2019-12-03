#ifndef SEDAN_H
#define SEDAN_H


#include "CarHandler.h"

class Sedan : public Car
{
public:
	Sedan();
	Sedan(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDriveType,
		  string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
		  double price, bool reserveStatus, string& reserverUsername);
	Sedan(Car& car);

	~Sedan();
};


#endif // SEDAN_H