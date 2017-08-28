/*
Assignment: CS 211 - MA4
Description: Linked List - Pop
Author: "Jack" Daniel Kinne
HSU ID: 9395-18119
Completion Time: 4 Hours (ish)
worked with: Jack W
*/
#ifndef STACK_H
#define STACK_H

#include "LinkedListNode.h"

template <typename T>
class Stack
{
private:
    LinkedListNode<T> *_top = nullptr;
    int _size = 0;

public:
    Stack()
    {

    }

    //Adds a new item onto our stack
    void push(T value)
    {
        LinkedListNode<T> *next = new LinkedListNode<T>{value};
        next->setNext(_top);
        _top = next;
        _size++;
    }

    //removes an item from the stack
    T pop()
    {
		/*	go to the first element
			look at its next  "list.next"
			probably delete the memory at the first location
			temp = current list pointer
			current list pointer now becomes two
			kill temp */
		LinkedListNode<T> *_temp = _top; // temp holder for our LL so we don't lose it
		T popReturn = _temp -> getValue(); // return object from pop
		_top = _top->getNext(); // set LL to LL arrow get next object in LL (memory loc 2)
		delete(_temp); //cleanup using the DECONSTRUCTOR OMGLAWL
		_size--;  //decrement listing
		return popReturn;
    }

    //returns size of stack
    int getSize()
    {
        return _size;
    }

    //returns whether or not stack is empty
    bool isEmpty()
    {
        return _size == 0;
    }
};

#endif // STACK_H
