#include "Padel.h"

#include <sstream>
#include <cmath>

Padel::Padel() = default;
Padel::~Padel() = default;

unordered_map<string, Court> Padel::getCourts() { return courts; }
unordered_map<string, Booking> Padel::getBookings() { return bookings; }

void Padel::addCourt(Court court) { courts[court.getName()] = court; }
bool Padel::removeCourt(Court court) {
    if (courts.empty()) return false;
    if (courts.find(court.getName()) == courts.end()) return false;
    courts.erase(court.getName());
    return true;
}
void Padel::updateCourt(string name, Court court) {
    courts[name] = court;
}
Court Padel::searchCourt(string name) {
	for (auto pair : courts) {
		if (pair.second.getName() == name) {
			cout << "Court found: " << pair.second.getName() << endl;
			return pair.second;
		}
	}
	cout << "Court not found!" << endl;
	return Court();
}
void Padel::displayAllCourts() {
	cout << "All courts:\n";
	for (auto pair : courts) {
		cout << "Court ID: " << pair.first << ", Name: " << pair.second.getName() << ", Location: " << pair.second.getLocation() << ", Available: " << pair.second.getIsAvailable() << endl;
	}
}


bool Padel::bookCourt(Booking booking) {
    if (!booking.confirmBooking()) return false;

    string id = booking.getId();
    // Reject duplicate ID
    if (bookings.find(id) != bookings.end()) {
        cout << "Booking with ID " << id << " already exists!\n";
        return false;
    }

    // Helper to convert "HH:MM" → total minutes
    auto toMinutes = [](const string& hhmm) {
        int h, m; char c;
        stringstream ss(hhmm);
        ss >> h >> c >> m;
        return h * 60 + m;
        };

    int newStart = toMinutes(booking.getStartTime());
    int newEnd = toMinutes(booking.getEndTime());

    // Check for time-overlap on same day
    for (auto it = bookings.begin(); it != bookings.end(); ++it) {
        string otherId = it->first;
        Booking existing = it->second;

        if (existing.getDay() != booking.getDay())
            continue;

        int exStart = toMinutes(existing.getStartTime());
        int exEnd = toMinutes(existing.getEndTime());

        // overlap if NOT (newEnd ≤ exStart || newStart ≥ exEnd)
        if (!(newEnd <= exStart || newStart >= exEnd)) {
            cout << "Booking overlaps with existing ID "
                << otherId << " on " << booking.getDay() << "\n";
            return false;
        }
    }
    // No conflicts—insert & return success
    bookings[id] = booking;
    return true;
}
bool Padel::removeBooking(Booking booking) {
    if (bookings.find(booking.getId()) == bookings.end()) return false;
    bookings.erase(booking.getId());
    return true;
}

vector<string> Padel::padel_to_string_courts() {
    vector<string> ss;
	for (auto& pair : courts) {
		ss.push_back(pair.second.courts_to_string());
	}
	return ss;
}
vector<string> Padel::padel_to_string_bookings() {
    vector<string> ss;
	for (auto& pair : bookings) {
        ss.push_back(pair.second.bookings_to_string());
	}
	return ss;
}
