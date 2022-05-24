#include <iostream>
#include <fstream>
#include <string>
#include "function.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	unsigned int count = 0;
	string filename;
	cout << "Введите количество техники: ";
	cin >> count;
	Receipts* receipts = nullptr;

	receipts = CreateArrayStudent(receipts, count);
	if (receipts ==nullptr)
	{
		return 1;
	}
	cout << "Введите название файла: ";
	cin >> filename;
	WriteInFile(filename, receipts, count);
	cout << "\nДанные из файла" << filename << endl;
	ReadFile(filename);
	delete[] receipts;

	return 0;
}

Receipts* CreateArrayStudent(Receipts* object, unsigned int _count)
{
	if (_count==0)
	{
		return nullptr;
	}

	object = new Receipts[_count];
	cout << "Введите данные:" << endl;

	for (int i = 0; i < _count; i++)
	{
		cout << "Введите название бренда телевизора: ";
		cin >> object[i].TVbrand;
		cout << "Введите дату принятия(dd.mm.yyyy): ";
		cin >> object[i].dateInvite;
		cout << "Введите статус: ";
		cin >> object[i].statusReady;
		cout << std::string(100, '\n');
	}

	cout << "Данные введены успешно!" << endl;
	return object;
}

void WriteInFile(const std::string filename, Receipts* receipts, int count)
{
	if (receipts == nullptr)
	{
		cout << "Нулевой указатель!\n";
		return;
	}
	ofstream write;
	write.open("Z:\\" + filename + ".txt", ios::app);
	if (!write.is_open())
	{
		cout << "is_open вернула false\n";
		return;
	}

	for (int i = 0; i < count; i++)
	{
		if (!receipts[i].statusReady)
		{
			write << "\nБренд TV: " + receipts[i].TVbrand << "\nДата: " + receipts[i].dateInvite << "\nСтатус: "<<"Не выполнен" << endl;
		}
	}
	write.close();

}

void ReadFile(std::string filename)
{
	string outputInfo;
	ifstream read("Z:\\" + filename + ".txt");

	if (!read.is_open())
	{
		cout << "is_open вернула false\n";
		return;
	}

	while (getline(read, outputInfo))
	{
		cout << outputInfo << endl;
	}

	read.close();
}
