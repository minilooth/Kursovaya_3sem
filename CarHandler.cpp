#include "CarHandler.h"

using namespace car;

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
	double mileage;
	double price;
	bool reserveStatus;
	string reserverUsername;

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
				wheelDriveType		= data.at(4);
				engineType			= data.at(5);
				engineVolume		= stod(data.at(6));
				bodyType			= data.at(7);
				bodyColor			= data.at(8);
				interiorColor		= data.at(9);
				interiorMaterial	= data.at(10);
				mileage				= stod(data.at(11));
				price				= stod(data.at(12));
				reserveStatus		= data.at(13) == "1" ? true : false;
				reserverUsername	= data.at(14);

				if (bodyType == "Кроссовер")
				{
					cars_.push_back(Crossover(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
										interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "Кабриолет")
				{
					cars_.push_back(Cabriolet(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
										interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "Хэтчбэк 5 дв.")
				{
					cars_.push_back(FiveDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
												interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "5 м. минивен")
				{
					cars_.push_back(FiveSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
											  interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "4 дв. купе")
				{
					cars_.push_back(FourDoorCoupe(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
											interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "Длинный седан")
				{
					cars_.push_back(LongWheelbaseSedan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
												 interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "Седан")
				{
					cars_.push_back(Sedan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
									interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "7 м. минивен")
				{
					cars_.push_back(SevenSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
											   interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "Универсал")
				{
					cars_.push_back(StationWagon(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
										   interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "Хэтчбэк 3 дв.")
				{
					cars_.push_back(ThreeDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
												 interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "2 дв. купе")
				{
					cars_.push_back(TwoDoorCoupe(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
										   interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
			}
		}
		carsFile.close();
	}
}

CarHandler::CarHandler(const string& fileName)
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
	double mileage;
	double price;
	bool reserveStatus;
	string reserverUsername;

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
				mileage			= stod(data.at(11));
				price				= stod(data.at(12));
				reserveStatus		= data.at(13) == "1" ? true : false;
				reserverUsername	= data.at(14);

				if (bodyType == "Кроссовер")
				{
					cars_.push_back(Crossover(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "Кабриолет")
				{
					cars_.push_back(Cabriolet(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "Хэтчбэк 5 дв.")
				{
					cars_.push_back(FiveDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "5 м. минивен")
				{
					cars_.push_back(FiveSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "4 дв. купе")
				{
					cars_.push_back(FourDoorCoupe(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "Длинный седан")
				{
					cars_.push_back(LongWheelbaseSedan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "Седан")
				{
					cars_.push_back(Sedan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "7 м. минивен")
				{
					cars_.push_back(SevenSeatMinivan(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "Универсал")
				{
					cars_.push_back(StationWagon(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "Хэтчбэк 3 дв.")
				{
					cars_.push_back(ThreeDoorHatchback(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
				else if (bodyType == "2 дв. купе")
				{
					cars_.push_back(TwoDoorCoupe(brand, model, yearOfProduction, transmissionType, wheelDriveType, engineType, engineVolume, bodyColor,
						interiorColor, interiorMaterial, mileage, price, reserveStatus, reserverUsername));
				}
			}
		}
		carsFile.close();
	}
}

// Files
void CarHandler::rewriteCarsFile()
{
	ofstream carsFile;
	carsFile.open(R"(cars.txt)", ios::trunc);
	if (carsFile.is_open())
	{
		for (auto& i : cars_)
		{
			carsFile << i.getBrand() << ";"
					 << i.getModel() << ";"
					 << i.getYearOfProduction() << ";"
					 << i.getTransmissionType() << ";"
					 << i.getWheelDriveType() << ";"
					 << i.getEngineType() << ";"
					 << i.getEngineVolume() << ";"
					 << i.getBodyType() << ";"
					 << i.getBodyColor() << ";"
					 << i.getInteriorColor() << ";"
					 << i.getInteriorMaterial() << ";"
					 << i.getMileage() << ";"
					 << i.getPrice() << ";"
					 << i.getReserveStatus() << ";"
					 << i.getReserverUsername()
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
	struct tm now;
	time_t newTime = time(nullptr);
	errno_t err = localtime_s(&now, &newTime);

	ofstream report;
	string path = "Checks/";
	string filename = to_string(now.tm_mday) + "-" + to_string(now.tm_mon + 1) + "-" + to_string(now.tm_year + 1900) + " " + 
					  to_string(now.tm_hour) + "." + to_string(now.tm_min) + "." + to_string(now.tm_sec) + ".txt";

	string currentDate = to_string(now.tm_mday) + "." + to_string(now.tm_mon + 1) + "." + to_string(now.tm_year + 1900) + " " +
						 to_string(now.tm_hour) + ":" + to_string(now.tm_min);

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
			   << "КПП:" << setw(79) << right << car.getTransmissionType() << endl
			   << "Привод:" << setw(76) << right << car.getWheelDriveType() << endl
			   << "Тип двигателя:" << setw(69) << right << car.getEngineType() << endl
			   << "Объем двигателя:" << setw(67) << right << car.getEngineVolume() << endl
			   << "Тип кузова:" << setw(72) << right << car.getBodyType() << endl
			   << "Цвет кузова:" << setw(71) << right << car.getBodyColor() << endl
			   << "Цвет салона:" << setw(71) << right << car.getInteriorColor() << endl
			   << "Материал салона:" << setw(67) << right << car.getInteriorMaterial() << endl
			   << "Пробег:" << setw(73) << right << car.getMileage() << " км" << endl
			   << "-----------------------------------------------------------------------------------" << endl
			   << "Покупатель:" << setw(72) << right << car.getReserverUsername() << endl
			   << "Цена:" << setw(77) << right << car.getPrice() << "$" << endl
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
	return firstCar.getYearOfProduction() < secondCar.getYearOfProduction();
}

bool CarHandler::compareYearsOfProductionsDescending(Car& firstCar, Car& secondCar)
{
	return firstCar.getYearOfProduction() > secondCar.getYearOfProduction();
}

bool CarHandler::compareEngineVolumesAscending(Car& firstCar, Car& secondCar)
{
	return firstCar.getEngineVolume() < secondCar.getEngineVolume();
}

bool CarHandler::compareEngineVolumesDescending(Car& firstCar, Car& secondCar)
{
	return firstCar.getEngineVolume() > secondCar.getEngineVolume();
}

bool CarHandler::comparePricesAscending(Car& firstCar, Car& secondCar)
{
	return firstCar.getPrice() < secondCar.getPrice();
}

bool CarHandler::comparePricesDescending(Car& firstCar, Car& secondCar)
{
	return firstCar.getPrice() > secondCar.getPrice();
}

// Reset
void CarHandler::resetCarToEdit()
{
	carToEdit_ = nullptr;
}

void CarHandler::resetReservedCarsByUsername(const string& username)
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
	menu::ConsoleMenu* menu = new menu::BodyTypeMenu();

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
	menu::ConsoleMenu* menu = new menu::WheelDriveTypeMenu("Тип привода:", { "Передний.", "Задний.", "Полный.", "Назад." });

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
	menu::ConsoleMenu* menu = new menu::TransmissionTypeMenu("Тип КПП:", { "Механическая.", "Автоматическая.", "Назад." });

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

// Search
void CarHandler::searchByBrand()
{
	HorizontalShow<Car>* horizontalShow = nullptr;
	
	string brand;

	try
	{
		system("cls");

		cout << "Введите марку: ";
		if (limitedInput(brand, BRAND_MAX_INPUT_LENGTH) == false)
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

		auto cars = getCarsByBrand(brand);

		if (cars.empty())
		{
			throw exception("Не найдено ни одного автомобиля!");
		}

		horizontalShow = new HorizontalShow<Car>("Были найдены автомобили:", cars);
		horizontalShow->showMode();
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

void CarHandler::searchByModel()
{
	HorizontalShow<Car>* horizontalShow = nullptr;
	
	string model;

	try
	{
		system("cls");

		cout << "Введите модель: ";
		if (limitedInput(model, MODEL_MAX_INPUT_LENGTH) == false)
		{
			return;
		}

		if (model.length() < 1)
		{
			throw exception("Модель должна состоять как минимум из одного символа!");
		}

		if (model.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890") != string::npos)
		{
			throw exception("Модель должна состоять только из цифр и букв латинского алфавита!");
		}

		auto cars = getCarsByModel(model);

		if (cars.empty())
		{
			throw exception("Не найдено ни одного автомобиля!");
		}

		horizontalShow = new HorizontalShow<Car>("Были найдены автомобили:", cars);
		horizontalShow->showMode();
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

void CarHandler::searchByYearOfProduction()
{
	HorizontalShow<Car>* horizontalShow = nullptr;
	
	string yearOfProduction;

	try
	{
		system("cls");

		cout << "Введите новый год выпуска: ";
		if (limitedInput(yearOfProduction, YEAR_OF_PRODUCTION_MAX_INPUT_LENGTH) == false)
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
			throw exception("Год выпуска должен быть больше чем 1900 и меньше чем 2020!");
		}

		auto cars = getCarsByYearOfProduction(stoul(yearOfProduction));

		if (cars.empty())
		{
			throw exception("Не найдено ни одного автомобиля!");
		}

		horizontalShow = new HorizontalShow<Car>("Были найдены автомобили:", cars);
		horizontalShow->showMode();
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

void CarHandler::searchByEngineType()
{
	HorizontalShow<Car>* horizontalShow = nullptr;
	menu::ConsoleMenu* menu = nullptr;

	string engineType;

	try
	{
		system("cls");

		menu = new menu::EngineTypeMenu("Выберите тип двигателя: ", { "Бензиновый.", "Дизельный.", "Назад." });

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

		if (cars.empty())
		{
			throw exception("Не найдено ни одного автомобиля!");
		}

		horizontalShow = new HorizontalShow<Car>("Были найдены автомобили:", cars);
		horizontalShow->showMode();
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

// Sorting
void CarHandler::sortByYearOfProduction()
{
	menu::ConsoleMenu* menu = nullptr;

	try
	{
		if (cars_.empty())
		{
			throw exception("Список автомобилей пуст!");
		}

		menu = new menu::TypeOfSortingMenu();

		switch (menu->selectMode())
		{
		case menu::TypeOfSortingMenu::Action::ASCENDING :
			sort(cars_.begin(), cars_.end(), compareYearsOfProductionsAscending);
			break;
		case menu::TypeOfSortingMenu::Action::DESCENDING :
			sort(cars_.begin(), cars_.end(), compareYearsOfProductionsDescending);
			break;
		case menu::TypeOfSortingMenu::Action::BACK :
			menu->resetChoice();
			delete menu;
			return;
		default:
			menu->resetChoice();
			delete menu;
			return;
		}
		menu->resetChoice();
		delete menu;

		rewriteCarsFile();

		system("cls");

		setTextColor(Color::LIGHT_GREEN);
		cout << "Автомобили успешно отсортированы!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
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
	menu::ConsoleMenu* menu = nullptr;

	try
	{
		if (cars_.empty())
		{
			throw exception("Список автомобилей пуст!");
		}

		menu = new menu::TypeOfSortingMenu();

		switch (menu->selectMode())
		{
		case menu::TypeOfSortingMenu::Action::ASCENDING :
			sort(cars_.begin(), cars_.end(), compareEngineVolumesAscending);
			break;
		case menu::TypeOfSortingMenu::Action::DESCENDING :
			sort(cars_.begin(), cars_.end(), compareEngineVolumesDescending);
			break;
		case menu::TypeOfSortingMenu::Action::BACK :
			menu->resetChoice();
			delete menu;
			return;
		default:
			menu->resetChoice();
			delete menu;
			return;
		}
		menu->resetChoice();
		delete menu;

		rewriteCarsFile();
		
		system("cls");

		setTextColor(Color::LIGHT_GREEN);
		cout << "Автомобили успешно отсортированы!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
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
	menu::ConsoleMenu* menu = nullptr;
	try
	{
		if (cars_.empty())
		{
			throw exception("Список автомобилей пуст!");
		}

		menu = new menu::TypeOfSortingMenu();

		switch (menu->selectMode())
		{
		case menu::TypeOfSortingMenu::Action::ASCENDING :
			sort(cars_.begin(), cars_.end(), comparePricesAscending);
			break;
		case menu::TypeOfSortingMenu::Action::DESCENDING : 
			sort(cars_.begin(), cars_.end(), comparePricesDescending);
			break;
		case menu::TypeOfSortingMenu::Action::BACK :
			menu->resetChoice();
			delete menu;
			return;
		default:
			menu->resetChoice();
			delete menu;
			return;
		}
		menu->resetChoice();
		delete menu;

		rewriteCarsFile();
		
		system("cls");

		setTextColor(Color::LIGHT_GREEN);
		cout << "Автомобили успешно отсортированы!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
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
		if (limitedInput(brand, BRAND_MAX_INPUT_LENGTH) == false)
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

		brand[0] = toupper(brand[0]);

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
		if (limitedInput(model, MODEL_MAX_INPUT_LENGTH) == false)
		{
			return;
		}
		if (model.length() < 1)
		{
			throw exception("Модель должна состоять как минимум из одного символа!");
		}
		if (model.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890-") != string::npos)
		{
			throw exception("Модель должна состоять только из цифр и букв латинского алфавита!");
		}

		model[0] = toupper(model[0]);

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
		if (limitedInput(yearOfProduction, YEAR_OF_PRODUCTION_MAX_INPUT_LENGTH) == false)
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
	menu::ConsoleMenu* menu = nullptr;

	unsigned index = 0;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		menu = new menu::BodyTypeMenu();

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
	menu::ConsoleMenu* menu = nullptr;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		menu = new menu::TransmissionTypeMenu("Тип КПП:", { "Механическая.", "Автоматическая.", "Назад." });

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
		cout << "Тип КПП успешно изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Тип КПП не изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editWheelDriveType()
{
	menu::ConsoleMenu* menu = nullptr;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		menu = new menu::WheelDriveTypeMenu("Тип привода:", {"Передний.", "Задний.", "Полный.", "Назад."});

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
		cout << "Тип привода успешно изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}
	catch (exception & ex)
	{
		system("cls");

		showEditCar();

		setTextColor(Color::RED);
		cout << ex.what() << endl;
		cout << "Тип привода не изменен!" << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
	}

	system("pause");
}

void CarHandler::editEngineType()
{
	menu::ConsoleMenu* menu = nullptr;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		menu = new menu::EngineTypeMenu("Тип двигателя: ", { "Бензиновый.", "Дизельный.", "Назад." });

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
		if (limitedInput(engineVolume, ENGINE_VOLUME_MAX_INPUT_LENGTH) == false)
		{
			return;
		}
		if (engineVolume.length() < 3 || engineVolume.length() > 3)
		{
			throw exception("Объем двигателя должен состоять из трех символов!");
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
		if (limitedInput(bodyColor, BODY_COLOR_MAX_INPUT_LENGTH) == false)
		{
			return;
		}
		if (bodyColor.length() < 3)
		{
			throw exception("Цвет кузова должен состоять как минимум из трех сиволов!");
		}
		if (bodyColor.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя- ") != string::npos)
		{
			throw exception("Цвет кузова должен состоять только из букв!");
		}

		bodyColor[0] = toupper(bodyColor[0]);

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
		if (limitedInput(interiorColor, INTERIOR_COLOR_MAX_INPUT_LENGTH) == false)
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

		interiorColor[0] = toupper(interiorColor[0]);

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
		if (limitedInput(interiorMaterial, INTERIOR_MATERIAL_MAX_INPUT_LENGTH) == false)
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

		interiorMaterial[0] = toupper(interiorMaterial[0]);

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

void CarHandler::editMileage()
{
	string mileage;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		cout << "Введите новый пробег: ";
		if (limitedInput(mileage, MILEAGE_MAX_INPUT_LENGTH) == false)
		{
			return;
		}
		if (mileage.length() < 1)
		{
			throw exception("Пробег должен состоять как минимум из одного символа!");
		}
		if (mileage.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Пробег должен состоять только из цифр!");
		}

		carToEdit_->setMileage(stoul(mileage));

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
		if (limitedInput(price, PRICE_MAX_INPUT_LENGTH) == false)
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
	ItemSelection<account::Account>* itemSelection = nullptr;

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
			auto accounts = account::AccountHandler::getUsers();

			itemSelection = new ItemSelection<account::Account>("Выберите новый резервирующий аккаунт:", accounts);

			index = itemSelection->selectMode();

			if (index == 0)
			{
				return;
			}

			carToEdit_->setReserverUsername(accounts.at(index - 1).getUsername());
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
	ItemSelection<account::Account>* itemSelection = nullptr;

	unsigned index = 0;

	try
	{
		if (carToEdit_ == nullptr)
		{
			throw exception("Редактируемый автомобиль не установлен!");
		}

		system("cls");

		showEditCar();

		auto accounts = account::AccountHandler::getUsers();

		itemSelection = new ItemSelection<account::Account>("Выберите новый резервирующий аккаунт:", accounts);

		index = itemSelection->selectMode();

		if (index == 0)
		{
			return;
		}

		if (carToEdit_->getReserveStatus() == false)
		{
			carToEdit_->setReserveStatus(true);
		}

		carToEdit_->setReserverUsername(accounts.at(index - 1).getUsername());

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

void CarHandler::editReservedCarsReserverUsername(const string& oldUsername, const string& newUsername)
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

vector<Car> CarHandler::getCars(unsigned from, unsigned to)
{
	vector<Car> cars;
	for (unsigned i = from; i < to && i < cars_.size();i++)
	{
		cars.push_back(cars_.at(i));
	}
	return cars;
}

pair<vector<Car*>, vector<Car>> CarHandler::getNotReservedNewCars()
{
	pair<vector<Car*>, vector<Car>> cars;
	for (auto& i : cars_)
	{
		if (i.getMileage() == 0.0 && i.getReserveStatus() == false)
		{
			cars.first.push_back(&i);
			cars.second.push_back(i);
		}
	}
	return cars;
}

pair<vector<Car*>, vector<Car>> CarHandler::getNotReservedUsedCars()
{
	pair<vector<Car*>, vector<Car>> cars;
	for (auto& i : cars_)
	{
		if (i.getMileage() != 0.0 && i.getReserveStatus() == false)
		{
			cars.first.push_back(&i);
			cars.second.push_back(i);
		}
	}
	return cars;
}

pair<vector<Car*>, vector<Car>> CarHandler::getReservedCars()
{
	pair<vector<Car*>, vector<Car>> cars;
	for (auto& i : cars_)
	{
		if (i.getReserveStatus() == true)
		{
			cars.first.push_back(&i);
			cars.second.push_back(i);
		}
	}
	return cars;
}

vector<Car> CarHandler::getReservedCarsByUsername(const string& username)
{
	vector<Car> cars;
	for (auto& i : cars_)
	{
		if (i.getReserverUsername() == username)
		{
			cars.push_back(i);
		}
	}
	return cars;
}

vector<Car> CarHandler::getUsedCars()
{
	vector<Car> cars;
	for (auto& i : cars_)
	{
		if (i.getMileage() != 0.0)
		{
			cars.push_back(i);
		}
	}
	return cars;
}

vector<Car> CarHandler::getNewCars()
{
	vector<Car> cars;
	for (auto& i : cars_)
	{
		if (i.getMileage() == 0.0)
		{
			cars.push_back(i);
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
	for (auto& i : cars_)
	{
		if (i.getBrand() == brand)
		{
			cars.push_back(i);
		}
	}
	return cars;
}

vector<Car> CarHandler::getCarsByModel(const string& model)
{
	vector<Car> cars;
	for (auto& i : cars_)
	{
		if (i.getModel() == model)
		{
			cars.push_back(i);
		}
	}
	return cars;
}

vector<Car> CarHandler::getCarsByYearOfProduction(unsigned yearOfProduction)
{
	vector<Car> cars;
	for (auto& i : cars_)
	{
		if (i.getYearOfProduction() == yearOfProduction)
		{
			cars.push_back(i);
		}
	}
	return cars;
}

vector<Car> CarHandler::getCarsByEngineType(const string& engineType)
{
	vector<Car> cars;
	for (auto& i : cars_)
	{
		if (i.getEngineType() == engineType)
		{
			cars.push_back(i);
		}
	}
	return cars;
}

// Functional
void CarHandler::showCars()
{
	HorizontalShow<Car>* horizontalShow = nullptr;
	try
	{
		if (cars_.empty())
		{
			throw exception("Список автомобилей пуст!");
		}

		horizontalShow = new HorizontalShow<Car>("Все автомобили:", cars_);
		horizontalShow->showMode();
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

void CarHandler::showAccountReservedCars()
{
	HorizontalShow<Car>* horizontalShow = nullptr;
	try
	{
		if (account::AccountHandler::getCurrentAccount() == nullptr)
		{
			throw exception("Текущий аккаунт не установлен!");
		}

		auto cars = getReservedCarsByUsername(account::AccountHandler::getCurrentAccount()->getUsername());

		if (cars.empty())
		{
			throw exception("У вас нет зарезервированных автомобилей!");
		}

		horizontalShow = new HorizontalShow<Car>("Автомобили, зарезервированные вами:", cars);
		horizontalShow->showMode();
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

void CarHandler::showNewCars()
{
	HorizontalShow<Car>* horizontalShow = nullptr;
	auto newCars = getNewCars();

	try
	{
		if (newCars.empty())
		{
			throw exception("Список новых автомобилей пуст!");
		}

		horizontalShow = new HorizontalShow<Car>("Новые автомобили:", newCars);
		horizontalShow->showMode();
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

void CarHandler::showUsedCars()
{
	HorizontalShow<Car>* horizontalShow = nullptr;
	
	auto usedCars = getUsedCars();
	try
	{
		if (usedCars.empty())
		{
			throw exception("Список автомобилей с пробегом пуст!");
		}

		horizontalShow = new HorizontalShow<Car>("Автомобили с пробегом:", usedCars);
		horizontalShow->showMode();
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

void CarHandler::showEditCar()
{
	CarPrinter::printCars({ *carToEdit_ });
	cout << endl;
}

void CarHandler::showFilteredCars()
{
	HorizontalShow<Car>* horizontalShow = nullptr;
	
	auto cars = getFilteredCars();
	try
	{
		if (cars.empty())
		{
			throw exception("Такие автомобили не найдены!");
		}

		system("cls");

		horizontalShow = new HorizontalShow<Car>("Отфильтрованные автомобили:", cars);
		horizontalShow->showMode();
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

void CarHandler::sellCar()
{
	ItemSelection<Car>* itemSelection = nullptr;

	unsigned index = 0;

	string path;

	try
	{
		if (cars_.empty())
		{
			throw exception("Список автомобилей пуст!");
		}

		auto reservedCars = getReservedCars();

		if (reservedCars.second.empty())
		{
			throw exception("Нет зарезервированных автомобилей!");
		}

		itemSelection = new ItemSelection<Car>("Выберите автомобиль для продажи:", reservedCars.second);

		index = itemSelection->selectMode();

		delete itemSelection;

		if (index == 0)
		{
			return;
		}
		
		path = createReport(*reservedCars.first.at(index - 1));
		
		account::StatisticsHandler::getAccountStatistics(reservedCars.first.at(index - 1)->getReserverUsername())->addPurchaseAmount(reservedCars.first.at(index - 1)->getPrice());
		account::StatisticsHandler::rewriteStatisticsFile();

		cars_.erase(cars_.begin() + index);

		rewriteCarsFile();

		system("cls");

		setTextColor(Color::LIGHT_GREEN);
		cout << "Автомобиль успешно продан!\nЧек сохранен по пути " << path << endl << endl;
		setTextColor(Color::LIGHT_CYAN);
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
	string mileage;
	string price;
	string isReserved;

	Car* car = nullptr;
	menu::ConsoleMenu* menu = new menu::BodyTypeMenu();

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
		if (limitedInput(brand, BRAND_MAX_INPUT_LENGTH) == false)
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

		brand[0] = toupper(brand[0]);

		car->setBrand(brand);

		cout << "Модель: ";
		if (limitedInput(model, MODEL_MAX_INPUT_LENGTH) == false)
		{
			return;
		}
		if (model.length() < 1)
		{
			throw exception("Модель должна состоять как минимум из одного символа!");
		}
		if (model.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890-") != string::npos)
		{
			throw exception("Модель должна состоять только из цифр и букв латинского алфавита!");
		}
		
		model[0] = toupper(model[0]);

		car->setModel(model);

		cout << "Год выпуска: ";
		if (limitedInput(yearOfProduction, YEAR_OF_PRODUCTION_MAX_INPUT_LENGTH) == false)
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

		menu = new menu::WheelDriveTypeMenu();

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
		cout << "Тип привода: " << car->getWheelDriveType() << endl;

		menu = new menu::EngineTypeMenu();

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

		menu = new menu::TransmissionTypeMenu();

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
		if (limitedInput(engineVolume, ENGINE_VOLUME_MAX_INPUT_LENGTH) == false)
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
		if (limitedInput(bodyColor, BODY_COLOR_MAX_INPUT_LENGTH) == false)
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

		bodyColor[0] = toupper(bodyColor[0]);

		car->setBodyColor(bodyColor);

		cout << "Цвет салона: ";
		if (limitedInput(interiorColor, INTERIOR_COLOR_MAX_INPUT_LENGTH) == false)
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

		bodyColor[0] = toupper(bodyColor[0]);

		car->setInteriorColor(interiorColor);

		cout << "Материал салона: ";
		if (limitedInput(interiorMaterial, INTERIOR_MATERIAL_MAX_INPUT_LENGTH) == false)
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

		interiorMaterial[0] = toupper(interiorMaterial[0]);

		car->setInteriorMaterial(interiorMaterial);

		cout << "Пробег: ";
		if (limitedInput(mileage, MILEAGE_MAX_INPUT_LENGTH) == false)
		{
			return;
		}

		if (mileage.length() < 1)
		{
			throw exception("Пробег должен состоять как минимум из одного символа!");
		}
		if (mileage.find_first_not_of("1234567890.") != string::npos)
		{
			throw exception("Пробег должен состоять только из цифр!");
		}

		car->setMileage(stoul(mileage));

		cout << "Цена: ";
		if (limitedInput(price, PRICE_MAX_INPUT_LENGTH) == false)
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
		if (cars_.empty())
		{
			throw exception("Список автомобилей пуст!");
		}

		itemSelection = new ItemSelection<Car>("Выберите автомобиль для удаления:", cars_);

		index = itemSelection->selectMode();
		if (index == 0)
		{
			return;
		}

		cars_.erase(cars_.begin() + (index - 1));

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
		if (cars_.empty())
		{
			throw exception("Список автомобилей пуст!");
		}

		auto notReservedNewCars = getNotReservedNewCars();

		if (notReservedNewCars.first.empty())
		{
			throw exception("Список незарезервированных новых автомобилей пуст!");
		}

		itemSelection = new ItemSelection<Car>("Выберите автомобиль, чтобы его зарезервировать:", notReservedNewCars.second);

		index = itemSelection->selectMode();
		if (index == 0)
		{
			return;
		}

		notReservedNewCars.first.at(index - 1)->setReserveStatus(true);
		notReservedNewCars.first.at(index - 1)->setReserverUsername(account::AccountHandler::getCurrentAccount()->getUsername());

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
		if (cars_.empty())
		{
			throw exception("Список автомобилей пуст!");
		}
		auto notReservedUsedCars = getNotReservedUsedCars();

		if (notReservedUsedCars.first.empty())
		{
			throw exception("Список незарезервированных автомобилей с пробегом пуст!");
		}

		itemSelection = new ItemSelection<Car>("Выберите автомобиль, чтобы его зарезервировать:", notReservedUsedCars.second);

		index = itemSelection->selectMode();
		if (index == 0)
		{
			return;
		}

		notReservedUsedCars.first.at(index - 1)->setReserveStatus(true);
		notReservedUsedCars.first.at(index - 1)->setReserverUsername(account::AccountHandler::getCurrentAccount()->getUsername());

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

	menu::ConsoleMenu* menu = nullptr;

	try
	{
		if (cars_.empty())
		{
			throw exception("Список автомобилей пуст!");
		}

		itemSelection = new ItemSelection<Car>("Выберите автомобиль для редактирования: ", cars_);

		index = itemSelection->selectMode();

		if (index == 0)
		{
			return;
		}

		carToEdit_ = getCar(index - 1);

		menu = new menu::CarEditMenu();

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