#ifndef CARHANDLER_H
#define CARHANDLER_H


#include "BodyTypeMenu.h"
#include "WheelDriveTypeMenu.h"
#include "EngineTypeMenu.h"
#include "TransmissionTypeMenu.h"
#include "CarEditMenu.h"

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

#include "CarPrinter.h"

using namespace std;

class CarHandler
{
	static vector<Car> cars_;
	static Car* carToEdit_;

	// Limits
	const static unsigned brandMaxInputLength = 10;
	const static unsigned modelMaxInputLength = 10;
	const static unsigned yearOfProductionMaxInputLength = 4;
	const static unsigned engineVolumeMaxInputLength = 3;
	const static unsigned bodyColorMaxInputLength = 9;
	const static unsigned interiorColorMaxInputLength = 9;
	const static unsigned interiorMaterialMaxInputLength = 9;
	const static unsigned mealeageMaxInputLength = 6;
	const static unsigned priceMaxInputLength = 6;

	// Files
	static void rewriteCarsFile();
	static void createReport(Car car);
public:
	//Constructors
	CarHandler();
	CarHandler(string fileName);

	// Count
	static unsigned countNewCars();
	static unsigned countNotReservedNewCars();
	static unsigned countUsedCars();
	static unsigned countNotReservedUsedCars();
	static unsigned countReservedCars();

	// Reset
	static void resetCarToEdit();
	static void resetReservedCarsByUsername(string username);

	// Gets
	static unsigned getCarIndex(Car* car);
	static Car* getCar(unsigned index);
	static vector<Car> getCars();
	static pair<vector<Car*>, vector<Car>> getNotReservedNewCars();
	static pair<vector<Car*>, vector<Car>> getNotReservedUsedCars();
	static pair<vector<Car*>, vector<Car>> getReservedCars();
	static vector<Car> getReservedCarsByUsername(string username);

	// Edit
	static void editBrand();
	static void editModel();
	static void editYearOfProduction();
	static void editBodyType();
	static void editTransmissionType();
	static void editWheelDriveType();
	static void editEngineType();
	static void editEngineVolume();
	static void editBodyColor();
	static void editInteriorColor();
	static void editInteriorMaterial();
	static void editMealeage();
	static void editPrice();
	static void editReserveStatus();
	static void editReserverUsername();
	static void editReservedCarsReserverUsername(string oldUsername, string newUsername);

	// Functional
	static void sellCar();
	static void showCars();
	static void showAccountReservedCars();
	static void showNewCars();
	static void showUsedCars();
	static void showEditCar();
	static void addCar();
	static void deleteCar();
	static void editCar();
	static void reserveNewCar();
	static void reserveUsedCar();
	//static bool findCar();

	~CarHandler();
};


#endif // CARHANDLER_H