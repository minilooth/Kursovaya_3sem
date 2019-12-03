#ifndef CABRIOLET_H
#define CABRIOLET_H

#include "CarHandler.h"

class Cabriolet : public Car
{
public:
	Cabriolet();
	Cabriolet(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDriveType,
			  string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
			  double price, bool reserveStatus, string& reserverUsername);
	Cabriolet(Car& car);

	~Cabriolet();
};


#endif // CABRIOLET_H