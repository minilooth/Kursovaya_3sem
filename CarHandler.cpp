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

				brand = data.at(0);
				model = data.at(1);
				yearOfProduction = stoi(data.at(2));
				transmissionType = data.at(3);
				wheelDrive = data.at(4);
				engineType = data.at(5);
				engineVolume = stod(data.at(6));
				bodyType = data.at(7);
				bodyColor = data.at(8);
				interiorColor = data.at(9);
				interiorMaterial = data.at(10);
				mealeage = stod(data.at(11));
				price = stod(data.at(12));
				isReserved = data.at(13) == "1" ? true : false;

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

				brand = data.at(0);
				model = data.at(1);
				yearOfProduction = stoi(data.at(2));
				transmissionType = data.at(3);
				wheelDrive = data.at(4);
				engineType = data.at(5);
				engineVolume = stod(data.at(6));
				bodyType = data.at(7);
				bodyColor = data.at(8);
				interiorColor = data.at(9);
				interiorMaterial = data.at(10);
				mealeage = stod(data.at(11));
				price = stod(data.at(12));
				isReserved = data.at(13) == "1" ? true : false;

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

// Functional
void CarHandler::showCars()
{
	system("cls");

	for (unsigned i = 0; i < cars_.size(); i++)
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
			 << endl;
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
		limitedInput(brand, brandMaxLength);

		if (brand.length() < 3)
		{
			throw exception("Brand should be at least three characters long!");
		}

		if (brand.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != string::npos)
		{
			throw exception("Brand should only consists of letters!");
		}

		car->setBrand(brand);

		cout << "Model: ";
		limitedInput(model, modelMaxLength);

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
		limitedInput(yearOfProduction, yearOfProductionMaxLength);

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
		limitedInput(engineVolume, engineVolumeMaxLength);

		if (engineVolume.length() < 3)
		{
			throw exception("Engine volume should be three characters long!");
		}

		if (engineVolume.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Engine volume should only consists of digits!");
		}

		car->setEngineVolume(stoul(engineVolume));

		cout << "Body color: ";
		limitedInput(bodyColor, bodyColorMaxLength);

		if (bodyColor.length() < 4)
		{
			throw exception("Body color should be at least three characters long!");
		}

		if (bodyColor.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != string::npos)
		{
			throw exception("Body color should only consists of letters!");
		}

		car->setBodyColor(bodyColor);

		cout << "Interior color: ";
		limitedInput(interiorColor, interiorColorMaxLength);

		if (interiorColor.length() < 4)
		{
			throw exception("Interior color should be at least three characters long!");
		}

		if (bodyColor.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != string::npos)
		{
			throw exception("Interior color should only consists of letters!");
		}

		car->setInteriorColor(interiorColor);

		cout << "Interior material: ";
		limitedInput(interiorMaterial, interiorMaterialMaxLength);

		if (interiorMaterial.length() < 4)
		{
			throw exception("Interior material should be at least three characters long!");
		}

		if (interiorMaterial.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != string::npos)
		{
			throw exception("Interior material should only consists of letters!");
		}

		car->setInteriorMaterial(interiorMaterial);

		cout << "Mealeage: ";
		limitedInput(mealeage, mealeageMaxLength);

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
		limitedInput(price, priceMaxLength);

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

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << endl << "Car succesfully added!" << endl << endl;
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