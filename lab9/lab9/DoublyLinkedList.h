#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "LinkedList.h"
#include "DoublyLinkedNode.h"

template <typename T>
class DoublyLinkedList : LinkedList<T>
{
protected:
	LinkedListNode<T> *_end = nullptr;

	virtual LinkedListNode<T>* createNode(T value) {
		return new DoublyLinkedNode<T>{ value };
	}

	virtual LinkedListNode<T>* getNodeAtIndex(int index) {
		//if we're closer to the end, start from end
		if index(index > _size / 2) {
			//convert _end which is a single LL to a doubly LL
			DoublyLinkedNode<T> * cursor =
				dynamic_cast<DoublyLinkedListNode<T> *>(_end);

			//note: cursor might be nullptr

			int counter = LinkedList<T>::_size - 1;

			//move forward through our LL until we hit
			//either nullptr (somewhat unexpected)
			//or we arrive at the requested index
			while (cursor != nullptr && counter > index)
			{
				cursor = cursor->getPrevious();
				counter--;
			}

			return cursor;

		}
		else {
			//otherwise, do it normally like a single LL
			return LinkedList<T>::getNodeAtIndex(index);
		}
	}

public:
	virtual void addElementAt(T value, int index)
	{
		//new considerations for a doubly linked list:
		//now have to set a previous pointer;
		//update end;
		//the end gets set when: add an element at our size
		DoublyLinkedNode<T> *new_node = 
			dynamic_cast<DoublylinkedNode<T> *> (createNode(value));

		//special case check: are we adding to the front?
		if (index == 0)
		{
			//attach current front to new_node
			new_node->setNext(_front);
			_front = new_node;
			_size++;

			if (_end == nullptr) {
				_end = _front;

			}
			return;
		}




		LinkedListNode<T> *previous = getNodeAtIndex(index - 1);
		LinkedListNode<T> *current = previous->getNext();


		//At this point, we need to connect new_node
		//into our LL.  Meaning, set previous' next to
		//new_node and new_node's next to current
		previous->setNext(new_node);
		new_node->setNext(current);

		//set previous pointers
		

		_size++;

		
	}

	

};

#endif