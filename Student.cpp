/*--------------------------

Student.h
Date: 14 May 2021
Author: Damon Heard
Student ID: 001670334

--------------------------*/

#include "Student.h"
#include <iostream>
#include <iomanip>
#include <string>

using std::string;
using std::cout;

/* Parameterless Constructor */

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->Age = 0;
	for (int i = 0; i < daysInCourseSize; i++) this->daysInCourse[i] = daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::UNDECIDED;
};

/* Constructor w/ defaults */
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int Age, int daysInCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->Age = Age;
	for (int i = 0; i < daysInCourseSize; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
};

/* Destructor */
Student::~Student() {};

	/* Accessors (Getters) */ 

string Student::getStudentID() {
	return studentID;
};

string Student::getfirstName() {
	return firstName;
};

string Student::getlastName() {
	return lastName;
};

string Student::getemailAddress() {
	return emailAddress;
};

int Student::getAge() {
	return Age;
};

int* Student::getdaysInCourse() {
	return daysInCourse; 
};

DegreeProgram Student::getdegreeProgram() {
	return degreeProgram;
};

	/* Setters (mutators) */

void Student::setstudentID(string studentID) {
	this->studentID = studentID;
};

void Student::setfirstName(string firstName) {
	this->firstName = firstName;
};

void Student::setlastName(string lastName) {
	this->lastName = lastName;
};

void Student::setemailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
};

void Student::setAge(int studentAge) {
	this->Age = Age;
};

void Student::setdaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < daysInCourseSize; i++) this->daysInCourse[i] = daysInCourse[i];
};

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
};

void Student::printHeader() {
	cout << "Format: Student ID---First Name---Last Name---Email---Age---Days In Course---Degree Program" << endl;
};

int Student::getDaysInCourse(int index) {
	return daysInCourse[index];
}

void Student::print() {
	cout << left << setw(5) << getStudentID() << "\t";
	cout << left << setw(10) << getfirstName() << "\t";
	cout << left << setw(10) << getlastName() << "\t";
	cout << left << setw(25) << getemailAddress() << "\t";
	cout << left << setw(5) << getAge() << "\t";
	cout << left << getDaysInCourse(0) << ", ";
	cout << left << getDaysInCourse(1) << ", ";
	cout << left << getDaysInCourse(2) << "\t";
	cout << degreeProgramStrings[getdegreeProgram()] << endl; 
};