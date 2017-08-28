#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include "TreeNode.h"
//JACK DANIEL KINNE
// CS 211
using namespace std;

bool searchTree(TreeNode *root, int value)
{
    //COMPLETE
    if(root == nullptr) return false;
    if(root->value == value) return true;
    if(value < root->value){
        return searchTree(root->left, value);
    }
    if (value > root->value){
        return searchTree(root->right, value);
    }

    return false;
}

vector<int> bstToVector(TreeNode *root)
{
    vector<int> numbers{};
    int temp;
    /*
    while(root != nullptr){
        //in order traversal
        if (root->left) {bstToVector(root->left);}

        //numbers.push_back(root->root);
        //ALMOST!

        if (root->right) {bstToVector(root->right);}
    }
    */
    return numbers;
}

bool isHeap(vector<int> &numbers)
{
    //COMPLETE
    priority_queue<int>heap;

    for (int i = 0; i < numbers.size(); i++){
        heap.push(numbers[i]);
        //cout << "heap[i]:" << heap.top() << endl;
        //cout << "numbers[i]: " << numbers[i] << endl;

    if (heap.top() != numbers[i]){
        return false;
    }//end if

    }//end for

    return true;
}

vector<int> mergeSorted(vector<int> left, vector<int> right)
{
    vector<int> result{};
	int left_pointer = 0;
	int right_pointer = 0;
	while (left_pointer < left.size() && right_pointer < right.size()) {
		if (left[left_pointer] < right[right_pointer]) {
			result.push_back(left[left_pointer]);
			left_pointer++;

		}
		else {
			result.push_back(right[right_pointer]);
			right_pointer++;
		}

		//stuff remains in left side?
		if (left_pointer < left.size()) {
			while (left_pointer < left.size()) {
				result.push_back(left[left_pointer]);
				left_pointer++;
			}
		}


	}

    return result;
}

int findNthSmallest(vector<int> numbers, int n)
{   //COMPLETE!  THANK YOU PRIORITY QUEUE
    priority_queue<int>smallest;
    for (int i = 0; i < numbers.size(); i++){
        smallest.push(numbers[i]);
        //cout << "smallest[i]:" << smallest.top() << endl;
    }

    for (int i = 0 ; i < n; i++){
        smallest.pop();
    }
    return smallest.top();
}

char findMostCommon(string text)
{

	//adams solution

	unordered_map<char, int> chars{};
	for (auto ch : text) {
		char[ch]++;
	}
	char max_char = text[0];
	for (auto item : chars) {
		if (chars[max_char] < item.second) {
			max_char = item.first;
		}
	}

	return max_char;

	/*
	unordered_map<char, char>common;
	
    for (int i = 0; i < text.size(); i++){
        common[i] = text[i];
        cout << "common: " << common[i] << endl;
    }


  unsigned nbuckets = common.bucket_count();

  std::cout << "common has " << nbuckets << " buckets:\n";

  for (unsigned i=0; i<nbuckets; ++i) {
    std::cout << "bucket #" << i << " has " << common.bucket_size(i) << " elements.\n";
    //TO DO: COUNT THE BUCKETS, RETURN value of largest.
    //why do i have 11 buckets instead of three???
  }


    return text[6];
	*/
}

int main()
{
    string test_text = "ababbcbccc";
    vector<int> vector_heap{1, 2, 3, 4, 5, 6, 7, 8, 9, 20};
    vector<int> sorted = {3, 4, 9, 12, 15, 17};
    vector<int> numbers{5, 2, 1, 9, 3, 7, 4};
    TreeNode *root = new TreeNode{10};
    root->left = new TreeNode{5};
    root->left->left = new TreeNode{1};
    root->left->right = new TreeNode{7};
    root->left->right->left = new TreeNode{6};
    root->right = new TreeNode{20};
    root->right->right = new TreeNode{50};
    root->right->left = new TreeNode{15};

    cout << "Searching tree for 15: " << searchTree(root, 15) << " (expected: 1)" << endl;
    cout << "Searching tree for 0: " << searchTree(root, 0) << " (expected: 0)" << endl;

    cout << "Converting tree to vector: ";
    vector<int> treeAsVector = bstToVector(root);
    for(auto i : treeAsVector)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << " Expected: 1 5 6 7 10 15 20 50";
    cout << endl << endl;
    cout << "Is vector heap: " << isHeap(vector_heap) << " (expected: 1)" << endl;
    cout << "Is vector heap: " << isHeap(numbers) << " (expected: 0)" << endl;
    cout << "Merging sorted vectors: ";
    vector<int> merged = mergeSorted(vector_heap, sorted);
    for(auto i : merged)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << " Expected: 1 2 3 3 4 4 5 6 7 8 9 9 12 15 17 20";
    cout << endl << endl;
    cout << "3rd smallest number: " << findNthSmallest(sorted, 3) << " (expected: 9)" << endl;
    cout << "Most common char: " << findMostCommon(test_text) << " (expected: 'c')" << endl;
    return 0;
}
