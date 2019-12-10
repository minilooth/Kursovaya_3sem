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
	double mileage_;
	double price_;
	bool reserveStatus_;
	string reserverUsername_;
public:
	Car();
	Car(const string& brand, const string& model, unsigned yearOfProduction, const string& transmissionType, const string& wheelDriveType,
		const string& engineType, double engineVolume, const string& bodyColor, const string& interiorColor, const string& interiorMaterial, double mileage,
		double price, bool reserveStatus, const string& reserverUsername);

	void setBrand(const string& brand);
	void setModel(const string &model);
	void setYearOfProduction(unsigned yearOfProduction);
	void setTransmissionType(const string& transmissionType);
	void setWheelDriveType(const string& wheelDriveType);
	void setEngineType(const string& engineType);
	void setEngineVolume(double engineVolume);
	void setBodyColor(const string& bodyColor);
	void setInteriorColor(const string& interiorColor);
	void setInteriorMaterial(const string& interiorMaterial);
	void setMileage(double mileage);
	void setPrice(double price);
	void setReserveStatus(bool reserveStatus);
	void setReserverUsername(const string& reserverUsername);

	string getBrand() const;
	string getModel() const;
	unsigned getYearOfProduction() const;
	string getTransmissionType() const;
	string getBodyType() const;
	string getWheelDriveType() const;
	string getEngineType() const;
	double getEngineVolume() const;
	string getBodyColor() const;
	string getInteriorColor() const;
	string getInteriorMaterial() const;
	double getMileage() const;
	double getPrice() const;
	bool getReserveStatus() const;
	string getReserverUsername() const;

	friend ostream& operator<<(ostream& out, const Car& car);
	
	~Car();
};


#endif // CAR_H