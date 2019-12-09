#ifndef ITEMSELECTION_H
#define ITEMSELECTION_H


#include "CarHandler.h"
#include "Car.h"
#include "AccountHandler.h"
#include "Account.h"

using namespace std;

template<typename T>
class ItemSelection
{
protected:
	string title_;
	string tooltip_;
	vector<T> items_;
	unsigned maxPages_;
	unsigned currentPage_;
	unsigned choice_;
	unsigned pageSize_;
public:
	ItemSelection();
	ItemSelection(string& title, vector<T>& items);
	ItemSelection(const char* title, vector<T>& items);
	void nextPage();
	void previousPage();
	unsigned selectMode();
	void showCurrentPageNumber();
	void showTooltip();
	void showTitle();
	virtual void showItems();
	~ItemSelection();
};

template<typename T>
ItemSelection<T>::ItemSelection() = default;

template<typename T>
ItemSelection<T>::ItemSelection(string& title, vector<T>& items)
{
	title_ = title;
	items_ = items;
	tooltip_ = "Подсказка:\nНажмите -> чтобы перейти на следующую страницу.\nНажмите <- чтобы перейти на предыдущую страницу.\nНажмите ESC чтобы вернутся назад.";
	pageSize_ = 10;

	maxPages_ = items_.size() / pageSize_;

	if (items_.size() % pageSize_ != 0)
	{
		maxPages_++;
	}

	currentPage_ = 1;

	choice_ = 1;
}

template<typename T>
ItemSelection<T>::ItemSelection(const char* title, vector<T>& items)
{
	title_ = title;
	items_ = items;
	tooltip_ = "Подсказка:\nНажмите -> чтобы перейти на следующую страницу.\nНажмите <- чтобы перейти на предыдущую страницу.\nНажмите ESC чтобы вернутся назад.";
	pageSize_ = 10;

	maxPages_ = items_.size() / pageSize_;

	if (items_.size() % pageSize_ != 0)
	{
		maxPages_++;
	}

	currentPage_ = 1;

	choice_ = 1;
}

template<typename T>
void ItemSelection<T>::nextPage()
{
	if (currentPage_ == maxPages_)
	{
		return;
	}

	currentPage_++;

	choice_ = (pageSize_ * (currentPage_ - 1)) + 1;
}

template<typename T>
void ItemSelection<T>::previousPage()
{
	if (currentPage_ == 1)
	{
		return;
	}

	currentPage_--;

	choice_ = (pageSize_ * (currentPage_ - 1)) + 1;
}

template<typename T>
void ItemSelection<T>::showCurrentPageNumber()
{
	cout << "Страница " + to_string(currentPage_) + " из " + to_string(maxPages_) << endl;
}

template<typename T>
unsigned ItemSelection<T>::selectMode()
{
	KEY_EVENT_RECORD key;
	while (true)
	{
		system("cls");

		showTitle();

		cout << endl;

		showCurrentPageNumber();

		showItems();

		cout << endl;

		showTooltip();

		VP_GetCh(key);

	
		switch (key.wVirtualKeyCode)
		{
		case VK_UP:
			if (choice_ > (pageSize_ * (currentPage_ - 1)) + 1)
			{
				choice_--;
			}
			else
			{
				if (currentPage_ < maxPages_)
				{
					choice_ = (pageSize_ * currentPage_);
				}
				else
				{
					choice_ = items_.size();
				}
			}
			break;
		case VK_DOWN:
			if (currentPage_ < maxPages_)
			{
				if (choice_ > (pageSize_ * currentPage_) - 1)
				{
					choice_ = (pageSize_ * (currentPage_ - 1)) + 1;
				}
				else
				{
					choice_++;
				}
			}
			else
			{
				if (choice_ > items_.size() - 1)
				{
					choice_ = (pageSize_ * (currentPage_ - 1)) + 1 ;
				}
				else
				{
					choice_++;
				}
			}
			break;
		case VK_RIGHT :
			nextPage();
			break;
		case VK_LEFT :
			previousPage();
			break;
		case VK_RETURN:
			return choice_;
		case VK_ESCAPE :
			return 0;
		default:
			break;
		}
	}
}

template<typename T>
void ItemSelection<T>::showTitle()
{
	cout << title_ << endl;
}

template<typename T>
void ItemSelection<T>::showTooltip()
{
	cout << tooltip_ << endl;
}

template<typename T>
void ItemSelection<T>::showItems()
{
	if (typeid(T) == typeid(Account))
	{
		AccountPrinter::showHeader();

		for (unsigned i = (10 * (currentPage_ - 1)); i < (10 * currentPage_) && i < items_.size(); i++)
		{
			if (choice_ == i + 1)
			{
				setTextColor(Color::WHITE);
			}
			choice_ == i + 1 ? cout << items_.at(i) << "<--" << endl : cout << items_.at(i) << endl;
			setTextColor(Color::LIGHT_CYAN);
		}

		drawSolidLine(AccountPrinter::getSolidLineLength());
	}

	if (typeid(T) == typeid(Car))
	{
		CarPrinter::showHeader();

		for (unsigned i = (10 * (currentPage_ - 1)); i < (10 * currentPage_) && i < items_.size(); i++)
		{
			if (choice_ == i + 1)
			{
				setTextColor(Color::WHITE);
			}
			choice_ == i + 1 ? cout << items_.at(i) << "<--" << endl : cout << items_.at(i) << endl;
			setTextColor(Color::LIGHT_CYAN);
		}

		drawSolidLine(CarPrinter::getSolidLineLength());
	}
}

template<typename T>
ItemSelection<T>::~ItemSelection() = default;


#endif // ITEMSELECTION_H