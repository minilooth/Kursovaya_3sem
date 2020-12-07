#ifndef STATIONWAGON_H
#define STATIONWAGON_H


#include "CarHandler.h"



	class StationWagon : public Car
	{
	public:
		StationWagon();
		StationWagon(const string& brand, const string& model, unsigned yearOfProduction, const string& transmissionType, const string& wheelDriveType,
			const string& engineType, double engineVolume, const string& bodyColor, const string& interiorColor, const string& interiorMaterial, double mileage,
			double price, bool reserveStatus, const string& reserverUsername);
		explicit StationWagon(Car& car);

		~StationWagon();
	};



#endif // STATIONWAGON_H