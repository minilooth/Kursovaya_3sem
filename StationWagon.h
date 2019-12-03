#ifndef STATIONWAGON_H
#define STATIONWAGON_H


#include "CarHandler.h"

class StationWagon : public Car
{
public:
	StationWagon();
	StationWagon(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDriveType,
				 string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
				 double price, bool reserveStatus, string& reserverUsername);
	StationWagon(Car& car);

	~StationWagon();
};


#endif // STATIONWAGON_H