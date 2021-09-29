/*--------------------------

Roster.cpp
Date: 14 May 2021
Author: Damon Heard
Student ID: 001670334

--------------------------*/

#include <iostream>
#include <string>
#include "Roster.h"
using std::string;
using std::cout;
using std::endl;

/* const static int numStudents = 5; */
/* Student** classRosterArray; */

/* Defining add method and creating array */
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int Age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysInCourse[] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[++index] = new Student(studentID, firstName, lastName, emailAddress, Age, daysInCourse, degreeProgram);
    }

/* 
Parsing record
Quick reference: 
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int Age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysInCourse[] = {daysInCourse1, daysInCourse2, daysInCourse3 };
*/
Roster::Roster(int numStudents)
{
}
void Roster::parseStudent(string row) {
    /*rhs - lhs*/
    DegreeProgram degreeProgram = SOFTWARE;

    if (row.back() == 'K') {
        degreeProgram = NETWORK;
    }
    else if (row.back() == 'Y') {
        degreeProgram = SECURITY;
    }

    int rhs = row.find(",");
    string studentID = row.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = row.find(",", /*rhs - */lhs);
    string firstName = row.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = row.find(",", /*rhs - */lhs);
    string lastName = row.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = row.find(",", /*rhs - */lhs);
    string emailAddress = row.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = row.find(",", /*rhs - */lhs);
    int Age = stoi(row.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", /*rhs - */lhs);
    int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", /*rhs - */lhs);
    int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = row.find(",", /*rhs - */lhs);
    int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

    
    /* lhs = rhs + 1;
    rhs = row.find(",", rhs - lhs);
    degreeProgram = row.substr(lhs, rhs - lhs); */

    add(studentID, firstName, lastName, emailAddress, Age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    
   /*  for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            if ((*classRosterArray[j]).string.length > )
                maxLengthsArray[i] = classRosterArray[j].string::length; 
        }

    } */
};


/* Validating email addresses (must include @ and "." and not contain spaces */
 void Roster::printInvalidEmails() {
    bool found = false;
    for (int i = 0; i < numStudents; i++) {
        string invalid = classRosterArray[i]->getemailAddress();
        if (invalid.find(".") == string::npos || invalid.find("@") == string::npos || invalid.find(" ") != string::npos) {
            found = true;
            cout << invalid << " is an invalid email address. Please add a period and try again." << endl;
        }
    }
    if (!found) cout << "No invalid emails" << endl;
 
 }

void Roster::printAll() {
    cout << "Printing all students.\n";
    for (int i = 0; i <= index; i++) {
        classRosterArray[i]->print();
    };
};

/*void Roster::printHeader()
{
}*/

/* Print average days in course */
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= index; i++) {
        if (this->classRosterArray[i]->getStudentID() == studentID) {
            cout << "Student ID" << classRosterArray[i]->getStudentID() << ": ";
            int* daysInCourse = classRosterArray[i]->getdaysInCourse();
            cout << "Average days in course: " << (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3.0;
            cout << '\n';
        };
    };
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "Displaying students in " << degreeProgramStrings[degreeProgram] << " program" << endl;
    for (int i = 0; i < numStudents; i++) {
        if (this->classRosterArray[i]->getdegreeProgram() == degreeProgram) {
            classRosterArray[i]->print(); 
        }
    }
}



void Roster::remove(string studentID) 
{   cout << "Removing A3." << endl;
    bool idFound = false;
    for (int i = 0; i <= index; i++) {
            if (this->classRosterArray[i]->getStudentID() == studentID) {
                idFound = true;
                delete this->classRosterArray[i];
                classRosterArray[i] = classRosterArray[index]; 
                index--;
            }
     }
    if (idFound == false) {
            cout << "Student ID " << studentID << " found and removed." << endl;
     }
}

Roster::~Roster() {
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];
        }

    }
}