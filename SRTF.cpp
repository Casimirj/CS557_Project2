#include "SRTF.h"

#include<iostream>



SRTF::SRTF(Queue* input){
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

void SRTF::tick(){
    readyQueue->enqueue(processTable->getArriving(tickNumber));
    if(running->isEmpty() && !readyQueue->isEmpty()){
        running = readyQueue->dequeue(); //first tick case
    }
    if(running->getProgCounter() == 0 && readyQueue->isEmpty()){
        terminatedQueue->enqueue(running);
        finished = true;
        return;
    }
    if(running->getProgCounter() == 0 || tickNumber == timeLimit){ //need to switch case
        switchProcesses();
    }
    readyQueue->incWaitTimes();
    running->deIncProgCounter();
    switchProcesses();
    readyQueue->sort();
    tickNumber++;
}

void SRTF::switchProcesses(){
    if(running->getProgCounter() == 0){
        Process* tmp = new Process(running);
        terminatedQueue->enqueue(tmp);
        running = readyQueue->dequeue();
    }
    else{
        readyQueue->enqueue(running);
        running = new Process(true);
    }
}

void SRTF::output(){
    numOfProcesses = terminatedQueue->getSize();
    totalWaitTime = terminatedQueue->getTotalWaitTime();
    averageWaitTime = (((float) totalWaitTime) / ((float) numOfProcesses));

    std::cout << "--------------------------SRTF--------------------------\n"
              << "Number of processes Executed: " << numOfProcesses <<std::endl
              << "Total ticks: " << tickNumber <<std::endl
              << "Total wait time: " << totalWaitTime <<std::endl
              << "Average waiting time: " <<averageWaitTime<<std::endl
              << "--------------------------------------------------------\n";

}


bool SRTF::isFinished() {
    return finished;
}
void SRTF::print(){
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