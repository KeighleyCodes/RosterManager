
#include <iostream>
#include <string>
#include <sstream>
#include "student.h"
#include "degree.h"
#include "roster.h"

using namespace std;



// Converts DegreeProgram enum to string in order to parse

DegreeProgram convert(const std::string& str)
{
	if (str == "SECURITY") return SECURITY;
	else if (str == "NETWORK") return NETWORK;
	else if (str == "SOFTWARE") return SOFTWARE;
	else cout << "None" << endl;
}


int main() {

	cout << "\t" << "\t" << "--------------------------------------------------------------------------" << endl;
	cout << "\t" << "\t" << "| \t Course Title: WGU C867" << "\t \t Language Used: C++" << "\t \t |" << endl;
	cout << "\t" << "\t" << "| \t Student ID: 001321515" << "\t \t Student Name: Keighley Manke" << "\t |" << endl;
	cout << "\t" << "\t" << "--------------------------------------------------------------------------" << endl;
	cout << "\t" << "\t" << endl;
	cout << "\t" << "\t" << endl;
	cout << "\t" << "\t" << endl;


	const string studentData[5] = {
		"A1,John,Smith,John1989@g ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99@yahoo.com,18,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"001321515,Keighley,Manke,kmanke@wgu.edu,37,14,24,38,SOFTWARE"
	};




	// Create instance of Roster classRoster

	Roster* classRoster = new Roster();

	// Parsing studentData

	for (int i = 0; i < 5; ++i) {
		
		string str = studentData[i];

		stringstream ss(str);

		string studentId;
		std::getline(ss, studentId, ',');

		string firstName;
		std::getline(ss, firstName, ',');

		string lastName;
		std::getline(ss, lastName, ',');

		string email;
		std::getline(ss, email, ',');

		string ageString;
		std::getline(ss, ageString, ',');
		int age = stoi(ageString);

		string days1String;
		std::getline(ss, days1String, ',');
		int days1 = stoi(days1String);

		string days2String;
		std::getline(ss, days2String, ',');
		int days2 = stoi(days2String);

		string days3String;
		std::getline(ss, days3String, ',');
		int days3 = stoi(days3String);

		string program;
		std::getline(ss, program, ',');
		DegreeProgram degree = convert(program);

		classRoster->add(studentId, firstName, lastName, email, age, days1, days2, days3, degree);
	}


	
	classRoster->printAll();

	classRoster->printInvalidEmails();

	cout << "Average days in course: " << endl;
	classRoster->printAverageDaysInCourse("A1");
	classRoster->printAverageDaysInCourse("A2");
	classRoster->printAverageDaysInCourse("A3");
	classRoster->printAverageDaysInCourse("A4");
	classRoster->printAverageDaysInCourse("A5");
	cout << endl;

	classRoster->printByDegreeProgram(SOFTWARE);

	classRoster->remove("A3");

	classRoster->printAll();

	classRoster->~Roster();

	

};

