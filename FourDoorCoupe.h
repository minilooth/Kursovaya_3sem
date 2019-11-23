#ifndef FOURDOORCOUPE_H
#define FOURDOORCOUPE_H


#include "CarHandler.h"

class FourDoorCoupe : public Car
{
public:
	FourDoorCoupe();
	FourDoorCoupe(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
				  string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
				  double price, bool isReserved);

	~FourDoorCoupe();
};


#endif // FOURDOORCOUPE_H