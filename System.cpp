#include <xlnt/xlnt.hpp>
#include "System.h"
#include <iostream>

//Trainee
////lad
unordered_map<int, Trainee> SystemManager::Load_Trainee(xlnt::worksheet& ws) {
    unordered_map<int, Trainee> traineeList;

    for (auto row : ws.rows(false)) {
        //Skip the header row
        if (row[0].to_string() == "ID") continue;
        Trainee t;
        t.setId(row[0].value<int>());                      // A - ID
        t.setName(row[1].to_string());                     // B - Name
        t.setPhone(row[2].to_string());                    // C - Phone Number
        t.setGender(row[3].to_string());                   // D - Gender
        t.setDateOfBirth(row[4].to_string());              // E - Date of Birth
        t.setEmail(row[5].to_string());                    // F - Email
        t.setPassword(row[6].to_string());                 // G - Password
        t.setIsVIP(row[7].value<bool>());
        traineeList[t.getId()] = t;
    }

    return traineeList;
}

//save
void SystemManager::Save_Trainee(xlnt::worksheet& ws, unordered_map<int, Trainee> traineeList) {
    //// Clear all existing cells
    for (auto row : ws.rows(false))
    {
        for (auto cell : row)
        {
            cell.clear_value();
        }
    }

    // // Add header row
    ws.cell("A1").value("ID");
    ws.cell("B1").value("Name");
    ws.cell("C1").value("Phone");
    ws.cell("D1").value("Gender");
    ws.cell("E1").value("Date of Birth");
    ws.cell("F1").value("Email");
    ws.cell("G1").value("Password");
    ws.cell("H1").value("IsVIP");

    int row_num = 2;
    for (const auto& pair : traineeList) {
        int id = pair.first;
        Trainee t = pair.second;
        ws.cell("A" + std::to_string(row_num)).value(t.getId());
        ws.cell("B" + std::to_string(row_num)).value(t.getName());
        ws.cell("C" + std::to_string(row_num)).value(t.getPhone());
        ws.cell("D" + std::to_string(row_num)).value(t.getGender());
        ws.cell("E" + std::to_string(row_num)).value(t.getDateOfBirth());
        ws.cell("F" + std::to_string(row_num)).value(t.getEmail());
        ws.cell("G" + std::to_string(row_num)).value(t.getPassword());
        ws.cell("H" + std::to_string(row_num)).value(t.getIsVIP());

        row_num++;
    }
}

//get id
int SystemManager::GetMaxTraineeID(xlnt::worksheet& ws) {
    int maxId = 0;
    for (auto row : ws.rows(false)) {
        if (row[0].to_string() == "ID") continue; // Skip header
        int id = row[0].value<int>();
        if (id > maxId) {
            maxId = id;
        }
    }
    return maxId;
}

//Coatch
/////lad
unordered_map<string, Coatch> SystemManager::Load_Coatch(xlnt::worksheet& ws) {
    unordered_map<string, Coatch> coatchList;

    for (auto row : ws.rows(false)) {
        if (row[0].to_string() == "ID") continue;

        Coatch c;
        c.setid(row[0].value<int>());
        c.setname(row[1].to_string());
        c.setpassword(row[2].to_string());
        c.setSalary(row[3].value<float>());

        coatchList[row[0].to_string()] = c;
    }

    return coatchList;
}

//save
void SystemManager::Save_Coatch(xlnt::worksheet& ws, unordered_map<string, Coatch> coatchList) {
    // Clear all existing cells
    for (auto row : ws.rows(false))
    {
        for (auto cell : row)
        {
            cell.clear_value();
        }
    }

    // Add header row
    ws.cell("A1").value("ID");
    ws.cell("B1").value("Name");
    ws.cell("C1").value("Password");
    ws.cell("D1").value("Salary");

    int row_num = 2;
    for (const auto& pair : coatchList) {
        string id = pair.first;
        Coatch c = pair.second;
        if (c.getid()[0] == '\0')
            break;
        ws.cell("A" + std::to_string(row_num)).value(c.getid());
        ws.cell("B" + std::to_string(row_num)).value(c.getname());

        ws.cell("C" + std::to_string(row_num)).value(c.getpassword());

        ws.cell("D" + std::to_string(row_num)).value(c.getSalary());
        row_num++;
    }
}



//Receptionist
//lad
unordered_map<string, Receptionist> SystemManager::Load_Receptionist(xlnt::worksheet& ws) {
    unordered_map<string, Receptionist> receptionistList;

    for (auto row : ws.rows(false)) {
        if (row[0].to_string() == "ID") continue;

        Receptionist r;
        r.setid(row[0].value<int>());
        r.setname(row[1].to_string());
        r.setpassword(row[2].to_string());
        r.setSalary(row[3].value<float>());

        receptionistList[row[0].to_string()] = r;
    }

    return receptionistList;
}

//save
void SystemManager::Save_Receptionist(xlnt::worksheet& ws, unordered_map<string, Receptionist> receptionistList) {
    // Clear all existing cells
    for (auto row : ws.rows(false))
    {
        for (auto cell : row)
        {
            cell.clear_value();
        }
    }

    // Add header row
    ws.cell("A1").value("ID");
    ws.cell("B1").value("Name");
    ws.cell("C1").value("Password");
    ws.cell("D1").value("Salary");

    int row_num = 2;
    for (const auto& pair : receptionistList) {
        string id = pair.first;
        Receptionist r = pair.second;
        if (r.getid()[0] == '\0')
            break;
        ws.cell("A" + std::to_string(row_num)).value(r.getid());
        ws.cell("B" + std::to_string(row_num)).value(r.getname());
        ws.cell("C" + std::to_string(row_num)).value(r.getpassword());
        ws.cell("D" + std::to_string(row_num)).value(r.getSalary());

        row_num++;
    }
}


//Manager
//lad

unordered_map<string, Manager> SystemManager::Load_Manager(xlnt::worksheet& ws) {
    unordered_map<string, Manager> managerList;

    for (auto row : ws.rows(false)) {
        if (row[0].to_string() == "ID") continue;

        Manager m;
        m.setid(row[0].to_string());
        m.setname(row[1].to_string());
        m.setpassword(row[2].to_string());

        managerList[row[0].to_string()] = m;
    }

    return managerList;
}

//save
void SystemManager::Save_Manager(xlnt::worksheet& ws, unordered_map<string, Manager> managerList) {
    // Clear all existing cells
    for (auto row : ws.rows(false))
    {
        for (auto cell : row)
        {
            cell.clear_value();
        }
    }

    // Add header row
    ws.cell("A1").value("ID");
    ws.cell("B1").value("Name");
    ws.cell("C1").value("Password");

    int row_num = 2;
    for (const auto& pair : managerList) {
        string id = pair.first;
        Manager m = pair.second;
        if (m.getid()[0] == '\0')
            break;
        ws.cell("A" + std::to_string(row_num)).value(m.getid());
        ws.cell("B" + std::to_string(row_num)).value(m.getname());
        ws.cell("C" + std::to_string(row_num)).value(m.getpassword());

        row_num++;
    }
}



//Gym Class
//lad
unordered_map<string, GymClass> SystemManager::Load_GymClass(xlnt::worksheet& ws) {
    unordered_map<string, GymClass> classList;

    for (auto row : ws.rows(false)) {
        if (row[0].to_string() == "ID") continue;

        GymClass g;
        g.setName(row[0].to_string());
        g.setCapacity(row[1].value<int>());
        g.setStartTime(row[2].to_string());
        g.setEndTime(row[3].to_string());
        g.setTimePeriod(row[4].value<float>());
        g.setNumberOfSessions(row[5].value<int>());
        g.setType(row[6].value<bool>());
        g.setClassCoach(row[7].to_string());

        classList[row[0].to_string()] = g;
    }

    return classList;
}

//save
void SystemManager::Save_GymClass(xlnt::worksheet& ws, unordered_map<string, GymClass> classList) {
    // Clear all existing cells
    for (auto row : ws.rows(false))
    {
        for (auto cell : row)
        {
            cell.clear_value();
        }
    }

    // Add header row
    ws.cell("A1").value("ID");
    ws.cell("B1").value("Capacity");
    ws.cell("C1").value("Start Time");
    ws.cell("D1").value("End Time");
    ws.cell("E1").value("Time Period");
    ws.cell("F1").value("Number Of Sessions");
    ws.cell("G1").value("Type");
    ws.cell("H1").value("Class Coach");

    int row_num = 2;
    for (const auto& pair : classList) {
        string id = pair.first;
        GymClass g = pair.second;
        if (g.getName()[0] == '\0')
            break;
        ws.cell("A" + std::to_string(row_num)).value(g.getName());
        ws.cell("B" + std::to_string(row_num)).value(g.getCapacity());
        ws.cell("C" + std::to_string(row_num)).value(g.getStartTime());
        ws.cell("D" + std::to_string(row_num)).value(g.getEndTime());
        ws.cell("E" + std::to_string(row_num)).value(g.getTimePeriod());
        ws.cell("F" + std::to_string(row_num)).value(g.getNumberOfSessions());
        ws.cell("G" + std::to_string(row_num)).value(g.getType());
        ws.cell("H" + std::to_string(row_num)).value(g.getClassCoach());

        row_num++;
    }
}

//Hall
//lad
unordered_map<string, Hall> SystemManager::Load_Hall(xlnt::worksheet& ws) {
    unordered_map<string, Hall> hallList;

    for (auto row : ws.rows(false)) {
        if (row[0].to_string() == "ID") continue;

        Hall h;
        h.setCode(row[0].to_string());
        h.setName(row[1].to_string());

        hallList[row[0].to_string()] = h;
    }

    return hallList;
}

//save
void SystemManager::Save_Hall(xlnt::worksheet& ws, unordered_map<string, Hall> hallList) {
    // Clear all existing cells
    for (auto row : ws.rows(false))
    {
        for (auto cell : row)
        {
            cell.clear_value();
        }
    }

    // Add header row
    ws.cell("A1").value("ID");
    ws.cell("B1").value("Name");

    int row_num = 2;
    for (const auto& pair : hallList) {
        string id = pair.first;
        Hall h = pair.second;
        if (h.getCode()[0] == '\0')
            break;
        ws.cell("A" + std::to_string(row_num)).value(h.getCode());
        ws.cell("B" + std::to_string(row_num)).value(h.getName());

        row_num++;
    }
}

// Workout Plan
//lad
unordered_map<string, WorkoutPlan> SystemManager::Load_WorkoutPlan(xlnt::worksheet& ws) {
    unordered_map<string, WorkoutPlan> workoutPlanList;

    for (auto row : ws.rows(false)) {
        if (row[0].to_string() == "ID") continue;

        WorkoutPlan wp;
        wp.setName(row[0].to_string());
        wp.setHoursPerDay(row[1].value<float>());
        wp.setIntensity(row[2].to_string());
        wp.setLostCalories(row[3].value<float>());
        wp.setClass_name_code(row[4].to_string());


        workoutPlanList[row[0].to_string()] = wp;
    }

    return workoutPlanList;
}

//save
void SystemManager::Save_WorkoutPlan(xlnt::worksheet& ws, unordered_map<string, WorkoutPlan> workoutPlanList) {
    // Clear all existing cells
    for (auto row : ws.rows(false))
    {
        for (auto cell : row)
        {
            cell.clear_value();
        }
    }

    // Add header row
    ws.cell("A1").value("ID");
    ws.cell("B1").value("Hours Per Day");
    ws.cell("C1").value("Intensity");
    ws.cell("D1").value("Lost Calories");
    ws.cell("E1").value("Class Name Code");

    int row_num = 2;

    for (const auto& pair : workoutPlanList) {
        string id = pair.first;
        WorkoutPlan wp = pair.second;
        if (wp.getName()[0] == '\0')
            break;
        ws.cell("A" + std::to_string(row_num)).value(wp.getName());
        ws.cell("B" + std::to_string(row_num)).value(wp.getHoursPerDay());
        ws.cell("C" + std::to_string(row_num)).value(wp.getIntensity());
        ws.cell("D" + std::to_string(row_num)).value(wp.getLostCalories());
        ws.cell("E" + std::to_string(row_num)).value(wp.getClass_name_code());
        row_num++;
    }
}

//Court
//lad
unordered_map<string, Court> SystemManager::Load_Court(xlnt::worksheet& ws) {
    unordered_map<string, Court> courtList;

    for (auto row : ws.rows(false)) {
        if (row[0].to_string() == "Name Code") continue;

        Court c;
        c.setName(row[0].to_string());
        c.setPrice(row[1].value<float>());
        c.setLocation(row[2].to_string());
        c.setIsAvailable(row[3].value<bool>());

        courtList[row[0].to_string()] = c;
    }

    return courtList;
}

//save
void SystemManager::Save_Court(xlnt::worksheet& ws, unordered_map<string, Court> courtList) {
    // Clear all existing cells
    for (auto row : ws.rows(false))
    {
        for (auto cell : row)
        {
            cell.clear_value();
        }
    }

    // Add header row
    ws.cell("A1").value("Name Code");
    ws.cell("B1").value("Price");
    ws.cell("C1").value("Location");
    ws.cell("D1").value("Is Available");

    int row_num = 2;
    for (const auto& pair : courtList) {
        string id = pair.first;
        Court c = pair.second;
        if (c.getName()[0] == '\0')
            break;
        ws.cell("A" + std::to_string(row_num)).value(c.getName());
        ws.cell("B" + std::to_string(row_num)).value(c.getPrice());
        ws.cell("C" + std::to_string(row_num)).value(c.getLocation());
        ws.cell("D" + std::to_string(row_num)).value(c.getIsAvailable());

        row_num++;
    }
}

//Booking
//lad

unordered_map<string, Booking> SystemManager::Load_Booking(xlnt::worksheet& ws) {
    unordered_map<string, Booking> bookingList;

    for (auto row : ws.rows(false)) {
        if (row[0].to_string() == "ID") continue;

        Booking b;


        b.setId(row[0].to_string());
        b.setDay(row[1].to_string());
        b.setPrice(row[2].value<float>());
        b.setStartTime(row[3].to_string());
        b.setEndTime(row[4].to_string());
        b.setTimePeriod(row[5].value<float>());
        b.setIsConfirmed(row[6].value<bool>());
        bookingList[row[0].to_string()] = b;
    }

    return bookingList;
}

//save
void SystemManager::Save_Booking(xlnt::worksheet& ws, unordered_map<string, Booking> bookingList) {
    // Clear all existing cells
    for (auto row : ws.rows(false))
    {
        for (auto cell : row)
        {
            cell.clear_value();
        }
    }

    // Add header row
    ws.cell("A1").value("ID");
    ws.cell("B1").value("Day");
    ws.cell("C1").value("Price");
    ws.cell("D1").value("Start Time");
    ws.cell("E1").value("End Time");
    ws.cell("F1").value("Time Period");
    ws.cell("G1").value("Is Confirmed");

    int row_num = 2;

    for (const auto& pair : bookingList) {
        string id = pair.first;
        Booking b = pair.second;
        if (b.getId()[0] == '\0')
            break;

        ws.cell("A" + std::to_string(row_num)).value(b.getId());
        ws.cell("B" + std::to_string(row_num)).value(b.getDay());
        ws.cell("C" + std::to_string(row_num)).value(b.getPrice());
        ws.cell("D" + std::to_string(row_num)).value(b.getStartTime());
        ws.cell("E" + std::to_string(row_num)).value(b.getEndTime());
        ws.cell("F" + std::to_string(row_num)).value(b.getTimePeriod());
        ws.cell("G" + std::to_string(row_num)).value(b.getIsConfirmed());

        row_num++;
    }
}


unordered_map<int, Subscription> SystemManager::Load_Subscription(xlnt::worksheet& ws) {
    unordered_map<int, Subscription> subscriptionList;


    for (auto row : ws.rows(false)) {
        if (row[0].to_string() == "ID") continue;

        Subscription s;
        s.setID(row[0].value<int>());
        s.setTraineeID(row[1].value<int>());
        s.setStartDate(row[2].to_string());
        s.setPeriod(row[3].value<int>());
        s.setEndDate(row[4].to_string());
        s.setPrice(row[5].value<float>());

        subscriptionList[row[0].value<int>()] = s;
    }

    return subscriptionList;
}

//save
void SystemManager::Save_Subscription(xlnt::worksheet& ws, unordered_map<int, Subscription> subscriptionList) {
    // Clear all existing cells
    for (auto row : ws.rows(false))
    {
        for (auto cell : row)
        {
            cell.clear_value();
        }
    }

    // Add header row
    ws.cell("A1").value("ID");
    ws.cell("B1").value("Trainee ID");
    ws.cell("C1").value("Start Date");
    ws.cell("D1").value("Period");
    ws.cell("E1").value("End Date");
    ws.cell("F1").value("Price");
    cout << "SUBSCRIPTION \n";
    int row_num = 2;

    for (const auto& pair : subscriptionList) {
        int id = pair.first;
        Subscription s = pair.second;
        ws.cell("A" + std::to_string(row_num)).value(s.getID());
        ws.cell("B" + std::to_string(row_num)).value(s.getTraineeID());
        ws.cell("C" + std::to_string(row_num)).value(s.getStartDate());
        ws.cell("D" + std::to_string(row_num)).value(s.getPeriod());
        ws.cell("E" + std::to_string(row_num)).value(s.getEndDate());
        ws.cell("F" + std::to_string(row_num)).value(s.getPrice());

        row_num++;
    }
}


void SystemManager::Load_All_Data() {
    xlnt::workbook& wb = this->db->getGym_Padel_DB("Gym_Padel_DB.xlsx");

    this->traineeList = this->Load_Trainee(this->db->GetTrainee("Trainees"));
    cout << 1;
    this->maxTraineeID = this->GetMaxTraineeID(this->db->GetTrainee("Trainees"));
    cout << 2;
    this->coatchList = this->Load_Coatch(this->db->GetCoach("Coatch"));
    cout << 3;
    this->receptionistList = this->Load_Receptionist(this->db->GetReceptionist("Receptionist"));
    cout << 4;
    this->managerList = this->Load_Manager(this->db->GetManager("Manager"));
    cout << 5;
    this->classList = this->Load_GymClass(this->db->GetGymClass("GymClass"));
    cout << 6;
    this->hallList = this->Load_Hall(this->db->GetHallSystem("HallSystem"));
    cout << 7;
    this->workoutPlanList = this->Load_WorkoutPlan(this->db->GetWorkoutPlan("WorkoutPlan"));
    cout << 8;
    this->CourtList = this->Load_Court(this->db->GetCourt("Court"));
    cout << 9;
    this->BookingList = this->Load_Booking(this->db->GetBooking("Booking"));
    cout << 10;
    this->SubscriptionList = this->Load_Subscription(this->db->GetSubscription("Subscription"));
    cout << 11;
    cout << "LOADED \n";
}

void SystemManager::Save_All_Data() {
    cout << "SAVING \n";
    //Update worksheets in existing workbook
    this->Save_Trainee(this->db->GetTrainee("Trainees"), this->traineeList);
    cout << 1;
    this->Save_Coatch(this->db->GetCoach("Coatch"), this->coatchList);
    cout << 2;
    this->Save_Receptionist(this->db->GetReceptionist("Receptionist"), this->receptionistList);
    cout << 3;
    this->Save_Manager(this->db->GetManager("Manager"), this->managerList);
    cout << 4;
    this->Save_GymClass(this->db->GetGymClass("GymClass"), this->classList);
    cout << 5;
    this->Save_Hall(this->db->GetHallSystem("HallSystem"), this->hallList);
    cout << 6;
    this->Save_WorkoutPlan(this->db->GetWorkoutPlan("WorkoutPlan"), this->workoutPlanList);
    cout << 7;
    this->Save_Court(this->db->GetCourt("Court"), this->CourtList);
    cout << 8;
    this->Save_Booking(this->db->GetBooking("Booking"), this->BookingList);
    cout << 9;
    this->Save_Subscription(this->db->GetSubscription("Subscription"), this->SubscriptionList);
    this->db->SaveGym_Padel_DB("Gym_Padel_DB.xlsx");
    cout << "SAVED \n";
}