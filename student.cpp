#include <iostream>
#include <string>
#include <iomanip>
#include "student.h"

using namespace std;



// Constructor 

Student::Student(string sId, string fName, string lName, string em, int xyz, int days[], DegreeProgram degree)
{
	studentId = sId;
	firstName = fName;
	lastName = lName;
	email = em;
	age = xyz;
	for (int i = 0; i < 3; ++i) {
		daysToComplete[i] = days[i];
	}
	degreeProgram = degree;
}


// Accessors

string Student::getStudentId() {
	return this->studentId;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmail() {
	return this->email;
}

int Student::getAge() {
	return this->age;
}


int* Student::getDaysToComplete() {
	return this->daysToComplete;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}


// Mutators 

void Student::setStudentId(string studentId) {
	this->studentId = studentId;
	return;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
	return;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
	return;
}

void Student::setEmail(string email) {
	this->email = email;
	return;
}

void Student::setAge(int age) {
	this->age = age;
	return;
}


void Student::setDaysToComplete(int days[]) {
	for (int i = 0; i < 3; ++i) {
		this->daysToComplete[i] = days[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}



// Destructor

Student::~Student()	{ 
	studentId.clear();
	firstName.clear();
	lastName.clear();
	email.clear();
	age = NULL;
	for (int i = 0; i < 5; ++i) {
		daysToComplete[i] = NULL;
	}
	degreeProgram = INVALID;
}


// Print function - used setw() instead of \t because fields weren't even

void Student::print()	{

	string dp_str = "";

	switch (degreeProgram) {

	case SECURITY:
		dp_str = "SECURITY";
		break;

	case NETWORK:
		dp_str = "NETWORK";
		break;

	case SOFTWARE:
		dp_str = "SOFTWARE";
		break;
	}

	cout << left << setw(14) << Student::studentId;
	cout << left << setw(16) << Student::firstName;
	cout << left << setw(16) << Student::lastName;
	cout << left << setw(29) << Student::email;
	cout << left << setw(7) << Student::age;
	cout << left << setw(5) << Student::daysToComplete[0];
	cout << left << setw(5) << Student::daysToComplete[1];
	cout << left << setw(10) << Student::daysToComplete[2];
	cout << left << setw(4) << dp_str; 

	cout << endl; 
};
