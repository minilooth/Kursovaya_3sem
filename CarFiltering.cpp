#include "CarFiltering.h"

bool car::CarFiltering::bodyTypeFilterStatus_ = false;
string car::CarFiltering::bodyTypeFilter_;
bool car::CarFiltering::wheelDriveTypeFilterStatus_ = false;
string car::CarFiltering::wheelDriveTypeFilter_;
bool car::CarFiltering::transmissionTypeFilterStatus_ = false;
string car::CarFiltering::transmissionTypeFilter_;

car::CarFiltering::CarFiltering()
{
	bodyTypeFilterStatus_ = false;
	wheelDriveTypeFilterStatus_ = false;
	transmissionTypeFilterStatus_ = false;
	bodyTypeFilter_ = "";
	wheelDriveTypeFilter_ = "";
	transmissionTypeFilter_ = "";
}

void car::CarFiltering::setBodyTypeFilter(const string& bodyType)
{
	bodyTypeFilter_ = bodyType;
	bodyTypeFilterStatus_ = true;
}

void car::CarFiltering::setWheelDriveTypeFilter(const string& wheelDriveType)
{
	wheelDriveTypeFilter_ = wheelDriveType;
	wheelDriveTypeFilterStatus_ = true;
}

void car::CarFiltering::setTransmissionTypeFilter(const string& transmissionType)
{
	transmissionTypeFilter_ = transmissionType;
	transmissionTypeFilterStatus_ = true;
}

bool car::CarFiltering::getBodyTypeFilterStatus()
{
	return bodyTypeFilterStatus_;
}

bool car::CarFiltering::getWheelDriveTypeFilterStatus()
{
	return wheelDriveTypeFilterStatus_;
}

bool car::CarFiltering::getTransmissionTypeFilterStatus()
{
	return transmissionTypeFilterStatus_;
}

string car::CarFiltering::getBodyTypeFilter()
{
	return bodyTypeFilter_;
}

string car::CarFiltering::getWheelDriveTypeFilter()
{
	return wheelDriveTypeFilter_;
}

string car::CarFiltering::getTransmissionTypeFilter()
{
	return transmissionTypeFilter_;
}

void car::CarFiltering::resetBodyTypeFilter()
{
	bodyTypeFilterStatus_ = false;
	bodyTypeFilter_ = "";
}

void car::CarFiltering::resetWheelDriveTypeFilter()
{
	wheelDriveTypeFilterStatus_ = false;
	wheelDriveTypeFilter_ = "";
}

void car::CarFiltering::resetTransmissionTypeFilter()
{
	transmissionTypeFilterStatus_ = false;
	transmissionTypeFilter_ = "";
}

car::CarFiltering::~CarFiltering() = default;