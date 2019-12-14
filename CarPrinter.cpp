#include "CarPrinter.h"

using namespace car;

unsigned CarPrinter::signsAfterDot_					 = 1;
unsigned CarPrinter::brandLabelLength_				 = 0;
unsigned CarPrinter::modelLabelLength_				 = 0;
unsigned CarPrinter::bodyTypeLabelLength_			 = 0;
unsigned CarPrinter::bodyColorLabelLength_			 = 0;
unsigned CarPrinter::interiorColorLabelLength_		 = 0;
unsigned CarPrinter::interiorMaterialLabelLength_	 = 0;
unsigned CarPrinter::mileageLabelLength_			 = 0;
unsigned CarPrinter::priceLabelLength_				 = 0;
unsigned CarPrinter::yearOfProductionLabelLength_	 = 0;
unsigned CarPrinter::transmissionTypeLabelLength_	 = 0;
unsigned CarPrinter::wheelDriveTypeLabelLength_		 = 0;
unsigned CarPrinter::engineTypeLabelLength_			 = 0;
unsigned CarPrinter::engineVolumeLabelLength_		 = 0;
unsigned CarPrinter::reserveStatusLabelLength_		 = 0;

unsigned CarPrinter::solidLineLength_ = 0;

CarPrinter::CarPrinter()
{
	signsAfterDot_					= 1;
	brandLabelLength_				= 0;
	modelLabelLength_				= 0;
	bodyTypeLabelLength_			= 0;
	bodyColorLabelLength_			= 0;
	interiorColorLabelLength_		= 0;
	interiorMaterialLabelLength_	= 0;
	mileageLabelLength_				= 0;
	priceLabelLength_				= 0;
	yearOfProductionLabelLength_	= 0;
	transmissionTypeLabelLength_	= 0;
	wheelDriveTypeLabelLength_		= 0;
	engineTypeLabelLength_			= 0;
	engineVolumeLabelLength_		= 0;
	reserveStatusLabelLength_		= 0;
	solidLineLength_				= 0;
}

void CarPrinter::refresh()
{
	brandLabelLength_				= calculateBrandMaxLength() < 5 ? 5 : calculateBrandMaxLength();
	modelLabelLength_				= calculateModelMaxLength() < 6 ? 6 : calculateModelMaxLength();
	bodyTypeLabelLength_			= calculateBodyTypeMaxLength() < 10 ? 10 : calculateBodyTypeMaxLength();
	bodyColorLabelLength_			= calculateBodyColorMaxLength() < 11 ? 11 : calculateBodyColorMaxLength();
	interiorColorLabelLength_		= calculateInteriorColorMaxLength() < 11 ? 11 : calculateInteriorColorMaxLength();
	interiorMaterialLabelLength_	= calculateInteriorMaterialMaxLength() < 15 ? 15 : calculateInteriorMaterialMaxLength();
	mileageLabelLength_				= ((calculateMileageMaxLength() < 6 ? 6 : calculateMileageMaxLength()) + 3);
	priceLabelLength_				= ((calculatePriceMaxLength() < 4 ? 4 : calculatePriceMaxLength()) + 2);
	yearOfProductionLabelLength_	= 11;
	transmissionTypeLabelLength_	= calculateTransmissionTypeMaxLength() < 3 ? 3 : calculateTransmissionTypeMaxLength();
	wheelDriveTypeLabelLength_		= calculateWheelDriveTypeMaxLength() < 6 ? 6 : calculateWheelDriveTypeMaxLength();
	engineTypeLabelLength_			= calculateEngineTypeMaxLength() < 13 ? 13 : calculateEngineTypeMaxLength();
	engineVolumeLabelLength_		= 15;
	reserveStatusLabelLength_		= calculateReservedStatusMaxLength() < 14 ? 14 : calculateReservedStatusMaxLength();
	solidLineLength_				= (brandLabelLength_ + modelLabelLength_ + bodyTypeLabelLength_ + bodyColorLabelLength_ + interiorColorLabelLength_ + 
									   interiorMaterialLabelLength_ + yearOfProductionLabelLength_ + transmissionTypeLabelLength_ + wheelDriveTypeLabelLength_ + 
									   engineTypeLabelLength_ + engineVolumeLabelLength_ + reserveStatusLabelLength_ + mileageLabelLength_ + priceLabelLength_ + 15);
}

unsigned CarPrinter::calculateBrandMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < CarHandler::getCars().size(); i++)
	{
		if (length <= CarHandler::getCars().at(i).getBrand().length())
		{
			length = CarHandler::getCars().at(i).getBrand().length();
		}
	}
	return length;
}

unsigned CarPrinter::calculateModelMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < CarHandler::getCars().size(); i++)
	{
		if (length <= CarHandler::getCars().at(i).getModel().length())
		{
			length = CarHandler::getCars().at(i).getModel().length();
		}
	}
	return length;
}

unsigned CarPrinter::calculateTransmissionTypeMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < CarHandler::getCars().size(); i++)
	{
		if (length <= CarHandler::getCars().at(i).getTransmissionType().length())
		{
			length = CarHandler::getCars().at(i).getTransmissionType().length();
		}
	}
	return length;
}

unsigned CarPrinter::calculateBodyTypeMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < CarHandler::getCars().size(); i++)
	{
		if (length <= CarHandler::getCars().at(i).getBodyType().length())
		{
			length = CarHandler::getCars().at(i).getBodyType().length();
		}
	}
	return length;
}

unsigned CarPrinter::calculateBodyColorMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < CarHandler::getCars().size(); i++)
	{
		if (length <= CarHandler::getCars().at(i).getBodyColor().length())
		{
			length = CarHandler::getCars().at(i).getBodyColor().length();
		}
	}
	return length;
}

unsigned CarPrinter::calculateInteriorColorMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < CarHandler::getCars().size(); i++)
	{
		if (length <= CarHandler::getCars().at(i).getInteriorColor().length())
		{
			length = CarHandler::getCars().at(i).getInteriorColor().length();
		}
	}
	return length;
}

unsigned CarPrinter::calculateInteriorMaterialMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < CarHandler::getCars().size(); i++)
	{
		if (length <= CarHandler::getCars().at(i).getInteriorMaterial().length())
		{
			length = CarHandler::getCars().at(i).getInteriorMaterial().length();
		}
	}
	return length;
}

unsigned CarPrinter::calculateMileageMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < CarHandler::getCars().size(); i++)
	{
		if (length <= calculateDoubleLength(CarHandler::getCars().at(i).getMileage(), signsAfterDot_))
		{
			length = calculateDoubleLength(CarHandler::getCars().at(i).getMileage(), signsAfterDot_);
		}
	}
	return length;
}

unsigned CarPrinter::calculatePriceMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < CarHandler::getCars().size(); i++)
	{
		if (length <= calculateDoubleLength(CarHandler::getCars().at(i).getPrice(), signsAfterDot_))
		{
			length = calculateDoubleLength(CarHandler::getCars().at(i).getPrice(), signsAfterDot_);
		}
	}
	return length;
}

unsigned CarPrinter::calculateReservedStatusMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < CarHandler::getCars().size(); i++)
	{
		if (length <= (CarHandler::getCars().at(i).getReserverUsername().length() + 15))
		{
			if (CarHandler::getCars().at(i).getReserveStatus() == false)
			{
				if (length <= 17)
				{
					length = 17;
				}
			}
			else
			{
				length = (15 + CarHandler::getCars().at(i).getReserverUsername().length());
			}
		}
	}
	return length;
}

unsigned CarPrinter::calculateWheelDriveTypeMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < CarHandler::getCars().size(); i++)
	{
		if (length <= CarHandler::getCars().at(i).getWheelDriveType().length())
		{
			length = CarHandler::getCars().at(i).getWheelDriveType().length();
		}
	}
	return length;
}

unsigned CarPrinter::calculateEngineTypeMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < CarHandler::getCars().size(); i++)
	{
		if (length <= CarHandler::getCars().at(i).getEngineType().length())
		{
			length = CarHandler::getCars().at(i).getEngineType().length();
		}
	}
	return length;
}

unsigned CarPrinter::getSignsAfterDotValue()
{
	return signsAfterDot_;
}

unsigned CarPrinter::getBrandLabelLength()
{
	return brandLabelLength_;
}

unsigned CarPrinter::getModelLabelLength()
{
	return modelLabelLength_;
}

unsigned CarPrinter::getBodyTypeLabelLength()
{
	return bodyTypeLabelLength_;
}

unsigned CarPrinter::getBodyColorLabelLength()
{
	return bodyColorLabelLength_;
}

unsigned CarPrinter::getInteriorColorLabelLength()
{
	return interiorColorLabelLength_;
}

unsigned CarPrinter::getInteriorMaterialLabelLength()
{
	return interiorMaterialLabelLength_;
}

unsigned CarPrinter::getMileageLabelLength()
{
	return mileageLabelLength_;
}

unsigned CarPrinter::getPriceLabelLength()
{
	return priceLabelLength_;
}

unsigned CarPrinter::getYearOfProductionLabelLength()
{
	return yearOfProductionLabelLength_;
}

unsigned CarPrinter::getTransmissionTypeLabelLength()
{
	return transmissionTypeLabelLength_;
}

unsigned CarPrinter::getWheelDriveTypeLabelLength()
{
	return wheelDriveTypeLabelLength_;
}

unsigned CarPrinter::getEngineTypeLabelLength()
{
	return engineTypeLabelLength_;
}

unsigned CarPrinter::getEngineVolumeLabelLength()
{
	return engineVolumeLabelLength_;
}

unsigned CarPrinter::getReserveStatusLabelLength()
{
	return reserveStatusLabelLength_;
}

unsigned CarPrinter::getSolidLineLength()
{
	return solidLineLength_;
}

void CarPrinter::showHeader()
{
	refresh();

	drawSolidLine(solidLineLength_);

	cout << "|" << makeCenteredString("Марка", brandLabelLength_)
		 << "|" << makeCenteredString("Модель", modelLabelLength_)
		 << "|" << makeCenteredString("Год выпуска", yearOfProductionLabelLength_)
		 << "|" << makeCenteredString("Тип кузова", bodyTypeLabelLength_)
		 << "|" << makeCenteredString("КПП", transmissionTypeLabelLength_)
		 << "|" << makeCenteredString("Привод", wheelDriveTypeLabelLength_)
		 << "|" << makeCenteredString("Тип двигателя", engineTypeLabelLength_)
		 << "|" << makeCenteredString("Объем двигателя", engineVolumeLabelLength_)
		 << "|" << makeCenteredString("Цвет кузова", bodyColorLabelLength_)
		 << "|" << makeCenteredString("Цвет салона", interiorColorLabelLength_)
		 << "|" << makeCenteredString("Материал салона", interiorMaterialLabelLength_)
		 << "|" << makeCenteredString("Пробег", mileageLabelLength_)
		 << "|" << makeCenteredString("Цена", priceLabelLength_)
		 << "|" << makeCenteredString("Статус резерва", reserveStatusLabelLength_)
		 << "|" << endl;

	drawSolidLine(solidLineLength_);
}

void CarPrinter::printCars(const vector<Car>& cars)
{
	showHeader();
	for (unsigned i = 0; i < cars.size(); i++)
	{
		cout << cars.at(i) << endl;
	}
	drawSolidLine(solidLineLength_);
}

CarPrinter::~CarPrinter() = default;