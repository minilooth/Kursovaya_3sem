#ifndef TWODOORCOUPE_H
#define TWODOORCOUPE_H


#include "Car.h"

class TwoDoorCoupe : public Car
{
	string bodyType_ = "Two-door coupe";
public:
	TwoDoorCoupe();
	TwoDoorCoupe(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
		string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
		double price, bool isReserved);

	string getBodyType();

	~TwoDoorCoupe();
};


#endif // TWODOORCOUPE_H