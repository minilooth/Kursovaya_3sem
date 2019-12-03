#ifndef CAR_H
#define CAR_H


#include "CarHandler.h"

using namespace std;

class Car
{
protected:
	string brand_;
	string model_;
	unsigned yearOfProduction_;
	string bodyType_;
	string transmissionType_;
	string wheelDriveType_;
	string engineType_;
	double engineVolume_;
	string bodyColor_;
	string interiorColor_;
	string interiorMaterial_;
	double mealeage_;
	double price_;
	bool reserveStatus_;
	string reserverUsername_;
public:
	Car();
	Car(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDriveType,
		string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage, 
		double price, bool reserveStatus, string& reserverUsername);

	void setBrand(string brand);
	void setModel(string model);
	void setYearOfProduction(unsigned yearOfProduction);
	void setTransmissionType(string transmissionType);
	void setWheelDriveType(string wheelDriveType);
	void setEngineType(string engineType);
	void setEngineVolume(double engineVolume);
	void setBodyColor(string bodyColor);
	void setInteriorColor(string interiorColor);
	void setInteriorMaterial(string interiorMaterial);
	void setMealeage(double mealeage);
	void setPrice(double price);
	void setReserveStatus(bool reserveStatus);
	void setReserverUsername(string reserverUsername);

	string getBrand();
	string getModel();
	unsigned getYearOfProduction();
	string getTransmissionType();
	string getBodyType();
	string getWheelDriveType();
	string getEngineType();
	double getEngineVolume();
	string getBodyColor();
	string getInteriorColor();
	string getInteriorMaterial();
	double getMealeage();
	double getPrice();
	bool getReserveStatus();
	string getReserverUsername();

	friend ostream& operator<<(ostream& out, const Car& car);
	
	~Car();
};


#endif // CAR_H