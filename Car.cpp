#include "Car.h"

Car::Car()
{
	brand_ = "";
	model_ = "";
	yearOfProduction_ = 0;
	transmissionType_ = "";
	wheelDrive_ = "";
	engineType_ = "";
	engineVolume_ = 0.0;
	bodyColor_ = "";
	interiorColor_ = "";
	interiorMaterial_ = "";
	mealeage_ = 0.0;
	price_ = 0.0;
	isReserved_ = false;
}

Car::Car(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
		 string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial,
		 double mealeage, double price, bool isReserved)
{
	brand_ = brand;
	model_ = model;
	yearOfProduction_ = yearOfProduction;
	transmissionType_ = transmissionType_;
	wheelDrive_ = wheelDrive;
	engineType_ = engineType;
	engineVolume_ = engineVolume;
	bodyColor_ = bodyColor;
	interiorColor_ = interiorColor;
	interiorMaterial_ = interiorMaterial;
	mealeage_ = mealeage;
	price_ = price;
	isReserved_ = isReserved;
}

void Car::setBrand(string brand)
{
	brand_ = brand;
}

void Car::setModel(string model)
{
	model_ = model;
}

void Car::setYearOfProduction(unsigned yearOfProduction)
{
	yearOfProduction_ = yearOfProduction;
}

void Car::setTransmissionType(string transmissionType)
{
	transmissionType_ = transmissionType;
}

void Car::setWheelDrive(string wheelDrive)
{
	wheelDrive_ = wheelDrive;
}

void Car::setEngineType(string engineType)
{
	engineType_ = engineType;
}

void Car::setEngineVolume(double engineVolume)
{
	engineVolume_ = engineVolume_;
}

void Car::setBodyColor(string bodyColor)
{
	bodyColor_ = bodyColor;
}

void Car::setInteriorColor(string interiorColor)
{
	interiorColor_ = interiorColor;
}

void Car::setInteriorMaterial(string interiorMaterial)
{
	interiorMaterial_ = interiorMaterial;
}

void Car::setMealeage(double mealeage)
{
	mealeage_ = mealeage;
}

void Car::setPrice(double price)
{
	price_ = price;
}

void Car::setIsReserved(bool isReserved)
{
	isReserved_ = isReserved;
}

string Car::getBrand()
{
	return brand_;
}

string Car::getModel()
{
	return model_;
}

unsigned Car::getYearOfProduction()
{
	return yearOfProduction_;
}

string Car::getTransmissionType()
{
	return transmissionType_;
}

string Car::getWheelDrive()
{
	return wheelDrive_;
}

string Car::getEngineType()
{
	return engineType_;
}

double Car::getEngineVolume()
{
	return engineVolume_;
}

string Car::getBodyColor()
{
	return bodyColor_;
}

string Car::getInteriorColor()
{
	return interiorColor_;
}

string Car::getInteriorMaterial()
{
	return interiorMaterial_;
}

double Car::getMealeage()
{
	return mealeage_;
}

double Car::getPrice()
{
	return price_;
}

bool Car::getIsReserved()
{
	return isReserved_;
}

Car::~Car() = default;