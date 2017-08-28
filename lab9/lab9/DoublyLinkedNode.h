#ifndef DOUBLY_LINKED_NODE_H
#define DOUBLY_LINKED_NODE_H

#include "LinkedListNode.h"

template<typename T> 
class DoublyLinkedNode : public LinkedListNode<T>
{
protected:
	LinkedListNode<T>* _previous = nullptr;

public:
	DoublyLinkedNode(T value) 
		: LinkedListNode<T>(value) // calls parent's constructor
	{
		return _previous;
	}

	void setPrevious(LinkedListNode<T> *previous) {
		_previous = previous;
	}


};

#endif // DOUBLY_LINKED_NODE_H