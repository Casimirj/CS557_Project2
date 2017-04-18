#include "Queue.h"
#include "LinkedList.h"
#include "Process.h"

Queue::Queue() {
    list = new LinkedList();
    size = 0;
}
Queue::Queue(LinkedList* input){
    list = new LinkedList();
    size = 0;
    this->enqueue(input);


}
Process* Queue::peek(){
    return list->getHead();
}
void Queue::enqueue(Process* input){ list->addAtHead(input); size++;}
void Queue::enqueue(LinkedList* input){
    while(!input->isEmpty()){
         this->enqueue(input->removeAtTail());
    }
}
LinkedList* Queue::getArriving(int input) {return list->getArrivingProcess(input);}

Process* Queue::dequeue(){ size--; return (list->removeAtTail()); }
bool Queue::isEmpty(){return (size <= 0);}
int Queue::getSize(){return size; }

void Queue::incWaitTimes() {
    if(!list->isEmpty()){
        Process* iterator = list->getHead();
        while(iterator->getNext() != NULL){
            iterator->incWaitTime();
            iterator= iterator->getNext();
        }
        iterator->incWaitTime();
    }
}
int Queue::getTotalWaitTime() {
    int output = 0;
    if(!list->isEmpty()){
        Process* iterator = list->getHead();
        while(iterator->getNext() != NULL){
            output += iterator->getWaitTime();
            iterator = iterator->getNext();
        }
    }
    return output;
}

void Queue::sort(){//Bubble Sort
    if(this->isSorted()) std::cout << "Already done baby!\n";
    while(!this->isSorted()){
        Process* iterator = list->getHead();
        while(iterator->getNext() != NULL){
            if(iterator->getProgCounter() < iterator->getNext()->getProgCounter()){
                swap(iterator, iterator->getNext());
                iterator = list->getHead();

            }
            else{ // p1 !> p2,move on
                iterator = iterator->getNext();
            }
        }

    }

}
void Queue::swap(Process* p1, Process* p2){
    Process* tmp = new Process();
    if(p1->getPrevious() != NULL){
        tmp->setPrevious(p1->getPrevious());
        p2->setPrevious(tmp->getPrevious());

        if(p2->getNext()!= NULL){p1->setNext(p2->getNext());}
        else{p1->setNextAsNull();}

        p2->setNext(p1);
        p1->setPrevious(p2);


        p2->getPrevious()->setNext(p2);
    }
    else{
        tmp = list->removeAtHead();
        Process* tmp2 = list->removeAtHead();

        list->addAtHead(tmp);
        list->addAtHead(tmp2);

    }





}
/*LinkedList* sorted = new LinkedList();
    if(!list->isEmpty()){
        int prevMin = 0;
        while(!list->isEmpty()) {
            Process* iterator = list->getHead();
            list->print("listname");
            int minimum = iterator->getProgCounter();
            Process* tmp;
            while (iterator->getNext() != NULL) {
                if(iterator->getProgCounter() < minimum && iterator->getProgCounter() >= prevMin){
                    tmp = new Process(iterator);
                    if(iterator->getProgCounter() == list->getHead()->getProgCounter() && iterator->getArrivingtime() == list->getHead()->getArrivingtime() && iterator->getWaitTime() == list->getHead()->getWaitTime()){
                        list->setHead(iterator->getNext());
                        iterator->getNext()->setPreviousAsNull();
                    }
                    else{
                        iterator->getPrevious()->setNext(iterator->getNext());
                    }
                    minimum = iterator->getProgCounter();
                }
                iterator = iterator->getNext();
            }
            sorted->addAtTail(tmp);
            prevMin = minimum;
            if(list->getHead()->nextIsNull()) sorted->addAtTail(list->removeAtHead());
        }
    }
    list = sorted;*/
bool Queue::isSorted(){
    if(!list->isEmpty()){
        Process* iterator = list->getHead();
        if(iterator->getNext() != NULL){
            while(iterator->getNext()->getNext() != NULL){
                if(iterator->getProgCounter() < iterator->getNext()->getProgCounter()) return false;
                iterator = iterator->getNext();
            }
            if(iterator->getProgCounter() < iterator->getNext()->getProgCounter()) return false;
        }

    }
    return true;
}

void Queue::print(std::string nameInput){
    list->print(nameInput);
}
void Queue::printGanttChart(){
    if(!list->isEmpty()){
        Process* iterator = list->getHead();
        for(int i = 1; iterator->getNext() != NULL; i++ ){

        }
    }
}