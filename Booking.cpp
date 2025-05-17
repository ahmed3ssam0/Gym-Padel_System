#include "Booking.h"

#include <iomanip>
#include <sstream>

int Booking::count = 0;

Booking::Booking() = default;
Booking::Booking(Trainee trainee, Court court, string day,string startTime, float timePeriod) : trainee(trainee), court(court) {
    this->id = to_string(trainee.getId()) + to_string(++count);
    this->day = day;
    this->startTime = startTime;
    this->endTime = calculateEndTime(startTime, timePeriod);
    this->timePeriod = timePeriod;
    this->price = court.getPrice() * timePeriod;
    this->isConfirmed = false;
}

Booking::~Booking() {
    this->day.clear();
    this->startTime.clear();
    this->endTime.clear();
    this->timePeriod = 0;
    this->price = 0;
    this->isConfirmed = false;
}

void Booking::setId(string id) { this->id = id; }
void Booking::setDay(string d) { this->day = d; }
void Booking::setStartTime(string st) { this->startTime = st; }
void Booking::setEndTime(string et) { this->endTime = et; }
void Booking::setTimePeriod(float tp) { this->timePeriod = tp; }
void Booking::setIsConfirmed (bool ic){this->isConfirmed =ic  ;}
void Booking::setPrice(float price) { this->price = price; }

string Booking::getId() { return id; }
string Booking::getDay() { return day; }
string Booking::getStartTime() { return startTime; }
string Booking::getEndTime() { return endTime; }
float Booking::getTimePeriod() { return timePeriod; }
bool Booking:: getIsConfirmed() {return isConfirmed ;}
float Booking::getPrice() { return price; }


string Booking::calculateEndTime(string start, float durationHours) {
    // Parse "HH:MM" (24-hour)
    int hour = 0, minute = 0;
    char colon;
    {
        stringstream ss(start);
        ss >> hour >> colon >> minute;
    }

    // Compute total minutes (round fractional minutes)
    int addMins = static_cast<int>(round(durationHours * 60.0f));
    int total = hour * 60 + minute + addMins;

    // Wrap around 24h clock
    total %= (24 * 60);
    if (total < 0) total += 24 * 60;

    int endHour = total / 60;
    int endMinute = total % 60;

    // Format back to "HH:MM"
    stringstream out;
    out << setfill('0') << setw(2) << endHour
        << ":" << setfill('0') << setw(2) << endMinute;
    return out.str();
}

bool Booking::confirmBooking () {
    if (!court.getIsAvailable()) {
		cout << "Court is not available for booking!" << endl;
        return false;
    }
    if (!isConfirmed){
        isConfirmed = true;
        return true;
    }
    return false;

}

void Booking::displayBookingInfo() {
    cout<<"startTime: "<< startTime << endl;
    cout<<"endTime: "<< endTime << endl;
    cout<<"total price per duration: " << price << endl;
}

string Booking::bookings_to_string() {
    ostringstream oss;

    oss << "ID=" << id
        << ", Day=" << day
        << ", Start=" << startTime
        << ", End=" << endTime
        << ", Duration=" << timePeriod
        << ", Price=" << price
        << ", Confirmed=" << isConfirmed
        << ", TraineeID=" << trainee.getId();

    return oss.str();
}