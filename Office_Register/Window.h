#ifndef WINDOW_H
#define WINDOW_H

#include "Student.h"
#include "DataStructures/LinkedListQueue.h"
#include "DataStructures/SLList.h"
#include "DataStructures/Alist.h"

class Window {
    public:
        Window(int size);
        ~Window();

        void AddStudent(Student *student);
        void RemoveStudent(int windowPos);

        bool HasAvailableWindows() { return (numOccupiedWindows < maxCapacity); }
        int NextAvailableWindow() { return nextAvailableWindow.frontValue(); }

        void SortListOfIdleTimes();
        int GetLongestIdleTime() { return this->longestIdleTime; }
        int GetNumOfIdleTimesAboveFive() { return this->numOfIdleTimeAboveFive; }

        void Update();
        void UpdateIdleTimeList();
        bool isEmpty() { return (numOccupiedWindows == 0); }
        void DisplayWindowData();

        Student** window;
        int* arrayIdleTimes;
        LinkedListQueue<int> nextAvailableWindow;
        SLList<int> listOfIdleTimes;

        int overallTime;
        int numOccupiedWindows;
        int maxCapacity;

        int avgIdleTime;
        int longestIdleTime;
        int numOfIdleTimeAboveFive;


    private:
};

#endif
