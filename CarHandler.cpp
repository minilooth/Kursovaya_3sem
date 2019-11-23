#include "CarHandler.h"

// Static initialization
vector<Car> CarHandler::cars_;

// Constructors
CarHandler::CarHandler()
{
	string token;

	string brand;
	string model;
	unsigned yearOfProduction;
	string transmissionType;
	string wheelDrive;
	string engineType;
	double engineVolume;
	string bodyType;
	string bodyColor;
	string interiorColor;
	string interiorMaterial;
	double mealeage;
	double price;
	bool isReserved;

	Car* car = nullptr;

	ifstream carsFile(R"(cars.txt)");

	if (carsFile.is_open())
	{
		while (!carsFile.eof())
		{
			if (getline(carsFile, token, '\n'))
			{
				auto data = stringSplitter(token);

				brand				= data.at(0);
				model				= data.at(1);
				yearOfProduction	= stoi(data.at(2));
				transmissionType	= data.at(3);
				wheelDrive			= data.at(4);
				engineType			= data.at(5);
				engineVolume		= stod(data.at(6));
				bodyType			= data.at(7);
				bodyColor			= data.at(8);
				interiorColor		= data.at(9);
				interiorMaterial	= data.at(10);
				mealeage			= stod(data.at(11));
				price				= stod(data.at(12));
				isReserved			= data.at(13) == "1" ? true : false;

				if (bodyType == "Crossover")
				{
					car = new Crossover(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor, 
										interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Cabriolet")
				{
					car = new Cabriolet(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor, 
										interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Five-door hatchback")
				{
					car = new FiveDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor, 
												interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Five-seat minivan")
				{
					car = new FiveSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor, 
											  interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Four-door coupe")
				{
					car = new FourDoorCoupe(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor, 
											interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Long-wheelbase sedan")
				{
					car = new LongWheelbaseSedan(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor, 
												 interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Sedan")
				{
					car = new Sedan(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor, 
									interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Seven-seat minivan")
				{
					car = new SevenSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor, 
											   interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Station wagon")
				{
					car = new StationWagon(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor, 
										   interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Three-door hatchback")
				{
					car = new ThreeDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor, 
												 interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Two-door coupe")
				{
					car = new TwoDoorCoupe(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor, 
										   interiorColor, interiorMaterial, mealeage, price, isReserved);
				}

				cars_.push_back(*car);
			}
		}
		carsFile.close();
		delete car;
	}
}

CarHandler::CarHandler(string fileName)
{
	string token;

	string brand;
	string model;
	unsigned yearOfProduction;
	string transmissionType;
	string wheelDrive;
	string engineType;
	double engineVolume;
	string bodyType;
	string bodyColor;
	string interiorColor;
	string interiorMaterial;
	double mealeage;
	double price;
	bool isReserved;

	Car* car = nullptr;

	ifstream carsFile(fileName);

	if (carsFile.is_open())
	{
		while (!carsFile.eof())
		{
			if (getline(carsFile, token, '\n'))
			{
				auto data = stringSplitter(token);

				brand				= data.at(0);
				model				= data.at(1);
				yearOfProduction	= stoi(data.at(2));
				transmissionType	= data.at(3);
				wheelDrive			= data.at(4);
				engineType			= data.at(5);
				engineVolume		= stod(data.at(6));
				bodyType			= data.at(7);
				bodyColor			= data.at(8);
				interiorColor		= data.at(9);
				interiorMaterial	= data.at(10);
				mealeage			= stod(data.at(11));
				price				= stod(data.at(12));
				isReserved			= data.at(13) == "1" ? true : false;

				if (bodyType == "Crossover")
				{
					car = new Crossover(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Cabriolet")
				{
					car = new Cabriolet(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Five-door hatchback")
				{
					car = new FiveDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Five-seat minivan")
				{
					car = new FiveSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Four-door coupe")
				{
					car = new FourDoorCoupe(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Long wheel-base sedan")
				{
					car = new LongWheelbaseSedan(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Sedan")
				{
					car = new Sedan(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Seven-seat minivan")
				{
					car = new SevenSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Station wagon")
				{
					car = new StationWagon(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else if (bodyType == "Three-door hatchback")
				{
					car = new ThreeDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, isReserved);
				}
				else
				{
					car = new TwoDoorCoupe(brand, model, yearOfProduction, transmissionType, wheelDrive, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, isReserved);
				}

				cars_.push_back(*car);
			}
		}
		carsFile.close();
		delete car;
	}
}

// Calculate
unsigned CarHandler::calculateBrandMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (length <= cars_.at(i).getBrand().length())
		{
			length = cars_.at(i).getBrand().length();
		}
	}
	return length;
}

unsigned CarHandler::calculateModelMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (length <= cars_.at(i).getModel().length())
		{
			length = cars_.at(i).getModel().length();
		}
	}
	return length;
}

unsigned CarHandler::calculateTransmissionTypeMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (length <= cars_.at(i).getTransmissionType().length())
		{
			length = cars_.at(i).getTransmissionType().length();
		}
	}
	return length;
}

unsigned CarHandler::calculateBodyColorMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (length <= cars_.at(i).getBodyColor().length())
		{
			length = cars_.at(i).getBodyColor().length();
		}
	}
	return length;
}

unsigned CarHandler::calculateInteriorColorMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (length <= cars_.at(i).getInteriorColor().length())
		{
			length = cars_.at(i).getInteriorColor().length();
		}
	}
	return length;
}

unsigned CarHandler::calculateInteriorMaterialMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (length <= cars_.at(i).getInteriorMaterial().length())
		{
			length = cars_.at(i).getInteriorMaterial().length();
		}
	}
	return length;
}

unsigned CarHandler::calculateBodyTypeMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (length <= cars_.at(i).getBodyType().length())
		{
			length = cars_.at(i).getBodyType().length();
		}
	}
	return length;
}

unsigned CarHandler::calculateMealeageMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (length <= calculateDoubleLength(cars_.at(i).getMealeage(), signsAfterDot_))
		{
			length = calculateDoubleLength(cars_.at(i).getMealeage(), signsAfterDot_);
		}
	}
	return length;
}

unsigned CarHandler::calculatePriceMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (length <= calculateDoubleLength(cars_.at(i).getPrice(), signsAfterDot_))
		{
			length = calculateDoubleLength(cars_.at(i).getPrice(), signsAfterDot_);
		}
	}
	return length;
}

unsigned CarHandler::getSignsAfterDotValue()
{
	return signsAfterDot_;
}

// Functional
void CarHandler::showCars()
{
	unsigned brandLabelLength				= 0;
	unsigned modelLabelLength				= 0;
	unsigned bodyTypeLabelLength			= 0;
	unsigned bodyColorLabelLength			= 0;
	unsigned interiorColorLabelLength		= 0;
	unsigned interiorMaterialLabelLength	= 0;
	unsigned mealeageLabelLength			= 0;
	unsigned priceLabelLength				= 0;
	unsigned yearOfProductionLabelLength	= 0;
	unsigned transmissionTypeLabelLength	= 0;
	unsigned wheelDriveLabelLength			= 0;
	unsigned engineTypeLabelLength			= 0;
	unsigned engineVolumeLabelLength		= 0;
	unsigned reserveStatusLabelLength		= 0;

	unsigned solidLineLength				= 0;

	try
	{
		if (cars_.size() == 0)
		{
			throw exception("List of cars is empty!");
		}

		brandLabelLength				= calculateBrandMaxLength() < 5 ? 5 : calculateBrandMaxLength();
		modelLabelLength				= calculateModelMaxLength() < 5 ? 5 : calculateModelMaxLength();
		bodyTypeLabelLength				= calculateBodyTypeMaxLength() < 9 ? 9 : calculateBodyTypeMaxLength();
		bodyColorLabelLength			= calculateBodyColorMaxLength() < 10 ? 10 : calculateBodyColorMaxLength();
		interiorColorLabelLength		= calculateInteriorColorMaxLength() < 14 ? 14 : calculateInteriorColorMaxLength();
		interiorMaterialLabelLength		= calculateInteriorMaterialMaxLength() < 17 ? 17 : calculateInteriorMaterialMaxLength();
		mealeageLabelLength				= (calculateMealeageMaxLength() < 8 ? 8 : calculateMealeageMaxLength()) + 3;
		priceLabelLength				= (calculatePriceMaxLength() < 5 ? 5 : calculatePriceMaxLength()) + 2;
		yearOfProductionLabelLength		= 18;
		transmissionTypeLabelLength		= 12;
		wheelDriveLabelLength			= 11;
		engineTypeLabelLength			= 11;
		engineVolumeLabelLength			= 13;
		reserveStatusLabelLength		= 14;

		solidLineLength = brandLabelLength + modelLabelLength + bodyTypeLabelLength + bodyColorLabelLength + interiorColorLabelLength + interiorMaterialLabelLength +
						  yearOfProductionLabelLength + transmissionTypeLabelLength + wheelDriveLabelLength + engineTypeLabelLength + engineVolumeLabelLength +
						  reserveStatusLabelLength + mealeageLabelLength + priceLabelLength + 15;

		system("cls");

		drawSolidLine(solidLineLength);

		cout << "|" << makeCenteredString("Brand", brandLabelLength)
			 << "|" << makeCenteredString("Model", modelLabelLength)
			 << "|" << makeCenteredString("Year of production", yearOfProductionLabelLength)
			 << "|" << makeCenteredString("Body type", bodyTypeLabelLength)
			 << "|" << makeCenteredString("Transmission", transmissionTypeLabelLength)
			 << "|" << makeCenteredString("Wheel drive", wheelDriveLabelLength)
			 << "|" << makeCenteredString("Engine type", engineTypeLabelLength)
			 << "|" << makeCenteredString("Engine volume", engineVolumeLabelLength)
			 << "|" << makeCenteredString("Body color", bodyColorLabelLength)
			 << "|" << makeCenteredString("Interior color", interiorColorLabelLength)
			 << "|" << makeCenteredString("Interior material", interiorMaterialLabelLength)
			 << "|" << makeCenteredString("Mealeage", mealeageLabelLength)
			 << "|" << makeCenteredString("Price", priceLabelLength)
			 << "|" << makeCenteredString("Reserve status", reserveStatusLabelLength)
			 << "|" << endl;

		drawSolidLine(solidLineLength);

		for (unsigned i = 0; i < cars_.size(); i++)
		{
			cout << "|" << left << setw(brandLabelLength) << cars_.at(i).getBrand()
				 << "|" << left << setw(modelLabelLength) << cars_.at(i).getModel()
				 << "|" << left << setw(yearOfProductionLabelLength) << cars_.at(i).getYearOfProduction()
				 << "|" << left << setw(bodyTypeLabelLength) << cars_.at(i).getBodyType()
				 << "|" << left << setw(transmissionTypeLabelLength) << cars_.at(i).getTransmissionType()
				 << "|" << left << setw(wheelDriveLabelLength) << cars_.at(i).getWheelDrive()
				 << "|" << left << setw(engineTypeLabelLength) << cars_.at(i).getEngineType()
				 << "|" << left << setw(engineVolumeLabelLength) << setprecision(signsAfterDot_) << fixed << cars_.at(i).getEngineVolume()
				 << "|" << left << setw(bodyColorLabelLength) << cars_.at(i).getBodyColor()
				 << "|" << left << setw(interiorColorLabelLength) << cars_.at(i).getInteriorColor()
				 << "|" << left << setw(interiorMaterialLabelLength) << cars_.at(i).getInteriorMaterial()

				 << "|" << left << setw(calculateDoubleLength(cars_.at(i).getMealeage(), signsAfterDot_) + 1)
				 << setprecision(signsAfterDot_) << fixed << cars_.at(i).getMealeage() << left
				 << setw((mealeageLabelLength - 1) - calculateDoubleLength(cars_.at(i).getMealeage(), signsAfterDot_)) << "km"

				 << "|" << left << setw(calculateDoubleLength(cars_.at(i).getPrice(), signsAfterDot_) + 1)
				 << setprecision(signsAfterDot_) << fixed << cars_.at(i).getPrice() << left
				 << setw((priceLabelLength - 1) - calculateDoubleLength(cars_.at(i).getPrice(), signsAfterDot_)) << "$"

				 << "|" << left << setw(reserveStatusLabelLength) << (cars_.at(i).getIsReserved() ? "Yes" : "No")
				 << "|" << endl;
		}

		drawSolidLine(solidLineLength);

		cout << endl;
	}
	catch (exception & ex)
	{
		system("cls");

		setTextColor(Color::RED);
		cout << ex.what() << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::showNewCars()
{
	system("cls");

	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getMealeage() == 0)
		{
			cout <<   "Brand: "					<< cars_.at(i).getBrand() 
				 << ", Model: "					<< cars_.at(i).getModel() 
				 << ", Year Of Production: "	<< cars_.at(i).getYearOfProduction() 
				 << ", Transmission: "			<< cars_.at(i).getTransmissionType()
				 << ", Wheel Drive: "			<< cars_.at(i).getWheelDrive() 
				 << ", Engine Type: "			<< cars_.at(i).getEngineType() 
				 << ", Engine Volume: "			<< cars_.at(i).getEngineVolume() 
				 << ", Body Color: "			<< cars_.at(i).getBodyColor()
				 << ", Interior Color: "		<< cars_.at(i).getInteriorColor() 
				 << ", Interior Material: "		<< cars_.at(i).getInteriorMaterial() 
				 << ", Mealeage: "				<< cars_.at(i).getMealeage() 
				 << ", Price: "					<< cars_.at(i).getPrice()
				 << ", Is Reserved: "			<< boolalpha << cars_.at(i).getIsReserved() 
				 << endl << endl;
		}
	}

	system("pause");
}

void CarHandler::showCarsForSale()
{
	system("cls");

	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getMealeage() != 0)
		{
			cout <<   "Brand: "					<< cars_.at(i).getBrand() 
				 << ", Model: "					<< cars_.at(i).getModel() 
				 << ", Year Of Production: "	<< cars_.at(i).getYearOfProduction() 
				 << ", Transmission: "			<< cars_.at(i).getTransmissionType()
				 << ", Wheel Drive: "			<< cars_.at(i).getWheelDrive() 
				 << ", Engine Type: "			<< cars_.at(i).getEngineType() 
				 << ", Engine Volume: "			<< cars_.at(i).getEngineVolume() 
				 << ", Body Color: "			<< cars_.at(i).getBodyColor()
				 << ", Interior Color: "		<< cars_.at(i).getInteriorColor() 
				 << ", Interior Material: "		<< cars_.at(i).getInteriorMaterial() 
				 << ", Mealeage: "				<< cars_.at(i).getMealeage() 
				 << ", Price: "					<< cars_.at(i).getPrice()
				 << ", Is Reserved: "			<< boolalpha << cars_.at(i).getIsReserved() 
				 << endl << endl;
		}
	}

	system("pause");
}

void CarHandler::addCar()
{
	string brand;
	string model;
	string yearOfProduction;
	string engineVolume;
	string bodyColor;
	string interiorColor;
	string interiorMaterial;
	string mealeage;
	string price;
	string isReserved;

	Car* car = nullptr;
	ConsoleMenu* menu = new BodyTypeMenu();

	ofstream carsFile;

	switch (menu->selectMode())
	{
		case BodyType::CROSSOVER :
			car = new Crossover();
			break;
		case BodyType::CABRIOLET :
			car = new Cabriolet();
			break;
		case BodyType::FIVE_DOOR_HATCHBACK :
			car = new FiveDoorHatchback();
			break;
		case BodyType::FIVE_SEAT_MINIVAN :
			car = new FiveSeatMinivan();
			break;
		case BodyType::FOUR_DOOR_COUPE :
			car = new FourDoorCoupe();
			break;
		case BodyType::LONG_WHEEL_BASE_SEDAN :
			car = new LongWheelbaseSedan();
			break;
		case BodyType::SEDAN :
			car = new Sedan();
			break;
		case BodyType::SEVEN_SEAT_MINIVAN :
			car = new SevenSeatMinivan();
			break;
		case BodyType::STATION_WAGON :
			car = new StationWagon();
			break;
		case BodyType::THREE_DOOR_HATCHBACK :
			car = new ThreeDoorHatchback();
			break;
		case BodyType::TWO_DOOR_COUPE :
			car = new TwoDoorCoupe();
			break;
		default:
			menu->resetChoice();
			return;
	}

	menu->resetChoice();

	system("cls");

	try
	{
		cout << "Brand: ";
		limitedInput(brand, inputBrandMaxLength);

		if (brand.length() < 3)
		{
			throw exception("Brand should be at least three characters long!");
		}

		if (brand.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ") != string::npos)
		{
			throw exception("Brand should only consists of letters!");
		}

		car->setBrand(brand);

		cout << "Model: ";
		limitedInput(model, inputModelMaxLength);

		if (model.length() < 3)
		{
			throw exception("Model should be at least three characters long!");
		}

		if (model.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890") != string::npos)
		{
			throw exception("Model should only consists of letters!");
		}
		
		car->setModel(model);

		cout << "Year of production: ";
		limitedInput(yearOfProduction, inputYearOfProductionMaxLength);

		if (yearOfProduction.length() < 4)
		{
			throw exception("Year of production should be four characters long!");
		}

		if (yearOfProduction.find_first_not_of("1234567890") != string::npos)
		{
			throw exception("Year of production should only consists of digits!");
		}

		car->setYearOfProduction(stoul(yearOfProduction));

		menu = new WheelDriveMenu();

		switch (menu->selectMode())
		{
		case WheelDrive::FWD :
			car->setWheelDrive("FWD");
			break;
		case WheelDrive::RWD :
			car->setWheelDrive("RWD");
			break;
		case WheelDrive::AWD :
			car->setWheelDrive("AWD");
			break;
		default:
			car->setWheelDrive("Not setted");
			break;
		}

		menu->resetChoice();

		clearLine();
		cout << "Wheel drive: " << car->getWheelDrive() << endl;

		menu = new EngineTypeMenu();

		switch (menu->selectMode())
		{
		case EngineType::PETROL :
			car->setEngineType("Petrol");
			break;
		case EngineType::DIESEL :
			car->setEngineType("Diesel");
			break;
		default:
			car->setEngineType("Not setted");
			break;
		}

		menu->resetChoice();

		clearLine();
		cout << "Engine type: " << car->getEngineType() << endl;

		menu = new TransmissionTypeMenu();

		switch (menu->selectMode())
		{
		case TransmissionType::MANUAL :
			car->setTransmissionType("Manual");
			break;
		case TransmissionType::AUTOMATIC :
			car->setTransmissionType("Automatic");
			break;
		default:
			car->setTransmissionType("Not setted");
			break;
		}

		menu->resetChoice();

		clearLine();
		cout << "Transmission type: " << car->getTransmissionType() << endl;

		cout << "Engine volume: ";
		limitedInput(engineVolume, inputEngineVolumeMaxLength);

		if (engineVolume.length() < 3)
		{
			throw exception("Engine volume should be three characters long!");
		}

		if (engineVolume.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Engine volume should only consists of digits!");
		}

		car->setEngineVolume(stod(engineVolume));

		cout << "Body color: ";
		limitedInput(bodyColor, inputBodyColorMaxLength);

		if (bodyColor.length() < 3)
		{
			throw exception("Body color should be at least three characters long!");
		}

		if (bodyColor.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != string::npos)
		{
			throw exception("Body color should only consists of letters!");
		}

		car->setBodyColor(bodyColor);

		cout << "Interior color: ";
		limitedInput(interiorColor, inputInteriorColorMaxLength);

		if (interiorColor.length() < 3)
		{
			throw exception("Interior color should be at least three characters long!");
		}

		if (bodyColor.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != string::npos)
		{
			throw exception("Interior color should only consists of letters!");
		}

		car->setInteriorColor(interiorColor);

		cout << "Interior material: ";
		limitedInput(interiorMaterial, inputInteriorMaterialMaxLength);

		if (interiorMaterial.length() < 3)
		{
			throw exception("Interior material should be at least three characters long!");
		}

		if (interiorMaterial.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != string::npos)
		{
			throw exception("Interior material should only consists of letters!");
		}

		car->setInteriorMaterial(interiorMaterial);

		cout << "Mealeage: ";
		limitedInput(mealeage, inputMealeageMaxLength);

		if (mealeage.length() < 1)
		{
			throw exception("Mealeage should be at least one characters long!");
		}

		if (mealeage.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Mealeage should only consists of digits!");
		}

		car->setMealeage(stoul(mealeage));

		cout << "Price: ";
		limitedInput(price, inputPriceMaxLength);

		if (price.length() < 1)
		{
			throw exception("Price should be at least one characters long!");
		}

		if (price.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Price should only consists of digits!");
		}

		car->setPrice(stoul(price));

		car->setIsReserved(false);

		carsFile.open(R"(cars.txt)", ios::app);
		if (carsFile.is_open())
		{
			carsFile << car->getBrand() << ";"
					 << car->getModel() << ";"
					 << car->getYearOfProduction() << ";"
					 << car->getTransmissionType() << ";"
					 << car->getWheelDrive() << ";"
					 << car->getEngineType() << ";"
					 << car->getEngineVolume() << ";"
					 << car->getBodyType() << ";"
					 << car->getBodyColor() << ";"
					 << car->getInteriorColor() << ";"
					 << car->getInteriorMaterial() << ";"
					 << car->getMealeage() << ";"
			   		 << car->getPrice() << ";"
					 << car->getIsReserved()
					 << endl;
		}
		else
		{
			throw exception("Cannot open file!");
		}
		carsFile.close();

		cars_.push_back(*car);

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "Car succesfully added!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		setTextColor(Color::RED);
		cout << endl << ex.what() << endl << "Car not added!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");

	delete menu;
}

void CarHandler::deleteCar()
{
	ItemSelection<Car>* itemSelection = nullptr;

	unsigned index = 0;

	ofstream carsFile;

	try
	{
		if (cars_.size() == 0)
		{
			throw exception("List of cars is empty!");
		}

		itemSelection = new ItemSelection<Car>("Choose car to delete:", cars_);

		index = itemSelection->selectMode();

		if (index == 0)
		{
			return;
		}
		else
		{
			index -= 1;
		}

		cars_.erase(cars_.begin() + index);

		carsFile.open(R"(cars.txt)", ios::trunc);
		if (carsFile.is_open())
		{
			for (unsigned i = 0; i < cars_.size(); i++)
			{
				carsFile << cars_.at(i).getBrand() << ";"
						 << cars_.at(i).getModel() << ";"
						 << cars_.at(i).getYearOfProduction() << ";"
						 << cars_.at(i).getTransmissionType() << ";"
						 << cars_.at(i).getWheelDrive() << ";"
						 << cars_.at(i).getEngineType() << ";"
						 << cars_.at(i).getEngineVolume() << ";"
						 << cars_.at(i).getBodyType() << ";"
						 << cars_.at(i).getBodyColor() << ";"
						 << cars_.at(i).getInteriorColor() << ";"
						 << cars_.at(i).getInteriorMaterial() << ";"
					 	 << cars_.at(i).getMealeage() << ";"
						 << cars_.at(i).getPrice() << ";"
						 << cars_.at(i).getIsReserved()
						 << endl;
			}
		}
		carsFile.close();

		system("cls");

		setTextColor(Color::LIGHT_GREEN);
		cout << "Car succesfully deleted!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		delete itemSelection;
	}
	catch (exception & ex)
	{
		system("cls");

		setTextColor(Color::RED);
		cout << ex.what() << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}