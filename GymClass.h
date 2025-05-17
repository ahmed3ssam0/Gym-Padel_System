#pragma once
#include <iostream>
#include <list>
#include <queue>
using namespace std;

#include "Trainee.h"
#include "WorkoutPlan.h"
//#include "Coatch.h"

class GymClass
{
    string name;
    int capacity;
    string startTime;
    float timePeriod;
    int numberOfSessions;
	bool type; // 1 private, 0 group
    string coachId;
    list<WorkoutPlan> ClassWorkoutPlans;
    list<Trainee> ClassTrainees;
    queue<Trainee> ClassWaitingList;

	public:
	GymClass();
	GymClass(string name, int capacity, string startTime, float timePeriod, int numberOfSessions, bool type);
	~GymClass();

	void setName(string name);
	void setCapacity(int capacity);
	void setStartTime(string startTime);
	void setEndTime(string endTime);
	void setTimePeriod(float timePeriod);
	void setNumberOfSessions(int numberOfSessions);
	void setType(bool type);
	void setClassCoach(string coachId);

	string getName();
	int getCapacity();
	string getStartTime();
	string getEndTime();
	float getTimePeriod();
	int getNumberOfSessions();
	bool getType();
	string getClassCoach();

	void addTraineeToClass(Trainee t);
	void removeTraineeFromClass(Trainee t);

	void addWorkoutPlan(WorkoutPlan wp);
	void removeWorkoutPlan(WorkoutPlan wp);

	void displayClassInfo();
	void displayWorkoutPlans();
	void displayTraineesInClass();

	vector<string> class_to_string();

};

