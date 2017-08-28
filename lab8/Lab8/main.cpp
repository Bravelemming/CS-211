#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "StringSplitter.h"
#include "BinarySearchTree.h"

using namespace std;

void bstTest()
{
    BinarySearchTree<int> bst{};
    bst.addItem(10);
    bst.addItem(5);
    bst.addItem(2);
    bst.addItem(3);
    bst.addItem(20);
    bst.addItem(15);
	vector<TreeNode<int> *> in_order = bst.inOrderTraversal();
}


//case one; has left child 
//case two ; has right child
//case three; has no children
//case four: has two children

void caseOne()
{
	BinarySearchTree<int> bst1{};
	bst1.addItem();
	bst1.addItem();
	bst1.addItem();
	bst1.addItem();
	bst1.addItem();
	vector<TreeNode<int> *> in_order = bst.inOrderTraversal();
}


int main()
{
    bstTest();
	caseOne();
    return 0;
}


//demo code coverage; how do we test:
//add items that we need to add and call remove such that
//case 1 hits
//case 2 hits
//case 3 hits
//case 4 hits