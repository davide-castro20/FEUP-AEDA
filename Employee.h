#pragma once

#include "Plane.h"
#include "Date.h"
#include "Schedule.h"

class Schedule;
class Flight;
class Plane;
class Date;


class Employee {
public:
	Employee(string name, Date *birthDate,string type);

	string getName() const ;
	Date getDate() const;
	double getSalary() const;
	string getType() const;

	virtual string getCategory() { return "Non existant for this employee"; }; //returns none if category is non existant
	virtual vector <Plane*> getPlanes() { return {}; }; //returns empty vector if non existant
	virtual vector <Flight*> getFlights() { return {}; }; //returns empty vector if non existant
	virtual string getDeparment() { return "Non existant for this employee"; }; //returns none if department is non existant
	virtual string getFunction() { return "Non existant for this employee"; }; //returns none if function is non existant
	//virtual Schedule getSchedule() { Schedule *schedule; return *schedule; };

	virtual bool setCategory(string category) { return true; };
	virtual bool setSchedule(Schedule *schedule) { return true; };
	virtual bool setDepartment(string department) { return true; };
	virtual bool setFunction(string function) { return true; };

	bool setName(string name);
	bool setDate(Date *birthDate);
	bool setSalary(float salary);
	

	virtual double calcSalary() {return 0;}; //returns 0 but has no effect since all derivated classes will have this method
protected:
	string name;
	string type;
	double salary = calcSalary();
	Date *birthDate;
};

class Pilot : public Employee {
private:
	string category;//para simplificar apenas existem categorias A, B, C
	vector <Plane*> planes;
	vector <Flight*> flights;
public: 
	Pilot(string name, Date *birthDate, string category, vector <Plane*> planes, vector <Flight*> flights,string type);

	string getCategory() const ;
	vector <Plane*> getPlane() const;
	vector <Flight*> getFlights() const;
	bool setCategory(string categ);
	bool setFlights(vector<Flight*> &flights);
	bool setPlanes(vector<Plane*> &planes);

	
	double calcSalary();
};

class FlightCrew : public Employee {
private:
	string category;//para simplificar apenas existem categorias A, B, C
	vector <Flight*> flights;
public:
	FlightCrew(string name, Date *birthDate, string category,vector <Flight*> flights,string type);

	string getCategory();
	vector <Flight*> getFlights();
	bool setCategory(string categ);
	bool setFlights(vector<Flight*> &flights);


	double calcSalary();
};

class Admin : public Employee {
private:
	string department;
	string function;
public:
	Admin(string name, Date *birthDate, string department, string function,string type);

	string getDepartment();
	string getFunction();

	bool setDepartment(string depart);
	bool setFunction(string func);

	double calcSalary();
};

class BaseCrew : public Employee {
private:
	string category;
	Schedule *schedule;
public:
	BaseCrew(string name, Date *birthDate, string category, Schedule *schedule,string type);

	string getCategory();
	Schedule getSchedule();
	bool setCategory(string categ);
	bool setSchedule(Schedule *sched);



	double calcSalary();
};




