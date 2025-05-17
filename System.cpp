#include "System.h"
#include <iostream>

// Trainee
//load
unordered_map<int, Trainee> SystemManager::Load_Trainee(xlnt::worksheet& ws) {
    unordered_map<int, Trainee> traineeList;

    for (auto row : ws.rows(false)) {
        // Skip the header row
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

    auto last_row = ws.highest_row();
    for (int row = 2; row <= last_row; row++) {
        for (int col = 1; col <= 7; col++) {
            auto cell_ref = xlnt::cell_reference(col, row);
            if (ws.has_cell(cell_ref)) {
                ws.cell(cell_ref).clear_value();
            }
        }
    }

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

/// Coatch
//load
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
    auto last_row = ws.highest_row();
    for (int row = 2; row <= last_row; row++) {
        for (int col = 1; col <= 4; col++) {
            auto cell_ref = xlnt::cell_reference(col, row);
            if (ws.has_cell(cell_ref)) {
                ws.cell(cell_ref).clear_value();
            }
        }
    }

    int row_num = 2;
    for (const auto& pair : coatchList) {
        string id = pair.first;
        Coatch c = pair.second;

        ws.cell("A" + std::to_string(row_num)).value(c.getid());
        ws.cell("B" + std::to_string(row_num)).value(c.getname());
        ws.cell("C" + std::to_string(row_num)).value(c.getpassword());
        ws.cell("D" + std::to_string(row_num)).value(c.getSalary());

        row_num++;
    }
}



// Receptionist
//load
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
    auto last_row = ws.highest_row();
    for (int row = 2; row <= last_row; row++) {
        for (int col = 1; col <= 4; col++) {
            auto cell_ref = xlnt::cell_reference(col, row);
            if (ws.has_cell(cell_ref)) {
                ws.cell(cell_ref).clear_value();
            }
        }
    }

    int row_num = 2;
    for (const auto& pair : receptionistList) {
        string id = pair.first;
        Receptionist r = pair.second;

        ws.cell("A" + std::to_string(row_num)).value(r.getid());
        ws.cell("B" + std::to_string(row_num)).value(r.getname());
        ws.cell("C" + std::to_string(row_num)).value(r.getpassword());
        ws.cell("D" + std::to_string(row_num)).value(r.getSalary());

        row_num++;
    }
}


// Manager
//load

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
    auto last_row = ws.highest_row();
    for (int row = 2; row <= last_row; row++) {
        for (int col = 1; col <= 3; col++) {
            auto cell_ref = xlnt::cell_reference(col, row);
            if (ws.has_cell(cell_ref)) {
                ws.cell(cell_ref).clear_value();
            }
        }
    }

    int row_num = 2;
    for (const auto& pair : managerList) {
        string id = pair.first;
        int row_num = 2;
        for (const auto& pair : managerList) {
            string id = pair.first;
            Manager m = pair.second;

            ws.cell("A" + std::to_string(row_num)).value(m.getid());
            ws.cell("B" + std::to_string(row_num)).value(m.getname());
            ws.cell("C" + std::to_string(row_num)).value(m.getpassword());

            row_num++;
        }

    }
}



// Gym Class
//load
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
    auto last_row = ws.highest_row();
    for (int row = 2; row <= last_row; row++) {
        for (int col = 1; col <= 8; col++) {
            auto cell_ref = xlnt::cell_reference(col, row);
            if (ws.has_cell(cell_ref)) {
                ws.cell(cell_ref).clear_value();
            }
        }
    }

    int row_num = 2;
    for (const auto& pair : classList) {
        string id = pair.first;
        GymClass g = pair.second;

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

// Hall
//load
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
    auto last_row = ws.highest_row();
    for (int row = 2; row <= last_row; row++) {
        for (int col = 1; col <= 2; col++) {
            auto cell_ref = xlnt::cell_reference(col, row);
            if (ws.has_cell(cell_ref)) {
                ws.cell(cell_ref).clear_value();
            }
        }
    }

    int row_num = 2;
    for (const auto& pair : hallList) {
        string id = pair.first;
        Hall h = pair.second;

        ws.cell("A" + std::to_string(row_num)).value(h.getCode());
        ws.cell("B" + std::to_string(row_num)).value(h.getName());

        row_num++;
    }
}

// Workout Plan
//load
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
    auto last_row = ws.highest_row();
    for (int row = 2; row <= last_row; row++) {
        for (int col = 1; col <= 5; col++) {
            auto cell_ref = xlnt::cell_reference(col, row);
            if (ws.has_cell(cell_ref)) {
                ws.cell(cell_ref).clear_value();
            }
        }
    }

    int row_num = 2;

    for (const auto& pair : workoutPlanList) {
        string id = pair.first;
        WorkoutPlan wp = pair.second;

        ws.cell("A" + std::to_string(row_num)).value(wp.getName());
        ws.cell("B" + std::to_string(row_num)).value(wp.getHoursPerDay());
        ws.cell("C" + std::to_string(row_num)).value(wp.getIntensity());
        ws.cell("D" + std::to_string(row_num)).value(wp.getLostCalories());
        ws.cell("E" + std::to_string(row_num)).value(wp.getClass_name_code());
        row_num++;
    }
}

// Court
//load
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
    auto last_row = ws.highest_row();
    for (int row = 2; row <= last_row; row++) {
        for (int col = 1; col <= 4; col++) {
            auto cell_ref = xlnt::cell_reference(col, row);
            if (ws.has_cell(cell_ref)) {
                ws.cell(cell_ref).clear_value();
            }
        }
    }


    int row_num = 2;
    for (const auto& pair : courtList) {
        string id = pair.first;
        Court c = pair.second;

        ws.cell("A" + std::to_string(row_num)).value(c.getName());
        ws.cell("B" + std::to_string(row_num)).value(c.getPrice());
        ws.cell("C" + std::to_string(row_num)).value(c.getLocation());
        ws.cell("D" + std::to_string(row_num)).value(c.getIsAvailable());

        row_num++;
    }
}

// Booking
//load

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
    auto last_row = ws.highest_row();
    for (int row = 2; row <= last_row; row++) {
        for (int col = 1; col <= 7; col++) {
            auto cell_ref = xlnt::cell_reference(col, row);
            if (ws.has_cell(cell_ref)) {
                ws.cell(cell_ref).clear_value();
            }
        }
    }

    int row_num = 2;

    for (const auto& pair : bookingList) {
        string id = pair.first;
        Booking b = pair.second;

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


// Subscription

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

        subscriptionList[std::stoi(row[0].to_string())] = s;
    }

    return subscriptionList;
}

//save
void SystemManager::Save_Subscription(xlnt::worksheet& ws, unordered_map<int, Subscription> subscriptionList) {
    auto last_row = ws.highest_row();
    for (int row = 2; row <= last_row; row++) {
        for (int col = 1; col <= 6; col++) {
            auto cell_ref = xlnt::cell_reference(col, row);
            if (ws.has_cell(cell_ref)) {
                ws.cell(cell_ref).clear_value();
            }
        }
    }

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
	this->maxTraineeID = this->GetMaxTraineeID(this->db->GetTrainee("Trainees"));
    this->coatchList = this->Load_Coatch(this->db->GetCoach("Coatch"));
    this->receptionistList = this->Load_Receptionist(this->db->GetReceptionist("Receptionist"));
    this->managerList = this->Load_Manager(this->db->GetManager("Manager"));
    this->classList = this->Load_GymClass(this->db->GetGymClass("GymClass"));
    this->hallList = this->Load_Hall(this->db->GetHallSystem("HallSystem"));
    this->workoutPlanList = this->Load_WorkoutPlan(this->db->GetWorkoutPlan("WorkoutPlan"));
    this->CourtList = this->Load_Court(this->db->GetCourt("Court"));
    this->BookingList = this->Load_Booking(this->db->GetBooking("Booking"));
    this->SubscriptionList = this->Load_Subscription(this->db->GetSubscription("Subscription"));
    cout << "LOADED \n";
}

void SystemManager::Save_All_Data() {

    // Update worksheets in existing workbook
    this->Save_Trainee(this->db->GetTrainee("Trainees"), this->traineeList);
    this->Save_Coatch(this->db->GetCoach("Coatch"), this->coatchList);
    this->Save_Receptionist(this->db->GetReceptionist("Receptionist"), this->receptionistList);
    this->Save_Manager(this->db->GetManager("Manager"), this->managerList);
    this->Save_GymClass(this->db->GetGymClass("GymClass"), this->classList);
    this->Save_Hall(this->db->GetHallSystem("HallSystem"), this->hallList);
    this->Save_WorkoutPlan(this->db->GetWorkoutPlan("WorkoutPlan"), this->workoutPlanList);
    this->Save_Court(this->db->GetCourt("Court"), this->CourtList);
    this->Save_Booking(this->db->GetBooking("Booking"), this->BookingList);
    this->Save_Subscription(this->db->GetSubscription("Subscription"), this->SubscriptionList);

    // Save once at the end
    this->db->SaveGym_Padel_DB("Gym_Padel_DB.xlsx");

    cout << "SAVED \n";
}