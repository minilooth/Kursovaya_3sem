#include "CarFiltering.h"

bool CarFiltering::bodyTypeFilterStatus_ = false;
string CarFiltering::bodyTypeFilter_;
bool CarFiltering::wheelDriveTypeFilterStatus_ = false;
string CarFiltering::wheelDriveTypeFilter_;
bool CarFiltering::transmissionTypeFilterStatus_ = false;
string CarFiltering::transmissionTypeFilter_;

CarFiltering::CarFiltering()
{
	bodyTypeFilterStatus_ = false;
	wheelDriveTypeFilterStatus_ = false;
	transmissionTypeFilterStatus_ = false;
	bodyTypeFilter_ = "";
	wheelDriveTypeFilter_ = "";
	transmissionTypeFilter_ = "";
}

void CarFiltering::setBodyTypeFilter(const string& bodyType)
{
	bodyTypeFilter_ = bodyType;
	bodyTypeFilterStatus_ = true;
}

void CarFiltering::setWheelDriveTypeFilter(const string& wheelDriveType)
{
	wheelDriveTypeFilter_ = wheelDriveType;
	wheelDriveTypeFilterStatus_ = true;
}

void CarFiltering::setTransmissionTypeFilter(const string& transmissionType)
{
	transmissionTypeFilter_ = transmissionType;
	transmissionTypeFilterStatus_ = true;
}

bool CarFiltering::getBodyTypeFilterStatus()
{
	return bodyTypeFilterStatus_;
}

bool CarFiltering::getWheelDriveTypeFilterStatus()
{
	return wheelDriveTypeFilterStatus_;
}

bool CarFiltering::getTransmissionTypeFilterStatus()
{
	return transmissionTypeFilterStatus_;
}

string CarFiltering::getBodyTypeFilter()
{
	return bodyTypeFilter_;
}

string CarFiltering::getWheelDriveTypeFilter()
{
	return wheelDriveTypeFilter_;
}

string CarFiltering::getTransmissionTypeFilter()
{
	return transmissionTypeFilter_;
}

void CarFiltering::resetBodyTypeFilter()
{
	bodyTypeFilterStatus_ = false;
	bodyTypeFilter_ = "";
}

void CarFiltering::resetWheelDriveTypeFilter()
{
	wheelDriveTypeFilterStatus_ = false;
	wheelDriveTypeFilter_ = "";
}

void CarFiltering::resetTransmissionTypeFilter()
{
	transmissionTypeFilterStatus_ = false;
	transmissionTypeFilter_ = "";
}

CarFiltering::~CarFiltering() = default;