#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "StringSplitter.h"
#include "BinarySearchTree.h"
#include "TreeNode.h"
//"Jack" Daniel Kinne

//testing
#include <cstdlib>

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

    //test, pause for the output.
    system("PAUSE");
}

int main()
{
    bstTest();
    return 0;
}
