#ifndef FOURDOORCOUPE_H
#define FOURDOORCOUPE_H


#include "Car.h"

class FourDoorCoupe : public Car
{
	string bodyType_ = "Four-door coupe";
public:
	FourDoorCoupe();
	FourDoorCoupe(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
				  string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
				  double price, bool isReserved);

	string getBodyType();

	~FourDoorCoupe();
};


#endif // FOURDOORCOUPE_H