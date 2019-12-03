#include "CarHandler.h"

Car::Car()
{
	brand_ = "";
	model_ = "";
	yearOfProduction_ = 0;
	transmissionType_ = "";
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

Car::Car(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDriveType,
		 string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial,
		 double mealeage, double price, bool reserveStatus, string& reserverUsername)
{
	brand_ = brand;
	model_ = model;
	yearOfProduction_ = yearOfProduction;
	transmissionType_ = transmissionType;
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

void Car::setWheelDriveType(string wheelDriveType)
{
	wheelDriveType_ = wheelDriveType;
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

void Car::setReserveStatus(bool reserveStatus)
{
	reserveStatus_ = reserveStatus;
}

void Car::setReserverUsername(string reserverUsername)
{
	reserverUsername_ = reserverUsername;
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

string Car::getWheelDriveType()
{
	return wheelDriveType_;
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

bool Car::getReserveStatus()
{
	return reserveStatus_;
}

string Car::getReserverUsername()
{
	return reserverUsername_;
}

ostream& operator<<(ostream& out, const Car& car)
{
	out << "|" << left << setw(CarPrinter::getBrandLabelLength()) << car.brand_
		<< "|" << left << setw(CarPrinter::getModelLabelLength()) << car.model_
		<< "|" << left << setw(CarPrinter::getYearOfProductionLabelLength()) << car.yearOfProduction_
		<< "|" << left << setw(CarPrinter::getBodyTypeLabelLength()) << car.bodyType_
		<< "|" << left << setw(CarPrinter::getTransmissionTypeLabelLength()) << car.transmissionType_
		<< "|" << left << setw(CarPrinter::getWheelDriveTypeLabelLength()) << car.wheelDriveType_
		<< "|" << left << setw(CarPrinter::getEngineTypeLabelLength()) << car.engineType_
		<< "|" << left << setw(CarPrinter::getEngineVolumeLabelLength()) << setprecision(CarPrinter::getSignsAfterDotValue()) << fixed << car.engineVolume_
		<< "|" << left << setw(CarPrinter::getBodyColorLabelLength()) << car.bodyColor_
		<< "|" << left << setw(CarPrinter::getInteriorColorLabelLength()) << car.interiorColor_
		<< "|" << left << setw(CarPrinter::getInteriorMaterialLabelLength()) << car.interiorMaterial_

		<< "|" << left << setw(calculateDoubleLength(car.mealeage_, CarPrinter::getSignsAfterDotValue()) + 1)
		<< setprecision(CarPrinter::getSignsAfterDotValue()) << fixed << car.mealeage_ << left
		<< setw((CarPrinter::getMealeageLabelLength() - 1) - calculateDoubleLength(car.mealeage_, CarPrinter::getSignsAfterDotValue())) << "km"

		<< "|" << left << setw(calculateDoubleLength(car.price_, CarPrinter::getSignsAfterDotValue()) + 1)
		<< setprecision(CarPrinter::getSignsAfterDotValue()) << fixed << car.price_ << left
		<< setw((CarPrinter::getPriceLabelLength() - 1) - calculateDoubleLength(car.price_, CarPrinter::getSignsAfterDotValue())) << "$"

		<< "|" << left << setw(CarPrinter::getReserveStatusLabelLength()) << (car.reserveStatus_ ? ("Reserved by " + car.reserverUsername_) : "Not reserved")
		<< "|";


	return out;
}

Car::~Car() = default;