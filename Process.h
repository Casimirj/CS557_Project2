#ifndef PROCESS_H
#define PROCESS_H
#include <cstddef>
#include <string>


class Process
{
private:
    //-------Node------------
    Process* next;
    Process* previous;

    //------Process----------
    int id;
public:
    void setId(int id);

public:
    int getId() const;

private:
    int progCounter;
    int arrivingTime;
    int waitTime = 0;
    bool empty = false;

public:
    Process();
    Process(Process* input);
    Process(int id, int numInstructionsInput, int arrivingInput);
    Process(bool input);

    void print();

    //----------------------Node Stuff--------------

    //void setValue(int input);
    void setNext(Process* input);
    void setNextAsNull();
    void setPrevious(Process* input);
    void setPreviousAsNull();

    Process* getNext();
    Process* getPrevious();

    bool nextIsNull();
    bool prevIsNull();
    bool processIsStranded();
    //-----------------------Process Stuff------------
    //---------------Getters-----------------
    int getProgCounter();
    int getArrivingtime();
    bool isArriving(int input);
    bool isEmpty();
    int getWaitTime();
    //------------Setters---------------------
    void setProgCounter(int input);
    void deIncProgCounter();
    void incWaitTime();

};

#endif // PROCESS_H
