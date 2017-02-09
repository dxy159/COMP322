#include <iostream>

// Question 1
// void test1(int a, int* b);
// // int main() {
// //      int x = 3;
// //      std::cout << &x;
// //      test1(x, &x);
// // }
// void test1(int a, int* b) {
//   std::cout << &a << b;
//  if (&a == b) {
//    std:: cout << "equal!";
//  }
//  else {
//    std:: cout << "not equal";
//  } 
// }

// Question 2
   int* func1();
   int* func2();
   int main() {
     int* a = func1();
     int* b = func2();
     if (a == b) {
       std:: cout << "equal";
     }
     else {
       std :: cout << "not equal";
} }
   int* func1() {
     int x;
     std::cout << &x << std::endl;
return &x; }
   int * func2() {
     int x;
     std::cout << &x << std::endl;
return &x; }


// Question 3
// int main() {
// 	int * p = new int(5);
// 	int *q = p;
// 	delete p;
// 	delete q;
// }

// Question 4
// int main() {
// 	int *p = new int(5);
// 	int *q = p;
// 	delete p;
// 	p = NULL;
// }

// Question 5
// int main() {
// 	char name[10];
// 	int x = 0;
// 	std::cout << "Enter your name" << std::endl;
// 	std::cin >> name;
// 	std::cout << x << " ";
// }





























