#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

#include <string>
using namespace std;

template<typename T>
class LinkedListNode
{
protected:
    T _value;
    LinkedListNode *_next = nullptr;

public:
    LinkedListNode(T value)
    {
        _value = value;
    }

    LinkedListNode(const LinkedListNode<T>& to_copy)
    {
        //copy value
        _value = to_copy.getValue();

        //Note: we could recursively call the copy constructor
        //on to_copy's next, but this might be overstepping.
        _next = nullptr;
    }

    //Because we are templated, we don't know what the default
    //value for T data type should be, so we need a default,
    //empty constructor.
    LinkedListNode(){}

    T getValue()
    {
        return _value;
    }

    void setValue(T value)
    {
        _value = value;
    }

    LinkedListNode *getNext()
    {
        return _next;
    }

    void setNext(LinkedListNode *next)
    {
        _next = next;
    }
};

#endif // LINKED_LIST_NODE_H
