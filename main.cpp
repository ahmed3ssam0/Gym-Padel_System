#include <iostream>
#include "Trainee.h"
#include "Subscription.h"
#include "Padel.h"
#include "Court.h"
#include "Booking.h"
#include "Home.h"
#include "Gym.h"
#include <Windows.h>
#include "Home2.h"
#include "PlanForm.h"
#include "CoatchForm.h"
#include "System.h"
#include "Register.h"
#include "GymClass.h"
#include <string>

using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using namespace gymproject;

int main(cli::array<System::String^>^ args) {
	AllocConsole();
	freopen(".log.txt", "w", stdout);
	freopen(".log.txt", "a", stderr);
	cout << "Starting program...\n";

	SystemManager sys;


	Trainee trainee = Trainee("ahmed", "01221292988", "male", "18-2-2006", "a@a.com", "123456789", true);
	Subscription subscription = Subscription("25-4-2025", 1);
	subscription.setEndDate("25-4-2026");
	trainee.subscribe(subscription);
	trainee.renew_subscription(6);
	Padel padel = Padel();
	Court court = Court("court1", 500, "loc1", true);
	court.displayCourtInfo();
	padel.addCourt(court);

	Booking booking = Booking(trainee, court, "25-4-2025", "10:00", 2);
	booking.displayBookingInfo();
	if (padel.bookCourt(booking)) cout << "Booking successful!" << endl;
	else cout << "Booking failed!" << endl;

	//vector<string> bookings = padel.padel_to_string_bookings();


	//for (const auto& booking : bookings) {
	//	cout << booking << endl;
	//}

	//vector<string> courts = padel.padel_to_string_courts();
	//for (const auto& court : courts) {
	//	cout << court << endl;
	//}

	Gym gym = Gym();
	gym.addGymClass(GymClass("Yoga", 20, "10:00", 1, 5, false));
	gym.addGymClass(GymClass("Upper Body", 20, "13:00", 2, 10, false));
	gym.addGymClass(GymClass("Lower Body", 20, "13:00", 2, 10, false));

	Coatch coatch = Coatch("ahmed", "111", "123456789", 12345);
	coatch.addClass(GymClass("Yoga", 20, "10:00", 1, 5, false));
	coatch.assignWorkoutPlan("Yoga");

	try {
		sys.Load_All_Data();
		cout << "Data loaded successfully\n";
	} 
	catch (const std::exception& e) {
		cout << "Error loading data: " << e.what() << endl;
	}

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	// Only run one form
	Application::Run(gcnew Register(&sys));
	// Comment out the second Run call as only one is allowed
	// Application::Run(gcnew Home(&gym, &trainee, &padel));
	
	try {
		sys.Save_All_Data();
		cout << "Data saved successfully\n";
	}
	catch (const std::exception& e) {
		cout << "Error saving data: " << e.what() << endl;
	}
	
    return 0;
}
