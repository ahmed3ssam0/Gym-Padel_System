#include "WorkoutPlan.h"

WorkoutPlan::WorkoutPlan() = default;
WorkoutPlan::WorkoutPlan(string name, float hoursPerDay, string intensity, float lostCalories,string cname) {
	this->Name = name;
	this->HoursPerDay = hoursPerDay;
	this->Intensity = intensity;
	this->LostCalories = lostCalories;
	this->className = cname;
}
WorkoutPlan::~WorkoutPlan() {
	this->Name.clear();
	this->HoursPerDay = 0;
	this->Intensity.clear();
	this->LostCalories = 0;
	this->className.clear();
}

void WorkoutPlan::setName(string name) { this->Name = name; }
void WorkoutPlan::setHoursPerDay(float hoursPerDay) { this->HoursPerDay = hoursPerDay; }
void WorkoutPlan::setIntensity(string intensity) { this->Intensity = intensity; }
void WorkoutPlan::setLostCalories(float lostCalories) { this->LostCalories = lostCalories; }
void WorkoutPlan::setClass_name_code(string className) { this->className = className; }

string WorkoutPlan::getName() { return Name; }
float WorkoutPlan::getHoursPerDay() { return HoursPerDay; }
string WorkoutPlan::getIntensity() { return Intensity; }
float WorkoutPlan::getLostCalories() { return LostCalories; }
string WorkoutPlan::getClass_name_code() { return className; }