#include <iostream>

#include"FCFS.h"
#include"SJF.h"
#include"SRTF.h"
#include"Queue.h"
#include"LinkedList.h"
#include"Process.h"



int TIME_QUANTUM = 15;


LinkedList* mockInput(LinkedList* inputList){

    Process* first = new Process(1, 1, 3);
    Process* second = new Process(2, 7, 0);
    Process* third = new Process(3, 3, 2);
    Process* fourth = new Process(4, 8, 1);

    inputList->addAtHead(first);
    inputList->addAtHead(second);
    inputList->addAtHead(third);
    inputList->addAtHead(fourth);

    return inputList;
}
void begin(LinkedList* inputList){
    int numProcesses;
    //LinkedList* inputList = new LinkedList();
    std::cout << "Please enter the amount of processes you wish to execute: ";
    std::cin >> numProcesses;
    std::cout << "\n\n";
    for(int i = 1; i < numProcesses; i++){
        int instructionsInput, arrivingInput;
        std::cout << "Please enter the number of instructions for process #"<<i<<": ";
        std::cin >> instructionsInput;
        std::cout << "When does this process arrive? : ";
        std::cin >> arrivingInput;
        std::cout << "\n\n";
        Process* tmp = new Process(i, instructionsInput, arrivingInput);
        inputList->addAtHead(tmp);
    }
}
void FCFS_TEST(Queue* input){
    FCFS* fcfs = new FCFS(input);
    while(!fcfs->isFinished()){
        fcfs->tick();
    }
    fcfs->output();
}
void SJF_TEST(Queue* input){
    SJF* sjf = new SJF(input);
    while(!sjf->isFinished()){
        sjf->tick();
        sjf->sortReadyQueue();
    }
    sjf->output();
}
void SRTF_TEST(Queue* input){
    SRTF* srtf = new SRTF(input);
    while(!srtf->isFinished()){
        srtf->tick();
    }
    srtf->output();
}


int main() {
    LinkedList* processes = new LinkedList();
    processes = mockInput(processes);
    Queue* input = new Queue(processes);

    FCFS_TEST(input);
    SJF_TEST(input);
    //SRTF_TEST(input);
    /*
    Queue* test = new Queue(processes);
    test->print("Before");


    test->sort();
    test->print("After");
    */




    return 0;

}











































/*


void tester() {
    //---------------------Process Test----------------------
    Process *first = new Process();
    Process *second = new Process();

    first->setNext(second);
    second->setProgCounter(2);

    std::cout << "Process Test, value should be 2: " << (first->getNext())->getProgCounter() << std::endl;

    //----------------------LinkedList Test-------------------
    first = new Process(8, 0);
    second = new Process(4,2);

    LinkedList *list = new LinkedList();
    first->setProgCounter(7);
    second->setProgCounter(4);

    list->addAtHead(first);
    list->addAtTail(second);

    Process *iterator = list->getHead();
    std::cout << "LinkedList Test 1, value should be 7: " << iterator->getProgCounter() << std::endl;
    list->addAtTail(second);

    iterator = list->getHead();
    std::cout << "LinkedList Test 2, value should be 4: " << (list->getHead()->getNext())->getProgCounter()
              << std::endl;

    //--------------------------Queue Test--------------------------
    first = new Process();
    second = new Process();

    Queue *line = new Queue();
    first->setProgCounter(3);
    second->setProgCounter(5);

    line->enqueue(first);
    line->enqueue(second);

    std::cout << "Queue Test 1, value should be 3: " << line->dequeue()->getProgCounter() << std::endl;
    std::cout << "Queue Test 2, Value should be 5: " << line->dequeue()->getProgCounter() << std::endl;
    std::cout << "Queue Test 3, value hsould be true: ";
    if (line->isEmpty()) std::cout << "True\n";
    else std::cout << "False\n";


    //--------------------------Print function tests-----------------
    first = new Process(1, 3);
    second = new Process(7, 0);
    Process* third = new Process(3, 2);
    Process* fourth = new Process(8, 1);
    std::cout << "\n\n--------------------PRINT FUNCTIONS-------------------------------\n";
    std::cout << "Process 1: "; first->print();
    std::cout << "\nProcess 2: "; second->print();
    std::cout << "\nProcess 3: "; third->print();
    std::cout << "\nProcess 4: "; fourth->print();

    list = new LinkedList();
    list->addAtHead(first);
    list->addAtHead(second);
    list->addAtHead(third);
    list->addAtHead(fourth);

    std::cout << "\nLinkedList print output:\n";
    list->print("smile list :)");
    std::cout << "\n";


    Queue* listInputTest = new Queue(list);
    std::cout << "Queue Tests :)\n";
    listInputTest->print("Smile Queue :)");



    //----------------------ALGORITHM TESTS----------------------------
    std::cout << "\n\n8888888888---------ALGsORITHM TESTS-------8888888888---------88888888888-------88888888\n";

    FCFS* fcfs = new FCFS(listInputTest);
    for(int i = 0; i < 10; i++){
        fcfs->tick();
        fcfs->print();
    }
}
*/