#include "Court.h"
#include <sstream>
#include <iostream>


Court::Court() = default;
Court::Court(string name, float price, string location, bool isAvailable) {
    this->name = name;
    this->pricePerHour = price;
    this->location = location;
	this->isAvailable = isAvailable;
}

Court::~Court() {
    this->pricePerHour = 0;
    this->location.clear();
    this->name.clear();
}

void Court::setName(string n) { this->name = n; }
void Court::setPrice(float p) { this->pricePerHour = p; }
void Court::setLocation(string loc) { this->location = loc; }
void Court::setIsAvailable(bool b) { this->isAvailable = b; }


string Court::getName() { return name; }
float Court::getPrice() { return pricePerHour; }
string Court::getLocation() { return location; }
bool Court::getIsAvailable() { return isAvailable; }


void Court::displayCourtInfo() {
    cout << "Location: " << location << endl;
    cout << "Price: " << pricePerHour << endl;
}

string Court::courts_to_string() {
	stringstream ss;
	ss << "Name=" << name << ", Location=" << location << ", Price=" << pricePerHour << ", Available=" << isAvailable;
	return ss.str();
}