/*
File Name: Office.cpp
This file handles both the Student and Office objects by having a waiting area, determining when to assign a student
from the queue onto a window space, and keeps track of student wait times.
*/
#include "Office.h"
#include <iostream>

Office::Office(int windowSize) : windowArea(windowSize) {
    officeTime = 0;
}

Office::~Office() { }


/*
Function Name: Update
What it does: This functions handles the students in the queue and determine if they can go to a window clerk as well as
updates and gathers waiting time in the process.
Parameters and Data Types: No parameters or data types
Return value and data type: Since this is a void function, no value is returned.
*/
void Office::Update() {

    // If there is available windows, place the students from the queue
    int i = waitingArea.length();
    waitingArea.moveToStart();
    while(windowArea.HasAvailableWindows() && i > 0) {
        listOfWaitingTimes.append(waitingArea.peekFront()->GetWaitingTime());
        windowArea.AddStudent(waitingArea.removeFront());
        i--;
    }

    // Iterate through waiting area to update the student's waiting time
    waitingArea.moveToStart();
    for (int i = waitingArea.length(); i > 0; i--) {
        waitingArea.getValue()->UpdateWaitingTime();
        waitingArea.next();
    }
    waitingArea.moveToStart();

    // simulate 1 minute in the window area
    windowArea.Update();

    officeTime++;
}

/*
Function Name: AddStudentsToQueue
What it does: This functions add students to the waiting queue.
Parameters and Data Types: The only parameter that this function takes in is a pointer of the student class.
Return value and data type: Since this is a void function, no value is returned.
*/
void Office::AddStudentsToQueue(Student *student) {
    waitingArea.insertBack(student);
}

/*
Function Name: SortListOfWaitingTimes
What it does: This functions sorts the list of wait times and calculates the mean, longest wait time, median wait time,
and number of wait times over 10.
Parameters and Data Types: No parameters or data types
Return value and data type: Since this is a void function, no value is returned.
*/
void Office::SortListOfWaitingTimes() {

  int lengthOfList = listOfWaitingTimes.length();
    int arrListOfWaitingTimes [lengthOfList];

    listOfWaitingTimes.moveToStart();
    for (int i = 0; i < lengthOfList; i++) {
        arrListOfWaitingTimes[i] = listOfWaitingTimes.remove();
    }

    int indexSmallestVal = 0;
    int tempVal = 0;

    for (int i = 0; i < lengthOfList - 1; i++) {

        indexSmallestVal = i;

        for (int j = i + 1; j < lengthOfList; j++) {
            if (arrListOfWaitingTimes[j] < arrListOfWaitingTimes[indexSmallestVal]) {
                indexSmallestVal = j;
            }
        }

        tempVal = arrListOfWaitingTimes[i];
        arrListOfWaitingTimes[i] = arrListOfWaitingTimes[indexSmallestVal];
        arrListOfWaitingTimes[indexSmallestVal] = tempVal;
    }

    this->medianWaitingTime = arrListOfWaitingTimes[lengthOfList/2];
    this->longestWaitingTime = arrListOfWaitingTimes[lengthOfList - 1];

    for (int i = 0; i < lengthOfList; i++) {
        meanWaitingTime += arrListOfWaitingTimes[i];
        if (arrListOfWaitingTimes[i] > 10)
            this->numOfStudentsWaitingOverTen++;
    }

    this->meanWaitingTime /= lengthOfList;

    std::cout << "Mean Student Wait Time in Queue: " << this->meanWaitingTime << std::endl;
    std::cout << "Median Student Wait Time in Queue: " << this->medianWaitingTime << std::endl;
    std::cout << "Longest Student Wait Time in Queue: " << this->longestWaitingTime << std::endl;
    std::cout << "Number of Students Waiting over 10 Minutes: " << this->numOfStudentsWaitingOverTen << std::endl;
    windowArea.SortListOfIdleTimes();
}

/*
Function Name: DisplayOfficeData
What it does: This function displays the progression of the office data. This function was created to make sure that the
simulation is working correctly.
Parameters and Data Types: No parameters or data types
Return value and data type: Since this is a void function, no value is returned.
*/
void Office::DisplayOfficeData() {

    std::cout << "Office Time: " << this->officeTime << std::endl;
    windowArea.DisplayWindowData();

    std::cout << " Students in the queue" << std::endl;

    waitingArea.moveToStart();
    for(int i = 0; i < waitingArea.length(); i++) {
        std::cout << " |" << waitingArea.getValue()->GetWindowTime() << "|\n";
        std::cout << " --\n";
        waitingArea.next();
    }
    waitingArea.moveToStart();

}
