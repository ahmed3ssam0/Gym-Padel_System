#include "GymClass.h"
#include <string>

GymClass::GymClass() = default;
GymClass::GymClass(string name, int capacity, string startTime, float timePeriod, int numberOfSessions, bool type) {
	this->name = name;
	this->capacity = capacity;
	this->startTime = startTime;
	this->timePeriod = timePeriod;
	this->numberOfSessions = numberOfSessions;
	this->type = type;
}
GymClass::~GymClass() {
	this->name.clear();
	this->capacity = 0;
	this->startTime.clear();
	this->timePeriod = 0;
	this->numberOfSessions = 0;
	this->type = false;
}
void GymClass::setName(string name) { this->name = name; }
void GymClass::setCapacity(int capacity) { this->capacity = capacity; }
void GymClass::setStartTime(string startTime) { this->startTime = startTime; }
void GymClass::setEndTime(string endTime) { this->startTime = endTime; }
void GymClass::setTimePeriod(float timePeriod) { this->timePeriod = timePeriod; }
void GymClass::setNumberOfSessions(int numberOfSessions) { this->numberOfSessions = numberOfSessions; }
void GymClass::setType(bool type) { this->type = type; }
void GymClass::setClassCoach(string coachId) { this->coachId = coachId; }

string GymClass::getName() { return name; }
int GymClass::getCapacity() { return capacity; }
string GymClass::getStartTime() { return startTime; }
string GymClass::getEndTime() { return startTime; }
float GymClass::getTimePeriod() { return timePeriod; }
int GymClass::getNumberOfSessions() { return numberOfSessions; }
bool GymClass::getType() { return type; }
string GymClass::getClassCoach() { return coachId; }

void GymClass::addTraineeToClass(Trainee t) {
	if (ClassTrainees.size() < capacity) {
		ClassTrainees.push_back(t);
		for (auto wp : ClassWorkoutPlans) {
			t.addWorkoutPlan(wp);
		}
	}
	else {
		ClassWaitingList.push(t);
		cout << "Class is full. Added to waiting list." << endl;
	}
}
void GymClass::removeTraineeFromClass(Trainee t) {
	for (auto it = ClassTrainees.begin(); it != ClassTrainees.end(); ++it) {
		if (it->getId() == t.getId()) { 
			ClassTrainees.erase(it);
			break;
		}
	}
	if (!ClassWaitingList.empty()) {
		Trainee nextTrainee = ClassWaitingList.front();
		ClassWaitingList.pop();
		ClassTrainees.push_back(nextTrainee);
	}
}

void GymClass::addWorkoutPlan(WorkoutPlan wp) {
	ClassWorkoutPlans.push_back(wp);
	for (auto t : ClassTrainees) {
		t.addWorkoutPlan(wp);
	}
}
void GymClass::removeWorkoutPlan(WorkoutPlan wp) {
	for (auto it = ClassWorkoutPlans.begin(); it != ClassWorkoutPlans.end(); ++it) {
		if (it->getName() == wp.getName()) {
			ClassWorkoutPlans.erase(it);
			break;
		}
	}
	for (auto t : ClassTrainees) {
		t.removeWorkoutPlan(wp);
	}
}

void GymClass::displayClassInfo() {
	cout << "Class Name: " << name << endl;
	cout << "Capacity: " << capacity << endl;
	cout << "Start Time: " << startTime << endl;
	cout << "Time Period: " << timePeriod << endl;
	cout << "Number of Sessions: " << numberOfSessions << endl;
	cout << "Type: " << (type ? "Private" : "Group") << endl;
}
void GymClass::displayWorkoutPlans() {
	for (auto wp : ClassWorkoutPlans) {
		cout << "Workout Plan Name: " << wp.getName() << endl;
		cout << "Hours Per Day: " << wp.getHoursPerDay() << endl;
		cout << "Type: " << wp.getType() << endl;
		cout << "Intensity: " << wp.getIntensity() << endl;
		cout << "Lost Calories: " << wp.getLostCalories() << endl;
	}
}
void GymClass::displayTraineesInClass() {
	for (auto t : ClassTrainees) {
		cout << "Trainee Name: " << t.getName() << endl;
		cout << "Trainee ID: " << t.getId() << endl;
	}
}

vector<string> GymClass::class_to_string() {
	vector<string> classInfo;
	classInfo.push_back("Class Name: " + name);
	classInfo.push_back("Capacity: " + to_string(capacity));
	classInfo.push_back("Start Time: " + startTime);
	classInfo.push_back("Time Period: " + to_string(timePeriod).substr(0,3) + " hours");
	classInfo.push_back("Number of Sessions: " + to_string(numberOfSessions));
	classInfo.push_back("Type: " + string(type ? "Private" : "Group"));
	return classInfo;

}