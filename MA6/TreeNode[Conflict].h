#ifndef TREE_NODE_H
#define TREE_NODE_H
#include "BinarySearchTree.h"
template <typename T>
class TreeNode
{
protected:

	//value that our box contains
	T _value;
	TreeNode<T> *_rightChild;
    TreeNode<T> *_leftChild;

public:


	//get value
	T& getValue()
	{
		return _value;
	}

	//sets the value of the current list node
	void setValue(T &value)
	{
		_value = value;
	}

	TreeNode<T> *getRightChild()
	{

	    return _rightChild;

	}

	void setRightChild(TreeNode<T> *value)
	{
        _rightChild = value;

	}

    TreeNode<T> *getLeftChild()
	{
	    return _leftChild;

	}

	void setLeftChild(TreeNode<T> *value)
	{
        _leftChild = value;

	}

};

#endif
