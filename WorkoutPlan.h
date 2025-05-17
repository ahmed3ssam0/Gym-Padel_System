#pragma once
#include <iostream>
#include <string>
using namespace std;

class WorkoutPlan
{
    string Name;
    float HoursPerDay;
    string Type;
    string Intensity;
    float LostCalories;
    string className;

public:
    WorkoutPlan();
    WorkoutPlan(string name, float hoursPerDay, string type, string intensity, float lostCalories);
    ~WorkoutPlan();

    void setName(string name);
    void setHoursPerDay(float hoursPerDay);
    void setType(string type);
    void setIntensity(string intensity);
    void setLostCalories(float lostCalories);
    void setClass_name_code(string className);

    string getName();
    float getHoursPerDay();
    string getType();
    string getIntensity();
    float getLostCalories();
    string getClass_name_code();
};
