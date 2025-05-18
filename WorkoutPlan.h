#pragma once
#include <iostream>
#include <string>
using namespace std;

class WorkoutPlan
{
    string Name;
    float HoursPerDay;
    string Intensity;
    float LostCalories;
    string className;

public:
    WorkoutPlan();
    WorkoutPlan(string name, float hoursPerDay,  string intensity, float lostCalories,string cname);
    ~WorkoutPlan();

    void setName(string name);
    void setHoursPerDay(float hoursPerDay);
    void setIntensity(string intensity);
    void setLostCalories(float lostCalories);
    void setClass_name_code(string className);

    string getName();
    float getHoursPerDay();
    string getIntensity();
    float getLostCalories();
    string getClass_name_code();
};
