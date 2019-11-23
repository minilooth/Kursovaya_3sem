#ifndef SEDAN_H
#define SEDAN_H


#include "CarHandler.h"

class Sedan : public Car
{
public:
	Sedan();
	Sedan(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
		  string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
		  double price, bool isReserved);

	~Sedan();
};


#endif // SEDAN_H