#include "Receptionist.h"

//constructor
Receptionist::Receptionist() = default;
Receptionist::Receptionist(string name, string id, string password, float salary) {
	this->name = name;
	this->id = id;
	this->password = password;
	this->salary = salary;
}
//setter
void Receptionist::setname(string name) {
	this->name = name;
}
void Receptionist::setid(int id) {
	this->id = id;
}
void Receptionist::setpassword(string password) {
	this->password = password;
}
void Receptionist::settrainees(unordered_map<int, Trainee> trainees) {
    this->trainees = trainees;
}
void Receptionist::setSalary(float salary) {
	this->salary = salary;
}
//getter
string Receptionist::getname() {
	return name;
}
string Receptionist::getid() {
	return id;
} 
unordered_map<int, Trainee>Receptionist::gettrainees() {
    return trainees;
}
string Receptionist::getpassword() {
	return password;
}
float Receptionist::getSalary() {
	return salary;
}
//update
void  Receptionist::UpdateReceptionistInfo(string newname, string newpassword) {
	name = newname;
	password = newpassword;
}
//destructor
Receptionist::~Receptionist() {

}
//registerTrainee
void Receptionist::registerTrainee(Trainee trainee) {
	trainees[trainee.getId()] = trainee;
    cout << "Trainee registered successfully.\n";
}
//remove
bool Receptionist::removeTrainee(int id) {
	auto it = trainees.find(id);
	if (it != trainees.end()) {
		trainees.erase(it);
		cout << "Trainee removed successfully.\n";
		return true;
	}
	else {
		cout << "Trainee not found.\n";
		return false;
	}
}
//viewTrainee
void Receptionist::viewTrainee() {
    if (trainees.empty()) {
        cout << "No trainees registered.\n";
        return;
    }
    for (auto t : trainees) {
        t.second.getName();
    }
}
