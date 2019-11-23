#ifndef CARHANDLER_H
#define CARHANDLER_H


#include "BodyTypeMenu.h"
#include "WheelDriveMenu.h"
#include "EngineTypeMenu.h"
#include "TransmissionTypeMenu.h"

#include "Car.h"
#include "Crossover.h"
#include "Cabriolet.h"
#include "Fivedoorhatchback.h"
#include "Fiveseatminivan.h"
#include "Fourdoorcoupe.h"
#include "Longwheelbasesedan.h"
#include "Sedan.h"
#include "Sevenseatminivan.h"
#include "Stationwagon.h"
#include "Threedoorhatchback.h"
#include "Twodoorcoupe.h"

#include "ItemSelection.h"

using namespace std;

class CarHandler
{
	static vector<Car> cars_;
	const static unsigned signsAfterDot_ = 1;
	const static unsigned inputBrandMaxLength = 10;
	const static unsigned inputModelMaxLength = 10;
	const static unsigned inputYearOfProductionMaxLength = 4;
	const static unsigned inputEngineVolumeMaxLength = 3;
	const static unsigned inputBodyColorMaxLength = 9;
	const static unsigned inputInteriorColorMaxLength = 9;
	const static unsigned inputInteriorMaterialMaxLength = 9;
	const static unsigned inputMealeageMaxLength = 6;
	const static unsigned inputPriceMaxLength = 6;
public:
	CarHandler();
	CarHandler(string fileName);
	
	static unsigned calculateBrandMaxLength();
	static unsigned calculateModelMaxLength();
	static unsigned calculateTransmissionTypeMaxLength();
	static unsigned calculateBodyTypeMaxLength();
	static unsigned calculateBodyColorMaxLength();
	static unsigned calculateInteriorColorMaxLength();
	static unsigned calculateInteriorMaterialMaxLength();
	static unsigned calculateMealeageMaxLength();
	static unsigned calculatePriceMaxLength();

	static unsigned getSignsAfterDotValue();

	static void showCars();
	static void showNewCars();
	static void showCarsForSale();
	static void addCar();
	static void deleteCar();
	//static bool findCar();
};


#endif // CARHANDLER_H