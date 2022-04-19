#include "student.h"
#include "degree.h"
#include "roster.h"
#include <iostream>
#include <iomanip>
#include <regex>

using namespace std;

void Roster::Add(string studentID,
	string firstName,
	string lastName,
	string emailAddr,
	int studentAge,
	int daysInCourse1,
	int daysInCourse2,
	int daysInCourse3,
	DegreeProgram degreeProgram)
{
	vector<int> addDaysInCourse{ daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* addStudent = new Student{ studentID, firstName, lastName, emailAddr, studentAge, addDaysInCourse, degreeProgram };
	classRosterArray.push_back(addStudent);
}

void Roster::Remove(string studentID)
{
	bool found = false;
	cout << "Removing Student ID: " << studentID << endl;
	for (size_t i = 0; i < classRosterArray.size(); i++) {
		if (studentID == classRosterArray.at(i)->getStudentID()) {
			delete classRosterArray.at(i);
			classRosterArray.erase(classRosterArray.begin() + i);
			found = true;
		}
	}
	if (!found) {
		cout << "No Match Found" << endl;
	}
}

void Roster::Parse(const string studentData[], int i)
{
	DegreeProgram degreeProgramInput = DegreeProgram::SOFTWARE;
	vector<string> arrayStudentData;
	size_t pStart = 0;
	int j = i;

	for (int i = 0; i < 9; i++) {
		size_t pLen = studentData[j].find(",", pStart);
		arrayStudentData.push_back(studentData[j].substr(pStart, pLen - pStart));
		pStart = pLen + 1;
	}

	string inputStudentID = arrayStudentData.at(0);
	string inputFirstName = arrayStudentData.at(1);
	string inputLastName = arrayStudentData.at(2);
	string inputEmailAddr = arrayStudentData.at(3);
	int inputStudentAge = stoi(arrayStudentData.at(4));
	int inputDaysInCourse1 = stoi(arrayStudentData.at(5));
	int inputDaysInCourse2 = stoi(arrayStudentData.at(6));
	int inputDaysInCourse3 = stoi(arrayStudentData.at(7));
	if (arrayStudentData.at(8) == "SECURITY") {
		degreeProgramInput = DegreeProgram::SECURITY;
	}
	else if (arrayStudentData.at(8) == "NETWORK") {
		degreeProgramInput = DegreeProgram::NETWORK;
	}
	else if (arrayStudentData.at(8) == "SOFTWARE") {
		degreeProgramInput = DegreeProgram::SOFTWARE;
	}

	Add(inputStudentID,
		inputFirstName,
		inputLastName,
		inputEmailAddr,
		inputStudentAge,
		inputDaysInCourse1,
		inputDaysInCourse2,
		inputDaysInCourse3,
		degreeProgramInput);
}

void Roster::PrintAll() const
{
	cout << "Print All Students:" << endl;
	for (int i = 0; i < classRosterArray.size(); i++) {
		classRosterArray.at(i)->Print();
	}
	cout << endl;
}

void Roster::PrintDaysInCourse(string studentID)
{
	int averageDayResult = 0;
	cout << "The Average number of days in course for " << studentID << " is: ";
	for (int i = 0; i < classRosterArray.size(); i++) {
		if (studentID == classRosterArray.at(i)->getStudentID()) {
			vector<int> averageVec = classRosterArray.at(i)->getDaysInCourse();
			for (int i = 0; i < averageVec.size(); i++) {
				averageDayResult = averageDayResult + averageVec.at(i);
			}
			cout << averageDayResult / averageVec.size() << endl;
		}
	}
}

void Roster::PrintByDegree(DegreeProgram degreeProgram)
{
	cout << "Printing all Students in the SOFTWARE Program: " << endl;
	for (int i = 0; i < classRosterArray.size(); i++) {
		if (degreeProgram == classRosterArray.at(i)->getDegreeProgram()) {
			classRosterArray.at(i)->Print();
		}
	}
}

void Roster::PrintInvalidEmail()
{
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	cout << "Invalid emails found for the following users:" << endl;
	for (int i = 0; i < classRosterArray.size(); i++) {
		if (!regex_match(classRosterArray.at(i)->getEmailAddr(), pattern)) {
			cout << "Student ID: " << classRosterArray.at(i)->getStudentID() << "\t";
			cout << "Student Name: " << classRosterArray.at(i)->getFirstName() << " " << classRosterArray.at(i)->getLastName() << "\t";
			cout << "Email Address: " << classRosterArray.at(i)->getEmailAddr() << endl;
		}
	}
	cout << endl;
}

Roster::Roster() {}

Roster::~Roster()
{
	for (int i = 0; i < classRosterArray.size(); i++) {
		delete classRosterArray.at(i);
	}
	for (int i = 0; i < classRosterArray.size(); i++) {
		delete classRosterArray.at(i);
	}
}