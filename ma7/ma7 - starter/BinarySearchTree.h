#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "TreeNode.h"

//"Jack" Daniel Kinne

/*
Incomplete BST.  We will fill this out more in future lectures.
*/
template <typename T>
class BinarySearchTree
{
private:
    TreeNode<T> *_root = nullptr;

protected:

	virtual TreeNode<T> *findLargestRec(TreeNode<T> *root)
	{
		//base case: root has no right child or root is null
		if (root == nullptr || root->getRightChild() == nullptr)
		{
			return root;
		}
		return findLargestRec(root->getRightChild());
	}

	virtual TreeNode<T> *findLargestIter(TreeNode<T> *root)
	{
		while (root != nullptr || root->getRightChild() != nullptr)
		{
			root = root->getRightChild();
		}
		return root;
	}

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

	virtual TreeNode<T> * getHeightHelper(TreeNode<T> *root)
	{
	    if (_root == nullptr)
        {
            return 0;
        }
		else
        {
                return 1 + max(getHeightHelper(root->getRightChild() ), getHeightHelper(root->getLeftChild() ) ) ;
        }
	}

	virtual TreeNode<T> * getSizeHelper(TreeNode<T> *root)
	{
	    if (_root == nullptr)
        {
            return 0;
        }
		else
        {
                return (1 + getSizeHelper(root->getRightChild() ) + getSizeHelper(root->getLeftChild()  )  ) ;
        }
	}


public:
    virtual void addItem(T value)
    {
        _root = addItemHelper(_root, value);
    }

	//MA #7 TODO: implement!
	//Gets the height of the tree.
	int getHeight()
	{
	    return getHeightHelper(_root);
	}

	//MA #7 TODO: implement!
	//Note: You cannot use a "counter variable" to track height.  Your function must
	//calculate the height manually (probably w/ recursion).
	int getSize()
	{

		return getSizeHelper(_root);
	}
};

#endif // BINARY_SEARCH_TREE_H
