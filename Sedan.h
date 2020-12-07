#ifndef SEDAN_H
#define SEDAN_H


#include "CarHandler.h"



	class Sedan : public Car
	{
	public:
		Sedan();
		Sedan(const string& brand, const string& model, unsigned yearOfProduction, const string& transmissionType, const string& wheelDriveType,
			const string& engineType, double engineVolume, const string& bodyColor, const string& interiorColor, const string& interiorMaterial, double mileage,
			double price, bool reserveStatus, const string& reserverUsername);
		explicit Sedan(Car& car);

		~Sedan();
	};




#endif // SEDAN_H