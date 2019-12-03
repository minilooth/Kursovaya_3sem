#ifndef SEVENSEATMINIVAN_H
#define SEVENSEATMINIVAN_H


#include "CarHandler.h"

class SevenSeatMinivan : public Car
{
public:
	SevenSeatMinivan();
	SevenSeatMinivan(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDriveType,
					 string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
					 double price, bool reserveStatus, string& reserverUsername);
	SevenSeatMinivan(Car& car);

	~SevenSeatMinivan();
};


#endif // SEVENSEATMINIVAN_H