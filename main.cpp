#include "degree.h"
#include "student.h"
#include "roster.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cout << "---------------------------------------------------------" << endl;
    cout << "Course: Scripting and Programming Applications - C867" << endl;
    cout << "Language: C++" << endl;
    cout << "StudentID: 001116069" << endl;
    cout << "Student Name: Stephanie Merrington" << endl;
    cout << "---------------------------------------------------------" << endl << endl;

    const string classRosterArray[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Stephanie,Merrington,smerr79@wgu.edu,30,14,21,28,SOFTWARE",
    };

    const int studentNum = sizeof(classRosterArray) / sizeof(classRosterArray[0]);

    Roster classRoster;
    for (int i = 0; i < studentNum; i++) {
        classRoster.Parse(classRosterArray, i);

    }

    classRoster.PrintAll();
    cout << "---------------------------------------------------------" << endl << endl;
    classRoster.PrintInvalidEmail();
    cout << "---------------------------------------------------------" << endl << endl;

    //Print Average Days in Course
    for (int i = 0; i < studentNum; i++) {
        classRoster.PrintDaysInCourse(classRoster.classRosterArray.at(i)->getStudentID());
    }
    cout << endl;
    cout << "---------------------------------------------------------" << endl << endl;
    classRoster.PrintByDegree(DegreeProgram::SOFTWARE);
    cout << endl;
    cout << "---------------------------------------------------------" << endl << endl;

    classRoster.Remove("A3");
    classRoster.PrintAll();
    cout << "---------------------------------------------------------" << endl;
    classRoster.Remove("A3");

    return 0;
}