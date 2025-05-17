#pragma once
#include "Coatch.h"
#include "Receptionist.h"
#include<list>
#include<unordered_map>
class Manager 
{
private:
	string id;
	string name;
	string password;
	unordered_map<string, Coatch> coachMap;
	unordered_map<string, Receptionist> recpMap;
public:
	//constructor
	Manager() = default;
	Manager(string id, string name, string password);
	//setter
	void setid(string id);
	void setname(string name);
	void setpassword(string password);
	void setcoaches(unordered_map<string, Coatch> coaches);
	void setreceptionists(unordered_map<string, Receptionist> receptionists);
	//getter
	string getid();
	string getname();
	string getpassword();
	unordered_map<string, Coatch> getcoaches();
	unordered_map<string, Receptionist> getreceptionists();
	// Update 
	void updateMangerInfo(string newname, string newpassword);
	//destructor
	~Manager();
	
	// Add a coach
	void addCoach(Coatch coach);
	// Remove a coach by ID
	bool removeCoach(string coachID);
	// Add a receptionist
	void addReceptionist(Receptionist receptionist);
	// Remove a receptionist by ID
	bool removeReceptionist(string receptionistID);
	

};


