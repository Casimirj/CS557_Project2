#ifndef CS557_PROJECT2_JAMES_CASIMIR_SJF_H
#define CS557_PROJECT2_JAMES_CASIMIR_SJF_H

#include"Queue.h"
#include"Process.h"

class SJF {
private:
    int tickNumber;
    int timeLimit;

    int numOfProcesses;
    int totalWaitTime;
    float averageWaitTime;
    bool finished = false;

    Queue* readyQueue;
    Queue* processTable;
    Queue* terminatedQueue;
    Process* running;

public:
    SJF(Queue* input);
    void tick();

    bool isFinished();

    void switchProcesses();
    void sortReadyQueue();

    void output();
    void print();
    void printGanttChart();

};


#endif //CS557_PROJECT2_JAMES_CASIMIR_SJF_H
