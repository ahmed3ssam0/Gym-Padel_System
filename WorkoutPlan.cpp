#include "WorkoutPlan.h"

WorkoutPlan::WorkoutPlan() = default;
WorkoutPlan::WorkoutPlan(string name, float hoursPerDay, string type, string intensity, float lostCalories) {
	this->Name = name;
	this->HoursPerDay = hoursPerDay;
	this->Type = type;
	this->Intensity = intensity;
	this->LostCalories = lostCalories;
}
WorkoutPlan::~WorkoutPlan() {
	this->Name.clear();
	this->HoursPerDay = 0;
	this->Type.clear();
	this->Intensity.clear();
	this->LostCalories = 0;
}

void WorkoutPlan::setName(string name) { this->Name = name; }
void WorkoutPlan::setHoursPerDay(float hoursPerDay) { this->HoursPerDay = hoursPerDay; }
void WorkoutPlan::setType(string type) { this->Type = type; }
void WorkoutPlan::setIntensity(string intensity) { this->Intensity = intensity; }
void WorkoutPlan::setLostCalories(float lostCalories) { this->LostCalories = lostCalories; }
void WorkoutPlan::setClass_name_code(string className) { this->className = className; }

string WorkoutPlan::getName() { return Name; }
float WorkoutPlan::getHoursPerDay() { return HoursPerDay; }
string WorkoutPlan::getType() { return Type; }
string WorkoutPlan::getIntensity() { return Intensity; }
float WorkoutPlan::getLostCalories() { return LostCalories; }
string WorkoutPlan::getClass_name_code() { return className; }