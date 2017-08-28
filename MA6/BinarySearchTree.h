#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "TreeNode.h"

/*
Incomplete BST.  We will fill this out more in future lectures.
*/
template <typename T>
class BinarySearchTree
{
private:
    TreeNode<T> *_root = nullptr;
    int _tree_size = 0;

protected:
    virtual TreeNode<T> * addItemHelper(TreeNode<T> *root, T item)
	{
		//BASE CASE: null root
		if (root == nullptr)
		{
			//allocate new space, store value, then return.
			root = new TreeNode<T>{};
			root->setValue(item);
			return root;
		}

		//RECURSIVE CASE: root is not null
		if (item >= root->getValue())
		{
			//CASE 1: belongs on the right side of root
			TreeNode<T> *right = addItemHelper(
                                         root->getRightChild(),
                                         item
                                         );

			//update right side with reconfigured state
			root->setRightChild(right);
		}
		else
		{
			//CASE 2: belongs on the left side of root
			TreeNode<T> *left = addItemHelper(
                                        root->getLeftChild(),
                                        item
                                        );
			root->setLeftChild(left);
		}

		return root;
	}

public:
    virtual void addItem(T value)
    {
        _root = addItemHelper(_root, value);
        _tree_size++;
    }
};

#endif // BINARY_SEARCH_TREE_H
