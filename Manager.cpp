#include "Manager.h"
#include <iostream>
using namespace std;

//constructor
Manager::Manager(string id, string name, string password) {
	this->id = id;
    this->name = name;
    this->password = password;
}
//destructor
Manager::~Manager() {
	this->name.clear();
	this->password.clear();
}
//setter
void Manager::setid(string id) {
	this->id = id;
}
void Manager::setname(string name) {
    this->name = name;
}
void Manager::setpassword(string password) {
    this->password = password;
}
void Manager::setcoaches(unordered_map<string, Coatch> coaches) {
    this->coachMap = coaches;
}
void Manager::setreceptionists(unordered_map<string, Receptionist> receptionists) {
	this->recpMap = receptionists;
}
//getter
string Manager::getid() {
	return id;
}
string Manager::getname() {
    return name;
}
string Manager::getpassword() {
    return password;
}

unordered_map<string, Coatch> Manager::getcoaches() {
    return coachMap;
}
unordered_map<string, Receptionist> Manager::getreceptionists() {
	return recpMap;
}

// Update 
void Manager::updateMangerInfo(string newname, string newpassword) {
    this->name = newname;
    this->password = newpassword;
}

//add coatch
void Manager::addCoach(Coatch coatch) {
    coachMap[coatch.getid()] = coatch;
    cout << "Coach added successfully.\n";
}
//remove coatch
bool Manager::removeCoach(string coachID) {
	auto it = coachMap.find(coachID);
	if (it != coachMap.end()) {
		coachMap.erase(it);
		cout << "Coach removed successfully.\n";
		return true;
	}
	else {
		cout << "Coach not found.\n";
		return false;
	}
}

//add receptionist
void Manager::addReceptionist(Receptionist receptionist) {
	recpMap[receptionist.getid()] = receptionist;
	cout << "Receptionist added successfully.\n";
}
//remove receptionist
bool Manager::removeReceptionist(string receptionistID) {
	auto it = recpMap.find(receptionistID);
	if (it != recpMap.end()) {
		recpMap.erase(it);
		cout << "Receptionist removed successfully.\n";
		return true;
	}
	else {
		cout << "Receptionist not found.\n";
		return false;
	}
}