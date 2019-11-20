#ifndef SEDAN_H
#define SEDAN_H


#include "Car.h"

class Sedan : public Car
{
	string bodyType_ = "Sedan";
public:
	Sedan();
	Sedan(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
		  string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
		  double price, bool isReserved);

	string getBodyType();

	~Sedan();
};


#endif // SEDAN_H