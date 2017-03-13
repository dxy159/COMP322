#include <stdlib.h>
#include <iostream>

using namespace std;

template <class T> class DynamicArray;

template <class T> class DynamicArrayIterator 
{
private: 
	int currentPosition;
	DynamicArray<T> * array;
	int direction;
public:

	DynamicArrayIterator(DynamicArray<T> * array, int currentPosition, int direction) {
		this -> array = array;
		this -> currentPosition = currentPosition;
		this -> direction = direction;
	}

	T & operator* () {
		return (*array)[currentPosition];
	}

	void operator++ () {
		if (direction == 1) {
			currentPosition++;
		} else if (direction == -1) {
			currentPosition--;
		}
	}

	bool operator ==(DynamicArrayIterator<T> second) {
		return currentPosition == second.currentPosition;
	}

	bool operator !=(DynamicArrayIterator<T> second) {
		return currentPosition != second.currentPosition;
	}
};

template <class T> class DynamicArray
{
private:
	T * array;
	int capacity;
	int currentPosition;
public:

	void add(T item) {
		if (currentPosition >= capacity - 1) {
			T * newArr = new T[capacity * 2];
			for (int i = 0; i < size; i++) {
				newArr[i] = array[i];
			}
			array = newArr;
			capacity *= 2;
		}
		array[currentPosition] = item;
		currentPosition++;
		size++;
	}

	int size;

	T remove(int i) {
		if (i >= 0 && i < size) {
			T element = array[i];
			for (int k = i; k < size - 1; k++) {
				array[k] = array[k + 1];
			}
			size--;
			currentPosition--;
			return element;
		} else {
			return NULL;
		}
	}

	DynamicArray() {
		capacity = 10;
		array = new T[capacity];
		currentPosition = 0;
		size = 0;
	}

	~DynamicArray() {
		delete [] array;
	}

	T & operator[] (int i) {
		return array[i];
	}

	DynamicArrayIterator<T> begin() {
		DynamicArrayIterator<T> begin(this, 0, 1);
		return begin;
	}

	DynamicArrayIterator<T> end() {
		DynamicArrayIterator<T> end(this, size, 1);
		return end;
	}

	DynamicArrayIterator<T> r_begin() {
		DynamicArrayIterator<T> begin(this, size - 1, -1);
		return begin;
	}

	DynamicArrayIterator<T> r_end() {
		DynamicArrayIterator<T> end(this, -1, -1);
		return end;
	}


};



int main(int argc, char const *argv[])
{
	DynamicArray<int> foo;
    foo.add(3);
    foo.add(2);
    cout << foo[1] << endl;
    foo[1] = 10;
    cout << foo[1] << endl;

	for(DynamicArrayIterator<int> a = foo.begin(); a != foo.end(); ++a) {
    	cout << *a << endl;
	}
	for(DynamicArrayIterator<int> a = foo.r_begin(); a != foo.r_end(); ++a) {
    	cout << *a << endl;
	}
  	
	return 0;
}








