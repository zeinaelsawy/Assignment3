#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std;

template <class T>
class Queue 
{
    private:
    int front;
    int rear;
    int counter;
    int maxSize;
    T* values;
    
    public:
    Queue() 
    {
        int size = 10;
        values = new T[size];
        maxSize = size;
        front = 0;
        rear = -1;
        counter = 0;
    }
    ~Queue() 
    {
        delete[] values;
    }
    bool isEmpty() 
    {
        if (counter != 0)
            return false;
        else
            return true;
    }
    bool isFull() 
    {
        if (counter < maxSize)
            return false;
        else
            return true;
    }
    bool enqueue(T& item) 
    {
        if (isFull()) 
        {
            cout << "Error- Queue full" << endl;
            return false;
        }
        else 
        {
            rear = (rear + 1) % maxSize;
            values[rear] = item;
            counter++;
            return true;
        }
    }
    T dequeue() 
    {
        if (isEmpty()) 
        {
            exit(EXIT_FAILURE);
        }
        else 
        {
            T item;
            item = values[front];
            front = (front + 1) % maxSize;
            counter--;
            return item;
        }
    }
};

#endif /* QUEUE_HPP */
