   #pragma once  
   #include <xlnt/xlnt.hpp>  
   #include <string>  
   #include <mutex>  
   #include <fstream>  

   ///singleton Class  
   class Data_Base  
   {  
      //Fields 

   private:  
      xlnt::workbook  Gym_Padel_DB;   
      xlnt::worksheet Manager;  
      xlnt::worksheet Trainee;  
      xlnt::worksheet Coach;
      xlnt::worksheet GymClass;  
      xlnt::worksheet HallSystem;   
      xlnt::worksheet WorkoutPlan;  
      xlnt::worksheet Receptionist;  
	  xlnt::worksheet Court;
      xlnt::worksheet Booking;  
      xlnt::worksheet Subscription;  
      static Data_Base* InstanceDB;  
      static std::mutex mtx;  
      Data_Base();  

   public:  
      Data_Base(Data_Base& t) = delete;  
      static Data_Base* GetDB();  
      std::ofstream fileee;  

      xlnt::worksheet& GetOrCreateSheet(int index, const std::string& sheetName, const std::vector<std::string>& headers, xlnt::worksheet& wsRef);
      xlnt::workbook & getGym_Padel_DB(std::string FileName);  
      xlnt::worksheet & GetManager(std::string FileName);  
      xlnt::worksheet & GetTrainee(std::string FileName);  
      xlnt::worksheet & GetCoach(std::string FileName);  
      xlnt::worksheet & GetGymClass(std::string FileName);  
      xlnt::worksheet & GetHallSystem(std::string FileName);  
      xlnt::worksheet & GetWorkoutPlan(std::string FileName);  
      xlnt::worksheet & GetReceptionist(std::string FileName);
	  xlnt::worksheet & GetCourt(std::string FileName);
	  xlnt::worksheet & GetBooking(std::string FileName);
	  xlnt::worksheet & GetSubscription(std::string FileName);

      void SaveGym_Padel_DB(std::string FileName);  
	  
     };
