#ifndef SEVENSEATMINIVAN_H
#define SEVENSEATMINIVAN_H


#include "CarHandler.h"

class SevenSeatMinivan : public Car
{
public:
	SevenSeatMinivan();
	SevenSeatMinivan(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
					 string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
					 double price, bool isReserved);

	~SevenSeatMinivan();
};


#endif // SEVENSEATMINIVAN_H