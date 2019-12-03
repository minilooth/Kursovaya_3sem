#ifndef FOURDOORCOUPE_H
#define FOURDOORCOUPE_H


#include "CarHandler.h"

class FourDoorCoupe : public Car
{
public:
	FourDoorCoupe();
	FourDoorCoupe(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDriveType,
				  string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
				  double price, bool reserveStatus, string& reserverUsername);
	FourDoorCoupe(Car& car);

	~FourDoorCoupe();
};


#endif // FOURDOORCOUPE_H