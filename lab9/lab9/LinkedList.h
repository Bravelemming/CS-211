#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "LinkedListNode.h"
//all functions: getNodeAtIndex, createNode, addElementAt, removeElement are virtual
template <typename T>
class LinkedList
{
protected:
    LinkedListNode<T> *_front = nullptr;
    int _size = 0;

	virtual LinkedListNode<T>* getNodeAtIndex(int index) {
		//TODO: make sure index is within bounds
		LinkedListNode<T> *cursor = _front;
		int counter = 0;

		//move forward through our LL until we hit
		//either nullptr (somewhat unexpected)
		//or we arrive at the requested index
		while (cursor != nullptr && counter < index)
		{
			cursor = cursor->getNext();
			counter++;
		}

		//At here: we've arrived at our index
		return cursor;
	}
	//this function allows abstraction of object creation into a function whihc allows
	//us to change the type of object created in child classes
	virtual LinkedListNode<T>* createNode(T value) {
		return new LinkedListNode<T>{ value };
	}

public:

    //empty constructor that does nothing
    LinkedList()
    {
    }

    //Copy constructor.  Allows for perfect duplication
    //of an existing linked list.  (note: you're going
    //to do something similar for PA5)
    LinkedList(const LinkedList<T>& to_copy)
    {
        //Remember: goal is to make perfect copy.  So
        //we start at the front
        LinkedListNode<T> *copy_node = to_copy._front;

        //it's possible that copy_node starts off null
        if(copy_node == nullptr)
        {
            _front = nullptr;
            _size = to_copy._size;
            return;
        }

        //make a copy of to_copy's front
        _front = new LinkedListNode<T>{*copy_node};

        //used to move through our LL
        LinkedListNode<T> *cursor = _front;

        //make copies of each item
        copy_node = copy_node->getNext();
        while(copy_node != nullptr)
        {
            //make copy of node
            LinkedListNode<T> *copy =
                new LinkedListNode<T>(*copy_node);

            //assign result to our cursor
            cursor->setNext(copy);

            //progress both cursor and copy_node forward
            cursor = cursor->getNext();
            copy_node = copy_node->getNext();
        }
    }

    //Move constructor: assume ownership of an existing LL
    LinkedList(LinkedList<T> &&to_move)
    {
        _size = to_move._size;
        _front = to_move._front;
        to_move._front = nullptr;
    }

    //destructor needs to delete all dynamically created
    //nodes
    virtual ~LinkedList()
    {
        LinkedListNode<T> *cursor = _front;
        while(cursor != nullptr)
        {
            LinkedListNode<T> *temp = cursor->getNext();
            delete cursor;
            cursor = temp;
        }
    }

    //returns a value at a specific location inside LL
    virtual T getElementAt(int index)
    {
		return getNodeAtIndex(index)->getValue();
    }

    int getSize() const
    {
        return _size;
    }

    void AddElementToEnd(T value)
    {
        addElementAt(value, _size);
    }

    virtual T removeElementAt(int index)
    {
        _size--;

        //special case: remove first element
        if(index == 0)
        {
            LinkedListNode<T> *temp = _front->getNext();
            T value = _front->getValue();
            delete _front;
            _front = temp;
            return value;
        }

		LinkedListNode<T> *previous = getNodeAtIndex(index - 1);
        LinkedListNode<T> *current = previous->getNext();
        

        //remove current from LL
        previous->setNext(current->getNext());

        //delete current from memory
        T value = current->getValue();
        delete current;
        return value;
    }

    virtual void addElementAt(T value, int index)
    {
        //create a new linked list node
		LinkedListNode<T> *new_node = createNode(value);

        //special case check: are we adding to the front?
        if(index == 0)
        {
            //attach current front to new_node
            new_node->setNext(_front);
            _front = new_node;
            _size++;
            return;
        }

		LinkedListNode<T> *previous = getNodeAtIndex(index - 1);
        LinkedListNode<T> *current = previous->getNext();
        

        //At this point, we need to connect new_node
        //into our LL.  Meaning, set previous' next to
        //new_node and new_node's next to current
        previous->setNext(new_node);
        new_node->setNext(current);
        _size++;
    }
};

#endif // LINKED_LIST_H
