#ifndef CAR_H
#define CAR_H


#include "Includes.h"

using namespace std;

class Car
{
protected:
	string brand_;
	string model_;
	unsigned yearOfProduction_;
	string transmissionType_;
	string wheelDrive_;
	string engineType_;
	double engineVolume_;
	string bodyColor_;
	string interiorColor_;
	string interiorMaterial_;
	double mealeage_;
	double price_;
	bool isReserved_;
public:
	Car();
	Car(string& brand, string& model, unsigned yearOfProduction, string& transmissionType, string& wheelDrive,
		string& engineType, double engineVolume, string& bodyColor, string& interiorColor, string& interiorMaterial, double mealeage, 
		double price, bool isReserved);

	void setBrand(string brand);
	void setModel(string model);
	void setYearOfProduction(unsigned yearOfProduction);
	void setTransmissionType(string transmissionType);
	void setWheelDrive(string wheelDrive);
	void setEngineType(string engineType);
	void setEngineVolume(double engineVolume);
	void setBodyColor(string bodyColor);
	void setInteriorColor(string interiorColor);
	void setInteriorMaterial(string interiorMaterial);
	void setMealeage(double mealeage);
	void setPrice(double price);
	void setIsReserved(bool isReserved);

	string getBrand();
	string getModel();
	unsigned getYearOfProduction();
	string getTransmissionType();
	string getWheelDrive ();
	string getEngineType();
	double getEngineVolume();
	string getBodyColor();
	string getInteriorColor();
	string getInteriorMaterial();
	double getMealeage();
	double getPrice();
	bool getIsReserved();
	
	~Car();
};


#endif // CAR_H