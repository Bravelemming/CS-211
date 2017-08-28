#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector

{
private: 
	//keeps track of actual physical size of our array
	int _physical_size;
	//keeps track of number of items in our array
	int _logical_size;
	//this is a pointer to our array
	T *_data;
protected:
	virtual void requestResize(int new_size) {
		//alter the  physical size of our array
		//allocate space for new array
		T *new_data = new T[new_size];

		//figure out which is smaller: logical size or new size
		if (_logical_size > new_size) {
			//logical size cannot exceed new physical size
			_logical_size = new_size;
		}
		//copy from current data into new space
		for (int i = 0; i < _logical_size ; i++) {
			new_data[i] = _data[i];
		}
		//assume ownership of new array
		delete[] _data;
		_data = new_data;
		_physical_size = new_size;

	}
	virtual void checkSize() {
		//ensure our vector stays efficient
		//at least half full.  if completely full, we will resize
		if (_logical_size < _physical_size/2) {
			requestResize(_physical_size / 2);
		}
		else if (_logical_size >= _physical_size) {
			requestResize(_physical_size * 2 + 1);
		}
	}
public:

	//allows us to use cool [] syntax on vector
	virtual T& operator[] (int index)
	{
		return _data[index];


	}
	virtual const T& operator[](int index) const
	{
		return _data[index];
	}

	//copy constructor.  called whenever we create a new instance of vector and 
	//supply an existing vector as a starting point. 
	//ex. vector <int> some_vector{prior_vector};
	Vector(const Vector<T> &to_copy) 
		: Vector(to_copy.getSize()) // before we run copy constructor, call normal constructor, passing in to_copy's size
	{
		//now copy over other guys info
		for (int i = 0; i < to_copy.getSize(); i++) {
			_data[i] = to_copy[i];
			//same as: setElementAt(to_copy->getElementAt(i), i);
		}
	}



	//because we dynamically allocate memory, we need a destructor
	virtual ~Vector() {
		//make sure that we have stuff to delete
		if (_data != nullptr) {
			delete[] _data;
		}
	}

	//copy operator.  this gets called when we reassign an existing vector to be  the state of another vector.
	//ex; vector foo{};
	//Vector bar{};
	//foo = bar;

	virtual Vector<T> &operator=(const Vector<T> &to_copy) {
		//delete dynamic memory if allocated
		if (_data != nullptr) {
			delete[] _data;
		}

		//create new state
		_data = new T[to_copy._physical_size];
		//copy over other guys state
		_physical_size = to_copy._physical_size;
		_logical_size = to_copy._logical_size;
		for (int i = 0; i < to_copy.getSize(); i++) {
			_data[i] = to_copy[i];
		}

		//return ourselves as a reference
		return *this;
	}

	//move operator
	Vector(Vector<T> &operator=(Vector<T> &&other)) {
		//clear state before we assume ownership
		if (_data != nullptr) {
			delete[] _data;
		}
		//steal other guys stuff
		_physical_size = other._physical_size;
		_logical_size = other._logical_size;
		_data = other._data;
		other._data = nullptr;
		return *this;
	}



	//move constructor; called whenever we create a new instance of a vector based on a 
	//temporary (R-value) vector.
	//R Values don't have a name associated with them.  int x = 5;
	//
	Vector(Vector<T> &&other) {
		//take other guys stuff
		_physical_size = other._physical_size;
		_logical_size = other._logical_size;
		_data = other._data;
		other._data = nullptr;
	}


	Vector(int size = 0) {
		//by default our veector should be empty
		_logical_size = size;
		//base physical size off of logical size
		_physical_size = size * 2 + 1;

		//allocate memory for array
		_data = new T[ _physical_size ];
	}
	//returns logical size of vector
	const int& getSize() const {
		return _logical_size;
	}

	//adds item to end of vector
	void push(const T& item) {
		checkSize();
		_data[_logical_size] = item;
		_logical_size++;
		
	}

	//return element at location
	const T& getElementAt(int location) const {
		if (location < _logical_size) {
			return _data[location];
		}
		else {
			//TODO: throw exception
		}
	}

	//set
	void setElementAt(const T &item, int location) {
		if (location < _logical_size) {
			_data[location] = item;
		}
		else {
			//TO DO: Throw exception
		}
	}

	const T& pop() {
		
		checkSize();
		
		//grab last value
		const T& last = _data[_logical_size - 1];

		//make it look like we're smaller
		_logical_size--;

		

		return last;
	}



};

#endif // vector h