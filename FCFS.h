#ifndef CS557_PROJECT2_JAMES_CASIMIR_FCFS_H
#define CS557_PROJECT2_JAMES_CASIMIR_FCFS_H

#include"Queue.h"
#include"Process.h"

class FCFS {
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
    FCFS(Queue* input);
    void tick();

    bool isFinished();

    void switchProcesses();
    void output();

    void print();


};


#endif //CS557_PROJECT2_JAMES_CASIMIR_FCFS_H
