/*
File Name: mainprogram.cpp
This file basically reads the text file, takes in all of the information, and calls the Office class
to begin the simulation.
*/
#include "Office.h"
#include <iostream>

int main(int argc, char** argv) {

    std::string fileName = argv[1];

    std::ifstream inFS;
    int windowSize;
    int overallTime;
    int numOfStudents;
    int studentWaitingTime;

    inFS.open(fileName);
    // Attempt to open file
    if (!inFS.is_open()) {
        std::cout << "Cannot open: " << fileName << std::endl;
        throw std::runtime_error("Error opening file");
    }

    inFS >> windowSize;
    //std::cout << "Window Size: " << windowSize << std::endl;
    Office anOffice(windowSize);

    inFS >> overallTime;

    //anOffice.DisplayOfficeData();

    while (!inFS.eof()) {
        inFS >> numOfStudents;
        for (int i = 0; i < numOfStudents; i++) {
            inFS >> studentWaitingTime;
            Student *student = new Student(studentWaitingTime);
            anOffice.AddStudentsToQueue(student);
        }

        inFS >> overallTime;

        if (!inFS.eof()) {
            while (anOffice.GetOfficeTime() != overallTime) {
                anOffice.Update();
                //anOffice.DisplayOfficeData();
            }
        } else {
            while (!anOffice.IsEmpty()) {
                anOffice.Update();
                //anOffice.DisplayOfficeData();
            }
            // Collect the last idle times from window clerks waiting for last students to finish up
            anOffice.windowArea.UpdateIdleTimeList();
            break;
        }
    }
    inFS.close();

    //std::cout << "List of waiting times: " << std::endl;
    anOffice.listOfWaitingTimes.moveToStart();
    for (int i = 0; i < anOffice.listOfWaitingTimes.length(); i++) {
        //std::cout << anOffice.listOfWaitingTimes.getValue() << ", ";
        anOffice.listOfWaitingTimes.next();
    }
    anOffice.listOfWaitingTimes.moveToStart();
    //std::cout << std::endl;

    anOffice.SortListOfWaitingTimes();


    return 0;
}
