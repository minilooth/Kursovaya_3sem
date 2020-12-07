#ifndef LONGWHEELBASESEDAN_H
#define LONGWHEELBASESEDAN_H


#include "CarHandler.h"


	class LongWheelbaseSedan : public Car
	{
	public:
		LongWheelbaseSedan();
		LongWheelbaseSedan(const string& brand, const string& model, unsigned yearOfProduction, const string& transmissionType, const string& wheelDriveType,
			const string& engineType, double engineVolume, const string& bodyColor, const string& interiorColor, const string& interiorMaterial, double mileage,
			double price, bool reserveStatus, const string& reserverUsername);
		explicit LongWheelbaseSedan(Car& car);

		~LongWheelbaseSedan();
	};



#endif // LONGWHEELBASESEDAN_H