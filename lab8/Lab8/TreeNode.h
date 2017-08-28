#ifndef TREE_NODE_H
#define TREE_NODE_H

template <typename T>
class TreeNode
{
private:
    TreeNode<T> *_left_child = nullptr;
    TreeNode<T> *_right_child = nullptr;
    T _value;
	bool _is_visited = false;

public:
    TreeNode(TreeNode<T> *left_child = nullptr, TreeNode<T> *right_child = nullptr)
    {
        _left_child = left_child;
        _right_child = right_child;
    }

    TreeNode<T> *getLeftChild()
    {
        return _left_child;
    }

	bool isVisited()
	{
		return _is_visited;
	}

	void setVisited(bool value)
	{
		_is_visited = value;
	}

    void setLeftChild(TreeNode<T> *child)
    {
        _left_child = child;
    }

    TreeNode<T> *getRightChild()
    {
        return _right_child;
    }

    void setRightChild(TreeNode<T> *child)
    {
        _right_child = child;
    }

    T getValue()
    {
        return _value;
    }

    void setValue(T value)
    {
        _value = value;
    }
};

#endif // TREE_NODE_H
