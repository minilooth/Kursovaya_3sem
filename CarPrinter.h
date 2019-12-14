#ifndef CARPRINTER_H
#define CARPRINTER_H


#include "Includes.h"
#include "CarHandler.h"


namespace car
{

	class CarPrinter
	{
		static unsigned signsAfterDot_;

		static unsigned brandLabelLength_;
		static unsigned modelLabelLength_;
		static unsigned bodyTypeLabelLength_;
		static unsigned bodyColorLabelLength_;
		static unsigned interiorColorLabelLength_;
		static unsigned interiorMaterialLabelLength_;
		static unsigned mileageLabelLength_;
		static unsigned priceLabelLength_;
		static unsigned yearOfProductionLabelLength_;
		static unsigned transmissionTypeLabelLength_;
		static unsigned wheelDriveTypeLabelLength_;
		static unsigned engineTypeLabelLength_;
		static unsigned engineVolumeLabelLength_;
		static unsigned reserveStatusLabelLength_;

		static unsigned solidLineLength_;

		static unsigned calculateBrandMaxLength();
		static unsigned calculateModelMaxLength();
		static unsigned calculateTransmissionTypeMaxLength();
		static unsigned calculateBodyTypeMaxLength();
		static unsigned calculateBodyColorMaxLength();
		static unsigned calculateInteriorColorMaxLength();
		static unsigned calculateInteriorMaterialMaxLength();
		static unsigned calculateMileageMaxLength();
		static unsigned calculatePriceMaxLength();
		static unsigned calculateReservedStatusMaxLength();
		static unsigned calculateWheelDriveTypeMaxLength();
		static unsigned calculateEngineTypeMaxLength();



		static void refresh();

		CarPrinter();
	public:
		static unsigned getSignsAfterDotValue();

		static unsigned getBrandLabelLength();
		static unsigned getModelLabelLength();
		static unsigned getBodyTypeLabelLength();
		static unsigned getBodyColorLabelLength();
		static unsigned getInteriorColorLabelLength();
		static unsigned getInteriorMaterialLabelLength();
		static unsigned getMileageLabelLength();
		static unsigned getPriceLabelLength();
		static unsigned getYearOfProductionLabelLength();
		static unsigned getTransmissionTypeLabelLength();
		static unsigned getWheelDriveTypeLabelLength();
		static unsigned getEngineTypeLabelLength();
		static unsigned getEngineVolumeLabelLength();
		static unsigned getReserveStatusLabelLength();

		static unsigned getSolidLineLength();

		static void showHeader();

		static void printCars(const vector<Car>& cars);

		~CarPrinter();
	};

}


#endif // CARPRINTER_H