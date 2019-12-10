#ifndef TWODOORCOUPE_H
#define TWODOORCOUPE_H


#include "CarHandler.h"

class TwoDoorCoupe : public Car
{
public:
	TwoDoorCoupe();
	TwoDoorCoupe(const string& brand, const string& model, unsigned yearOfProduction, const string& transmissionType, const string& wheelDriveType,
				 const string& engineType, double engineVolume, const string& bodyColor, const string& interiorColor, const string& interiorMaterial, double mileage,
				 double price, bool reserveStatus, const string& reserverUsername);
	explicit TwoDoorCoupe(Car& car);

	~TwoDoorCoupe();
};


#endif // TWODOORCOUPE_H