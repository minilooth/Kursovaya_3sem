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

				if (bodyType == "Кроссовер")
				{
					car = new Crossover(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
										interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Кабриолет")
				{
					car = new Cabriolet(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
										interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Хэтчбэк 5 дв.")
				{
					car = new FiveDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
												interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "5 м. минивен")
				{
					car = new FiveSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
											  interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "4 дв. купе")
				{
					car = new FourDoorCoupe(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
											interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Длинный седан")
				{
					car = new LongWheelbaseSedan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
												 interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Седан")
				{
					car = new Sedan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
									interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "7 м. минивен")
				{
					car = new SevenSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
											   interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Универсал")
				{
					car = new StationWagon(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
										   interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Хэтчбэк 3 дв.")
				{
					car = new ThreeDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor, 
												 interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "2 дв. купе")
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

				if (bodyType == "Кроссовер")
				{
					car = new Crossover(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Кабриолет")
				{
					car = new Cabriolet(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Хэтчбэк 5 дв.")
				{
					car = new FiveDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "5 м. минивен")
				{
					car = new FiveSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "4 дв. купе")
				{
					car = new FourDoorCoupe(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Длинный седан")
				{
					car = new LongWheelbaseSedan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Седан")
				{
					car = new Sedan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "7 м. минивен")
				{
					car = new SevenSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Универсал")
				{
					car = new StationWagon(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "Хэтчбэк 3 дв.")
				{
					car = new ThreeDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mealeage, price, reserveStatus, reserverUsername);
				}
				else if (bodyType == "2 дв. купе")
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

string CarHandler::createReport(Car& car)
{
	time_t time = std::time(0);
	tm* now = std::localtime(&time);

	ofstream report;
	string path = "Checks/";
	string filename = to_string(now->tm_mday) + "-" + to_string(now->tm_mon + 1) + "-" + to_string(now->tm_year + 1900) + " " + 
					  to_string(now->tm_hour) + "." + to_string(now->tm_min) + "." + to_string(now->tm_sec) + ".txt";

	string currentDate = to_string(now->tm_mday) + "." + to_string(now->tm_mon + 1) + "." + to_string(now->tm_year + 1900) + " " +
						 to_string(now->tm_hour) + ":" + to_string(now->tm_min);

	if (!filesystem::exists(path))
	{
		filesystem::create_directory(path);
	}

	report.open(path + filename);

	if (report.is_open())
	{
		report << "-----------------------------------------------------------------------------------" << endl
			   << makeCenteredString("Чек о продаже автомобиля", 83) << endl
			   << "-----------------------------------------------------------------------------------" << endl
			   << "Марка:" << setw(77) << right << car.getBrand() << endl
			   << "Модель:" << setw(76) << right << car.getModel() << endl
			   << "Год выпуска:" << setw(71) << right << car.getYearOfProduction() << endl
			   << "КПП:" << setw(80) << right << car.getTransmissionType() << endl
			   << "Привод:" << setw(76) << right << car.getWheelDriveType() << endl
			   << "Тип двигателя:" << setw(69) << right << car.getEngineType() << endl
			   << "Объем двигателя:" << setw(67) << right << car.getEngineVolume() << endl
			   << "Тип кузова:" << setw(72) << right << car.getBodyType() << endl
			   << "Цвет кузова:" << setw(71) << right << car.getBodyColor() << endl
			   << "Цвет салона:" << setw(71) << right << car.getInteriorColor() << endl
			   << "Материал салона:" << setw(67) << right << car.getInteriorMaterial() << endl
			   << "Пробег:" << setw(76) << right << car.getMealeage() << " km" << endl
			   << "-----------------------------------------------------------------------------------" << endl
			   << "Покупатель:" << setw(72) << right << car.getReserverUsername() << endl
			   << "Цена:" << setw(78) << right << car.getPrice() << "$" << endl
			   << "-----------------------------------------------------------------------------------" << endl
			   << "Дата продажи:" << setw(70) << right << currentDate << endl;

		report.close();
	}

	return (path + filename);
}

// Equal
bool CarHandler::isBodyTypesNotEqual(Car& car)
{
	return car.getBodyType() != CarFiltering::getBodyTypeFilter();
}

bool CarHandler::isTransmissionTypesNotEqual(Car& car)
{
	return car.getTransmissionType() != CarFiltering::getTransmissionTypeFilter();
}

bool CarHandler::isWheelDriveTypesNotEqual(Car& car)
{
	return car.getWheelDriveType() != CarFiltering::getWheelDriveTypeFilter();
}

// Compare
bool CarHandler::compareYearsOfProductionsAscending(Car& firstCar, Car& secondCar)
{
	return firstCar.getYearOfProduction() > secondCar.getYearOfProduction();
}

bool CarHandler::compareYearsOfProductionsDescending(Car& firstCar, Car& secondCar)
{
	return firstCar.getYearOfProduction() < secondCar.getYearOfProduction();
}

bool CarHandler::compareEngineVolumesAscending(Car& firstCar, Car& secondCar)
{
	return firstCar.getEngineVolume() > secondCar.getEngineVolume();
}

bool CarHandler::compareEngineVolumesDescending(Car& firstCar, Car& secondCar)
{
	return firstCar.getEngineVolume() < secondCar.getEngineVolume();
}

bool CarHandler::comparePricesAscending(Car& firstCar, Car& secondCar)
{
	return firstCar.getPrice() > secondCar.getPrice();
}

bool CarHandler::comparePricesDescending(Car& firstCar, Car& secondCar)
{
	return firstCar.getPrice() < secondCar.getPrice();
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

// Set
void CarHandler::setFilterByBodyType()
{
	ConsoleMenu* menu = new BodyTypeMenu();

	if (CarFiltering::getBodyTypeFilterStatus() == false)
	{
		system("cls");

		switch (menu->selectMode())
		{
		case BodyType::CROSSOVER:
			CarFiltering::setBodyTypeFilter("Кроссовер");
			break;
		case BodyType::CABRIOLET:
			CarFiltering::setBodyTypeFilter("Кабриолет");
			break;
		case BodyType::FIVE_DOOR_HATCHBACK:
			CarFiltering::setBodyTypeFilter("Хэтчбек 5 дв.");
			break;
		case BodyType::FIVE_SEAT_MINIVAN:
			CarFiltering::setBodyTypeFilter("5 м. минивен");
			break;
		case BodyType::FOUR_DOOR_COUPE:
			CarFiltering::setBodyTypeFilter("4 дв. купе");
			break;
		case BodyType::LONG_WHEEL_BASE_SEDAN:
			CarFiltering::setBodyTypeFilter("Длинный седан");
			break;
		case BodyType::SEDAN:
			CarFiltering::setBodyTypeFilter("Седан");
			break;
		case BodyType::SEVEN_SEAT_MINIVAN:
			CarFiltering::setBodyTypeFilter("7 м. минивен");
			break;
		case BodyType::STATION_WAGON:
			CarFiltering::setBodyTypeFilter("Универсал");
			break;
		case BodyType::THREE_DOOR_HATCHBACK:
			CarFiltering::setBodyTypeFilter("Хэтчбек 3 дв.");
			break;
		case BodyType::TWO_DOOR_COUPE:
			CarFiltering::setBodyTypeFilter("2 дв. купе");
			break;
		default:
			menu->resetChoice();
			delete menu;
			return;
		}
		menu->resetChoice();
		delete menu;
	}
	else
	{
		CarFiltering::resetBodyTypeFilter();
	}

	system("cls");

	setTextColor(Color::LIGHT_GREEN);
	if (CarFiltering::getBodyTypeFilterStatus() == false)
	{
		cout << "Фильтр успешно удален!" << endl << endl;
	}
	else
	{
		cout << "Фильтр успешно установлен!" << endl << endl;
	}
	setTextColor(Color::LIGHT_CYAN);

	system("pause");
}

void CarHandler::setFilterByWheelDriveType()
{
	ConsoleMenu* menu = new WheelDriveTypeMenu("Тип привода:", { "Передний.", "Задний.", "Полный.", "Назад." });

	if (CarFiltering::getWheelDriveTypeFilterStatus() == false)
	{
		system("cls");

		switch (menu->selectMode())
		{
		case WheelDriveType::FWD:
			CarFiltering::setWheelDriveTypeFilter("Передний");
			break;
		case WheelDriveType::RWD:
			CarFiltering::setWheelDriveTypeFilter("Задний");
			break;
		case WheelDriveType::AWD:
			CarFiltering::setWheelDriveTypeFilter("Полный");
			break;
		default:
			menu->resetChoice();
			delete menu;
			return;
		}
		menu->resetChoice();
		delete menu;
	}
	else
	{
		CarFiltering::resetWheelDriveTypeFilter();
	}

	system("cls");

	setTextColor(Color::LIGHT_GREEN);
	if (CarFiltering::getWheelDriveTypeFilterStatus() == false)
	{
		cout << "Фильтр успешно удален!" << endl << endl;
	}
	else
	{
		cout << "Фильтр успешно установлен!" << endl << endl;
	}
	setTextColor(Color::LIGHT_CYAN);

	system("pause");
}

void CarHandler::setFilterByTransmissionType()
{
	ConsoleMenu* menu = new TransmissionTypeMenu("Тип КПП:", { "Механическая.", "Автоматическая.", "Назад." });

	if (CarFiltering::getTransmissionTypeFilterStatus() == false)
	{
		system("cls");

		switch (menu->selectMode())
		{
		case TransmissionType::MANUAL:
			CarFiltering::setTransmissionTypeFilter("Механическая");
			break;
		case TransmissionType::AUTOMATIC:
			CarFiltering::setTransmissionTypeFilter("Автоматическая");
			break;
		default:
			menu->resetChoice();
			delete menu;
			return;
		}
		menu->resetChoice();;
		delete menu;
	}
	else
	{
		CarFiltering::resetTransmissionTypeFilter();
	}

	system("cls");

	setTextColor(Color::LIGHT_GREEN);
	if (CarFiltering::getTransmissionTypeFilterStatus() == false)
	{
		cout << "Фильтр успешно удален!" << endl << endl;
	}
	else
	{
		cout << "Фильтр успешно установлен!" << endl << endl;
	}
	setTextColor(Color::LIGHT_CYAN);

	system("pause");
}

// Count
//unsigned CarHandler::countNewCars()
//{
//	unsigned counter = 0;
//	for (unsigned i = 0; i < cars_.size(); i++)
//	{
//		if (cars_.at(i).getMealeage() == 0.0)
//		{
//			counter++;
//		}
//	}
//	return counter;
//}
//
//unsigned CarHandler::countNotReservedNewCars()
//{
//	unsigned counter = 0;
//	for (unsigned i = 0; i < cars_.size(); i++)
//	{
//		if (cars_.at(i).getReserveStatus() == false && cars_.at(i).getMealeage() == 0.0)
//		{
//			counter++;
//		}
//	}
//	return counter;
//}
//
//unsigned CarHandler::countUsedCars()
//{
//	unsigned counter = 0;
//	for (unsigned i = 0; i < cars_.size(); i++)
//	{
//		if (cars_.at(i).getMealeage() != 0.0)
//		{
//			counter++;
//		}
//	}
//	return counter;
//}
//
//unsigned CarHandler::countNotReservedUsedCars()
//{
//	unsigned counter = 0;
//	for (unsigned i = 0; i < cars_.size(); i++)
//	{
//		if (cars_.at(i).getReserveStatus() == false && cars_.at(i).getMealeage() != 0.0)
//		{
//			counter++;
//		}
//	}
//	return counter;
//}
//
//unsigned CarHandler::countReservedCars()
//{
//	unsigned counter = 0;
//	for (unsigned i = 0; i < cars_.size(); i++)
//	{
//		if (cars_.at(i).getReserveStatus() == true)
//		{
//			counter++;
//		}
//	}
//	return counter;
//}

// Search
void CarHandler::searchByBrand()
{
	string brand;

	try
	{
		system("cls");

		cout << "Введите марку: ";
		if (limitedInput(brand, brandMaxInputLength) == false)
		{
			return;
		}

		if (brand.length() < 3)
		{
			throw exception("Марка должна быть как минимум три символа в длину!");
		}

		if (brand.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя ") != string::npos)
		{
			throw exception("Марка должна состоять только из букв!");
		}

		auto cars = getCarsByBrand(brand);

		if (cars.size() == 0)
		{
			throw exception("Не найдено ни одного автомобиля!");
		}

		system("cls");

		cout << "Были найдены автомобили: " << endl << endl;

		CarPrinter::printCars(cars);

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

void CarHandler::searchByModel()
{
	string model;

	try
	{
		system("cls");

		cout << "Введите модель: ";
		if (limitedInput(model, modelMaxInputLength) == false)
		{
			return;
		}

		if (model.length() < 2)
		{
			throw exception("Модель должна быть как минимум два символа в длину!");
		}

		if (model.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890") != string::npos)
		{
			throw exception("Модель должна состоять только из цифр и букв латинского алфавита!");
		}

		auto cars = getCarsByModel(model);

		if (cars.size() == 0)
		{
			throw exception("Не найдено ни одного автомобиля!");
		}

		system("cls");

		cout << "Были найдены автомобили: " << endl << endl;

		CarPrinter::printCars(cars);

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

void CarHandler::searchByYearOfProduction()
{
	string yearOfProduction;

	try
	{
		system("cls");

		cout << "Введите новый год выпуска: ";
		if (limitedInput(yearOfProduction, yearOfProductionMaxInputLength) == false)
		{
			return;
		}

		if (yearOfProduction.length() < 4)
		{
			throw exception("Год выпуска должен быть минимум четыре символа в длину!");
		}
		if (yearOfProduction.find_first_not_of("1234567890") != string::npos)
		{
			throw exception("Год выпуска должен состоять только из цифр!");
		}
		if (stoul(yearOfProduction) < 1900 || stoul(yearOfProduction) > 2020)
		{
			throw exception("Год выпуска должен быть больше чем 1900 и меньше чем 2020!");
		}

		auto cars = getCarsByYearOfProduction(stoul(yearOfProduction));

		if (cars.size() == 0)
		{
			throw exception("Не найдено ни одного автомобиля!");
		}

		system("cls");

		cout << "Были найдены автомобили: " << endl << endl;

		CarPrinter::printCars(cars);

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

void CarHandler::searchByEngineType()
{
	ConsoleMenu* menu = nullptr;

	string engineType;

	try
	{
		system("cls");

		menu = new EngineTypeMenu("Выберите тип двигателя: ", { "Бензиновый.", "Дизельный.", "Назад." });

		switch (menu->selectMode())
		{
		case EngineType::PETROL:
			engineType = "Бензиновый";
			break;
		case EngineType::DIESEL:
			engineType = "Дизельный";
			break;
		default:
			menu->resetChoice();
			delete menu;
			return;
		}
		menu->resetChoice();
		delete menu;

		auto cars = getCarsByEngineType(engineType);

		if (cars.size() == 0)
		{
			throw exception("Не найдено ни одного автомобиля!");
		}

		system("cls");

		cout << "Были найдены автомобили: " << endl << endl;

		CarPrinter::printCars(cars);

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

// Sorting
void CarHandler::sortByYearOfProduction()
{
	ConsoleMenu* menu = nullptr;

	try
	{
		auto cars = getCars();
		if (cars.size() == 0)
		{
			throw exception("Список автомобилей пуст!");
		}

		menu = new TypeOfSortingMenu();

		switch (menu->selectMode())
		{
		case TypeOfSortingMenuAction::ASCENDING :
			sort(cars.begin(), cars.end(), compareYearsOfProductionsAscending);
			break;
		case TypeOfSortingMenuAction::DESCENDING :
			sort(cars.begin(), cars.end(), compareYearsOfProductionsDescending);
			break;
		case TypeOfSortingMenuAction::BACK :
			menu->resetChoice();
			delete menu;
			return;
		}
		menu->resetChoice();
		delete menu;

		system("cls");

		cout << "Автомобили, отсортированные по году выпуска по убыванию:" << endl << endl;

		CarPrinter::printCars(cars);

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

void CarHandler::sortByEngineVolume()
{
	ConsoleMenu* menu = nullptr;

	try
	{
		auto cars = getCars();
		if (cars.size() == 0)
		{
			throw exception("Список автомобилей пуст!");
		}

		menu = new TypeOfSortingMenu();

		switch (menu->selectMode())
		{
		case TypeOfSortingMenuAction::ASCENDING :
			sort(cars.begin(), cars.end(), compareEngineVolumesAscending);
			break;
		case TypeOfSortingMenuAction::DESCENDING :
			sort(cars.begin(), cars.end(), compareEngineVolumesDescending);
			break;
		case TypeOfSortingMenuAction::BACK :
			menu->resetChoice();
			delete menu;
			return;
		}
		menu->resetChoice();
		delete menu;

		system("cls");

		CarPrinter::printCars(cars);

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

void CarHandler::sortByPrice()
{
	ConsoleMenu* menu = nullptr;
	try
	{
		auto cars = getCars();
		if (cars.size() == 0)
		{
			throw exception("Список автомобилей пуст!");
		}

		menu = new TypeOfSortingMenu();

		switch (menu->selectMode())
		{
		case TypeOfSortingMenuAction::ASCENDING :
			sort(cars.begin(), cars.end(), comparePricesAscending);
			break;
		case TypeOfSortingMenuAction::DESCENDING : 
			sort(cars.begin(), cars.end(), comparePricesDescending);
			break;
		case TypeOfSortingMenuAction::BACK :
			menu->resetChoice();
			return;
		}
		menu->resetChoice();
		delete menu;

		system("cls");

		CarPrinter::printCars(cars);

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

// Edit
void CarHandler::editBrand()
{
	string brand;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		cout << "Введите новую марку: ";
		if (limitedInput(brand, brandMaxInputLength) == false)
		{
			return;
		}

		if (brand.length() < 3)
		{
			throw exception("Марка должна быть как минимум три символа в длину!");
		}

		if (brand.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя ") != string::npos)
		{
			throw exception("Марка должна состоять только из букв!");
		}

		carToEdit_->setBrand(brand);

		rewriteCarsFile();

		system("cls");

		showEditCar();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Марка успешно изменена!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Марка не изменена!" << endl << endl;
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
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		cout << "Введите новую модель: ";
		if (limitedInput(model, modelMaxInputLength) == false)
		{
			return;
		}

		if (model.length() < 2)
		{
			throw exception("Модель должна быть как минимум два символа в длину!");
		}

		if (model.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890") != string::npos)
		{
			throw exception("Модель должна состоять только из цифр и букв латинского алфавита!");
		}

		carToEdit_->setModel(model);

		rewriteCarsFile();

		system("cls");

		showEditCar();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Модель успешно изменена!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Модель не изменена!" << endl << endl;
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
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		cout << "Введите новый год выпуска: ";
		if (limitedInput(yearOfProduction, yearOfProductionMaxInputLength) == false)
		{
			return;
		}

		if (yearOfProduction.length() < 4)
		{
			throw exception("Год выпуска должен быть минимум четыре символа в длину!");
		}
		if (yearOfProduction.find_first_not_of("1234567890") != string::npos)
		{
			throw exception("Год выпуска должен состоять только из цифр!");
		}
		if (stoul(yearOfProduction) < 1900 || stoul(yearOfProduction) > 2020)
		{
			throw exception("Год выпуска должен быть больше чем 1900 и меньше чем 2020!");
		}

		carToEdit_->setYearOfProduction(stoul(yearOfProduction));

		rewriteCarsFile();

		system("cls");

		showEditCar();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Год выпуска успешно изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Год выпуска не изменен!" << endl << endl;
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
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		menu = new BodyTypeMenu();

		index = getCarIndex(carToEdit_);
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
		menu->resetChoice();

		cars_.erase(cars_.begin() + index);
		cars_.insert(cars_.begin() + index, *carToEdit_);

		carToEdit_ = getCar(index);

		rewriteCarsFile();

		system("cls");

		showEditCar();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Тип кузова успешно изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Тип кузова не изменен!" << endl << endl;
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
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		menu = new TransmissionTypeMenu("Тип КПП:", { "Механическая.", "Автоматическая.", "Назад." });

		switch (menu->selectMode())
		{
		case TransmissionType::MANUAL :
			carToEdit_->setTransmissionType("Механическая");
			break;
		case TransmissionType::AUTOMATIC :
			carToEdit_->setTransmissionType("Автоматическая");
			break;
		default:
			menu->resetChoice();
			return;
		}
		menu->resetChoice();

		rewriteCarsFile();

		system("cls");

		showEditCar();

		setTextColor(Color::LIGHT_GREEN);
		cout << "КПП успешно изменена!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "КПП не изменена!" << endl << endl;
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
			throw exception("Редактиреумый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		menu = new WheelDriveTypeMenu("Тип привода:", {"Передний.", "Задний.", "Полный.", "Назад."});

		switch (menu->selectMode())
		{
		case WheelDriveType::FWD :
			carToEdit_->setWheelDriveType("Передний");
			break;
		case WheelDriveType::RWD :
			carToEdit_->setWheelDriveType("Задний");
			break;
		case WheelDriveType::AWD :
			carToEdit_->setWheelDriveType("Полный");
			break;
		default:
			menu->resetChoice();
			return;
		}
		menu->resetChoice();

		rewriteCarsFile();

		system("cls");

		showEditCar();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Привод успешно изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Привод не изменен!" << endl << endl;
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
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		menu = new EngineTypeMenu("Тип двигателя: ", { "Бензиновый.", "Дизельный.", "Назад." });

		switch (menu->selectMode())
		{
		case EngineType::PETROL :
			carToEdit_->setEngineType("Бензиновый");
			break;
		case EngineType::DIESEL :
			carToEdit_->setEngineType("Дизельный");
			break;
		default:
			menu->resetChoice();
			return;
		}
		menu->resetChoice();

		rewriteCarsFile();

		system("cls");

		showEditCar();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Тип двигателя успешно изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Тип двигателя не изменен!" << endl << endl;
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
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		cout << "Введите новый объем двигателя: ";
		if (limitedInput(engineVolume, engineVolumeMaxInputLength) == false)
		{
			return;
		}

		if (engineVolume.length() < 3 || engineVolume.length() > 3)
		{
			throw exception("Объем двигателя должен состоять не меньше и не более чем из трех символов!");
		}

		if (engineVolume.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Объем двигателя должен стостять только из цирф!");
		}

		if (engineVolume.find(".") != 1)
		{
			throw exception("Объем двигателя должен быть заполнен в виде X.Y!");
		}

		carToEdit_->setEngineVolume(stod(engineVolume));

		rewriteCarsFile();

		system("cls");

		showEditCar();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Объем двигателя успешно изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Объем двигателя не изменен!" << endl << endl;
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
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		cout << "Введите новый цвет кузова: ";
		if (limitedInput(bodyColor, bodyColorMaxInputLength) == false)
		{
			return;
		}

		if (bodyColor.length() < 3)
		{
			throw exception("Цвет кузова должен состоять минимум из трех сиволов!");
		}

		if (bodyColor.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя- ") != string::npos)
		{
			throw exception("Цвет кузова должен состоять только из букв!");
		}

		carToEdit_->setBodyColor(bodyColor);

		rewriteCarsFile();

		system("cls");

		showEditCar();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Цвет кузова успешно изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Цвет кузова не изменен!" << endl << endl;
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
			throw exception("Редактируемый автомобиль не установен!");
		}

		system("cls");

		showEditCar();

		cout << "Введите новый цвет салона: ";
		if (limitedInput(interiorColor, interiorColorMaxInputLength) == false)
		{
			return;
		}

		if (interiorColor.length() < 3)
		{
			throw exception("Цвет салона должен состоять как мининмум из трех символов!");
		}

		if (interiorColor.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя- ") != string::npos)
		{
			throw exception("Цвет салона должен стостоять только из букв!");
		}

		carToEdit_->setInteriorColor(interiorColor);

		rewriteCarsFile();

		system("cls");

		showEditCar();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Цвет салона успешно изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Цвет салона не изменен!" << endl << endl;
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
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		cout << "Введите новый материал салона: ";
		if (limitedInput(interiorMaterial, interiorMaterialMaxInputLength) == false)
		{
			return;
		}

		if (interiorMaterial.length() < 3)
		{
			throw exception("Материал салона должен состоять как минимум из трех символов!");
		}

		if (interiorMaterial.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя ") != string::npos)
		{
			throw exception("Материал салона должен состоять только из букв!");
		}

		carToEdit_->setInteriorMaterial(interiorMaterial);

		rewriteCarsFile();

		system("cls");

		showEditCar();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Материал салона успешно изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Материал салона не изменен!" << endl << endl;
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
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		cout << "Введите новый пробег: ";
		if (limitedInput(mealeage, mealeageMaxInputLength) == false)
		{
			return;
		}

		if (mealeage.length() < 1)
		{
			throw exception("Пробег должен состоять как минимум из одного символа!");
		}

		if (mealeage.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Пробег должен состоять только из цифр!");
		}

		carToEdit_->setMealeage(stoul(mealeage));

		rewriteCarsFile();

		system("cls");

		showEditCar();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Пробег успешно изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Пробег не изменен!" << endl << endl;
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
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		cout << "Введите новую цену: ";
		if (limitedInput(price, priceMaxInputLength) == false)
		{
			return;
		}

		if (price.length() < 1)
		{
			throw exception("Цена должна состоять как минимум из одного символа!");
		}

		if (price.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Цена должна состоять только из цифр!");
		}

		carToEdit_->setPrice(stoul(price));

		rewriteCarsFile();

		system("cls");

		showEditCar();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Цена успешно изменена!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Цена не изменена!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editReserveStatus()
{
	ItemSelection<Account>* itemSelection = nullptr;

	unsigned index = 0;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Редактируемый автомобиль не изменен!");
		}

		
		if (carToEdit_->getReserveStatus() == true)
		{
			carToEdit_->setReserveStatus(!(carToEdit_->getReserveStatus()));
		}
		else
		{
			auto accounts = AccountHandler::getUsers();

			itemSelection = new ItemSelection<Account>("Выберете новый резервирующий аккаунт:", accounts);

			index = itemSelection->selectMode();

			if (index == 0)
			{
				return;
			}
			else
			{
				index--;
			}

			carToEdit_->setReserverUsername(accounts.at(index).getUsername());
			carToEdit_->setReserveStatus(true);
		}

		rewriteCarsFile();

		system("cls");

		showEditCar();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Статус резерва успешно изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Статус резерва не изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editReserverUsername()
{
	ItemSelection<Account>* itemSelection = nullptr;

	unsigned index = 0;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		auto accounts = AccountHandler::getUsers();

		itemSelection = new ItemSelection<Account>("Выберете новый резервирующий автомобиль:", accounts);

		index = itemSelection->selectMode();

		if (index == 0)
		{
			return;
		}
		else
		{
			index--;
		}

		if (carToEdit_->getReserveStatus() == false)
		{
			carToEdit_->setReserveStatus(true);
		}

		carToEdit_->setReserverUsername(accounts.at(index).getUsername());

		rewriteCarsFile();

		system("cls");

		showEditCar();

		setTextColor(Color::LIGHT_GREEN);
		cout << "Резервирующий аккаунт успешно изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Резервирующий аккаунт не изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	system("pause");
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
	//vector<Car*> cars;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getMealeage() != 0.0 && cars_.at(i).getReserveStatus() == false)
		{
			//cars.push_back(&(cars_.at(i)));
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

vector<Car> CarHandler::getUsedCars()
{
	vector<Car> cars;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getMealeage() != 0.0)
		{
			cars.push_back(cars_.at(i));
		}
	}
	return cars;
}

vector<Car> CarHandler::getNewCars()
{
	vector<Car> cars;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getMealeage() == 0.0)
		{
			cout << cars_.at(i) << endl;
		}
	}
	return cars;
}

vector<Car> CarHandler::getFilteredCars()
{
	auto cars = getCars();
	if (CarFiltering::getBodyTypeFilterStatus() == true)
	{
		cars.erase(remove_if(cars.begin(), cars.end(), isBodyTypesNotEqual), cars.end());
	}
	if (CarFiltering::getWheelDriveTypeFilterStatus() == true)
	{
		cars.erase(remove_if(cars.begin(), cars.end(), isWheelDriveTypesNotEqual), cars.end());
	}
	if (CarFiltering::getTransmissionTypeFilterStatus() == true)
	{
		cars.erase(remove_if(cars.begin(), cars.end(), isTransmissionTypesNotEqual), cars.end());
	}
	return cars;
}

vector<Car> CarHandler::getCarsByBrand(const string& brand)
{
	vector<Car> cars;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getBrand() == brand)
		{
			cars.push_back(cars_.at(i));
		}
	}
	return cars;
}

vector<Car> CarHandler::getCarsByModel(const string& model)
{
	vector<Car> cars;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getModel() == model)
		{
			cars.push_back(cars_.at(i));
		}
	}
	return cars;
}

vector<Car> CarHandler::getCarsByYearOfProduction(const unsigned yearOfProduction)
{
	vector<Car> cars;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getYearOfProduction() == yearOfProduction)
		{
			cars.push_back(cars_.at(i));
		}
	}
	return cars;
}

vector<Car> CarHandler::getCarsByEngineType(const string& engineType)
{
	vector<Car> cars;
	for (unsigned i = 0; i < cars_.size(); i++)
	{
		if (cars_.at(i).getEngineType() == engineType)
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
			throw exception("Список автомобилей пуст!");
		}

		system("cls");

		cout << "Все автомобили: " << endl << endl;

		CarPrinter::printCars(cars_);

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
			throw exception("Текущий аккаунт не установлен!");
		}

		auto cars = getReservedCarsByUsername(AccountHandler::getCurrentAccount()->getUsername());

		if (cars.size() == 0)
		{
			throw exception("У вас нет зарезервированных автомобилей!");
		}

		system("cls");

		cout << "Автомобили, зарезервиранные вами: " << endl << endl;

		CarPrinter::printCars(cars);

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
	auto newCars = getNewCars();

	try
	{
		if (newCars.size() == 0)
		{
			throw exception("Список новых автомобилей пуст!");
		}

		system("cls");

		CarPrinter::printCars(newCars);

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
	auto usedCars = getUsedCars();
	try
	{
		if (usedCars.size() == 0)
		{
			throw exception("Список автомобилей с пробегом пуст!");
		}

		system("cls");

		CarPrinter::printCars(usedCars);

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
	CarPrinter::printCars({ *carToEdit_ });

	cout << endl;
}

void CarHandler::showFilteredCars()
{
	auto cars = getFilteredCars();
	try
	{
		if (cars.size() == 0)
		{
			throw exception("Такие автомобили не найдены!");
		}

		system("cls");

		cout << "Отфильтрованные автомобили:" << endl << endl;

		CarPrinter::printCars(cars);

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

void CarHandler::sellCar()
{
	ItemSelection<Car>* itemSelection = nullptr;

	unsigned index = 0;

	string path;

	try
	{
		if (cars_.size() == 0)
		{
			throw exception("Список автомобилей пуст!");
		}

		auto reservedCars = getReservedCars();

		if (reservedCars.second.size() == 0)
		{
			throw exception("Нет зарезервированных атвоомобилей!");
		}

		itemSelection = new ItemSelection<Car>("Выберете автомобиль для продажи:", reservedCars.second);

		index = itemSelection->selectMode();

		if (index == 0)
		{
			return;
		}
		else
		{
			index--;
		}

		path = createReport(cars_.at(index));

		StatisticsHandler::getAccountStatistics(cars_.at(index).getReserverUsername())->addPurchaseAmount(cars_.at(index).getPrice());
		StatisticsHandler::rewriteStatisticsFile();

		cars_.erase(cars_.begin() + index);

		rewriteCarsFile();

		system("cls");

		setTextColor(Color::LIGHT_GREEN);
		cout << "Автомобиль успешно продан!\nЧек сохранен по пути " << path << endl << endl;
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
		cout << "Марка: ";
		if (limitedInput(brand, brandMaxInputLength) == false)
		{
			return;
		}

		if (brand.length() < 3)
		{
			throw exception("Марка должна состоять как минимум из трех символов!");
		}

		if (brand.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя ") != string::npos)
		{
			throw exception("Марка должна состоять только из букв!");
		}

		car->setBrand(brand);

		cout << "Модель: ";
		if (limitedInput(model, modelMaxInputLength) == false)
		{
			return;
		}

		if (model.length() < 2)
		{
			throw exception("Модель должна состоять как минимум из трех символов!");
		}

		if (model.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890") != string::npos)
		{
			throw exception("Модель должна состоять только из цифр и букв латинского алфавита!");
		}
		
		car->setModel(model);

		cout << "Год выпуска: ";
		if (limitedInput(yearOfProduction, yearOfProductionMaxInputLength) == false)
		{
			return;
		}

		if (yearOfProduction.length() < 4)
		{
			throw exception("Год выпуска должен состоять из четырех символов!");
		}

		if (yearOfProduction.find_first_not_of("1234567890") != string::npos)
		{
			throw exception("Год выпуска должен состоять только из цифр!");
		}
		if (stoul(yearOfProduction) < 1900 || stoul(yearOfProduction) > 2020)
		{
			throw exception("Год выпуска должен быть больше 1900 и меньше чем 2020!");
		}

		car->setYearOfProduction(stoul(yearOfProduction));

		menu = new WheelDriveTypeMenu();

		switch (menu->selectMode())
		{
		case WheelDriveType::FWD :
			car->setWheelDriveType("Передний");
			break;
		case WheelDriveType::RWD :
			car->setWheelDriveType("Задний");
			break;
		case WheelDriveType::AWD :
			car->setWheelDriveType("Полный");
			break;
		default:
			menu->resetChoice();
			return;
		}

		menu->resetChoice();

		clearNLines(4);
		cout << "Привод: " << car->getWheelDriveType() << endl;

		menu = new EngineTypeMenu("Тип двигателя:", {"Бензиновый.", "Дизельный."});

		switch (menu->selectMode())
		{
		case EngineType::PETROL :
			car->setEngineType("Бензиновый");
			break;
		case EngineType::DIESEL :
			car->setEngineType("Дизельный");
			break;
		default:
			menu->resetChoice();
			return;
		}

		menu->resetChoice();

		clearNLines(3);
		cout << "Тип двигателя: " << car->getEngineType() << endl;

		menu = new TransmissionTypeMenu("Тип КПП:", {"Механическая.", "Автоматическая."});

		switch (menu->selectMode())
		{
		case TransmissionType::MANUAL :
			car->setTransmissionType("Механическая");
			break;
		case TransmissionType::AUTOMATIC :
			car->setTransmissionType("Автоматическая");
			break;
		default:
			menu->resetChoice();
			return;
		}

		menu->resetChoice();

		clearNLines(3);
		cout << "Тип КПП: " << car->getTransmissionType() << endl;

		cout << "Объем двигателя: ";
		if (limitedInput(engineVolume, engineVolumeMaxInputLength) == false)
		{
			return;
		}

		if (engineVolume.length() < 3 || engineVolume.length() > 3)
		{
			throw exception("Объем двигателя должен состоять из трех символов!");
		}

		if (engineVolume.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Объем двигателя должен стоять только из цифр!");
		}

		if (engineVolume.find(".") != 1)
		{
			throw exception("Объем двигателя должен быть заполнен в виде X.Y!");
		}

		car->setEngineVolume(stod(engineVolume));

		cout << "Цвет кузова: ";
		if (limitedInput(bodyColor, bodyColorMaxInputLength) == false)
		{
			return;
		}

		if (bodyColor.length() < 3)
		{
			throw exception("Цвет кузова должен состоять как минимум из трех символов!");
		}

		if (bodyColor.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя- ") != string::npos)
		{
			throw exception("Цвет кузова должен состоять только из букв!");
		}

		car->setBodyColor(bodyColor);

		cout << "Цвет салона: ";
		if (limitedInput(interiorColor, interiorColorMaxInputLength) == false)
		{
			return;
		}

		if (interiorColor.length() < 3)
		{
			throw exception("Цвет салона должен состоять как минимум из трех символов!");
		}

		if (interiorColor.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя-  ") != string::npos)
		{
			throw exception("Цвет салона должен состоять только из букв!");
		}

		car->setInteriorColor(interiorColor);

		cout << "Материал салона: ";
		if (limitedInput(interiorMaterial, interiorMaterialMaxInputLength) == false)
		{
			return;
		}

		if (interiorMaterial.length() < 3)
		{
			throw exception("Материал салона должен состоять как минимум из трех символов!");
		}

		if (interiorMaterial.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя ") != string::npos)
		{
			throw exception("Материал салона должен состоять только из букв!");
		}

		car->setInteriorMaterial(interiorMaterial);

		cout << "Пробег: ";
		if (limitedInput(mealeage, mealeageMaxInputLength) == false)
		{
			return;
		}

		if (mealeage.length() < 1)
		{
			throw exception("Пробег должен состоять как минимум из одного символа!");
		}

		if (mealeage.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Пробег должен состоять только из цифр!");
		}

		car->setMealeage(stoul(mealeage));

		cout << "Цена: ";
		if (limitedInput(price, priceMaxInputLength) == false)
		{
			return;
		}

		if (price.length() < 1)
		{
			throw exception("Цена должна состоять как минимум из одного символа!");
		}

		if (price.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Цена должна состоять только из цифр!");
		}

		car->setPrice(stoul(price));

		car->setReserveStatus(false);
		car->setReserverUsername("");

		cars_.push_back(*car);

		rewriteCarsFile();

		setTextColor(Color::LIGHT_GREEN);
		cout << endl << "Автомобиль успешно добавлен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		setTextColor(Color::RED);
		cout << endl << ex.what() << endl << "Автомобиль не добавлен!" << endl << endl;
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
			throw exception("Список автомобилей пуст!");
		}

		itemSelection = new ItemSelection<Car>("Выберете автомобиль для удаления:", cars_);

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
		cout << "Автомобиль успешно удален!" << endl << endl;
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
			throw exception("Список автомобилей пуст!");
		}

		auto notReservedNewCars = getNotReservedNewCars();

		if (notReservedNewCars.first.size() == 0)
		{
			throw exception("Список незарезервированных новых автомобилей пуст!");
		}

		itemSelection = new ItemSelection<Car>("Выберете автомобиль, чтобы его зарезервировать:", notReservedNewCars.second);

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
		cout << "Вы успешно зарезервировали автомобиль!" << endl << endl;
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
			throw exception("Список автомобилей пуст!");
		}
		auto notReservedUsedCars = getNotReservedUsedCars();

		if (notReservedUsedCars.first.size() == 0)
		{
			throw exception("Список незарезервированных автомобилей с пробегом пуст!");
		}

		itemSelection = new ItemSelection<Car>("Выберите автомобиль, чтобы его зарезервировать:", notReservedUsedCars.second);
		//itemSelection = new ItemSelection<Car>("Выберите автомобиль, чтобы его зарезервировать:", notReservedUsedCars.second);

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
		cout << "Вы успешно зарезервировали автомобиль!" << endl << endl;
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
			throw exception("Список автомобилей пуст!");
		}

		itemSelection = new ItemSelection<Car>("Выберете автомобиль для редактирования: ", cars_);

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