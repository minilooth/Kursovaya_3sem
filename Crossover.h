#ifndef CROSSOVER_H
#define CROSSOVER_H


#include "CarHandler.h"

class Crossover : public Car
{
public:
	Crossover();
	Crossover(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDriveType,
			  string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
			  double price, bool reserveStatus, string& reserverUsername);
	Crossover(Car& car);

	~Crossover();
};


#endif // CROSSOVER_H