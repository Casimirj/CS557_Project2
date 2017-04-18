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
    if(tickNumber == 0) processTable->print("OG Procs ;)");
    readyQueue->enqueue(processTable->getArriving(tickNumber));
    if(readyQueue->isEmpty()){
        if(!running->isEmpty()) terminatedQueue->enqueue(running);
        finished = true;
        return;
    }
    if(running->isEmpty() && !readyQueue->isEmpty()){
        running = new Process(readyQueue->dequeue()); //first tick case
    }
    if(running->getProgCounter() == 0 && !running->isEmpty()){ //need to switch case
        switchProcesses();
    }

    if(!running->isEmpty())running->deIncProgCounter();
    readyQueue->incWaitTimes();
    print();
    switchProcesses();
    if(tickNumber != 4) readyQueue->sort();

    print();
    tickNumber++;

}

void SRTF::switchProcesses(){
    if(running->getProgCounter() == 0 && !running->isEmpty()){
        Process* tmp = new Process(running);
        terminatedQueue->enqueue(tmp);
        running = new Process(true);
    }
    else{
        if(!running->isEmpty())readyQueue->enqueue(new Process(running));
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
    std::cout << "\nSHORTEST REMAINING JOB FIRST-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-\n"
              << "  Finished: " << finished << "\n"
              << "  Tick Number: " << tickNumber << "\n"
              << "-------Queues-----------\n"
              << "READY QUEUE:\n";
    readyQueue->print("READY QUEUE");
    std::cout << "----Running Process-----\n";
    std::cout << "Running: ";running->print();
    std::cout << std::endl;
    //std::cout << "----Process Table-----\n"
    //          << "Table: ";
    //processTable->print("ProcTable");
    std::cout << "----Terminated Queue-----\n"
              << "Terminated: ";
    terminatedQueue->print("Terminated");

    std::cout << "END OF SHORTEST JOB FIRST---\n\n";


}