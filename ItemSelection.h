#ifndef ITEMSELECTION_H
#define ITEMSELECTION_H


#include "HorizontalShow.h"


using namespace std;

template<typename T> class HorizontalShow;

template<typename T>
class ItemSelection : virtual public HorizontalShow<T>
{
	unsigned choice_;
public:
	ItemSelection();
	ItemSelection(const string& title, const vector<T>& items);
	ItemSelection(const char* title, const vector<T>& items);

	virtual void nextPage() ;
	virtual void previousPage() ;
	unsigned selectMode() ;
	virtual void showItems() ;
	
	virtual ~ItemSelection();
};


template<typename T>
ItemSelection<T>::ItemSelection() = default;

template<typename T>
ItemSelection<T>::ItemSelection(const string& title, const vector<T>& items)
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

	this->choice_ = 1;
}

template<typename T>
ItemSelection<T>::ItemSelection(const char* title, const vector<T>& items)
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

	this->choice_ = 1;
}

template<typename T>
void ItemSelection<T>::nextPage()
{
	if (this->currentPage_ == this->maxPages_)
	{
		return;
	}

	this->currentPage_++;

	this->choice_ = (this->pageSize_ * (this->currentPage_ - 1)) + 1;
}

template<typename T>
void ItemSelection<T>::previousPage()
{
	if (this->currentPage_ == 1)
	{
		return;
	}

	this->currentPage_--;

	this->choice_ = (this->pageSize_ * (this->currentPage_ - 1)) + 1;
}

template<typename T>
unsigned ItemSelection<T>::selectMode()
{
	KEY_EVENT_RECORD key;
	while (true)
	{
		system("cls");

		this->showTitle();

		cout << endl;

		this->showCurrentPageNumber();

		this->showItems();

		cout << endl;

		this->showTooltip();

		VP_GetCh(key);

		switch (key.wVirtualKeyCode)
		{
		case VK_UP:
			if (this->choice_ > (this->pageSize_ * (this->currentPage_ - 1)) + 1)
			{
				this->choice_--;
			}
			else
			{
				if (this->currentPage_ < this->maxPages_)
				{
					this->choice_ = (this->pageSize_ * this->currentPage_);
				}
				else
				{
					this->choice_ = this->items_.size();
				}
			}
			break;
		case VK_DOWN:
			if (this->currentPage_ < this->maxPages_)
			{
				if (this->choice_ > (this->pageSize_ * this->currentPage_) - 1)
				{
					this->choice_ = (this->pageSize_ * (this->currentPage_ - 1)) + 1;
				}
				else
				{
					this->choice_++;
				}
			}
			else
			{
				if (this->choice_ > this->items_.size() - 1)
				{
					this->choice_ = (this->pageSize_ * (this->currentPage_ - 1)) + 1 ;
				}
				else
				{
					this->choice_++;
				}
			}
			break;
		case VK_RIGHT :
			this->nextPage();
			break;
		case VK_LEFT :
			this->previousPage();
			break;
		case VK_RETURN:
			return this->choice_;
		case VK_ESCAPE :
			return 0;
		default:
			break;
		}
	}
}

template<typename T>
void ItemSelection<T>::showItems()
{
	if (typeid(T) == typeid(account::Account))
	{
		account::AccountPrinter::showHeader();

		for (unsigned i = (10 * (this->currentPage_ - 1)); i < (10 * this->currentPage_) && i < this->items_.size(); i++)
		{
			if (this->choice_ == i + 1)
			{
				setTextColor(Color::WHITE);
			}
			this->choice_ == i + 1 ? cout << this->items_.at(i) << "<--" << endl : cout << this->items_.at(i) << endl;
			setTextColor(Color::LIGHT_CYAN);
		}

		drawSolidLine(account::AccountPrinter::getSolidLineLength());
	}

	if (typeid(T) == typeid(car::Car))
	{
		car::CarPrinter::showHeader();

		for (unsigned i = (10 * (this->currentPage_ - 1)); i < (10 * this->currentPage_) && i < this->items_.size(); i++)
		{
			if (this->choice_ == i + 1)
			{
				setTextColor(Color::WHITE);
			}
			this->choice_ == i + 1 ? cout << this->items_.at(i) << "<--" << endl : cout << this->items_.at(i) << endl;
			setTextColor(Color::LIGHT_CYAN);
		}

		drawSolidLine(car::CarPrinter::getSolidLineLength());
	}
}

template<typename T>
ItemSelection<T>::~ItemSelection() = default;


#endif // ITEMSELECTION_H