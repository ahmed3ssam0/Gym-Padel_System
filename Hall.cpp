#include "Hall.h"

Hall::Hall() = default;
Hall::Hall(string name, string code) {
	this->Name = name;
	this->Code = code;
}
Hall::~Hall() {
	this->Name.clear();
	this->Code.clear();
}
void Hall::setName(string name) { this->Name = name; }
void Hall::setCode(string code) { this->Code = code; }
string Hall::getName() { return Name; }
string Hall::getCode() { return Code; }
list<GymClass> Hall::getHallClasses() { return HallClasses; }

void Hall::addClass(GymClass c) {
	HallClasses.push_back(c);
}
void Hall::removeClassFromHall(GymClass c) {
	for (auto it = HallClasses.begin(); it != HallClasses.end(); ++it) {
		if (it->getName() == c.getName()) {
			HallClasses.erase(it);
			break;
		}
	}

}

void Hall::displayHallInfo() {
	cout << "Hall Name: " << Name << endl;
	cout << "Hall Code: " << Code << endl;
	cout << "Classes in this hall: " << endl;
	for (auto& gymClass : HallClasses) {
		cout << "Class Name: " << gymClass.getName() << endl;
		cout << "Capacity: " << gymClass.getCapacity() << endl;
		cout << "Start Time: " << gymClass.getStartTime() << endl;
		cout << "Time Period: " << gymClass.getTimePeriod() << endl;
		cout << "Number of Sessions: " << gymClass.getNumberOfSessions() << endl;
	}
}