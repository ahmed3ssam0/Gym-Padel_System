#include "Gym.h"

Gym::Gym() = default;
Gym::~Gym() {
	gymClasses.clear();
	halls.clear();
}
unordered_map<string, GymClass> Gym::getGymClasses() { return gymClasses; }
unordered_map<string, Hall> Gym::getHalls() { return halls; }

void Gym::addGymClass(GymClass c) {
	gymClasses[c.getName()] = c;
}
void Gym::removeGymClass(GymClass c) {
	gymClasses.erase(c.getName());
}

void Gym::addHall(Hall h) {
	halls[h.getCode()] = h;
}
void Gym::removeHall(Hall h) {
	halls.erase(h.getCode());
}

void Gym::displayGymInfo() {
	cout << "Gym Classes: " << endl;
	for (auto& gymClass : gymClasses) {
		cout << "Class Name: " << gymClass.second.getName() << endl;
		cout << "Capacity: " << gymClass.second.getCapacity() << endl;
		cout << "Start Time: " << gymClass.second.getStartTime() << endl;
		cout << "Time Period: " << gymClass.second.getTimePeriod() << endl;
		cout << "Number of Sessions: " << gymClass.second.getNumberOfSessions() << endl;
	}
}