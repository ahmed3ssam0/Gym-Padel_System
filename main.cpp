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
#include "ManagerTabs.h"
#include "ReceptionistForm.h"
#include "Login1.h"

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
	Padel padel;
	sys.Load_All_Data();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Login1(&sys, &padel));
	sys.Save_All_Data();
    return 0;
}
