#ifndef TWODOORCOUPE_H
#define TWODOORCOUPE_H


#include "CarHandler.h"

class TwoDoorCoupe : public Car
{
public:
	TwoDoorCoupe();
	TwoDoorCoupe(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
				 string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
				 double price, bool isReserved);

	~TwoDoorCoupe();
};


#endif // TWODOORCOUPE_H