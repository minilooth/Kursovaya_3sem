#ifndef FIVEDOORHATCHBACK_H
#define FIVEDOORHATCHBACK_H


#include "CarHandler.h"



	class FiveDoorHatchback : public Car
	{
	public:
		FiveDoorHatchback();
		FiveDoorHatchback(const string& brand, const string& model, unsigned yearOfProduction, const string& transmissionType, const string& wheelDriveType,
			const string& engineType, double engineVolume, const string& bodyColor, const string& interiorColor, const string& interiorMaterial, double mileage,
			double price, bool reserveStatus, const string& reserverUsername);
		explicit FiveDoorHatchback(Car& car);

		~FiveDoorHatchback();
	};



#endif // FIVEDOORHATCHBACK_H