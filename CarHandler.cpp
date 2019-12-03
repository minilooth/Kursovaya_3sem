#include "CarHandler.h"

// Static initialization
vector<Car> CarHandler::cars_;
Car* CarHandler::carToEdit_ = nullptr;

// Constructors
CarHandler::CarHandler()
{
	string token;

	string brand;
	string model;
	unsigned yearOfProduction;
	string transmissionType;
	string wheelDriveType;
	string engineType;
	double engineVolume;
	string bodyType;
	string bodyColor;
	string interiorColor;
	string interiorMaterial;
	double mealeage;
	double price;
	bool reserveStatus;
	string reserverUsername;

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
				wheelDriveType			= data.at(4);
				engineType			= data.at(5);
				engineVolume		= stod(data.at(6));
				bodyType			= data.at(7);
				bodyColor			= data.at(8);
				interiorColor		= data.at(9);
				interiorMaterial	= data.at(10);
				mealeage			= stod(data.at(11));
				price				= stod(data.at(12));
				reserveStatus		= data.at(13) == "1" ? true : false;
				reserverUsername	= data.at(14);

				if (bodyType == "Crossover")
				{
					car = new Crossover(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
										interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Cabriolet")
				{
					car = new Cabriolet(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
										interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Five-door hatchback")
				{
					car = new FiveDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
												interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Five-seat minivan")
				{
					car = new FiveSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
											  interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Four-door coupe")
				{
					car = new FourDoorCoupe(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
											interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Long-wheelbase sedan")
				{
					car = new LongWheelbaseSedan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
												 interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Sedan")
				{
					car = new Sedan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
									interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Seven-seat minivan")
				{
					car = new SevenSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
											   interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Station wagon")
				{
					car = new StationWagon(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
										   interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Three-door hatchback")
				{
					car = new ThreeDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
												 interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Two-door coupe")
				{
					car = new TwoDoorCoupe(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
										   interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
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
	string wheelDriveType;
	string engineType;
	double engineVolume;
	string bodyType;
	string bodyColor;
	string interiorColor;
	string interiorMaterial;
	double mealeage;
	double price;
	bool reserveStatus;
	string reserverUsername;

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
				wheelDriveType		= data.at(4);
				engineType			= data.at(5);
				engineVolume		= stod(data.at(6));
				bodyType			= data.at(7);
				bodyColor			= data.at(8);
				interiorColor		= data.at(9);
				interiorMaterial	= data.at(10);
				mealeage			= stod(data.at(11));
				price				= stod(data.at(12));
				reserveStatus		= data.at(13) == "1" ? true : false;
				reserverUsername	= data.at(14);

				if (bodyType == "Crossover")
				{
					car = new Crossover(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Cabriolet")
				{
					car = new Cabriolet(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Five-door hatchback")
				{
					car = new FiveDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Five-seat minivan")
				{
					car = new FiveSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Four-door coupe")
				{
					car = new FourDoorCoupe(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Long wheel-base sedan")
				{
					car = new LongWheelbaseSedan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Sedan")
				{
					car = new Sedan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Seven-seat minivan")
				{
					car = new SevenSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Station wagon")
				{
					car = new StationWagon(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Three-door hatchback")
				{
					car = new ThreeDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else
				{
					car = new TwoDoorCoupe(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}

				cars_.push_back(*car);
			}
		}
		carsFile.close();
		delete car;
	}
}

// Files
void CarHandler::rewriteCarsFile()
{
	ofstream carsFile;
	carsFile.open(R"(cars.txt)", ios::trunc);
	if (carsFile.is_open())
	{
		for (unsigned i = 0; i < cars_.size(); i++)
		{
			carsFile << cars_.at(i).getBrand() << ";"
					 << cars_.at(i).getModel() << ";"
					 << cars_.at(i).getYearOfProduction() << ";"
					 << cars_.at(i).getTransmissionType() << ";"
					 << cars_.at(i).getWheelDriveType() << ";"
					 << cars_.at(i).getEngineType() << ";"
					 << cars_.at(i).getEngineVolume() << ";"
					 << cars_.at(i).getBodyType() << ";"
					 << cars_.at(i).getBodyColor() << ";"
					 << cars_.at(i).getInteriorColor() << ";"
					 << cars_.at(i).getInteriorMaterial() << ";"
					 << cars_.at(i).getMealeage() << ";"
					 << cars_.at(i).getPrice() << ";"
					 << cars_.at(i).getReserveStatus() << ";"
					 << cars_.at(i).getReserverUsername()
					 << endl;
		}
		carsFile.close();
	}
	else
	{
		throw exception("Cannot open cars file!");
	}
}

void CarHandler::createReport(Car car)
{
	time_t time = std::time(0);
	tm* now = std::localtime(&time);

	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "                               Car sales report                                    " << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "Brand: " << car.getBrand() << endl;
	cout << "Model: " << car.getModel() << endl;
	cout << "Year of production: " << car.getYearOfProduction() << endl;
	cout << "Transmission type: " << car.getTransmissionType() << endl;
	cout << "Wheel drive type: " << car.getWheelDriveType() << endl;
	cout << "Engine type: " << car.getEngineType() << endl;
	cout << "Engine volume: " << car.getEngineVolume() << endl;
	cout << "Body type: " << car.getBodyType() << endl;
	cout << "Body color: " << car.getBodyColor() << endl;
	cout << "Interior color: " << car.getInteriorColor() << endl;
	cout << "Interior material: " << car.getInteriorMaterial() << endl;
	cout << "Mealeage: " << car.getMealeage() << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "Buyer: " << car.getReserverUsername() << " Price: " << car.getPrice() << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "Date of sale: " << now->tm_wday << "."
							 << (now->tm_mon + 1) << "."
							 << (now->tm_year + 1900) << " "
							 << now->tm_hour << ":"
							 << now->tm_min
		 << endl;
}

// Reset
void CarHandler::resetCarToEdit()
{
	carToEdit_ = nullptr;
}

void CarHandler::resetReservedCarsByUsername(string username)
{
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getReserverUsername() == username)
		{
			cars_.at(i).setReserveStatus(false);
		}
	}
	rewriteCarsFile();
}

// Count
unsigned CarHandler::countNewCars()
{
	unsigned counter = 0;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getMealeage() == 0.0)
		{
			counter++;
		}
	}
	return counter;
}

unsigned CarHandler::countNotReservedNewCars()
{
	unsigned counter = 0;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getReserveStatus() == false && cars_.at(i).getMealeage() == 0.0)
		{
			counter++;
		}
	}
	return counter;
}

unsigned CarHandler::countUsedCars()
{
	unsigned counter = 0;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getMealeage() != 0.0)
		{
			counter++;
		}
	}
	return counter;
}

unsigned CarHandler::countNotReservedUsedCars()
{
	unsigned counter = 0;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getReserveStatus() == false && cars_.at(i).getMealeage() != 0.0)
		{
			counter++;
		}
	}
	return counter;
}

unsigned CarHandler::countReservedCars()
{
	unsigned counter = 0;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getReserveStatus() == true)
		{
			counter++;
		}
	}
	return counter;
}

// Edit
void CarHandler::editBrand()
{
	string brand;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Car to edit not setted!");
		}

		system("cls");

		showEditCar();

		cout << "Enter new brand: ";
		if (limitedInput(brand, brandMaxInputLength) == false)
		{
			return;
		}

		if (brand.length() < 3)
		{
			throw exception("Brand should be at least three characters long!");
		}

		if (brand.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ") != string::npos)
		{
			throw exception("Brand should only consists of letters!");
		}

		carToEdit_->setBrand(brand);

		system("cls");

		showEditCar();

		rewriteCarsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Brand has succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Brand has not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editModel()
{
	string model;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Car to edit not setted!");
		}

		system("cls");

		showEditCar();

		cout << "Enter new model: ";
		if (limitedInput(model, modelMaxInputLength) == false)
		{
			return;
		}

		if (model.length() < 2)
		{
			throw exception("Model should be at least three characters long!");
		}

		if (model.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890") != string::npos)
		{
			throw exception("Model should only consists of letters!");
		}

		carToEdit_->setModel(model);

		system("cls");

		showEditCar();

		rewriteCarsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Model has succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Model has not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editYearOfProduction()
{
	string yearOfProduction;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Car to edit not setted!");
		}

		system("cls");

		showEditCar();

		cout << "Enter new year of production: ";
		if (limitedInput(yearOfProduction, yearOfProductionMaxInputLength) == false)
		{
			return;
		}

		if (yearOfProduction.length() < 4)
		{
			throw exception("Year of production should be four characters long!");
		}

		if (yearOfProduction.find_first_not_of("1234567890") != string::npos)
		{
			throw exception("Year of production should only consists of digits!");
		}

		carToEdit_->setYearOfProduction(stoul(yearOfProduction));

		system("cls");

		showEditCar();

		rewriteCarsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Year of production has succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Year of production has not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editBodyType()
{
	ConsoleMenu* menu = nullptr;

	unsigned index = 0;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Car to edit not setted!");
		}

		system("cls");

		showEditCar();

		menu = new BodyTypeMenu();

		switch (menu->selectMode())
		{
		case BodyType::CROSSOVER:
			carToEdit_ = new Crossover(*carToEdit_);
			break;
		case BodyType::CABRIOLET:
			carToEdit_ = new Cabriolet(*carToEdit_);
			break;
		case BodyType::FIVE_DOOR_HATCHBACK:
			carToEdit_ = new FiveDoorHatchback(*carToEdit_);
			break;
		case BodyType::FIVE_SEAT_MINIVAN:
			carToEdit_ = new FiveSeatMinivan(*carToEdit_);
			break;
		case BodyType::FOUR_DOOR_COUPE:
			carToEdit_ = new FourDoorCoupe(*carToEdit_);
			break;
		case BodyType::LONG_WHEEL_BASE_SEDAN:
			carToEdit_ = new LongWheelbaseSedan(*carToEdit_);
			break;
		case BodyType::SEDAN:
			carToEdit_ = new Sedan(*carToEdit_);
			break;
		case BodyType::SEVEN_SEAT_MINIVAN:
			carToEdit_ = new SevenSeatMinivan(*carToEdit_);
			break;
		case BodyType::STATION_WAGON:
			carToEdit_ = new StationWagon(*carToEdit_);
			break;
		case BodyType::THREE_DOOR_HATCHBACK:
			carToEdit_ = new ThreeDoorHatchback(*carToEdit_);
			break;
		case BodyType::TWO_DOOR_COUPE:
			carToEdit_ = new TwoDoorCoupe(*carToEdit_);
			break;
		default:
			menu->resetChoice();
			return;
		}

		index = getCarIndex(carToEdit_);
		cars_.erase(cars_.begin() + index);
		cars_.insert(cars_.begin() + index, *carToEdit_);

		carToEdit_ = getCar(index);

		system("cls");

		showEditCar();

		rewriteCarsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Body type has succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Body type has not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editTransmissionType()
{
	ConsoleMenu* menu = nullptr;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Car to edit not setted!");
		}

		system("cls");

		showEditCar();

		menu = new TransmissionTypeMenu();

		switch (menu->selectMode())
		{
		case TransmissionType::MANUAL :
			carToEdit_->setTransmissionType("Manual");
			break;
		case TransmissionType::AUTOMATIC :
			carToEdit_->setTransmissionType("Automatic");
			break;
		default:
			menu->resetChoice();
			return;
		}

		system("cls");

		showEditCar();

		rewriteCarsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Transmission type has succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Transmission type has not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editWheelDriveType()
{
	ConsoleMenu* menu = nullptr;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Car to edit not setted!");
		}

		system("cls");

		showEditCar();

		menu = new WheelDriveTypeMenu();

		switch (menu->selectMode())
		{
		case WheelDriveType::FWD :
			carToEdit_->setWheelDriveType("FWD");
			break;
		case WheelDriveType::RWD :
			carToEdit_->setWheelDriveType("RWD");
			break;
		case WheelDriveType::AWD :
			carToEdit_->setWheelDriveType("AWD");
			break;
		default:
			menu->resetChoice();
			return;
		}

		system("cls");

		showEditCar();

		rewriteCarsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Wheel drive type has succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Wheel drive type has not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editEngineType()
{
	ConsoleMenu* menu = nullptr;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Car to edit not setted!");
		}

		system("cls");

		showEditCar();

		menu = new EngineTypeMenu();

		switch (menu->selectMode())
		{
		case EngineType::PETROL :
			carToEdit_->setEngineType("Petrol");
			break;
		case EngineType::DIESEL :
			carToEdit_->setEngineType("Diesel");
			break;
		default:
			menu->resetChoice();
			return;
		}

		system("cls");

		showEditCar();

		rewriteCarsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Engine type has succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Engine type has not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editEngineVolume()
{
	string engineVolume;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Car to edit not setted!");
		}

		system("cls");

		showEditCar();

		cout << "Enter new engine volume: ";
		if (limitedInput(engineVolume, engineVolumeMaxInputLength) == false)
		{
			return;
		}

		if (engineVolume.length() < 3 || engineVolume.length() > 3)
		{
			throw exception("Engine volume should be three characters long!");
		}

		if (engineVolume.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Engine volume should only consists of digits!");
		}

		if (engineVolume.find(".") != 1)
		{
			throw exception("Engine volume should be like X.Y!");
		}

		carToEdit_->setEngineVolume(stod(engineVolume));

		system("cls");

		showEditCar();

		rewriteCarsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Engine volume has succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Engine volume has not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editBodyColor()
{
	string bodyColor;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Car to edit not setted!");
		}

		system("cls");

		showEditCar();

		cout << "Enter new body color: ";
		if (limitedInput(bodyColor, bodyColorMaxInputLength) == false)
		{
			return;
		}

		if (bodyColor.length() < 3)
		{
			throw exception("Body color should be at least three characters long!");
		}

		if (bodyColor.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != string::npos)
		{
			throw exception("Body color should only consists of letters!");
		}

		carToEdit_->setBodyColor(bodyColor);

		system("cls");

		showEditCar();

		rewriteCarsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Body color has succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Body color has not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editInteriorColor()
{
	string interiorColor;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Car to edit not setted!");
		}

		system("cls");

		showEditCar();

		cout << "Enter new interior color: ";
		if (limitedInput(interiorColor, interiorColorMaxInputLength) == false)
		{
			return;
		}

		if (interiorColor.length() < 3)
		{
			throw exception("Interior color should be at least three characters long!");
		}

		if (interiorColor.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != string::npos)
		{
			throw exception("Interior color should only consists of letters!");
		}

		carToEdit_->setInteriorColor(interiorColor);

		system("cls");

		showEditCar();

		rewriteCarsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Interior color has succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Interior color has not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editInteriorMaterial()
{
	string interiorMaterial;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Car to edit not setted!");
		}

		system("cls");

		showEditCar();

		cout << "Enter new interior material: ";
		if (limitedInput(interiorMaterial, interiorMaterialMaxInputLength) == false)
		{
			return;
		}

		if (interiorMaterial.length() < 3)
		{
			throw exception("Interior material should be at least three characters long!");
		}

		if (interiorMaterial.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != string::npos)
		{
			throw exception("Interior material should only consists of letters!");
		}

		carToEdit_->setInteriorMaterial(interiorMaterial);

		system("cls");

		showEditCar();

		rewriteCarsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Interior material has succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Interior material has not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editMealeage()
{
	string mealeage;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Car to edit not setted!");
		}

		system("cls");

		showEditCar();

		cout << "Enter new mealeage: ";
		if (limitedInput(mealeage, mealeageMaxInputLength) == false)
		{
			return;
		}

		if (mealeage.length() < 1)
		{
			throw exception("Mealeage should be at least one characters long!");
		}

		if (mealeage.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Mealeage should only consists of digits!");
		}

		carToEdit_->setMealeage(stoul(mealeage));

		system("cls");

		showEditCar();

		rewriteCarsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Mealeage has succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Mealeage has not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editPrice()
{
	string price;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Car to edit not setted!");
		}

		system("cls");

		showEditCar();

		cout << "Enter new mealeage: ";
		if (limitedInput(price, priceMaxInputLength) == false)
		{
			return;
		}

		if (price.length() < 1)
		{
			throw exception("Price should be at least one characters long!");
		}

		if (price.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Price should only consists of digits!");
		}

		carToEdit_->setPrice(stoul(price));

		system("cls");

		showEditCar();

		rewriteCarsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Price has succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Price has not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editReserveStatus()
{
	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Car to edit not setted!");
		}

		carToEdit_->setReserveStatus(!(carToEdit_->getReserveStatus()));
		if (carToEdit_->getReserveStatus() == false)
		{
			carToEdit_->setReserverUsername("");
		}

		system("cls");

		showEditCar();

		rewriteCarsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Reserve status has succesfully changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Reserve status has not changed!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editReserverUsername()
{

}

void CarHandler::editReservedCarsReserverUsername(string oldUsername, string newUsername)
{
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getReserverUsername() == oldUsername)
		{
			cars_.at(i).setReserverUsername(newUsername);
		}
	}
	rewriteCarsFile();
}

// Gets
unsigned CarHandler::getCarIndex(Car* car)
{
	unsigned index = 0;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (&(cars_.at(i)) == car)
		{
			index = i;
			break;
		}
	}
	return index;
}

Car* CarHandler::getCar(unsigned index)
{
	return &(cars_.at(index));
}

vector<Car> CarHandler::getCars()
{
	return cars_;
}

pair<vector<Car*>, vector<Car>> CarHandler::getNotReservedNewCars()
{
	pair<vector<Car*>, vector<Car>> cars;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getMealeage() == 0.0 && cars_.at(i).getReserveStatus() == false)
		{
			cars.first.push_back(&(cars_.at(i)));
			cars.second.push_back(cars_.at(i));
		}
	}
	return cars;
}

pair<vector<Car*>, vector<Car>> CarHandler::getNotReservedUsedCars()
{
	pair<vector<Car*>, vector<Car>> cars;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getMealeage() != 0.0 && cars_.at(i).getReserveStatus() == false)
		{
			cars.first.push_back(&(cars_.at(i)));
			cars.second.push_back(cars_.at(i));
		}
	}
	return cars;
}

pair<vector<Car*>, vector<Car>> CarHandler::getReservedCars()
{
	pair<vector<Car*>, vector<Car>> cars;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getReserveStatus() == true)
		{
			cars.first.push_back(&(cars_.at(i)));
			cars.second.push_back(cars_.at(i));
		}
	}
	return cars;
}

vector<Car> CarHandler::getReservedCarsByUsername(string username)
{
	vector<Car> cars;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getReserverUsername() == username)
		{
			cars.push_back(cars_.at(i));
		}
	}
	return cars;
}

// Functional
void CarHandler::showCars()
{
	try
	{
		if (cars_.size() == 0)
		{
			throw exception("List of cars is empty!");
		}

		system("cls");

		CarPrinter::showHeader();

		for (unsigned i = 0; i < cars_.size(); i++)
		{
			cout << cars_.at(i) << endl;
		}

		drawSolidLine(CarPrinter::getSolidLineLength());

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

void CarHandler::showAccountReservedCars()
{
	try
	{
		if (AccountHandler::getCurrentAccount() == nullptr)
		{
			throw exception("Current account is not setted!");
		}

		auto cars = getReservedCarsByUsername(AccountHandler::getCurrentAccount()->getUsername());

		if (cars.size() == 0)
		{
			throw exception("You have not reserved cars!");
		}

		system("cls");

		cout << "Cars that reserved by you: " << endl << endl;

		CarPrinter::showHeader();

		for (unsigned i = 0; i < cars.size(); i++)
		{
			cout << cars.at(i) << endl;
		}

		drawSolidLine(CarPrinter::getSolidLineLength());

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
	try
	{
		if (countNewCars() == 0)
		{
			throw exception("List of new cars is empty!");
		}

		system("cls");

		CarPrinter::showHeader();

		for (unsigned i = 0; i < cars_.size(); i++)
		{
			if (cars_.at(i).getMealeage() == 0.0)
			{
				cout << cars_.at(i) << endl;
			}
		}

		drawSolidLine(CarPrinter::getSolidLineLength());

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

void CarHandler::showUsedCars()
{
	try
	{
		if (countNewCars() == 0)
		{
			throw exception("List of used cars is empty!");
		}

		system("cls");

		CarPrinter::showHeader();

		for (unsigned i = 0; i < cars_.size(); i++)
		{
			if (cars_.at(i).getMealeage() != 0.0)
			{
				cout << cars_.at(i) << endl;
			}
		}

		drawSolidLine(CarPrinter::getSolidLineLength());

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

void CarHandler::showEditCar()
{
	CarPrinter::showHeader();

	cout << *carToEdit_ << endl;

	drawSolidLine(CarPrinter::getSolidLineLength());

	cout << endl;

}

void CarHandler::sellCar()
{
	ItemSelection<Car>* itemSelection = nullptr;

	unsigned index = 0;

	ofstream reportFile;

	try
	{
		if (cars_.size() == 0)
		{
			throw exception("Cars list is empty!");
		}
		if (countReservedCars() == 0)
		{
			throw exception("No reserved cars!");
		}

		auto reservedCars = getReservedCars();

		itemSelection = new ItemSelection<Car>("Choose car to sell:", reservedCars.second);

		index = itemSelection->selectMode();

		if (index == 0)
		{
			return;
		}
		else
		{
			index--;
		}

		cars_.erase(cars_.begin() + index);

		rewriteCarsFile();

	}
	catch (exception & ex)
	{

	}
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

	system("cls");

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
		if (limitedInput(brand, brandMaxInputLength) == false)
		{
			return;
		}

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
		if (limitedInput(model, modelMaxInputLength) == false)
		{
			return;
		}

		if (model.length() < 2)
		{
			throw exception("Model should be at least three characters long!");
		}

		if (model.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890") != string::npos)
		{
			throw exception("Model should only consists of letters!");
		}
		
		car->setModel(model);

		cout << "Year of production: ";
		if (limitedInput(yearOfProduction, yearOfProductionMaxInputLength) == false)
		{
			return;
		}

		if (yearOfProduction.length() < 4)
		{
			throw exception("Year of production should be four characters long!");
		}

		if (yearOfProduction.find_first_not_of("1234567890") != string::npos)
		{
			throw exception("Year of production should only consists of digits!");
		}

		car->setYearOfProduction(stoul(yearOfProduction));

		menu = new WheelDriveTypeMenu();

		switch (menu->selectMode())
		{
		case WheelDriveType::FWD :
			car->setWheelDriveType("FWD");
			break;
		case WheelDriveType::RWD :
			car->setWheelDriveType("RWD");
			break;
		case WheelDriveType::AWD :
			car->setWheelDriveType("AWD");
			break;
		default:
			menu->resetChoice();
			return;
		}

		menu->resetChoice();

		clearLine();
		cout << "Wheel drive type: " << car->getWheelDriveType() << endl;

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
			menu->resetChoice();
			return;
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
			menu->resetChoice();
			return;
		}

		menu->resetChoice();

		clearLine();
		cout << "Transmission type: " << car->getTransmissionType() << endl;

		cout << "Engine volume: ";
		if (limitedInput(engineVolume, engineVolumeMaxInputLength) == false)
		{
			return;
		}

		if (engineVolume.length() < 3 || engineVolume.length() > 3)
		{
			throw exception("Engine volume should be three characters long!");
		}

		if (engineVolume.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Engine volume should only consists of digits!");
		}

		if (engineVolume.find(".") != 1)
		{
			throw exception("Engine volume should be like X.Y!");
		}

		car->setEngineVolume(stod(engineVolume));

		cout << "Body color: ";
		if (limitedInput(bodyColor, bodyColorMaxInputLength) == false)
		{
			return;
		}

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
		if (limitedInput(interiorColor, interiorColorMaxInputLength) == false)
		{
			return;
		}

		if (interiorColor.length() < 3)
		{
			throw exception("Interior color should be at least three characters long!");
		}

		if (interiorColor.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != string::npos)
		{
			throw exception("Interior color should only consists of letters!");
		}

		car->setInteriorColor(interiorColor);

		cout << "Interior material: ";
		if (limitedInput(interiorMaterial, interiorMaterialMaxInputLength) == false)
		{
			return;
		}

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
		if (limitedInput(mealeage, mealeageMaxInputLength) == false)
		{
			return;
		}

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
		if (limitedInput(price, priceMaxInputLength) == false)
		{
			return;
		}

		if (price.length() < 1)
		{
			throw exception("Price should be at least one characters long!");
		}

		if (price.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Price should only consists of digits!");
		}

		car->setPrice(stoul(price));

		car->setReserveStatus(false);

		cars_.push_back(*car);

		rewriteCarsFile();

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
			index--;
		}

		cars_.erase(cars_.begin() + index);

		rewriteCarsFile();

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

void CarHandler::reserveNewCar()
{
	ItemSelection<Car>* itemSelection = nullptr;

	unsigned index = 0;

	try
	{
		if (cars_.size() == 0)
		{
			throw exception("Cars list is empty!");
		}
		if (countNotReservedNewCars() == 0)
		{
			throw exception("No not reserved new cars!");
		}

		auto notReservedNewCars = getNotReservedNewCars();

		itemSelection = new ItemSelection<Car>("Choose car to reserve:", notReservedNewCars.second);

		index = itemSelection->selectMode();

		if (index == 0)
		{
			return;
		}
		else
		{
			index--;
		}

		notReservedNewCars.first.at(index)->setReserveStatus(true);
		notReservedNewCars.first.at(index)->setReserverUsername(AccountHandler::getCurrentAccount()->getUsername());

		rewriteCarsFile();

		system("cls");

		setTextColor(Color::LIGHT_GREEN);
		cout << "You succesfully reserved a car!" << endl << endl;
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

void CarHandler::reserveUsedCar()
{
	ItemSelection<Car>* itemSelection = nullptr;

	unsigned index = 0;

	try
	{
		if (cars_.size() == 0)
		{
			throw exception("Cars list is empty!");
		}
		if (countNotReservedUsedCars() == 0)
		{
			throw exception("No not reserved used cars!");
		}

		auto notReservedUsedCars = getNotReservedUsedCars();

		itemSelection = new ItemSelection<Car>("Choose car to reserve:", notReservedUsedCars.second);

		index = itemSelection->selectMode();

		if (index == 0)
		{
			return;
		}
		else
		{
			index--;
		}

		notReservedUsedCars.first.at(index)->setReserveStatus(true);
		notReservedUsedCars.first.at(index)->setReserverUsername(AccountHandler::getCurrentAccount()->getUsername());

		rewriteCarsFile();

		system("cls");

		setTextColor(Color::LIGHT_GREEN);
		cout << "You succesfully reserved a car!" << endl << endl;
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

void CarHandler::editCar()
{
	ItemSelection<Car>* itemSelection = nullptr;

	unsigned index = 0;

	ConsoleMenu* menu = nullptr;

	try
	{
		if (cars_.size() == 0)
		{
			throw exception("Car list is empty!");
		}

		itemSelection = new ItemSelection<Car>("Shoose car to edit: ", cars_);

		index = itemSelection->selectMode();

		if (index == 0)
		{
			return;
		}
		else
		{
			index--;
		}

		carToEdit_ = getCar(index);

		menu = new CarEditMenu();

		while (menu)
		{
			menu = menu->getNextMenu();
		}

		delete itemSelection;
		delete menu;
	}
	catch (exception & ex)
	{
		system("cls");

		setTextColor(Color::RED);
		cout << ex.what() << endl << endl;
		setTextColor(Color::LIGHT_CYAN);

		system("pause");
	}
}

// Destructor
CarHandler::~CarHandler()
{
	delete carToEdit_;
}