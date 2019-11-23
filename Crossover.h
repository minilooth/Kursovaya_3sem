#ifndef CROSSOVER_H
#define CROSSOVER_H


#include "CarHandler.h"

class Crossover : public Car
{
public:
	Crossover();
	Crossover(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
		string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
		double price, bool isReserved);

	~Crossover();
};


#endif // CROSSOVER_H