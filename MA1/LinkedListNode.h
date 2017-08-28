#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

//A linked list node represents a single "box" inside a lined list.  In this
//scheme, the LinkedList is simply a collection of LinkedListNode boxes.
template <typename T>
class LinkedListNode
{
protected:

	//value that our box contains
	T _value;

	//pointer to next node in the LL sequence
	LinkedListNode<T> *_next;

public:

	//constructor must accept a default value
	LinkedListNode(const T &value) : _value(value)
	{
		_next = nullptr;
	}

	LinkedListNode()
	{
		_next = nullptr;
	}

	//copy constructor prevents premature deletion of next pointer
	LinkedListNode(const LinkedListNode<T> &other)
	{
		_value = other.getValue();
		_next = other.getNext();
	}

	virtual ~LinkedListNode()
	{

	}

	//copy operator allows us to reassign previously created list nodes
	LinkedListNode<T> &operator=(const LinkedListNode<T> &other)
	{
		if (this != &other)
		{
			LinkedListNode<T> temp(other);
			swap(*this, temp);
		}
		return *this;
	}

	//returns a pointer to the next list node in the sequence
	LinkedListNode<T> *getNext()
	{
		return _next;
	}

	//sets the pointer to the next node in the sequence
	void setNext(LinkedListNode<T> *next)
	{
		_next = next;
	}

	//returns the value of the list node
	T &getValue()
	{
		return _value;
	}

	//constant version of the getter
	const T& getValue() const
	{
		return _value;
	}

	//sets the value of the current list node
	void setValue(const T &value)
	{
		_value = value;
	}
};

#endif
