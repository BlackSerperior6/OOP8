#pragma once
#include <iostream>

using namespace std;

class Object
{
public:

	virtual ~Object(){}

	Object() {}

	virtual void show(bool onlyNames = false) = 0;

	virtual void PutIn() = 0;

	virtual string GetName() = 0;
};

