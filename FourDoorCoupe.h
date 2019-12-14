#ifndef FOURDOORCOUPE_H
#define FOURDOORCOUPE_H


#include "CarHandler.h"


namespace car
{

	class FourDoorCoupe : public Car
	{
	public:
		FourDoorCoupe();
		FourDoorCoupe(const string& brand, const string& model, unsigned yearOfProduction, const string& transmissionType, const string& wheelDriveType,
			const string& engineType, double engineVolume, const string& bodyColor, const string& interiorColor, const string& interiorMaterial, double mileage,
			double price, bool reserveStatus, const string& reserverUsername);
		explicit FourDoorCoupe(Car& car);

		~FourDoorCoupe();
	};

}


#endif // FOURDOORCOUPE_H