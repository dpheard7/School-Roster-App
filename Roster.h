/*--------------------------

Student.cpp
Date: 14 May 2021
Author: Damon Heard
Student ID: 001670334

--------------------------*/

#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Student.h"
using std::string;



class Roster {

/* public: 
    Student* classRosterArray[5] = {
        nullptr, nullptr, nullptr, nullptr, nullptr
    }; */

private:
    int index = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents]; // changed from two publics to one and made this block private 

public: 

    /* Constructors */
    Roster();
    Roster(int numStudents);



    void parseStudent(string row);
    void add(string studentID, string firstName, string lastName, string emailAddress, int Age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails(); /* Prints invalid emails according to instructions ("valid emails include @ sign and should not include a space */
    void printByDegreeProgram(DegreeProgram degreeProgram);

    /* Destructor */
    ~Roster();
};

