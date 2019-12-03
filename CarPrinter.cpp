#include "CarPrinter.h"

unsigned CarPrinter::signsAfterDot_					 = 1;
unsigned CarPrinter::brandLabelLength_				 = 0;
unsigned CarPrinter::modelLabelLength_				 = 0;
unsigned CarPrinter::bodyTypeLabelLength_			 = 0;
unsigned CarPrinter::bodyColorLabelLength_			 = 0;
unsigned CarPrinter::interiorColorLabelLength_		 = 0;
unsigned CarPrinter::interiorMaterialLabelLength_	 = 0;
unsigned CarPrinter::mealeageLabelLength_			 = 0;
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
	mealeageLabelLength_			= 0;
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
	modelLabelLength_				= calculateModelMaxLength() < 5 ? 5 : calculateModelMaxLength();
	bodyTypeLabelLength_			= calculateBodyTypeMaxLength() < 9 ? 9 : calculateBodyTypeMaxLength();
	bodyColorLabelLength_			= calculateBodyColorMaxLength() < 10 ? 10 : calculateBodyColorMaxLength();
	interiorColorLabelLength_		= calculateInteriorColorMaxLength() < 14 ? 14 : calculateInteriorColorMaxLength();
	interiorMaterialLabelLength_	= calculateInteriorMaterialMaxLength() < 17 ? 17 : calculateInteriorMaterialMaxLength();
	mealeageLabelLength_			= ((calculateMealeageMaxLength() < 8 ? 8 : calculateMealeageMaxLength()) + 3);
	priceLabelLength_				= ((calculatePriceMaxLength() < 5 ? 5 : calculatePriceMaxLength()) + 2);
	yearOfProductionLabelLength_	= 18;
	transmissionTypeLabelLength_	= 12;
	wheelDriveTypeLabelLength_		= 11;
	engineTypeLabelLength_			= 11;
	engineVolumeLabelLength_		= 13;
	reserveStatusLabelLength_		= calculateReservedStatusMaxLength() < 12 ? 12 : calculateReservedStatusMaxLength();
	solidLineLength_				= (brandLabelLength_ + modelLabelLength_ + bodyTypeLabelLength_ + bodyColorLabelLength_ + interiorColorLabelLength_ + 
									   interiorMaterialLabelLength_ + yearOfProductionLabelLength_ + transmissionTypeLabelLength_ + wheelDriveTypeLabelLength_ + 
									   engineTypeLabelLength_ + engineVolumeLabelLength_ + reserveStatusLabelLength_ + mealeageLabelLength_ + priceLabelLength_ + 15);
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

unsigned CarPrinter::calculateMealeageMaxLength()
{
	unsigned length = 0;
	for (unsigned i = 0; i < CarHandler::getCars().size(); i++)
	{
		if (length <= calculateDoubleLength(CarHandler::getCars().at(i).getMealeage(), signsAfterDot_))
		{
			length = calculateDoubleLength(CarHandler::getCars().at(i).getMealeage(), signsAfterDot_);
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
		if (length <= CarHandler::getCars().at(i).getReserverUsername().length())
		{
			length = CarHandler::getCars().at(i).getReserverUsername().length();
		}
	}
	if (length != 0)
	{
		length = length + 12;
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

unsigned CarPrinter::getMealeageLabelLength()
{
	return mealeageLabelLength_;
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

	cout << "|" << makeCenteredString("Brand", brandLabelLength_)
		 << "|" << makeCenteredString("Model", modelLabelLength_)
		 << "|" << makeCenteredString("Year of production", yearOfProductionLabelLength_)
		 << "|" << makeCenteredString("Body type", bodyTypeLabelLength_)
		 << "|" << makeCenteredString("Transmission", transmissionTypeLabelLength_)
		 << "|" << makeCenteredString("Wheel drive", wheelDriveTypeLabelLength_)
		 << "|" << makeCenteredString("Engine type", engineTypeLabelLength_)
		 << "|" << makeCenteredString("Engine volume", engineVolumeLabelLength_)
		 << "|" << makeCenteredString("Body color", bodyColorLabelLength_)
		 << "|" << makeCenteredString("Interior color", interiorColorLabelLength_)
		 << "|" << makeCenteredString("Interior material", interiorMaterialLabelLength_)
		 << "|" << makeCenteredString("Mealeage", mealeageLabelLength_)
		 << "|" << makeCenteredString("Price", priceLabelLength_)
		 << "|" << makeCenteredString("Reserve status", reserveStatusLabelLength_)
		 << "|" << endl;

	drawSolidLine(solidLineLength_);
}

CarPrinter::~CarPrinter() = default;