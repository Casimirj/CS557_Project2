 #ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include "Process.h"

class Queue
{
	private:
		LinkedList* list;
        int size;


    public:
        Queue();
        Queue(LinkedList* input);
        Process* peek();
		void enqueue(Process* input);
        void enqueue(LinkedList* input);
        LinkedList* getArriving(int input);
		Process* dequeue();
		bool isEmpty();
        int getSize();
        void incWaitTimes();
        int getTotalWaitTime();
        void sort();
		void swap(Process* p1, Process* p2);
        bool isSorted();
        void print(std::string nameInput);
        void printGanttChart();
};

#endif // QUEUE_H
