//
// Created by poop on 4/4/17.
//

#ifndef CS557_PROJECT2_JAMES_CASIMIR_SRTF_H
#define CS557_PROJECT2_JAMES_CASIMIR_SRTF_H

#include"Queue.h"
#include"Process.h"


class SRTF {
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
    SRTF(Queue* input);
    void tick();

    void reset();
    bool isFinished();

    void switchProcesses();
    void sortReadyQueue();

    void output();
    void print();
    void printGanttChart();

};



#endif //CS557_PROJECT2_JAMES_CASIMIR_SRTF_H
