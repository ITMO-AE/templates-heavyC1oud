#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Node
{
public:
    T data;
    Node<T>* pNext;
    Node<T>* pPrev;

    Node(T data):
        data(data), pNext(nullptr), pPrev(nullptr)
    {
    }
};

template <typename T>
class Deque
{
private:
    Node<T>* head;
    Node<T>* tail;
    int dequeSize;

public:
    Deque():
        dequeSize(0)
    {   
    }

    bool empty() const
    {
        if(dequeSize == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    int size() const
    {
        return dequeSize;
    }

    T& getData(int index)
    {
        Node<T>* currentData = this->tail;
        int j = 0;

        if((index < 0) || (index > dequeSize))
        {
            throw std::out_of_range{"index out of range"};
        }

        for(int i = 0; i < dequeSize; i++)
        {
            if(j == i) {
                return currentData->data;
            }

            currentData = currentData->pNext;
            j++;
        }
    }

    T& operator[](size_t index)
    {
        try {
            return getData(index);
        }
        catch (std::out_of_range) {
        }
    }

    const T& operator[](size_t index) const
    {
        try {
            return getData(index);
        }
        catch (std::out_of_range) {
        }
    }

    T& At(size_t index)
    {
        try {
            return getData(index);
        }
        catch (std::out_of_range) {
        }
    }

    const T& At(size_t index) const
    {
        try {
            return getData(index);
        }
        catch (std::out_of_range) {
        }
    }

    T& Front()
    {
        return this->tail->data;
    }

    const T& Front() const
    {
        return this->tail->data;
    }

    T& Back()
    {
        return this->head->data;
    }

    const T& Back() const
    {
        return this->head->data;
    }

   void PushFront(T data)
   {
        Node<T>* newData = new Node<T>(data);

        if(dequeSize == 0) {
            head = newData;
            tail = newData;
        }
        else {
            newData->pPrev = head;
            head = newData;
        }

        dequeSize++;
    }

   void PushBack(T data)
   {
        Node<T>* newData = new Node<T>(data);

        if(dequeSize == 0) {
            head = newData;
            tail = newData;
        }
        else {
            newData->pNext = tail;
            tail = newData;
        }

        dequeSize++;
    }
};


#endif
