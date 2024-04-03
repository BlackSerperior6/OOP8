#pragma once

const int evNothing = 0;
const int evMessage = 100;

const int cmCreate = 1; //m;
const int cmAdd = 2; //+
const int cmDelete = 3; //-
const int cmPrint = 4; //s
const int cmPrintNames = 5; //z
const int cmQuit = 6; //q

class TEvent
{
public:
	int What;
	int Command;
};

