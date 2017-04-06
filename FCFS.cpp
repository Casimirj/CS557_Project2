#include "FCFS.h"
#include<iostream>



FCFS::FCFS(Queue* input){
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

void FCFS::tick(){
    readyQueue->enqueue(processTable->getArriving(tickNumber));
    if(running->getProgCounter() == 0 && readyQueue->isEmpty()){
        terminatedQueue->enqueue(running);
        finished = true;
        return;
    }
    else if(running->isEmpty() && !readyQueue->isEmpty()){
        running = readyQueue->dequeue(); //first tick case
    }
    if(running->getProgCounter() == 0 || tickNumber == timeLimit){ //need to switch case
        switchProcesses();
    }
    readyQueue->incWaitTimes();
    running->deIncProgCounter();
    tickNumber++;
}
void FCFS::switchProcesses(){
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

void FCFS::output(){
    numOfProcesses = terminatedQueue->getSize();
    totalWaitTime = terminatedQueue->getTotalWaitTime();
    averageWaitTime = (((float) totalWaitTime) / ((float) numOfProcesses));

    std::cout << "--------------------------FCFS--------------------------\n"
              << "Number of processes Executed: " << numOfProcesses <<std::endl
              << "Total ticks: " << tickNumber <<std::endl
              << "Total wait time: " << totalWaitTime <<std::endl
              << "Average waiting time: " <<averageWaitTime<<std::endl
              << "--------------------------------------------------------\n";

}


bool FCFS::isFinished() {
    return finished;
}
void FCFS::print(){
    std::cout << "\nFIRST COME FIRST SERVE ALGORITHM\n"
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

    std::cout << "END OF FIRST COME FIRST SERVE---\n\n\n\n";


}