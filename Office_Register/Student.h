#ifndef STUDENT_H 
#define STUDENT_H

class Student {
    public:
        Student();
        Student(int windowTime);
        ~Student();

        void SetWindowTime(int windowTime) { this->windowTime = windowTime; }
        void UpdateWindowTime();
        void UpdateWaitingTime();
        int GetWindowTime() { return this->windowTime; }
        int GetWaitingTime() { return this->waitingTime; }
        void SetWindowPos(int windowPos) { this->windowPos = windowPos; }
        int GetWindowPos() { return this->windowPos; }

        int windowTime;
        int waitingTime;
        int windowPos;

    private:

};

#endif