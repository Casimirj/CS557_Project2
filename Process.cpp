#include "Process.h"
#include <iostream>

Process::Process() {
    next = NULL;
    previous = NULL;

}
Process::Process(Process* input){
    progCounter = input->getProgCounter();
    arrivingTime = input->getArrivingtime();
    waitTime = input->getWaitTime();
    id = input->getId();
}
Process::Process(int idInput, int numInstructionsInput, int arrivingInput){
    next = NULL;
    previous = NULL;
    id = idInput;
    progCounter = numInstructionsInput;
    arrivingTime = arrivingInput;
}
Process::Process(bool input){
    empty = true;
    progCounter = 0;
}

//----------------------------Node Stuff--------------------------------------
void Process::setNext(Process* input){ next = input; }
void Process::setNextAsNull(){ next = NULL;}
void Process::setPrevious(Process* input){ previous = input; }
void Process::setPreviousAsNull(){previous = NULL;}

Process* Process::getNext(){ return next; }
Process* Process::getPrevious(){ return previous; }

bool Process::nextIsNull(){ return (next == NULL);}
bool Process::prevIsNull(){ return (previous == NULL);}
bool Process::processIsStranded(){ return (nextIsNull() && prevIsNull()); }
//----------------------------------Getters------------------------------------
int Process::getProgCounter(){return progCounter;}
int Process::getArrivingtime() {return arrivingTime;}
bool Process::isArriving(int input) {return (arrivingTime == input);}
bool Process::isEmpty(){return empty;};
int Process::getWaitTime() {return waitTime;}

//----------------------------------Setters------------------------------------
void Process::setProgCounter(int input) {progCounter = input;}
void Process::deIncProgCounter() {progCounter--;}
void Process::incWaitTime() {waitTime++;}

//--------------------------------Process Functions----------------------------

void Process::print(){
    if(this->isEmpty()) std::cout << "EMPTY";
    std::cout << "[instleft:" << progCounter<< ",arrivingtime:"<<arrivingTime<<",waitTime:"<<waitTime<<"]";
}

int Process::getId() const {
    return id;
}

void Process::setId(int id) {
    Process::id = id;
}
