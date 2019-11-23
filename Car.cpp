#include "CarHandler.h"

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
	transmissionType_ = transmissionType;
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
	engineVolume_ = engineVolume;
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

string Car::getBodyType()
{
	return bodyType_;
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

ostream& operator<<(ostream& out, const Car& car)
{
	unsigned brandLabelLength = CarHandler::calculateBrandMaxLength() < 5 ? 5 : CarHandler::calculateBrandMaxLength();
	unsigned modelLabelLength = CarHandler::calculateModelMaxLength() < 5 ? 5 : CarHandler::calculateModelMaxLength();
	unsigned bodyTypeLabelLength = CarHandler::calculateBodyTypeMaxLength() < 9 ? 9 : CarHandler::calculateBodyTypeMaxLength();
	unsigned bodyColorLabelLength = CarHandler::calculateBodyColorMaxLength() < 10 ? 10 : CarHandler::calculateBodyColorMaxLength();
	unsigned interiorColorLabelLength = CarHandler::calculateInteriorColorMaxLength() < 14 ? 14 : CarHandler::calculateInteriorColorMaxLength();
	unsigned interiorMaterialLabelLength = CarHandler::calculateInteriorMaterialMaxLength() < 17 ? 17 : CarHandler::calculateInteriorMaterialMaxLength();
	unsigned mealeageLableLength = (CarHandler::calculateMealeageMaxLength() < 8 ? 8 : CarHandler::calculateMealeageMaxLength()) + 3;
	unsigned priceLabelLength = (CarHandler::calculatePriceMaxLength() < 5 ? 5 : CarHandler::calculatePriceMaxLength()) + 2;
	unsigned yearOfProductionLabelLength = 18;
	unsigned transmissionTypeLabelLength = 12;
	unsigned wheelDriveLabelLength = 11;
	unsigned engineTypeLabelLength = 11;
	unsigned engineVolumeLabelLength = 13;
	unsigned reserveStatusLabelLength = 14;

	out << "|" << left << setw(brandLabelLength) << car.brand_
		<< "|" << left << setw(modelLabelLength) << car.model_
		<< "|" << left << setw(yearOfProductionLabelLength) << car.yearOfProduction_
		<< "|" << left << setw(bodyTypeLabelLength) << car.bodyType_
		<< "|" << left << setw(transmissionTypeLabelLength) << car.transmissionType_
		<< "|" << left << setw(wheelDriveLabelLength) << car.wheelDrive_
		<< "|" << left << setw(engineTypeLabelLength) << car.engineType_
		<< "|" << left << setw(engineVolumeLabelLength) << setprecision(CarHandler::getSignsAfterDotValue()) << fixed << car.engineVolume_
		<< "|" << left << setw(bodyColorLabelLength) << car.bodyColor_
		<< "|" << left << setw(interiorColorLabelLength) << car.interiorColor_
		<< "|" << left << setw(interiorMaterialLabelLength) << car.interiorMaterial_

		<< "|" << left << setw(calculateDoubleLength(car.mealeage_, CarHandler::getSignsAfterDotValue()) + 1)
		<< setprecision(CarHandler::getSignsAfterDotValue()) << fixed << car.mealeage_ << left
		<< setw((mealeageLableLength - 1) - calculateDoubleLength(car.mealeage_, CarHandler::getSignsAfterDotValue())) << "km"

		<< "|" << left << setw(calculateDoubleLength(car.price_, CarHandler::getSignsAfterDotValue()) + 1)
		<< setprecision(CarHandler::getSignsAfterDotValue()) << fixed << car.price_ << left
		<< setw((priceLabelLength - 1) - calculateDoubleLength(car.price_, CarHandler::getSignsAfterDotValue())) << "$"

		<< "|" << left << setw(reserveStatusLabelLength) << (car.isReserved_ ? "Yes" : "No")
		<< "|";


	return out;
}

Car::~Car() = default;