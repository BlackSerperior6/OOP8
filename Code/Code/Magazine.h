#pragma once
#include "Print.h"

class Magazine : public Print
{
private:
	int AmountOfPages;

public:

	Magazine():Print(){}

	Magazine(string name, string author, int pages) : Print(name, author) 
	{ 
		setPages(pages);
	}
	
	virtual ~Magazine() {}

	void setPages(int pages) { AmountOfPages = pages; }

	int getPages() { return AmountOfPages; }

	void show(bool onlyNames = false) override
	{
		Print::show(onlyNames);

		if (!onlyNames)
			cout << ", кол-во страниц: " << AmountOfPages;
	}

	void PutIn() override 
	{
		Print::PutIn();
		cout << "¬ведите кол-во страниц работы: "; cin >> AmountOfPages;
	}

	Magazine& operator=(Magazine& anotherMagazine)
	{
		Print::operator=(anotherMagazine);
		AmountOfPages = anotherMagazine.AmountOfPages;

		return *this;
	}
};

