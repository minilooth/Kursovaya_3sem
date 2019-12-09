#ifndef CARHANDLER_H
#define CARHANDLER_H

#define _CRT_SECURE_NO_WARNINGS

#include "BodyTypeMenu.h"
#include "WheelDriveTypeMenu.h"
#include "EngineTypeMenu.h"
#include "TransmissionTypeMenu.h"
#include "CarEditMenu.h"
#include "TypeOfSortingMenu.h"

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
#include "CarFiltering.h"

#include "StatisticsHandler.h"

using namespace std;

const unsigned brandMaxInputLength = 10;
const unsigned modelMaxInputLength = 10;
const unsigned yearOfProductionMaxInputLength = 4;
const unsigned engineVolumeMaxInputLength = 3;
const unsigned bodyColorMaxInputLength = 9;
const unsigned interiorColorMaxInputLength = 9;
const unsigned interiorMaterialMaxInputLength = 9;
const unsigned mealeageMaxInputLength = 6;
const unsigned priceMaxInputLength = 6;

class CarHandler
{
	static vector<Car> cars_;
	static Car* carToEdit_;

	// Files
	static void rewriteCarsFile();
	static string createReport(Car& car);

	// Equal
	inline static bool isBodyTypesNotEqual(Car& car);
	inline static bool isWheelDriveTypesNotEqual(Car& car);
	inline static bool isTransmissionTypesNotEqual(Car& car);

	// Compare
	inline static bool compareYearsOfProductionsAscending(Car& firstCar, Car& secondCar);
	inline static bool compareYearsOfProductionsDescending(Car& firstCar, Car& secondCar);
	inline static bool compareEngineVolumesAscending(Car& firstCar, Car& secondCar);
	inline static bool compareEngineVolumesDescending(Car& firstCar, Car& secondCar);
	inline static bool comparePricesAscending(Car& firstCar, Car& secondCar);
	inline static bool comparePricesDescending(Car& firstCar, Car& secondCar);
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

	// Set
	static void setFilterByBodyType();
	static void setFilterByWheelDriveType();
	static void setFilterByTransmissionType();

	// Gets
	static unsigned getCarIndex(Car* car);
	inline static Car* getCar(unsigned index);
	static vector<Car> getCars();
	static pair<vector<Car*>, vector<Car>> getNotReservedNewCars();
	static pair<vector<Car*>, vector<Car>> getNotReservedUsedCars();
	static pair<vector<Car*>, vector<Car>> getReservedCars();
	static vector<Car> getReservedCarsByUsername(string username);
	static vector<Car> getFilteredCars();
	static vector<Car> getCarsByBrand(const string& brand);
	static vector<Car> getCarsByModel(const string& brand);
	static vector<Car> getCarsByYearOfProduction(const unsigned yearOfProduction);
	static vector<Car> getCarsByEngineType(const string& engineType);

	// Search
	static void searchByBrand();
	static void searchByModel();
	static void searchByYearOfProduction();
	static void searchByEngineType();

	// Sorting
	static void sortByYearOfProduction();
	static void sortByEngineVolume();
	static void sortByPrice();

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
	static void showFilteredCars();
	static void addCar();
	static void deleteCar();
	static void editCar();
	static void reserveNewCar();
	static void reserveUsedCar();

	~CarHandler();
};


#endif // CARHANDLER_H