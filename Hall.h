#pragma once
#include <iostream>
using namespace std;

#include "GymClass.h"

class GymClass;

class Hall
{
	string Name;
	string Code;
	list<GymClass> HallClasses;
public:
	Hall();
	Hall(string name, string code);
	~Hall();
	void setName(string name);
	void setCode(string code);
	string getName();
	string getCode();
	list<GymClass> getHallClasses();

	void addClass(GymClass c);
	void removeClassFromHall(GymClass c);
	void displayHallInfo();

};