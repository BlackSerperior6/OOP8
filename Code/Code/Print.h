#pragma once

#include <string>
#include "Object.h"

class Print : public Object
{
protected:
	string Author;
	string Name;

public:

	Print() {}

	Print(string name, string author)
	{
		setName(name);
		setAuthor(Author);
	}

	virtual ~Print(){}

	string getAuthor() { return Author; }

	string GetName() override { return Name; }

	void setAuthor(string author) { Author = author; }

	void setName(string name) { Name = name; }

	void show(bool onlyNames = false) override
	{
		if (onlyNames)
		{
			cout << GetName();
			return;
		}

		cout << "�������: " << Name  << ", �����: " << Author;
	}

	void PutIn() override
	{
		cout << "������� �������� ������: ";
		getline(cin, Name);
		cout << "������� ������ ������: ";
		getline(cin, Author);
	}

	Print& operator=(Print& anotherPrint)
	{
		Name = anotherPrint.Name;
		Author = anotherPrint.Author;

		return *this;
	}
};

