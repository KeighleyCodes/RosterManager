#pragma once

#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;





class Roster {
private: 
	int i = 0;
	Student* classRosterArray[5];
	

public:
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	~Roster();  // Deconstructor

	// My parsing is done in main
};

