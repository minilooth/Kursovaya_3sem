#ifndef SEVENSEATMINIVAN_H
#define SEVENSEATMINIVAN_H


#include "Car.h"

class SevenSeatMinivan : public Car
{
	string bodyType_ = "Seven-seat minivan";
public:
	SevenSeatMinivan();
	SevenSeatMinivan(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
		string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
		double price, bool isReserved);

	string getBodyType();

	~SevenSeatMinivan();
};


#endif // SEVENSEATMINIVAN_H