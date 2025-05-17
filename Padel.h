#pragma once

#include <string>
#include <unordered_map>

#include "Court.h"
#include "Booking.h"
using namespace std;

class Padel {
    unordered_map<string, Court> courts;
    unordered_map<string, Booking> bookings;

public:
    Padel();
    ~Padel();


    unordered_map<string, Court> getCourts();
    unordered_map<string, Booking> getBookings();


    void addCourt(Court court);
    bool removeCourt (Court court);
    void updateCourt(string name, Court court);
    Court searchCourt(string name);
    void displayAllCourts();

    bool bookCourt(Booking booking);
    bool removeBooking(Booking booking);

    vector<string> padel_to_string_courts();
    vector<string> padel_to_string_bookings();
};