#pragma once
#include "Vector.h"
#include "TEvent.h"

class Dialog : public Vector
{
public:

	Dialog() { isOver = false; }

	~Dialog() {};

	void Execute()
	{
		cout << "m - ������� ����� ������ ���������!\n+ - �������� ����� �������!\n- - ������� ������� �� �����!\ns - ������� ������ � ���� ��������� ������!\nz - ������� ������ ���� ��������� ������!" << endl;

		TEvent Event;

		while (!isOver)
		{
			GetEvent(Event);
			HandleEvent(Event);
		}
	}

private:
	bool isOver;

	void GetEvent(TEvent& Event)
	{
		char CommandSymvol;
		cout << "> ";
		cin >> CommandSymvol;

		Event.What = evMessage;

		switch (CommandSymvol)
		{
		case 'm':
			Event.Command = cmCreate;
			break;
		case '+':
			Event.Command = cmAdd;
			break;
		case '-':
			Event.Command = cmDelete;
			break;
		case 's':
			Event.Command = cmPrint;
			break;
		case 'z':
			Event.Command = cmPrintNames;
			break;
		case 'q':
			Event.Command = cmQuit;
			break;
		default:
			Event.What = evNothing;
		}
	}

	void HandleEvent(TEvent& Event)
	{
		if (Event.What == evNothing)
		{
			cout << "���������� �������!" << endl << endl;
			return;
		}

		string Name;

		switch (Event.Command)
		{
		case cmCreate:

			int Size;

			do
			{
				cout << "������� ������ ������:" << endl;
				cin >> Size;
			} while (Size <= 0);

			Recreate(Size);

			break;

		case cmAdd:

			if (elements == 0)
			{
				cout << "������� ������ ���� �������!" << endl;
				break;
			}

			int number;

			do
			{
				cout << "��������, ����� ������ �� ������ ��������. 1 - �������� �������, 2 - ����������� �����!" << endl;
				cin >> number;
			} while (number != 1 && number != 2);

			cin.ignore();

			if (number == 1)
			{
				Print* print = new Print;
				print->PutIn();

				TryAdd(print);
			}
			else
			{
				Magazine* magazine = new Magazine;
				magazine->PutIn();

				TryAdd(magazine);
			}
			break;

		case cmDelete:

			if (elements == 0)
			{
				cout << "������� ������ ���� �������!" << endl;
				break;
			}

			cin.ignore();

			cout << "������� ��� ������, ������� �� ������ �������!" << endl;

			getline(cin, Name);

			TryDelete(Name);
			break;

		case cmPrint:

			print();
			cout << endl;
			break;

		case cmPrintNames:

			print(true);
			cout << endl;
			break;

		case cmQuit:

			isOver = true;
			break;

		default:
			break;
		}

		Event.What = evNothing;
	}
};

