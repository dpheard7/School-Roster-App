/*--------------------------

Student.cpp
Date: 14 May 2021
Author: Damon Heard
Student ID: 001670334

--------------------------*/
#pragma once
#include "Degree.h"
#include <iostream>
#include <string>
using std::string;

class Student {
    public: 

        const static int daysInCourseSize = 3;

    public: /* Declare variables */
        string studentID; 
        string firstName;
        string lastName;
        string emailAddress;
        int Age;
        int daysInCourse[daysInCourseSize]; 
        DegreeProgram degreeProgram;

public: /* Constructors */       

        Student(); /* Default */
        Student(string studentID, string firstName, string lastName, string emailAddress, int Age, int daysInCourse[], DegreeProgram degreeProgram); /* Full */

        /* Destructor */
        ~Student(); /* Function definition not found ???*/

         /* Accessors (getters) */ 
         string getStudentID();
         string getfirstName();
         string getlastName (); 
         string getemailAddress();
         int getAge();
         int* getdaysInCourse();
         int getDaysInCourse(int index );
         DegreeProgram getdegreeProgram();  

         /* Mutators (setters) */
         void setstudentID(string studentID);
         void setfirstName(string firstName);
         void setlastName(string lastName);
         void setemailAddress(string emailAddress);
         void setAge(int Age);
         void setdaysInCourse(int daysInCourse[]);
         void setDegreeProgram(DegreeProgram degreeProgram);

         /* Print functions */
         static void printHeader();
         void print();

/* Constructor - can't be declared outside of class according to VS error detection? */

};

/* 

Scrap Heap
-----------------------------------

void studentID(); 


int main() {
    public:
        class Student;
        string studentID; 
        string firstName; 
        string lastName; 
        striong emailAddress;
        int daysInCourse[0];
        string degreeProgram;

Student::Student() {
    int studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int Age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;
}

-----------------------------------

NOTES:

Looks sloppy for some reason. Consider rearranging blocks for readability.

*/