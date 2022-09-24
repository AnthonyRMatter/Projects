/*
File Name: Window.cpp
This file is meant to simulate through a set of windows, determine if there is enough space to take in students,
and track how long windows are idle.
*/
#include "Window.h"
#include "Student.h"
#include <iostream>

Window::Window(int size) {

    window = new Student*[size];

    for (int i = 0; i < size; i++) {
        window[i] = new Student();
    }

    arrayIdleTimes = new int[size];

    this->maxCapacity = size;
    numOccupiedWindows = 0;
    overallTime = 0;
    longestIdleTime = 0;
    numOfIdleTimeAboveFive = 0;

    // Assigining the initial available window positions in the window array
    for (int i = 0; i < maxCapacity; i++) {
        nextAvailableWindow.enqueue(i);
    }
}

Window::~Window() {

    for (int i = 0; i < maxCapacity; i++) {
        delete window[i];
    }
    delete [] window;
    delete [] arrayIdleTimes;
}
/*
Function Name: AddStudent
What it does: Determines if we can add a student and if so, save the idle time
Parameters and Data Types: The only parameter that this function takes in is a pointer of the student class
Return value and data type: Since this is a void function, no value is returned.
*/
void Window::AddStudent(Student *student) {

    if (numOccupiedWindows < maxCapacity) {

        student->SetWindowPos(nextAvailableWindow.dequeue());

        window[student->GetWindowPos()] = student;

        // Save the idle time for the window
        listOfIdleTimes.append(arrayIdleTimes[student->GetWindowPos()]);

        if (arrayIdleTimes[student->GetWindowPos()] > 5)
            numOfIdleTimeAboveFive++;
        if (arrayIdleTimes[student->GetWindowPos()] > longestIdleTime)
            longestIdleTime = arrayIdleTimes[student->GetWindowPos()];

        // Reset idle time position
        arrayIdleTimes[student->GetWindowPos()] = 0;

        numOccupiedWindows++;

    } else {
        std::cout << "We are at max capacity! Cannot attend to anymore students." << std::endl;
    }

}

/*
Function Name: RemoveStudent
What it does: Removes a student by indicating their window position is available
Parameters and Data Types: The only parameter that this function takes in is an int value of the window position
Return value and data type: Since this is a void function, no value is returned.
*/
void Window::RemoveStudent(int windowPos) {
    numOccupiedWindows--;
    nextAvailableWindow.enqueue(windowPos);
}

/*
Function Name: Update
What it does: Removes a student by indicating their window position is available
Parameters and Data Types: The only parameter that this function takes in is an int value of the window position
Return value and data type: Since this is a void function, no value is returned.
*/
void Window::Update() {

    overallTime++;

    for (int i = 0; i < maxCapacity; i++) {
        if (arrayIdleTimes[i] == 0 && window[i]->GetWindowTime() != 0) { // Window clerk has a student

            window[i]->UpdateWindowTime();

            if (window[i]->GetWindowTime() == 0) {                       // Indicates student finished
                RemoveStudent(i);
            }

        } else {
            arrayIdleTimes[i]++;                                        // Window clerk doesn't have anyone, increment their idle time
        }

    }

}


/*
Function Name: UpdateIdleTimeList
What it does: This function is used to call at the end of file after processing all the students and updates the idle time list.
Parameters and Data Types: No parameters or data types
Return value and data type: Since this is a void function, no value is returned.
*/
void Window::UpdateIdleTimeList() {

    for (int i = 0; i < maxCapacity; i++) {
        if (arrayIdleTimes[i] != 0) {
            if (arrayIdleTimes[i] > 5)
                numOfIdleTimeAboveFive++;

            if (arrayIdleTimes[i] > longestIdleTime)
                longestIdleTime = arrayIdleTimes[i];

            listOfIdleTimes.append(arrayIdleTimes[i]);
        }
    }

}

/*
Function Name: SortListOfIdleTimes
What it does: This functions sorts the list of idle times and calculates the mean, longest idle time,
and number of idle times over 5.
Parameters and Data Types: No parameters or data types
Return value and data type: Since this is a void function, no value is returned.
*/
void Window::SortListOfIdleTimes() {

    double sumOfIdleTimes = 0.0;
    int idleLengthofList = listOfIdleTimes.length();
    int arrListofIdleTimes [idleLengthofList];
    listOfIdleTimes.moveToStart();
    for (int i = 0; i < idleLengthofList; i++) {
        arrListofIdleTimes[i] = listOfIdleTimes.remove();
    }

    int indexSmallestValue = 0;
    int tempValue = 0;

    for (int i = 0; i < idleLengthofList - 1; i++) {

        indexSmallestValue = i;

        for (int j = i + 1; j < idleLengthofList; j++) {
            if (arrListofIdleTimes[j] < arrListofIdleTimes[indexSmallestValue]) {
                indexSmallestValue = j;
            }
        }

        tempValue = arrListofIdleTimes[i];
        arrListofIdleTimes[i] = arrListofIdleTimes[indexSmallestValue];
        arrListofIdleTimes[indexSmallestValue] = tempValue;
    }

    this->longestIdleTime = arrListofIdleTimes[idleLengthofList - 1];

    for (int i = 0; i < idleLengthofList; i++) {
        this->avgIdleTime += arrListofIdleTimes[i];
        if (arrListofIdleTimes[i] > 5)
            this->numOfIdleTimeAboveFive++;
    }

    this->avgIdleTime /= idleLengthofList;

    std::cout << "Mean Window Idle Time: " << this->avgIdleTime << std::endl;
    std::cout << "Longest Window Idle Time: " << this->longestIdleTime << std::endl;
    std::cout << "Number of Windows Idle over 5 Minutes: " << this->numOfIdleTimeAboveFive << std::endl;
}
/*
Function Name: DisplayWindowData
What it does: This function displays the progression of the window data. This function was created to make sure that the
simulation is working correctly.
Parameters and Data Types: No parameters or data types
Return value and data type: Since this is a void function, no value is returned.
*/
void Window::DisplayWindowData() {

    //std::cout << "Time: " << overallTime << std::endl;

    std::cout << " Window " << std::endl;
    std::cout << "|";
    for (int i = 0; i < maxCapacity; i++) {
        std::cout << window[i]->GetWindowTime() << "|";
    }
    std::cout << "\n" << std::endl;

}
