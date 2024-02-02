#pragma once

#include "degree.h"
#include <iostream>
#include <string>
using namespace std;



class Student {

public:

	// Constructor

	Student(string studentID, string firstName, string LastName, string email, int age, int daysToComplete[], DegreeProgram degreeProgram);


	// Accessors

	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int	   getAge();
	int    *getDaysToComplete();
	DegreeProgram getDegreeProgram();

	

	// Mutators

	void setStudentId(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToComplete(int daysToComplete[]);
	void setDegreeProgram(DegreeProgram degreeProgram);


	// Deconstructor

	~Student();

	// Print

	void print(); 

private:

	string studentId;
	string firstName;
	string lastName;
	string email;
	int    age;
	int    daysToComplete[3];
	DegreeProgram degreeProgram;


};

