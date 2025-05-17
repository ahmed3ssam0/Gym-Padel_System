#include "Data_Base.h"

Data_Base::Data_Base() {}
Data_Base* Data_Base::InstanceDB = nullptr;
std::mutex Data_Base::mtx;

Data_Base* Data_Base::GetDB() {
    static Data_Base instance;
    return &instance;
}

xlnt::workbook& Data_Base::getGym_Padel_DB(std::string FileName) {
    try {
        this->Gym_Padel_DB.load(FileName);
    }
    catch (const std::exception& e) {
        std::cerr << "Failed to load workbook: " << e.what() << "\nCreating a new one.\n";
        this->Gym_Padel_DB = xlnt::workbook();
        if (this->Gym_Padel_DB.sheet_count() > 0) {
            this->Gym_Padel_DB.remove_sheet(this->Gym_Padel_DB.active_sheet());
        }
    }
    return this->Gym_Padel_DB;
}

void Data_Base::SaveGym_Padel_DB(std::string FileName) {
    try {
        Gym_Padel_DB.save(FileName);
    }
    catch (const std::exception& e) {
        std::cerr << "[ERROR] Could not save workbook: " << e.what() << std::endl;
    }
}

xlnt::worksheet& Data_Base::GetOrCreateSheet(int index, const std::string& sheetName, const std::vector<std::string>& headers, xlnt::worksheet& wsRef) {
    while (Gym_Padel_DB.sheet_count() <= index) {
        Gym_Padel_DB.create_sheet();
    }
    wsRef = Gym_Padel_DB.sheet_by_index(index);
    if (!wsRef.has_cell("A1")) {
        wsRef.title(sheetName);
        for (size_t i = 0; i < headers.size(); ++i) {
            std::string col = std::string(1, 'A' + i) + "1";
            wsRef.cell(col).value(headers[i]);
        }
    }
    return wsRef;
}

xlnt::worksheet& Data_Base::GetManager(std::string) {
    return GetOrCreateSheet(0, "Manager", { "ID", "Name", "Password", "Salary" }, this->Manager);
}

xlnt::worksheet& Data_Base::GetTrainee(std::string) {
    return GetOrCreateSheet(1, "Trainee", {
        "ID", "Name", "Phone Number", "Gender", "Date Of Birth",
        "Email", "Password", "Is VIP"
        }, this->Trainee);
}

xlnt::worksheet& Data_Base::GetCoach(std::string) {
    return GetOrCreateSheet(2, "Coach", { "ID", "Name", "Password", "Salary" }, this->Coach);
}

xlnt::worksheet& Data_Base::GetGymClass(std::string) {
    return GetOrCreateSheet(3, "GymClass", {
        "Name Code", "Capacity", "Start Time", "End Time", "Time Period",
        "Number Of Sessions", "Type", "Coach ID"
        }, this->GymClass);
}

xlnt::worksheet& Data_Base::GetHallSystem(std::string) {
    return GetOrCreateSheet(4, "HallSystem", { "ID", "Name" }, this->HallSystem);
}

xlnt::worksheet& Data_Base::GetWorkoutPlan(std::string) {
    return GetOrCreateSheet(5, "WorkoutPlan", {
        "Name Code", "Hours per day ", "Intensity", "", "Lost Calories", "Class Name Code"
        }, this->WorkoutPlan);
}

xlnt::worksheet& Data_Base::GetReceptionist(std::string) {
    return GetOrCreateSheet(6, "Receptionist", {
        "ID", "Name", "Password", "Salary"
        }, this->Receptionist);
}

xlnt::worksheet& Data_Base::GetCourt(std::string) {
    return GetOrCreateSheet(7, "Court", {
        "Name Code", "Price Per Hour", "Location", "Is Available"
        }, this->Court);
}

xlnt::worksheet& Data_Base::GetBooking(std::string) {
    return GetOrCreateSheet(8, "Booking", {
        "ID", "Day", "Price", "Start Time", "End Time",
        "Time Period", "Is Confirmed"
        }, this->Booking);
}

xlnt::worksheet& Data_Base::GetSubscription(std::string) {
    return GetOrCreateSheet(9, "Subscription", {
        "ID", "Trainee ID", "Subscription Start Date",
        "Subscription Period", "Subscription End Date", "Subscription Price"
        }, this->Subscription);
}
