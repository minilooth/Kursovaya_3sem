#ifndef CABRIOLET_H
#define CABRIOLET_H


#include "Car.h"

class Cabriolet : public Car
{
	string bodyType_ = "Cabriolet";
public:
	Cabriolet();
	Cabriolet(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
			  string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
			  double price, bool isReserved);

	string getBodyType();

	~Cabriolet();
};


#endif // CABRIOLET_H