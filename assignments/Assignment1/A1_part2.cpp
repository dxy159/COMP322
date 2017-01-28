#include <iostream>

void mergeSort(int *p, int length);

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
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
	if (length == 1) {
		return;
	} else {
		int mid = (length - 1) / 2;
	}
}

int main() {
	int p[10] = {3,5,4,6,3,2,5,4,19,6};
	bubbleSort(p, 10);
	for (int i = 0; i < 10; i++) {
		std::cout << p[i] << std::endl;
	}
}


