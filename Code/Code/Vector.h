#pragma once
#include "Magazine.h"

class Vector
{
public:

	Vector() { elements = 0;  cur_Lenght = 0; Lenght = 0; }

	Vector(int lenght)
	{
		elements = new Object* [lenght];

		Lenght = lenght;
		cur_Lenght = 0;
	}

	virtual ~Vector()
	{
		if (elements == 0)
			return;

		for (int i = 0; i < cur_Lenght; i++)
			delete elements[i];

		delete[] elements;

		Lenght = 0;
		cur_Lenght = 0;
	}

	void Recreate(int lenght) 
	{
		if (elements != 0)
		{
			for (int i = 0; i < cur_Lenght; i++)
				delete elements[i];

			delete[] elements;
		}

		Lenght = lenght;
		elements = new Object * [lenght];
		cur_Lenght = 0;
	}

	bool TryAdd(Object* element) 
	{
		if (cur_Lenght >= Lenght)
		{
			cout << "Ваша группа переполнена!" << endl;
			return false;
		}
			

		elements[cur_Lenght] = element;
		cur_Lenght++;
		return true;
	}

	bool TryDelete(string Name)
	{
		if (cur_Lenght == 0)
		{
			cout << "Ваша группа пуста" << endl;
			return false;
		}

		bool flag = false;

		for (int i = 0; i < cur_Lenght && !flag; i++)
		{
			flag = elements[i]->GetName() == Name;

			if (flag)
			{
				Object* tmp = elements[i];

				for (int j = i; j < cur_Lenght - 1; j++)
					elements[j] = elements[j + 1];

				delete tmp;

				cur_Lenght--;
			}
		}

		if (!flag)
			cout << "Элемент с таким названием в группе не найден!" << endl;

		return flag;
	}

	void print(bool onlyNames = false)
	{
		if (cur_Lenght == 0)
		{
			cout << "Нечего показывать" << endl;
			return;
		}

		elements[0]->show(onlyNames);

		for (int i = 1; i < cur_Lenght; i++)
		{
			cout << endl;
			elements[i]->show(onlyNames);
		}
	}

	int operator()() { return cur_Lenght; }

protected:

	Object** elements;
	int Lenght;
	int cur_Lenght;
};

