#include "StationWagon.h"

using namespace car;

StationWagon::StationWagon()
{
	brand_ = "";
	model_ = "";
	yearOfProduction_ = 0;
	transmissionType_ = "";
	bodyType_ = "Универсал";
	wheelDriveType_ = "";
	engineType_ = "";
	engineVolume_ = 0.0;
	bodyColor_ = "";
	interiorColor_ = "";
	interiorMaterial_ = "";
	mileage_ = 0.0;
	price_ = 0.0;
	reserveStatus_ = false;
	reserverUsername_ = "";
}

StationWagon::StationWagon(const string& brand, const string& model, unsigned yearOfProduction, const string& transmissionType, const string& wheelDriveType,
						   const string& engineType, double engineVolume, const string& bodyColor, const string& interiorColor, const string& interiorMaterial, double mileage,
						   double price, bool reserveStatus, const string& reserverUsername)
{
	brand_ = brand;
	model_ = model;
	yearOfProduction_ = yearOfProduction;
	transmissionType_ = transmissionType;
	bodyType_ = "Универсал";
	wheelDriveType_ = wheelDriveType;
	engineType_ = engineType;
	engineVolume_ = engineVolume;
	bodyColor_ = bodyColor;
	interiorColor_ = interiorColor;
	interiorMaterial_ = interiorMaterial;
	mileage_ = mileage;
	price_ = price;
	reserveStatus_ = reserveStatus;
	reserverUsername_ = reserverUsername;
}

StationWagon::StationWagon(Car& car)
{
	brand_ = car.getBrand();
	model_ = car.getModel();
	yearOfProduction_ = car.getYearOfProduction();
	transmissionType_ = car.getTransmissionType();
	bodyType_ = "Универсал";
	wheelDriveType_ = car.getWheelDriveType();
	engineType_ = car.getEngineType();
	engineVolume_ = car.getEngineVolume();
	bodyColor_ = car.getBodyColor();
	interiorColor_ = car.getInteriorColor();
	interiorMaterial_ = car.getInteriorMaterial();
	mileage_ = car.getMileage();
	price_ = car.getPrice();
	reserveStatus_ = car.getReserveStatus();
	reserverUsername_ = car.getReserverUsername();
}

StationWagon::~StationWagon() = default;