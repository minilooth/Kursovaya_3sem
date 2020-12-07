#ifndef THREEDOORHATCHBACK_H
#define THREEDOORHATCHBACK_H


#include "CarHandler.h"



	class ThreeDoorHatchback : public Car
	{
	public:
		ThreeDoorHatchback();
		ThreeDoorHatchback(const string& brand, const string& model, unsigned yearOfProduction, const string& transmissionType, const string& wheelDriveType,
			const string& engineType, double engineVolume, const string& bodyColor, const string& interiorColor, const string& interiorMaterial, double mileage,
			double price, bool reserveStatus, const string& reserverUsername);
		explicit ThreeDoorHatchback(Car& car);

		~ThreeDoorHatchback();
	};



#endif // THREEDOORHATCHBACK_H