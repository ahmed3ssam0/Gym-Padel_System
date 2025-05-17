#include "Trainee.h"

int Trainee::id = 0;

Trainee::Trainee() {
    userId = ++id;
}

Trainee::Trainee(string name, string phone, string gender, string dateOfBirth, string email, string password, bool isVIP) 
        : subscription(subscription) {
    userId = ++id;
    this->name = name;
    this->phone = phone;
    this->gender = gender;
    this->dateOfBirth = dateOfBirth;
    this->email = email;
    this->password = password;
    this->isVIP = isVIP;
}

Trainee::~Trainee() {
    this->userId = 0;
    this->name.clear();
    this->phone.clear();
    this->gender.clear();
    this->dateOfBirth.clear();
    this->email.clear();
    this->password.clear();
}


int Trainee::getId() { return this->userId; }
string Trainee::getName() { return this->name; }
string Trainee::getPhone() { return this->phone; }
string Trainee::getGender() { return this->gender; }
string Trainee::getDateOfBirth() { return this->dateOfBirth; }
string Trainee::getEmail() { return this->email; }
string Trainee::getPassword() { return this->password; }
bool Trainee::getIsVIP() { return this->isVIP; }
Subscription Trainee::getSubscription() { return this->subscription; }
list<WorkoutPlan> Trainee::getWorkoutHistory() { return this->workout_history; }

void Trainee::setId(int id) { this->userId = id; }
void Trainee::setName(string name) { this->name = name; }
void Trainee::setPhone(string phone) { this->phone = phone; }
void Trainee::setGender(string gender) { this->gender = gender; }
void Trainee::setDateOfBirth(string dateOfBirth) { this->dateOfBirth = dateOfBirth; }
void Trainee::setEmail(string email) { this->email = email; }
void Trainee::setPassword(string password) { this->password = password; }
void Trainee::setIsVIP(bool isVIP) { this->isVIP = isVIP; }
void Trainee::setSubscription(Subscription subscription) { this->subscription = subscription; }
void Trainee::setWorkoutHistory(list<WorkoutPlan> workout_history) { this->workout_history = workout_history; }

void Trainee::subscribe(Subscription sub) {

    if (isVIP) {
        sub.setPrice((sub.getPrice() + 200) * sub.getPeriod());
        sub.setPrice(sub.manage_discount(sub.getPrice()));
	}
	else {
		sub.setPrice(sub.getPrice() * sub.getPeriod());
	}
    subscription = sub;
    sub.display();
}

void Trainee::renew_subscription(int period) {
    if (period == 1) subscription.setPrice(3000);
    else subscription.setPrice(300);
	if (subscription.return_year(subscription.getStartDate()) < subscription.return_year(subscription.getEndDate())) {
		if (subscription.return_month(subscription.getStartDate()) < subscription.return_month(subscription.getEndDate())) {
			cout << "Your Subscription is still active." << endl;
			return;
		}
		if ((subscription.return_month(subscription.getStartDate()) == subscription.return_month(subscription.getEndDate())) && subscription.return_year(subscription.getStartDate()) == subscription.return_year(subscription.getEndDate())) {
            subscription.setStartDate(subscription.getEndDate());
            subscription.setPeriod(period);

            string newEndDate = subscription.end_date_calc(subscription.getStartDate(), period);
            subscription.setEndDate(newEndDate);
            if (isVIP) subscription.setPrice(subscription.manage_discount((subscription.getPrice() * period)));
            else subscription.setPrice((subscription.getPrice() * period));
            subscription.display();
		}
	}
	subscription.setStartDate(subscription.getEndDate());
    subscription.setPeriod(period);

    string newEndDate = subscription.end_date_calc(subscription.getStartDate(), period);
	subscription.setEndDate(newEndDate);
    if (isVIP) subscription.setPrice(subscription.manage_discount((subscription.getPrice() * period)));
	else subscription.setPrice((subscription.getPrice() * period));
    subscription.display();
}

void Trainee::delete_subscription() {
    subscription = Subscription();
    cout << "Subscription deleted successfully." << endl;
}

void Trainee::view_workout_history() {
    for(auto i : workout_history) {
        cout << i.getName() << ", " << i.getHoursPerDay() << ", " << i.getType() << ", " << i.getIntensity() << ", " << i.getLostCalories() << ", " << endl;
    }
}

void Trainee::addWorkoutPlan(WorkoutPlan wp) {
    workout_history.push_back(wp);
}
void Trainee::removeWorkoutPlan(WorkoutPlan wp) {
    for (auto it = workout_history.begin(); it != workout_history.end(); ++it) {
        if (it->getName() == wp.getName()) {
            workout_history.erase(it);
            break;
        }
    }
}
