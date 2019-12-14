#ifndef CROSSOVER_H
#define CROSSOVER_H


#include "CarHandler.h"


namespace car
{

	class Crossover : public Car
	{
	public:
		Crossover();
		Crossover(const string& brand, const string& model, unsigned yearOfProduction, const string& transmissionType, const string& wheelDriveType,
			const string& engineType, double engineVolume, const string& bodyColor, const string& interiorColor, const string& interiorMaterial, double mileage,
			double price, bool reserveStatus, const string& reserverUsername);
		explicit Crossover(Car& car);

		~Crossover();
	};

}


#endif // CROSSOVER_H