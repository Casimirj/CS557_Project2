#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>
#include <iostream>
#include "Process.h"


class LinkedList {
private:
    Process* head;
    Process* tail;
public:
    LinkedList();

    Process* getHead();
    Process* getTail();
    void setHead(Process* input);
    void setTail(Process* input);

    LinkedList* getArrivingProcess(int arrivingTime);



    void addAtHead(Process* input);

    Process* removeAtHead();

    void addAtTail(Process* tail);

    Process* removeAtTail();

    bool isEmpty();

    void print(std::string nameInput);
};

#endif // LINKEDLIST_H
