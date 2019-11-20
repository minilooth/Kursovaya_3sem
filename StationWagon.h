#ifndef STATIONWAGON_H
#define STATIONWAGON_H


#include "Car.h"

class StationWagon : public Car
{
	string bodyType_ = "Station wagon";
public:
	StationWagon();
	StationWagon(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
		string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
		double price, bool isReserved);

	string getBodyType();

	~StationWagon();
};


#endif // STATIONWAGON_H