#ifndef CABRIOLET_H
#define CABRIOLET_H


#include "CarHandler.h"


namespace car
{

	class Cabriolet : public Car
	{
	public:
		Cabriolet();
		Cabriolet(const string& brand, const string& model, unsigned yearOfProduction, const string& transmissionType, const string& wheelDriveType,
			const string& engineType, double engineVolume, const string& bodyColor, const string& interiorColor, const string& interiorMaterial, double mileage,
			double price, bool reserveStatus, const string& reserverUsername);
		explicit Cabriolet(Car& car);

		~Cabriolet();
	};

}


#endif // CABRIOLET_H