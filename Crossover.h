#ifndef CROSSOVER_H
#define CROSSOVER_H


#include "Car.h"

class Crossover : public Car
{
	string bodyType_ = "Crossover";
public:
	Crossover();
	Crossover(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
		string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
		double price, bool isReserved);

	string getBodyType();

	~Crossover();
};


#endif // CROSSOVER_H