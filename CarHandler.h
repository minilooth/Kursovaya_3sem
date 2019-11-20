#ifndef CARHANDLER_H
#define CARHANDLER_H


#include "Includes.h"

#include "ConsoleMenu.h"
#include "BodyTypeMenu.h"
#include "WheelDriveMenu.h"
#include "EngineTypeMenu.h"
#include "TransmissionTypeMenu.h"

#include "Functions.h"
#include "Car.h"
#include "Crossover.h"
#include "Cabriolet.h"
#include "FiveDoorHatchback.h"
#include "FiveSeatMinivan.h"
#include "FourDoorCoupe.h"
#include "LongWheelbaseSedan.h"
#include "Sedan.h"
#include "SevenSeatMinivan.h"
#include "StationWagon.h"
#include "ThreeDoorHatchback.h"
#include "TwoDoorCoupe.h"

using namespace std;

class CarHandler
{
	static vector<Car> cars_;
	const static unsigned brandMaxLength = 10;
	const static unsigned modelMaxLength = 10;
	const static unsigned yearOfProductionMaxLength = 4;
	const static unsigned transmissionTypeMaxLength = 10;
	const static unsigned wheelDriveMaxLength = 10;
	const static unsigned engineTypeMaxLength = 10;
	const static unsigned engineVolumeMaxLength = 3;
	const static unsigned bodyTypeMaxLength = 10;
	const static unsigned bodyColorMaxLength = 10;
	const static unsigned interiorColorMaxLength = 10;
	const static unsigned interiorMaterialMaxLength = 10;
	const static unsigned mealeageMaxLength = 6;
	const static unsigned priceMaxLength = 7;
public:
	CarHandler();
	CarHandler(string fileName);
	
	static void showCars();
	static void showNewCars();
	static void showCarsForSale();
	static void addCar();
	//static bool findCar();
};


#endif // CARHANDLER_H