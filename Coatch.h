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
	string id;
	string password;
	float salary;
	list<GymClass> classAssignments;
	unordered_map<string, string> workoutPlans;
public:
	//constructor
	Coatch();
	Coatch(string name,string Id, string password, float salary);
	//setter
	void setname(string name);
	void setid(int id);
	void setpassword(string password);
	void setClassAssignments(list<GymClass> classAssignments);
	void setWorkoutPlans(unordered_map<string, string> workoutPlans);
	void setSalary(float salary);

	//getter
	string getname()const;
	string getid();
	string getpassword();
	list<GymClass> getClassAssignments();
	unordered_map<string, string> getWorkoutPlans();
	float getSalary();
	
	// Update 
	void updateCoachInfo(string newname, string newpassword);
	//destructor
	~Coatch();
	//add
	void addClass(GymClass gymClass);
	//remove
	void removeClass( string className);
	//assign workout plan
	void assignWorkoutPlan(string session, string workout);
	//display
	void displayClasses();
};