#ifndef CARFILTERING_H
#define CARFILTERING_H


#include "CarHandler.h"


	class CarFiltering
	{
		static bool bodyTypeFilterStatus_;
		static string bodyTypeFilter_;
		static bool wheelDriveTypeFilterStatus_;
		static string wheelDriveTypeFilter_;
		static bool transmissionTypeFilterStatus_;
		static string transmissionTypeFilter_;
	public:
		CarFiltering();

		static void setBodyTypeFilter(const string& bodyType);
		static void setWheelDriveTypeFilter(const string& wheelDriveType);
		static void setTransmissionTypeFilter(const string& transmissionType);

		static bool getBodyTypeFilterStatus();
		static bool getWheelDriveTypeFilterStatus();
		static bool getTransmissionTypeFilterStatus();
		static string getBodyTypeFilter();
		static string getWheelDriveTypeFilter();
		static string getTransmissionTypeFilter();

		static void resetBodyTypeFilter();
		static void resetWheelDriveTypeFilter();
		static void resetTransmissionTypeFilter();

		~CarFiltering();
	};



#endif // CARFILTERING_H