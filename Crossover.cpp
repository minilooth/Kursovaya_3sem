#include "Crossover.h"

Crossover::Crossover()
{
	brand_ = "";
	model_ = "";
	yearOfProduction_ = 0;
	transmissionType_ = "";
	bodyType_ = "Crossover";
	wheelDriveType_ = "";
	engineType_ = "";
	engineVolume_ = 0.0;
	bodyColor_ = "";
	interiorColor_ = "";
	interiorMaterial_ = "";
	mealeage_ = 0.0;
	price_ = 0.0;
	reserveStatus_ = false;
	reserverUsername_ = "";
}

Crossover::Crossover(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDriveType,
					 string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
					 double price, bool reserveStatus, string& reserverUsername)
{
	brand_ = brand;
	model_ = model;
	yearOfProduction_ = yearOfProduction;
	transmissionType_ = transmissionType;
	bodyType_ = "Crossover";
	wheelDriveType_ = wheelDriveType;
	engineType_ = engineType;
	engineVolume_ = engineVolume;
	bodyColor_ = bodyColor;
	interiorColor_ = interiorColor;
	interiorMaterial_ = interiorMaterial;
	mealeage_ = mealeage;
	price_ = price;
	reserveStatus_ = reserveStatus;
	reserverUsername_ = reserverUsername;
}

Crossover::Crossover(Car& car)
{
	brand_ = car.getBrand();
	model_ = car.getModel();
	yearOfProduction_ = car.getYearOfProduction();
	transmissionType_ = car.getTransmissionType();
	bodyType_ = "Crossover";
	wheelDriveType_ = car.getWheelDriveType();
	engineType_ = car.getEngineType();
	engineVolume_ = car.getEngineVolume();
	bodyColor_ = car.getBodyColor();
	interiorColor_ = car.getInteriorColor();
	interiorMaterial_ = car.getInteriorMaterial();
	mealeage_ = car.getMealeage();
	price_ = car.getPrice();
	reserveStatus_ = car.getReserveStatus();
	reserverUsername_ = car.getReserverUsername();
}

Crossover::~Crossover() = default;