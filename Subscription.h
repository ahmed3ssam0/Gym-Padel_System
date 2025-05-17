#pragma once
#include <iostream>
using namespace std;

class Subscription {
	static int id;
	int subId;
	int traineeId;
    string startDate, endDate;
    int period; //period[1 year, 6 months, 3 months] only 3 values (1,6,3)
    float price;

    public:
    Subscription();
    Subscription(string startDate, int period);
    ~Subscription();

    int getID();
	int getTraineeID();
    string getStartDate();
    string getEndDate();
    int getPeriod();
    float getPrice();

	void setID(int id);
	void setTraineeID(int id);
    void setStartDate(string startDate);
    void setEndDate(string endDate);
    void setPeriod(int period);
    void setPrice(float price);

    string end_date_calc(string startDate, int period);
    float manage_discount(float price);
    void display();
	int return_year(string date);
	int return_month(string date);

};

