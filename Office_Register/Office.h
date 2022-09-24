#ifndef OFFICE_H
#define OFFICE_H

#include "DataStructures/LinkedListQueue.h"
#include "DataStructures/SLList.h"
#include "DataStructures/DLList.h"
#include "Student.h"
#include "Window.h"
#include <string>
#include <unistd.h> // for usleep() when pausing in between generations
#include <fstream>


class Office {
    public:
        Office(int windowSize);
        ~Office();

        int GetOfficeTime() { return this->officeTime; }

        void Update();
        bool IsEmpty() { return (windowArea.isEmpty() && waitingArea.isEmpty()); }
        void AddStudentsToQueue(Student *student);
        void DisplayOfficeData();

        DLList<Student*> waitingArea;
        SLList<int> listOfWaitingTimes;
        Window windowArea;

        std::ifstream inFS;
        int officeTime;
        int numOfStudentsWaiting;
        void SortListOfWaitingTimes();

        double meanWaitingTime;
        int medianWaitingTime;
        int longestWaitingTime;
        int numOfStudentsWaitingOverTen = 0;

    private:

};

#endif
