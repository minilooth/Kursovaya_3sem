#ifndef LONGWHEELBASESEDAN_H
#define LONGWHEELBASESEDAN_H


#include "Car.h"

class LongWheelbaseSedan : public Car
{
	string bodyType_ = "Long wheel-base sedan";
public:
	LongWheelbaseSedan();
	LongWheelbaseSedan(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
					   string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
					   double price, bool isReserved);

	string getBodyType();

	~LongWheelbaseSedan();
};


#endif // LONGWHEELBASESEDAN_H