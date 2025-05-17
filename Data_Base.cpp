#include "Data_Base.h"

Data_Base* Data_Base::InstanceDB = nullptr;
std::mutex Data_Base::mtx;
//Constructor
Data_Base::Data_Base() {
}

Data_Base* Data_Base::GetDB() {
	if (InstanceDB == nullptr) {
		std::lock_guard<std::mutex>lock(mtx);
		if (InstanceDB == nullptr)
		{
			InstanceDB = new Data_Base();

		}
	}
	return InstanceDB;
}




xlnt::workbook& Data_Base::getGym_Padel_DB(std::string FileName) {
	try
	{
		this->Gym_Padel_DB.load(FileName);
	}
	catch (const std::exception&)
	{
		std::cout << "File Not Exist\n";
	}

	return this->Gym_Padel_DB;
}
//************************************************\\


xlnt::worksheet& Data_Base::GetManager(std::string FileName) {
	try
	{
		this->Manager = this->Gym_Padel_DB.sheet_by_index(0);
	}
	catch (const std::exception&)
	{
		this->Gym_Padel_DB.create_sheet().title(FileName);
		this->Manager = this->Gym_Padel_DB.sheet_by_index(0);
		this->Manager.cell("A1").value("ID");
		this->Manager.cell("B1").value("Name");
		this->Manager.cell("C1").value("Password");
		this->Manager.cell("D1").value("Salary");
	}
	return this->Manager;
}



//************************************************\\
	

xlnt::worksheet& Data_Base::GetTrainee(std::string FileName) {
	try
	{
		this->Trainee = this->Gym_Padel_DB.sheet_by_index(1);
	}
	catch (const std::exception&)
	{
		this->Gym_Padel_DB.create_sheet().title(FileName);
		this->Trainee = this->Gym_Padel_DB.sheet_by_index(1);
		this->Trainee.cell("A1").value("ID");
		this->Trainee.cell("B1").value("Name");
		this->Trainee.cell("C1").value("Phone Number");
		this->Trainee.cell("D1").value("Gender");
		this->Trainee.cell("E1").value("Date Of Birth");
		this->Trainee.cell("F1").value("Email");
		this->Trainee.cell("G1").value("Password");
		this->Trainee.cell("H1").value("Is VIP");
		this->Trainee.cell("I1").value("Name Code");

	}

	return this->Trainee;
}

//************************************************\\

xlnt::worksheet& Data_Base::GetCoach(std::string FileName) {
	try
	{
		this->Coach = this->Gym_Padel_DB.sheet_by_index(2);
	}
	catch (const std::exception&)
	{
		this->Gym_Padel_DB.create_sheet().title(FileName);
		this->Coach = this->Gym_Padel_DB.sheet_by_index(2);
		this->Coach.cell("A1").value("ID");
		this->Coach.cell("B1").value("Name");
		this->Coach.cell("C1").value("Password");
		this->Coach.cell("D1").value("Salary");

	}
	return this->Coach;
}

//************************************************\\


xlnt::worksheet& Data_Base::GetGymClass(std::string FileName) {
	try
	{
		this->GymClass = this->Gym_Padel_DB.sheet_by_index(3);

	}
	catch (const std::exception&)
	{
		this->Gym_Padel_DB.create_sheet().title(FileName);
		this->GymClass = this->Gym_Padel_DB.sheet_by_index(3);
		this->GymClass.cell("A1").value("Name Code");
		this->GymClass.cell("B1").value("Capacity");
		this->GymClass.cell("C1").value("Start Time");
		this->GymClass.cell("D1").value("End Time");
		this->GymClass.cell("E1").value("Time Period");
		this->GymClass.cell("F1").value("Number Of Sessions");
		this->GymClass.cell("G1").value("Type");
		this->GymClass.cell("H1").value("Coach ID");
	}
	return this->GymClass;
}

//************************************************\\

xlnt::worksheet& Data_Base::GetHallSystem(std::string FileName) {
	try
	{
		this->HallSystem = this->Gym_Padel_DB.sheet_by_index(4);

	}
	catch (const std::exception&)
	{
		this->Gym_Padel_DB.create_sheet().title(FileName);
		this->HallSystem = this->Gym_Padel_DB.sheet_by_index(4);
		this->HallSystem.cell("A1").value("ID");
		this->HallSystem.cell("B1").value("Name");

	}
	return this->HallSystem;
}

//************************************************\\


xlnt::worksheet& Data_Base::GetWorkoutPlan(std::string FileName) {
	try
	{
		this->WorkoutPlan = this->Gym_Padel_DB.sheet_by_index(5);
	}
	catch (const std::exception&)
	{  //Name, Hours per day ,Intensity,Lost Calories
		this->Gym_Padel_DB.create_sheet().title(FileName);
		this->WorkoutPlan = this->Gym_Padel_DB.sheet_by_index(5);
		this->WorkoutPlan.cell("A1").value("Name Code");
		this->WorkoutPlan.cell("B1").value("Hours per day ");
		this->WorkoutPlan.cell("C1").value("Intensity");
		this->WorkoutPlan.cell("E1").value("Lost Calories");
		this->WorkoutPlan.cell("F1").value("Class Name Code");

	}
	return this->WorkoutPlan;
}


//************************************************\\
	

xlnt::worksheet& Data_Base::GetReceptionist(std::string FileName) {
	try
	{
		this->Receptionist = this->Gym_Padel_DB.sheet_by_index(6);
	}
	catch (const std::exception&)
	{
		this->Gym_Padel_DB.create_sheet().title(FileName);
		this->Receptionist = this->Gym_Padel_DB.sheet_by_index(6);

		this->Receptionist.cell("A1").value("ID");
		this->Receptionist.cell("B1").value("Name");
		this->Receptionist.cell("C1").value("Password");
		this->Receptionist.cell("D1").value("Salary");

	}
	return this->Receptionist;
}

//************************************************\\
	

xlnt::worksheet& Data_Base::GetCourt(std::string FileName) {
	try
	{
		this->Court = this->Gym_Padel_DB.sheet_by_index(7);
	}
	catch (const std::exception&)
	{
		this->Gym_Padel_DB.create_sheet().title(FileName);
		this->Court = this->Gym_Padel_DB.sheet_by_index(7);

		this->Court.cell("A1").value("Name Code");
		this->Court.cell("B1").value("Price Per Hour");
		this->Court.cell("C1").value("Location");
		this->Court.cell("D1").value("Is Available");
	}
	return this->Court;
}

//************************************************\\
	

xlnt::worksheet& Data_Base::GetBooking(std::string FileName) {
	try
	{
		this->Booking = this->Gym_Padel_DB.sheet_by_index(8);
	}
	catch (const std::exception&)
	{
		this->Gym_Padel_DB.create_sheet().title(FileName);
		this->Booking = this->Gym_Padel_DB.sheet_by_index(8);

		this->Booking.cell("A1").value("ID");
		this->Booking.cell("B1").value("Day");
		this->Booking.cell("C1").value("Price");
		this->Booking.cell("D1").value("Start Time");
		this->Booking.cell("E1").value("End Time");
		this->Booking.cell("F1").value("Time Period");
		this->Booking.cell("G1").value("Is Confirmed");


	}
	return this->Booking;
}
//************************************************\\

xlnt::worksheet& Data_Base::GetSubscription(std::string FileName) {
	try
	{
		this->Subscription = this->Gym_Padel_DB.sheet_by_index(9);
	}
	catch (const std::exception&)
	{
		this->Gym_Padel_DB.create_sheet().title(FileName);
		this->Subscription = this->Gym_Padel_DB.sheet_by_index(9);
		this->Subscription.cell("A1").value("ID");
		this->Subscription.cell("B1").value("Trainee ID");
		this->Subscription.cell("C1").value("Subscription Start Date");
		this->Subscription.cell("D1").value("Subscription Period");
		this->Subscription.cell("E1").value("Subscription End Date");
		this->Subscription.cell("F1").value("Subscription Price");
	}
	return this->Subscription;
}

//************************************************\\


Data_Base :: ~Data_Base() { Gym_Padel_DB.save("Gym_Padel_DB.xlsx"); }
