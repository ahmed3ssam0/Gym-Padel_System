#include "Coatch.h"

//constructor
Coatch::Coatch() = default;
Coatch::Coatch(string name,string id, string password, float salary) {
	this->name = name;
	this->id = id;
	this->password = password;
	this->salary = salary;
}
//setter
void Coatch::setname(string name) {
	this->name = name;
}
void Coatch::setid(int id) {
	this->id = id;
}
void Coatch::setpassword(string password) {
	this->password= password;
}
void Coatch::setClassAssignments(list<GymClass> classAssignments) {
    this->classAssignments = classAssignments;
}
void Coatch::setWorkoutPlans(unordered_map<string, string> workoutPlans) {
	this->workoutPlans = workoutPlans;
}
void Coatch::setSalary(float salary) {
	this->salary = salary;
}

//getter
string Coatch::getname()const{
	return name;
}
string Coatch::getid() {
    return id;
}
string Coatch::getpassword() {
	return password;
}
list<GymClass>Coatch::getClassAssignments() {
    return classAssignments;
}
unordered_map<string, string> Coatch::getWorkoutPlans() {
	return workoutPlans;
}
float Coatch::getSalary() {
	return salary;
}

//update
void Coatch::updateCoachInfo(string newname, string newpassword) {
	name = newname;
	password = newpassword;
}
//destructor
Coatch::~Coatch() {
   // cout << "Destructor called"<<endl;
}
//add class
void Coatch::addClass(GymClass gymClass) {
    classAssignments.push_back(gymClass);
    cout << "Class added successfully.\n";
}
//remove class
void Coatch::removeClass(string className) {
    for (auto it = classAssignments.begin(); it != classAssignments.end(); ++it) {
        if (it->getName() == className) {
            classAssignments.erase(it);
            cout << "Class removed successfully.\n";
            return;
        }
    }
    cout << "Class not found.\n";
}
//assign workout plan
void Coatch::assignWorkoutPlan(string session, string workout) {
	workoutPlans[session] = workout;
}
//displayClasses
void Coatch::displayClasses() {
    cout << "Assigned Classes:\n";
    for (auto gymClass : classAssignments) {
        cout << "- " << gymClass.getName() << endl;
    }
}


