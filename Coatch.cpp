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
void Coatch::setSalary(float salary) {
	this->salary = salary;
}
void Coatch::setCoatchWorkoutPlans(list<WorkoutPlan> CoatchWorkoutPlans) {
	this->CoatchWorkoutPlans = CoatchWorkoutPlans;
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
float Coatch::getSalary() {
	return salary;
}
list<WorkoutPlan> Coatch::getCoatchWorkoutPlans() {
	return CoatchWorkoutPlans;
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
bool Coatch::removeClass(string className) {
    for (auto it = classAssignments.begin(); it != classAssignments.end(); ++it) {
        if (it->getName() == className) {
            classAssignments.erase(it);
            cout << "Class removed successfully.\n";
            return true;
        }
    }
    cout << "Class not found.\n";
	return false;
}
//displayClasses
void Coatch::displayClasses() {
    cout << "Assigned Classes:\n";
    for (auto gymClass : classAssignments) {
        cout << "- " << gymClass.getName() << endl;
    }
}


//assign workout plan
void Coatch::assignWorkoutPlan(string className) {
	for (auto& gymClass : classAssignments) {
		if (gymClass.getName() == className) {
			auto& Plans = gymClass.getClassWorkoutPlans();
			for (auto& p : Plans) {
				CoatchWorkoutPlans.push_back(p);
			}
			cout << "Workout plan assigned successfully.\n";
			return;
		}
	}
	cout << "Class not found.\n";
}