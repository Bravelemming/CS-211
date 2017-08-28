#ifndef TREE_NODE_H
#define TREE_NODE_H
#include "BinarySearchTree.h"
//"Jack" Daniel Kinne
template <typename T>
class TreeNode
{
protected:
	//value that our box contains
	T _value;
	//right child pointer of treenode type
	TreeNode<T> *_rightChild;
	//left child pointer of treenode type
    TreeNode<T> *_leftChild;

public:
	//get value at pointer
	T& getValue()
	{
		return _value;
	}

	//sets the value of the current node
	void setValue(T &value)
	{
		_value = value;
	}
    //returns rightchild only
	TreeNode<T> *getRightChild()
	{
	    return _rightChild;
	}
    //takes input of type treenode, value pointer, and sets to rightchild.
	void setRightChild(TreeNode<T> *value)
	{
        _rightChild = value;
	}
    //returns leftchild only
    TreeNode<T> *getLeftChild()
	{
	    return _leftChild;
	}
    //takes input of type treenode, value pointer, and sets to leftchild.
	void setLeftChild(TreeNode<T> *value)
	{
        _rightChild = value;
	}
}; //end class
#endif
