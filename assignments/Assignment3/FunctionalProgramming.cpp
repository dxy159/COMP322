#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <functional>

using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

bool isLessThan(int first, int second) {
	return first < second;
}

bool isGreaterThan(int first, int second) {
	return first > second;
}

void sortWithPointers(int *p, int length, bool (*compFunction)(int, int)) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (compFunction(p[j], p[j + 1])) {
				swap(p[j], p[j + 1]);
			}
		}
	}
}

void testSortWithPointers() {
	int p[10] = {1,2,3,4,5,6,7,8,9,10};

	sortWithPointers(p, 10, isLessThan);
	cout << "Reversing the array in descending order using pointers" << endl;
	for (int i = 0; i < 10; i++) {
		cout << p[i] << endl;
	}
}

class IComparer {
public:
	virtual bool isBefore(int first, int second) = 0;
};

class LessThanComparer: public IComparer {
public:
	bool isBefore(int first, int second) {
		return first > second;
	}
};

class GreaterThanComparer: public IComparer {
public:
	bool isBefore(int first, int second) {
		return first < second;
	}
};

class IsClosestToComparer: public IComparer {
private:
	int center;
public:
	IsClosestToComparer(int center) {
		this -> center = center;
	}
	bool isBefore(int first, int second) {
		return abs(center - first) < abs(center - second);
	}
};

void sortWithInterfaces(int *p, int length, IComparer *comparer) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (comparer -> isBefore(p[j], p[j + 1])) {
				swap(p[j], p[j + 1]);
			}
		}
	}
}

void testSortWithInterfaces() {
	int p[10] = {7,56,3,256,34,15,9,0,25,122};

	GreaterThanComparer g;
	sortWithInterfaces(p, 10, &g);
	cout << "Sort with GreaterThanComparer" << endl;
	for (int i = 0; i < 10; i++) {
		cout << p[i] << endl;
	}

	LessThanComparer l;
	sortWithInterfaces(p, 10, &l);
	cout << "Sort with LessThanComparer" << endl;
	for (int i = 0; i < 10; i++) {
		cout << p[i] << endl;
	}

	IsClosestToComparer c(70);
	sortWithInterfaces(p, 10, &c);
	cout << "Sort with IsClosestToComparer" << endl;
	for (int i = 0; i < 10; i++) {
		cout << p[i] << endl;
	}
}

void sortWithStandardFunction(int *p, int length, function<bool(int, int)> f) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (f(p[j], p[j + 1])) {
				swap(p[j], p[j + 1]);
			}
		}
	}
}

function<bool(int, int)> generateNearestTo(int center) {
	return [center](int first, int second) { return abs(center - first) < abs(center - second); };
}

void testSortWithLambdas() {
	int p[10] = {0,2,4,6,8,10,12,14,16,18};

	sortWithStandardFunction(p, 10, generateNearestTo(3));
	cout << "Sort comparing to 3" << endl;
	for (int i = 0; i < 10; i++) {
		cout << p[i] << endl;
	}

	sortWithStandardFunction(p, 10, generateNearestTo(10));
	cout << "Sort comparing to 10" << endl;
	for (int i = 0; i < 10; i++) {
		cout << p[i] << endl;
	}
}

int main(int argc, char const *argv[])
{
	testSortWithPointers();
	testSortWithInterfaces();
	testSortWithLambdas();

	return 0;
}






