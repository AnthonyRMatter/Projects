/*
File Name: Student.cpp
This file simulates a student entering an office and keeps track of their window and waiting time.
*/
#include "Student.h"
#include <iostream>

Student::Student() {
    this->windowTime = 0;
    this->waitingTime = 0;
}

Student::Student(int windowTime) {
    this->windowTime = windowTime;
    this->waitingTime = 0;
}

Student::~Student() { }

/*
Function Name: UpdateWindowTime
What it does: This functions updates the window time by decrementing by 1 and checks if window time is 0, it prints the student is done.
Parameters and Data Types: No parameters and data types
Return value and data type: Since this is a void function, no value is returned.
*/
void Student::UpdateWindowTime() {
    if (this->windowTime <= 0) {
        std::cout << "This student is done!" << std::endl;
    }
    this->windowTime--;
}

/*
Function Name: UpdateWaitingTime
What it does: This functions updates the waiting time by incrementing by 1.
Parameters and Data Types: No parameters and data types
Return value and data type: Since this is a void function, no value is returned.
*/
void Student::UpdateWaitingTime() {
    this->waitingTime++;
}
