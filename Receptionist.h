#pragma once
#include<iostream>
using namespace std;
#include "Trainee.h"
#include <unordered_map>
class Receptionist
{
private:
	string name;
	string id;
	string password;
	float salary;
	unordered_map<int, Trainee> trainees;
public:
	//constructor
	Receptionist();
	Receptionist(string name, string Id, string password, float salary);
	//setter
	void setname(string name);
	void setid(int id);
	void setpassword(string password);
	void settrainees(unordered_map<int, Trainee> trainees);
	void setSalary(float salary);
	
	//getter
	string getname();
	string getid();
	string getpassword();
	unordered_map<int, Trainee> gettrainees();
	float getSalary();
	// Update 
	void UpdateReceptionistInfo(string newname, string newpassword);
	//destructor
	~Receptionist();
	//add
	void registerTrainee(Trainee trainee);
	//remove
	bool removeTrainee(int traineeID);
	//view member
	void viewTrainee();
};

