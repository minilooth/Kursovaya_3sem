#ifndef CABRIOLET_H
#define CABRIOLET_H

#include "CarHandler.h"

class Cabriolet : public Car
{
public:
	Cabriolet();
	Cabriolet(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
			  string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
			  double price, bool isReserved);

	~Cabriolet();
};


#endif // CABRIOLET_H