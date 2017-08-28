#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>
#include <initializer_list>
#include "LinkedListNode.h"
#include <utility>
using namespace std;

template <typename T> // allows linked list of any data type
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

    //Returns the value of the LinkedListNode at the given index
    virtual T& getElementAt(int index)
    {
        //MA #1 TODO: ACTUALLY IMPLEMENT!
        int value = -1;
        return value;
    }

	//adds the specified item at the specified index and shifts everything else
	//to the "right" by one.
	virtual void addElementAt(T value, int location)
	{
		LinkedListNode<T> *new_value = createNode(value);

		//MA #1 TODO: IMPLEMENT!
		// Add variable new_value to proper location inside
		// our linked list.

	}
};

#endif // !LINKED_LIST_H
