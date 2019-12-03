#ifndef LONGWHEELBASESEDAN_H
#define LONGWHEELBASESEDAN_H


#include "CarHandler.h"

class LongWheelbaseSedan : public Car
{
public:
	LongWheelbaseSedan();
	LongWheelbaseSedan(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDriveType,
					   string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
					   double price, bool reserveStatus, string& reserverUsername);
	LongWheelbaseSedan(Car& car);

	~LongWheelbaseSedan();
};


#endif // LONGWHEELBASESEDAN_H