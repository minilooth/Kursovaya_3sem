#ifndef HORIZONTALSHOW_H
#define HORIZONTALSHOW_H


#include "CarHandler.h"
#include "Car.h"
#include "AccountHandler.h"
#include "Account.h"


using namespace std;

template<typename T>
class HorizontalShow
{
protected:
	string title_;
	string tooltip_;
	vector<T> items_;
	unsigned maxPages_;
	unsigned currentPage_;
	unsigned pageSize_;
public:
	HorizontalShow();
	HorizontalShow(const string& title, const vector<T>& items);
	HorizontalShow(const char* title, const vector<T>& items);
	virtual void nextPage();
	virtual void previousPage();
	void showCurrentPageNumber();
	unsigned showMode();
	void showTooltip();
	void showTitle();
	virtual void showItems();
	virtual ~HorizontalShow();
};

template<typename T>
HorizontalShow<T>::HorizontalShow() = default;

template<typename T>
HorizontalShow<T>::HorizontalShow(const string & title, const vector<T> & items)
{
	this->title_ = title;
	this->items_ = items;
	this->tooltip_ = "Подсказка:\nНажмите -> чтобы перейти на следующую страницу.\nНажмите <- чтобы перейти на предыдущую страницу.\nНажмите ESC чтобы вернутся назад.";
	this->pageSize_ = 10;

	this->maxPages_ = this->items_.size() / this->pageSize_;

	if (this->items_.size() % this->pageSize_ != 0)
	{
		this->maxPages_++;
	}

	this->currentPage_ = 1;
}

template<typename T>
HorizontalShow<T>::HorizontalShow(const char* title, const vector<T> & items)
{
	this->title_ = title;
	this->items_ = items;
	this->tooltip_ = "Подсказка:\nНажмите -> чтобы перейти на следующую страницу.\nНажмите <- чтобы перейти на предыдущую страницу.\nНажмите ESC чтобы вернутся назад.";
	this->pageSize_ = 10;

	this->maxPages_ = this->items_.size() / this->pageSize_;

	if (this->items_.size() % this->pageSize_ != 0)
	{
		this->maxPages_++;
	}

	this->currentPage_ = 1;
}

template<typename T>
void HorizontalShow<T>::nextPage()
{
	if (this->currentPage_ == this->maxPages_)
	{
		return;
	}

	this->currentPage_++;
}

template<typename T>
void HorizontalShow<T>::previousPage()
{
	if (this->currentPage_ == 1)
	{
		return;
	}

	this->currentPage_--;
}

template<typename T>
void HorizontalShow<T>::showCurrentPageNumber()
{
	cout << "Страница " + to_string(this->currentPage_) + " из " + to_string(this->maxPages_) << endl;
}

template<typename T>
unsigned HorizontalShow<T>::showMode()
{
	KEY_EVENT_RECORD key;
	while (true)
	{
		system("cls");

		if (!title_.empty())
		{
			
		}

		showTitle();

		cout << endl;

		showCurrentPageNumber();

		showItems();

		cout << endl;

		showTooltip();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_RIGHT:
			nextPage();
			break;
		case VK_LEFT:
			previousPage();
			break;
		case VK_ESCAPE:
			return 0;
		default:
			break;
		}
	}
}

template<typename T>
void HorizontalShow<T>::showTitle()
{
	cout << title_ << endl;
}

template<typename T>
void HorizontalShow<T>::showTooltip()
{
	cout << tooltip_ << endl;
}

template<typename T>
void HorizontalShow<T>::showItems()
{
	if (typeid(T) == typeid(account::Account))
	{
		account::AccountPrinter::showHeader();
		for (unsigned i = (10 * (currentPage_ - 1)); i < (10 * currentPage_) && i < items_.size(); i++)
		{
			cout << items_.at(i) << endl;
		}
		drawSolidLine(account::AccountPrinter::getSolidLineLength());
	}

	if (typeid(T) == typeid(car::Car))
	{
		car::CarPrinter::showHeader();
		for (unsigned i = (10 * (currentPage_ - 1)); i < (10 * currentPage_) && i < items_.size(); i++)
		{
			cout << items_.at(i) << endl;
		}
		drawSolidLine(car::CarPrinter::getSolidLineLength());
	}
}

template<typename T>
HorizontalShow<T>::~HorizontalShow() = default;


#endif // HORIZONTALSHOW_H