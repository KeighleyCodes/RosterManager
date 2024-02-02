#include <iostream>
#include <string>
#include <iomanip>
#include "degree.h"
#include "roster.h"
#include "student.h"
using namespace std;


// Parsing is done in main


// Deconstructor 

 Roster::~Roster()	{ 
	 for (int i = 0; i < 5; ++i) {
		 classRosterArray[i] = nullptr; 
	}
	 return;
 }
 

 
 // Add function

 void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	
	 int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	 if (i >= 5) {
		 cout << "The maximum limit of students has been entered.";
		 cout << endl;
		 cout << endl;
	 }

	 else {
		 Student* o = new Student(studentId, firstName, lastName, emailAddress, age, days, degreeProgram); 

		 classRosterArray[i] = o;

		 i = (i + 1);
	 }
	 
}


 // Remove function 

 void Roster::remove(string studentId) { /////// FIX THIS!!
	 bool idFound = false; 

	 static int rosterSize = 5;

	 for (int i = 0; i < rosterSize &&!idFound; ++i) {
			 if (classRosterArray[i]->getStudentId() == studentId) {
				 classRosterArray[i]->setStudentId("VOID");
				 idFound = true; 
			 }
	 }
	 
		if (idFound) {
			cout << "Student ID " << studentId << " was removed from roster." << endl;
		 }

		else {
			cout << "Error: Student ID " << studentId << " was not found." << endl;
		 }
		
		cout << endl;
	 
 }



 // PrintAll function 

void Roster::printAll() {
	cout << "Printing entire class roster: " << endl;
	cout << endl;
	cout << left << setw(14) << "ID:";
	cout << left << setw(16) << "First Name:";
	cout << left << setw(16) << "Last Name:";
	cout << left << setw(29) << "Email:";
	cout << left << setw(7) << "Age:";
	cout << left << setw(20) << "Days To Complete:";
	cout << left << setw(1) << "Program:";
	cout << endl;
	
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getStudentId() == "VOID") {
			continue;
		}

		classRosterArray[i]->print();
	}
	
	cout << endl;
	
	
};


// Print Average Days in Course

void Roster::printAverageDaysInCourse(string studentId) {
	for (int i = 0; i < 5; ++i) {
		
		if (classRosterArray[i]->getStudentId() == studentId) {
			
			cout << "Student ID " << studentId << " " ; 
			
			int *days = classRosterArray[i]->getDaysToComplete();
			
			cout << "average days in course: " << ((days[0] + days[1] + days[2]) / 3) <<  endl;
		}
	}
	
}

// Print Invalid Emails

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; ++i) {

		string email = classRosterArray[i]->getEmail();
		if ((email.find("@") == -1) || (email.find(".") == -1) || !(email.find(" ") == -1)) {
			cout << "Invalid e-mail address(es):" << endl;
			cout << email << endl;
			cout << endl;

		};

	}

} 


// Print By Degree

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)	{ 
	cout << "Printing by degree program:" << endl;
	cout << endl;
	cout << left << setw(14) << "ID:";
	cout << left << setw(16) << "First Name:";
	cout << left << setw(16) << "Last Name:";
	cout << left << setw(29) << "Email:";
	cout << left << setw(7) << "Age:";
	cout << left << setw(20) << "Days To Complete:";
	cout << left << setw(1) << "Program:";
	cout << endl;

	for (int i = 0; i < 5; ++i) {

		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {

			classRosterArray[i]->print();
		}
		
	}
	
	cout << endl;
	cout << endl;

}  



	