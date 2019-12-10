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
	mileage_ = 0.0;
	price_ = 0.0;
	reserveStatus_ = false;
	reserverUsername_ = "";
}

Car::Car(const string& brand, const string& model, unsigned yearOfProduction, const string& transmissionType, const string& wheelDriveType,
		 const string& engineType, double engineVolume, const string& bodyColor, const string& interiorColor, const string& interiorMaterial,
		 double mileage, double price, bool reserveStatus, const string& reserverUsername)
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
	mileage_ = mileage;
	price_ = price;
	reserveStatus_ = reserveStatus;
	reserverUsername_ = reserverUsername;
}

void Car::setBrand(const string& brand)
{
	brand_ = brand;
}

void Car::setModel(const string& model)
{
	model_ = model;
}

void Car::setYearOfProduction(unsigned yearOfProduction)
{
	yearOfProduction_ = yearOfProduction;
}

void Car::setTransmissionType(const string& transmissionType)
{
	transmissionType_ = transmissionType;
}

void Car::setWheelDriveType(const string& wheelDriveType)
{
	wheelDriveType_ = wheelDriveType;
}

void Car::setEngineType(const string& engineType)
{
	engineType_ = engineType;
}

void Car::setEngineVolume(double engineVolume)
{
	engineVolume_ = engineVolume;
}

void Car::setBodyColor(const string& bodyColor)
{
	bodyColor_ = bodyColor;
}

void Car::setInteriorColor(const string& interiorColor)
{
	interiorColor_ = interiorColor;
}

void Car::setInteriorMaterial(const string& interiorMaterial)
{
	interiorMaterial_ = interiorMaterial;
}

void Car::setMileage(double mileage)
{
	mileage_ = mileage;
}

void Car::setPrice(double price)
{
	price_ = price;
}

void Car::setReserveStatus(bool reserveStatus)
{
	reserveStatus_ = reserveStatus;
}

void Car::setReserverUsername(const string& reserverUsername)
{
	reserverUsername_ = reserverUsername;
}

string Car::getBrand() const
{
	return brand_;
}

string Car::getModel() const
{
	return model_;
}

unsigned Car::getYearOfProduction() const
{
	return yearOfProduction_;
}

string Car::getTransmissionType() const
{
	return transmissionType_;
}

string Car::getBodyType() const
{
	return bodyType_;
}

string Car::getWheelDriveType() const
{
	return wheelDriveType_;
}

string Car::getEngineType() const
{
	return engineType_;
}

double Car::getEngineVolume() const
{
	return engineVolume_;
}

string Car::getBodyColor() const
{
	return bodyColor_;
}

string Car::getInteriorColor() const
{
	return interiorColor_;
}

string Car::getInteriorMaterial() const
{
	return interiorMaterial_;
}

double Car::getMileage() const
{
	return mileage_;
}

double Car::getPrice() const
{
	return price_;
}

bool Car::getReserveStatus() const
{
	return reserveStatus_;
}

string Car::getReserverUsername() const
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

		<< "|" << left << setw(calculateDoubleLength(car.engineVolume_, CarPrinter::getSignsAfterDotValue() + 1)) 
		<< setprecision(CarPrinter::getSignsAfterDotValue()) << fixed << car.engineVolume_ << left 
		<< setw((CarPrinter::getEngineVolumeLabelLength() - 1) - calculateDoubleLength(car.engineVolume_, CarPrinter::getSignsAfterDotValue())) << "л"

		<< "|" << left << setw(CarPrinter::getBodyColorLabelLength()) << car.bodyColor_
		<< "|" << left << setw(CarPrinter::getInteriorColorLabelLength()) << car.interiorColor_
		<< "|" << left << setw(CarPrinter::getInteriorMaterialLabelLength()) << car.interiorMaterial_

		<< "|" << left << setw(static_cast<unsigned>(1) + static_cast<unsigned>(calculateDoubleLength(car.mileage_, CarPrinter::getSignsAfterDotValue())))
		<< setprecision(CarPrinter::getSignsAfterDotValue()) << fixed << car.mileage_ << left
		<< setw((CarPrinter::getMileageLabelLength() - 1) - calculateDoubleLength(car.mileage_, CarPrinter::getSignsAfterDotValue())) << "км"

		<< "|" << left << setw(static_cast<unsigned>(1) + static_cast<unsigned>(calculateDoubleLength(car.price_, CarPrinter::getSignsAfterDotValue())))
		<< setprecision(CarPrinter::getSignsAfterDotValue()) << fixed << car.price_ << left
		<< setw((CarPrinter::getPriceLabelLength() - 1) - calculateDoubleLength(car.price_, CarPrinter::getSignsAfterDotValue())) << "$"

		<< "|" << left << setw(CarPrinter::getReserveStatusLabelLength()) << (car.reserveStatus_ ? ("Зарезервирован " + car.reserverUsername_) : "Не зарезервирован")
		<< "|";


	return out;
}

Car::~Car() = default;