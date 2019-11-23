#include "FourDoorCoupe.h"

FourDoorCoupe::FourDoorCoupe()
{
	brand_ = "";
	model_ = "";
	yearOfProduction_ = 0;
	transmissionType_ = "";
	bodyType_ = "Four-door coupe";
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

FourDoorCoupe::FourDoorCoupe(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
							 string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
							 double price, bool isReserved)
{
	brand_ = brand;
	model_ = model;
	yearOfProduction_ = yearOfProduction;
	transmissionType_ = transmissionType;
	bodyType_ = "Four-door coupe";
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

FourDoorCoupe::~FourDoorCoupe() = default;