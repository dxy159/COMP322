#include <iostream>
#include <stdlib.h>
#include <time.h>

void recursiveMergeSort(int *, int, int);

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int* copyArray(int *p, int low, int high, int length) {
	int newArray[length];
	for (int i = low; i < high; i++) {
		newArray[i - low] = *(p + i);
	}
	return newArray;
}

void bubbleSort(int *p, int length) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (p[j] > p[j + 1]) {
				swap(p[j], p[j + 1]);
			}
		}
	}
}


void mergeSort(int *p, int length) {
	recursiveMergeSort(p, 0, length - 1);
}

void merge(int *p, int low, int mid, int high) {
	int temp[100000];

	int lowerEnd = mid - 1;
	int tempIndex = low;
	int length = high - low + 1;

	while ((low <= lowerEnd) && (mid <= high)) {
		if (p[low] <= p[mid]) {
			temp[tempIndex] = p[low];
			tempIndex++;
			low++;
		} else {
			temp[tempIndex] = p[mid];
			tempIndex++;
			mid++;
		}
	}
	while (low <= lowerEnd) {
		temp[tempIndex] = p[low];
		tempIndex++;
		low++;
	}
	while (mid <= high) {
		temp[tempIndex] = p[mid];
		tempIndex++;
		mid++;
	}
	for (int i = 0; i < length; i++) {
		p[high] = temp[high];
		high--;
	}
}

void recursiveMergeSort(int *p, int low, int high) {
	int mid;
	if (high > low) {
		mid = (low + high) / 2;
		recursiveMergeSort(p, low, mid);
		recursiveMergeSort(p, mid + 1, high);
		merge(p, low, mid + 1, high);
	}
}

int* generateRandomArray(int* p, int n) {
	for (int i = 0; i < n; i++) {
		p[i] = rand() % 1000;
	}
}

void printResults(int *p, int n) {
	std::cout << n << "\t\t\t";
	clock_t t;
	generateRandomArray(p, n);
	t = clock();
	bubbleSort(p, n);
	t = clock() - t;
	std::cout << t << "\t\t";
	generateRandomArray(p, n);
	t = clock();
	mergeSort(p, n);
	t = clock() - t;
	std::cout << t << std::endl;
}


int main() {
	std::cout << "Number of Elements\t" << "Bubble Sort\t" << "Merge Sort\t" <<std::endl;
	int n = 10;
	while (n < 1000000) {
		int p[n];
		printResults(p, n);
		n *= 2;
	}
}	


