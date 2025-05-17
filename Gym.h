#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;
#include "GymClass.h"
#include "Hall.h"

class GymClass;
class Hall;

class Gym
{
	unordered_map<string, GymClass> gymClasses;
	unordered_map<string, Hall> halls;
	public:
	Gym();
	~Gym();
	unordered_map<string, GymClass> getGymClasses();
	unordered_map<string, Hall> getHalls();
	void addGymClass(GymClass c);
	void removeGymClass(GymClass c);
	void addHall(Hall h);
	void removeHall(Hall h);
	void displayGymInfo();
};

