/*--------------------------

Main.cpp
Date: 14 May 2021
Author: Damon Heard
Student ID: 001670334

--------------------------*/

#include "Roster.h"
#include "Student.h"
#include "Degree.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;



int main() {

    /* Printing out course title, programming language used, student ID, and name. */

    cout << "WGU C867: Scripting and Programming - Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 001670334" << endl;
    cout << "Name: Damon Heard\n" << endl;
    cout << '\n' << endl;
    
    const string studentData[] = {
"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,29,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Damon,Heard,dhear12@wgu.edu,34,2,5,10,SOFTWARE\n"
    };

    const static int numStudents = 5; 
    Roster *classRoster = new Roster(numStudents);

    /* Parsing student data */

    for (int i = 0; i < numStudents; i++) {
        classRoster->parseStudent(studentData[i]);
    }

    /* Converting pseudocode */

    cout << "Printing class roster." << endl;
    cout << "Format: Student ID---First Name---Last Name---Email---Age---Days In Course---Degree Program" << endl;

    cout << endl; 
    classRoster->printAll();
    cout << '\n'; 

    cout << "Invalid emails: " << endl;
    classRoster->printInvalidEmails();
    cout << '\n';

    cout << "Average days in courses: " << endl;
    classRoster->printAverageDaysInCourse("A1");
    classRoster->printAverageDaysInCourse("A2");
    classRoster->printAverageDaysInCourse("A3");
    classRoster->printAverageDaysInCourse("A4");
    classRoster->printAverageDaysInCourse("A5");
    cout << '\n'; 

    classRoster->printByDegreeProgram(SOFTWARE);
    cout << '\n'; 

    classRoster->remove("A3");
    cout << '\n';

    classRoster->printAll();
    cout << '\n';

    classRoster->remove("A3");
    cout << '\n';
 

}