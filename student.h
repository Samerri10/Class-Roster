#pragma once

#include "degree.h"
#include <string>
#include <vector>

using namespace std;

class Student {
public:
	//Setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddr(string emailAddr);
	void setStudentAge(int studentAge);
	void setDaysInCourse(vector<int> daysInCourse);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//Getters
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddr() const;
	int getStudentAge() const;
	vector<int> getDaysInCourse() const;
	DegreeProgram getDegreeProgram() const;
	string getDaysInCourseString() const;
	string getDegreeProgramString() const;

	void Print();

	//Constructor and Deconstructor
	Student(string studentID,
		string firstName,
		string lastName,
		string emailAddr,
		int studentAge,
		vector<int> daysInCourse,
		DegreeProgram degreeProgram);
	Student();
	~Student();

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddr;
	int studentAge;
	vector<int> daysInCourse;
	DegreeProgram degreeProgram;

};