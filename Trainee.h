#pragma once
#include <iostream>
#include <list>

#include "Subscription.h"
#include "WorkoutPlan.h"
using namespace std;

class GymClass;

class Trainee {
    int userId;
    static int id;
    string name, phone, gender, dateOfBirth, email, password;
    bool isVIP; //1 for gym, 0 for padel
    Subscription subscription;
    list<WorkoutPlan> workout_history;

    public:
    Trainee(string name, string phone, string gender, string dateOfBirth, string email, string password, bool isVIP);
    Trainee();
    ~Trainee();

    int getId();
    string getName();
    string getPhone();
    string getGender();
    string getDateOfBirth();
    string getEmail();
    string getPassword();
    bool getIsVIP();
    Subscription getSubscription();
	list<WorkoutPlan> getWorkoutHistory();

	void setId(int id);
    void setName(string name);
    void setPhone(string phone);
    void setGender(string gender);
    void setDateOfBirth(string dateOfBirth);
    void setEmail(string email);
    void setPassword(string password);
    void setIsVIP(bool isVIP);
	void setSubscription(Subscription subscription);
	void setWorkoutHistory(list<WorkoutPlan> workout_history);

    void subscribe(Subscription subscription);
    void renew_subscription(int period);
    void view_workout_history();
    void delete_subscription();

    void addWorkoutPlan(WorkoutPlan wp);
    void removeWorkoutPlan(WorkoutPlan wp);
};
