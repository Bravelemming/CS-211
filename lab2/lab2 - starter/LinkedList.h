#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>
#include <initializer_list>
#include "LinkedListNode.h"
#include <utility>
using namespace std;

template <typename T>
class LinkedList
{
private:

	//points to the front of the linked list
	LinkedListNode<T> *_front = nullptr;

	//keeping track of size in a variable eliminates need to continually
	//count LL boxes.
	int _size = 0;

protected:

    //creates a new LinkedListNode for us
    virtual LinkedListNode<T> *createNode(T value)
	{
		return new LinkedListNode < T > { value };
	}

public:

    //default constructor
	LinkedList()
	{
		_front = nullptr;
	}

	//copy constructor
	LinkedList(const LinkedList<T> &other)
	{
		for (int i = 0; i < other.getSize(); i++)
		{
			addElement(other.getElementAt(i));
		}
	}

	//move constructor
	LinkedList(LinkedList<T> &&other)
	{
	    //take other's data
		_front = other._front;
		_size = other._size;

		//reset other's pointers
		other._front = nullptr;
	}

	//initializer list constructor
	LinkedList(initializer_list<T> values)
	{
		for (auto item : values)
		{
			addElement(item);
		}
	}

	//Always remember to clean up pointers in destructor!
	virtual ~LinkedList()
	{
		LinkedListNode<T> *current = _front;
		while (current != nullptr)
		{
			LinkedListNode<T> *temp = current->getNext();
			delete current;
			current = temp;
		}
	}

    //will return true if the LL is empty.
    virtual bool isEmpty() const
    {
        return _size == 0;
    }

    //returns the size of the LL.
    virtual int getSize() const
    {
        return _size;
    }

    //adds the supplied item to the end of our LL
    virtual void addElement(T value)
    {
        addElementAt(value, getSize());
    }

    //Removes an element at the provided index
    virtual void removeElementAt(int index)
    {
        //LAB #2 TODO: IMPLEMENT!
    }

    //Returns the value of the LinkedListNode at the given index
    virtual T& getElementAt(int index)
    {
        //make sure we're give a valid index
        if(index >= getSize())
        {
            throw exception{};
        }

        //loop until we hit the desired index
        LinkedListNode<T> *current = _front;
        int counter = 0;
        while(counter < index)
        {
            counter ++;
            current = current->getNext();
        }
        return current->getValue();
    }

	//adds the specified item at the specified index and shifts everything else
	//to the "right" by one.
	virtual void addElementAt(T value, int location)
	{
	    //create a new LinkedListNode for us to insert
		LinkedListNode<T> *new_value = createNode(value);

		// Add variable new_value to proper location inside
		// our linked list.

		//check for valid location
		if(location > getSize())
        {
            //probably, we should throw an exception, but for now
            //just return immediately.
            return;
        }
        else if(location == 0)
        {
            //zero insert is a special case
            new_value->setNext(_front);
            _front = new_value;
            _size++;
            return;
        }

        //loop until we reach a valid location
        int counter = 0;
        LinkedListNode<T> *current = _front;
        LinkedListNode<T> *previous = _front;
        while(counter < location && current != nullptr)
        {
            counter++;
            previous = current;
            current = current->getNext();
        }

        //once at the valid location, we can add the new item
        previous->setNext(new_value);
        new_value->setNext(current);
        _size++;
	}
};

#endif // !LINKED_LIST_H
