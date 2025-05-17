#pragma once  
#include <iostream>  
#include "Subscription.h"
#include "Coatch.h"  
#include "WorkoutPlan.h"  
#include "Trainee.h"  
#include <unordered_map> 
#include <string>  
#include "Hall.h"  
#include "Court.h"
#include "GymClass.h"
#include "Manager.h"
#include "Receptionist.h"
#include "Booking.h"
#include"Data_Base.h"
#include <xlnt/xlnt.hpp>
using namespace std;  
class SystemManager 
{  
	Data_Base* db = Data_Base::GetDB();
	xlnt::workbook GymWB = db->getGym_Padel_DB("Gym_Padel_DB.xlsx");
	xlnt::worksheet ManagerWS = db->GetManager("Manager");
	xlnt::worksheet TraineeWS = db->GetTrainee("Trainee");
	xlnt::worksheet CoatchWS = db->GetCoach("Coatch");
	xlnt::worksheet ClassWS = db->GetGymClass("GymClass");
	xlnt::worksheet HallSystemWS = db->GetHallSystem("HallSystem");
	xlnt::worksheet WorkoutPlanWS = db->GetWorkoutPlan("WorkoutPlan");
	xlnt::worksheet ReceptionistWS = db->GetReceptionist("Receptionist");
	xlnt::worksheet CourtWS = db->GetCourt("Court");
	xlnt::worksheet BookingWS = db->GetBooking("Booking");
	xlnt::worksheet SubscriptionWS = db->GetSubscription("Subscription");


	/// Trainee
	unordered_map<int, Trainee> Load_Trainee(xlnt::worksheet& ws);
    void Save_Trainee(xlnt::worksheet& ws, unordered_map<int, Trainee> traineeList);
	int GetMaxTraineeID(xlnt::worksheet& ws);
    /// Coatch
    unordered_map<string, Coatch> Load_Coatch(xlnt::worksheet & ws);
    void Save_Coatch(xlnt::worksheet &ws, unordered_map<string, Coatch> coatchList);
    /// Receptionist
	unordered_map<string, Receptionist> Load_Receptionist(xlnt::worksheet & ws);
    void Save_Receptionist(xlnt::worksheet &ws, unordered_map<string, Receptionist> receptionistList);
	/// Manager
	unordered_map<string, Manager> Load_Manager(xlnt::worksheet & ws);
    void Save_Manager(xlnt::worksheet &ws, unordered_map<string, Manager> managerList);
	/// Class
	unordered_map<string, GymClass> Load_GymClass(xlnt::worksheet & ws);
    void Save_GymClass(xlnt::worksheet &ws, unordered_map<string, GymClass> classList);
	/// Hall
	unordered_map<string, Hall> Load_Hall(xlnt::worksheet & ws);
    void Save_Hall(xlnt::worksheet &ws, unordered_map<string, Hall> hallList);
	/// workoutPlan
	unordered_map<string, WorkoutPlan> Load_WorkoutPlan(xlnt::worksheet & ws);
    void Save_WorkoutPlan(xlnt::worksheet &ws, unordered_map<string, WorkoutPlan> workoutPlanList);
	/// Court
	unordered_map<string, Court> Load_Court(xlnt::worksheet & ws);
	void Save_Court(xlnt::worksheet &ws, unordered_map<string, Court> CourtList);
	/// Booking
	unordered_map<string, Booking> Load_Booking(xlnt::worksheet & ws);
	void Save_Booking(xlnt::worksheet &ws, unordered_map<string, Booking> BookingList);
	/// Subscription
	unordered_map<int, Subscription> Load_Subscription(xlnt::worksheet & ws);
	void Save_Subscription(xlnt::worksheet &ws, unordered_map<int, Subscription> SubscriptionList);
    
public:
	unordered_map<int ,Trainee> traineeList;
	unordered_map<string,Coatch> coatchList;
	unordered_map<string, Receptionist> receptionistList;
	unordered_map<string, Manager> managerList;
	unordered_map<string,GymClass> classList;
	unordered_map<string, Hall> hallList;
	unordered_map<string, WorkoutPlan> workoutPlanList;
	unordered_map<string, Court> CourtList;
	unordered_map<string, Booking> BookingList;
	unordered_map<int, Subscription> SubscriptionList;
	int maxTraineeID = 0;


	void Load_All_Data();
	void Save_All_Data();

};
