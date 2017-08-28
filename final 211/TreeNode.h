#ifndef TREE_NODE_H
#define TREE_NODE_H
class TreeNode
{
public:
   int value;
   int temp;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int v = 0)
   {
       value = v;
       left = nullptr;
       right = nullptr;
   }
};
#endif // TREE_NODE_H

