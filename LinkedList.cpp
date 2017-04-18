#include "LinkedList.h"
#include "Process.h"


LinkedList::LinkedList()
{
    Process* head = NULL;
    Process* tail = NULL;

}
LinkedList* LinkedList::getArrivingProcess(int arrivingTime){
    LinkedList* output = new LinkedList();
    Process* iterator = head;
    //output is a linkedlist so that it can catch multiple arriving processes
    if(head != NULL){
        while(!iterator->nextIsNull()){
            if(iterator->isArriving(arrivingTime)){
                output->addAtHead(new Process(iterator));
                std::cout << "Found one at tick " << arrivingTime << std::endl;
            }
            iterator = iterator->getNext();
        }
        if(iterator->isArriving(arrivingTime)) output->addAtHead(new Process(iterator));
    }
    return output;
}



Process* LinkedList::getHead(){ return head;}
void LinkedList::setHead(Process* input) {head = input;}
Process* LinkedList::getTail(){return tail;}
void LinkedList::setTail(Process* input) {tail = input;}
void LinkedList::addAtHead(Process* input){
    Process* newProc = new Process(input);
    if(head == NULL){
        head = newProc;
        tail = newProc;
    }
    else{
        newProc->setNext(head);
        head->setPrevious(newProc);
        head = newProc;
    }
}
void LinkedList::addAtTail(Process* input){
    Process* newProc = new Process(input);
    if(head == NULL){
        head = newProc;
        tail = newProc;
    }
    else{
        tail->setNext(newProc);
        tail = newProc;
    }
}
Process* LinkedList::removeAtHead(){
    Process* tmp = new Process();
    if(head != NULL){
        tmp = new Process(head);
        if(!head->nextIsNull()){
            head = head->getNext();
            head->setPreviousAsNull();
        }
        else{
            head = NULL;
            tail = NULL;
        }
    }
    return tmp;
}
Process* LinkedList::removeAtTail(){
    Process* tmp = new Process();
    if(tail != NULL){
        tmp = tail;
        if(!tail->prevIsNull()){
            tail = tail->getPrevious();
            tail->setNextAsNull();
        }
        else{
            tail = NULL;
            head = NULL;
        }
    }
    return new Process(tmp);
}
bool LinkedList::isEmpty(){
    return (head == NULL || tail == NULL);
}

void LinkedList::print(std::string nameInput){
    std::cout << "  List : " << nameInput << " : 0000000000000000000000000000\n";
    if(head != NULL){
        Process* iterator = head;
        for(int i = 1; iterator->getNext() != NULL; i++){
            std::cout << "    Process "<< iterator->getId() << ": ";
            iterator->print();
            std::cout << "\n";
            iterator = iterator->getNext();
        }
        std::cout << "    Process "<< iterator->getId() << ": ";
        iterator->print();
        std::cout << "\n";
    }
    std::cout << "  000000000000000000000000000000000000000000\n\n";
}