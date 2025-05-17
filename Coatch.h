#pragma once
#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
using namespace std;
#include "GymClass.h"
class Coatch
{
private:
	string name;
	string id ;
	string password;
	float salary;
	list<GymClass> classAssignments;
	list<WorkoutPlan> CoatchWorkoutPlans;
public:
	//constructor
	Coatch();
	Coatch(string name,string Id, string password, float salary);
	//setter
	void setname(string name);
	void setid(int id);
	void setpassword(string password);
	void setClassAssignments(list<GymClass> classAssignments);
	void setSalary(float salary);
	void setCoatchWorkoutPlans(list<WorkoutPlan> CoatchWorkoutPlans);

	//getter
	string getname()const;
	string getid();
	string getpassword();
	list<GymClass> getClassAssignments();
	float getSalary();
	list<WorkoutPlan> getCoatchWorkoutPlans();
	
	// Update 
	void updateCoachInfo(string newname, string newpassword);
	//destructor
	~Coatch();
	//add
	void addClass(GymClass gymClass);
	//remove
	bool removeClass( string className);
	//assign workout plan
	void assignWorkoutPlan(string className);
	//display
	void displayClasses();
};