#ifndef SEVENSEATMINIVAN_H
#define SEVENSEATMINIVAN_H


#include "CarHandler.h"

class SevenSeatMinivan : public Car
{
public:
	SevenSeatMinivan();
	SevenSeatMinivan(const string& brand, const string& model, unsigned yearOfProduction, const string& transmissionType, const string& wheelDriveType,
					 const string& engineType, double engineVolume, const string& bodyColor, const string& interiorColor, const string& interiorMaterial, double mileage,
					 double price, bool reserveStatus, const string& reserverUsername);
	explicit SevenSeatMinivan(Car& car);

	~SevenSeatMinivan();
};


#endif // SEVENSEATMINIVAN_H