#pragma once

#include "student.h"
#include "degree.h"
#include <vector>
#include <string>

using namespace std;

class Roster
{
public:
	vector<Student*> classRosterArray;

	void Add(string studentID,
		string firstName,
		string lastName,
		string emailAddr,
		int studentAge,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeProgram);
	void Remove(string studentID);
	void Parse(const string studentData[], int i);

	void PrintAll() const;
	void PrintDaysInCourse(string studentID);
	void PrintByDegree(DegreeProgram degreeProgram);
	void PrintInvalidEmail();

	Roster();
	~Roster();
};