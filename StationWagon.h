#ifndef STATIONWAGON_H
#define STATIONWAGON_H


#include "CarHandler.h"

class StationWagon : public Car
{
public:
	StationWagon();
	StationWagon(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
				 string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
				 double price, bool isReserved);

	~StationWagon();
};


#endif // STATIONWAGON_H