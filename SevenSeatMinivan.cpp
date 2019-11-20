#include "SevenSeatMinivan.h"

SevenSeatMinivan::SevenSeatMinivan()
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

SevenSeatMinivan::SevenSeatMinivan(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
								   string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage,
								   double price, bool isReserved)
{
	brand_ = brand;
	model_ = model;
	yearOfProduction_ = yearOfProduction;
	transmissionType_ = transmissionType;
	wheelDrive_ = wheelDrive;
	engineType_ = engineType;
	engineVolume_ = engineVolume;
	bodyColor_ = bodyColor_;
	interiorColor_ = interiorColor;
	interiorMaterial_ = interiorMaterial;
	mealeage_ = mealeage;
	price_ = price;
	isReserved_ = isReserved;
}

string SevenSeatMinivan::getBodyType()
{
	return bodyType_;
}

SevenSeatMinivan::~SevenSeatMinivan() = default;