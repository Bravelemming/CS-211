#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <unordered_map>
using namespace std;

template <typename T>
class GraphNode
{
private:
	T _value;
	int _id;
	bool _visited;

	//key is the graph node ID (INT)
	//value is a pointer to some other graph node (graphNode<T>*)
	unordered_map<int, GraphNode<T>*> _attached_vertices;

public:
	GraphNode(int id = 0, bool visited = false)
	{
		_id = id;
		_visited = visited;

	}

	T getValue() {
		return _value;
	}

	void setValue(T value){
		_value = value;
	}

	int getId() {
		return _id;
	}

	void setId(int id) {
		_id = id;
	}

	unordered_map<int, GraphNode<T>*> & getVertices()
	{
		return _attached_vertices;
	}

	void setVisited(bool visited) {
		_visited = visited;
	}

	bool getVisited() {
		return _visited;
	}

};





#endif // GRAPH_NODE_H