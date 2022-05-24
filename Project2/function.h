#pragma once
#include<string>

typedef unsigned short int usi;

//struct Student
//{
//	std::string name;
//	std::string surName;
//	std::string lastName;
//	usi markOAIP;
//	usi markMath;
//};

struct Receipts
{
	std::string TVbrand;
	std::string dateInvite;
	bool statusReady;
};

struct Student
{
	std::string FIO;
	double averageMark;
	double money;
};

Receipts* CreateArrayStudent(Receipts *object, unsigned int _count);
void WriteInFile(const std::string filename, Receipts *receipts, int count);
void ReadFile(std::string filename);
