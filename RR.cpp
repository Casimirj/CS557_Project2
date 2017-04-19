#include "RR.h"
#include<iostream>



RR::RR(Queue* input, int timeslice){
    processTable = input;
    readyQueue = new Queue();
    numOfProcesses = readyQueue->getSize();
    totalWaitTime = 0;
    averageWaitTime = 0;
    tickNumber = 0;
    running = new Process(true);
    timeLimit = timeslice;
    terminatedQueue = new Queue();
}

void RR::tick(){
    readyQueue->enqueue(processTable->getArriving(tickNumber));
    if(running->getProgCounter() == 0 && readyQueue->isEmpty()){
        terminatedQueue->enqueue(running);
        finished = true;
        return;
    }
    else if(running->isEmpty() && !readyQueue->isEmpty()){
        running = readyQueue->dequeue(); //first tick case
    }
    if(running->getProgCounter() == 0 || tickNumber % timeLimit == 0){ //need to switch case
        switchProcesses();
    }
    readyQueue->incWaitTimes();
    running->deIncProgCounter();
    tickNumber++;
}
void RR::switchProcesses(){
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

void RR::output(){
    numOfProcesses = terminatedQueue->getSize();
    totalWaitTime = terminatedQueue->getTotalWaitTime();
    averageWaitTime = (((float) totalWaitTime) / ((float) numOfProcesses));

    std::cout << "--------------------------RR--------------------------\n"
              << "Number of processes Executed: " << numOfProcesses <<std::endl
              << "Total ticks: " << tickNumber <<std::endl
              << "Total wait time: " << totalWaitTime <<std::endl
              << "Average waiting time: " <<averageWaitTime<<std::endl
              << "--------------------------------------------------------\n";

}


bool RR::isFinished() {
    return finished;
}
void RR::print(){
    std::cout << "\nFIRST COME FIRST SERVE ALGORITHM\n"
              << "  Finished: " << finished << "\n"
              << "  Tick Number: " << tickNumber << "\n"
              << "-------Queues-----------\n"
              << "READY QUEUE:\n";
    readyQueue->print("READY QUEUE");
    std::cout << "----Running Process-----\n";
    std::cout << "Running: ";running->print();
    std::cout << std::endl;
    std::cout << "----Terminated Queue-----\n"
              << "Terminated: ";
    terminatedQueue->print("Terminated");

    std::cout << "END OF FIRST COME FIRST SERVE---\n\n\n\n";


}//
// Created by poop on 4/13/17.
//

#include "RR.h"
