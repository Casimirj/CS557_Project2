#include "SJF.h"
#include<iostream>



SJF::SJF(Queue* input){
    processTable = input;
    readyQueue = new Queue();
    numOfProcesses = readyQueue->getSize();
    totalWaitTime = 0;
    averageWaitTime = 0;
    tickNumber = 0;
    running = new Process(true);
    timeLimit = 200; //TODO
    terminatedQueue = new Queue();
}

void SJF::tick(){
    readyQueue->enqueue(processTable->getArriving(tickNumber));
    if(running->isEmpty() && !readyQueue->isEmpty()){
        running = readyQueue->dequeue(); //first tick case
    }
    else if(running->getProgCounter() == 0 && readyQueue->isEmpty()){
        terminatedQueue->enqueue(running);
        finished = true;
        return;
    }
    if(running->getProgCounter() == 0 || tickNumber == timeLimit){ //need to switch case
        switchProcesses();
    }
    readyQueue->incWaitTimes();
    running->deIncProgCounter();
    tickNumber++;
}
void SJF::switchProcesses(){
    if(running->getProgCounter() == 0){
        Process* tmp = new Process(running);
        terminatedQueue->enqueue(tmp);
        running = readyQueue->dequeue();
    }
    else{
        readyQueue->enqueue(running);
        running = readyQueue->dequeue();
    }
}
void SJF::sortReadyQueue(){
    readyQueue->sort();
}
void SJF::output(){
    numOfProcesses = terminatedQueue->getSize();
    totalWaitTime = terminatedQueue->getTotalWaitTime();
    averageWaitTime = (((float) totalWaitTime) / ((float) numOfProcesses));

    std::cout << "--------------------------SJF--------------------------\n"
              << "Number of processes Executed: " << numOfProcesses <<std::endl
              << "Total ticks: " << tickNumber <<std::endl
              << "Total wait time: " << totalWaitTime <<std::endl
              << "Average waiting time: " <<averageWaitTime<<std::endl
              << "Gantt Chart:\n";



    std::cout << "--------------------------------------------------------\n";

}


bool SJF::isFinished() {
    return finished;
}
void SJF::print(){
    std::cout << "\nSHORTEST JOB FIRST\n"
              << "  Finished: " << finished << "\n"
              << "  Tick Number: " << tickNumber << "\n"
              << "-------Queues-----------\n"
              << "READY QUEUE:\n";
    readyQueue->print("READY QUEUE");
    std::cout << "----Running Process-----\n";
    std::cout << "Running: ";running->print();
    std::cout << std::endl;
    std::cout << "----Process Table-----\n"
              << "Table: ";
    processTable->print("ProcTable");
    std::cout << "----Terminated Queue-----\n"
              << "Terminated: ";
    terminatedQueue->print("Terminated");

    std::cout << "END OF SHORTEST JOB FIRST---\n\n\n\n";


}