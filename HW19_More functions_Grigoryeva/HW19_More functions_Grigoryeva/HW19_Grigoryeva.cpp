#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int nod(int num1, int num2) {
	if (num1 == 0 || num2 == 0)
		return 1;
	if (num1 % num2 == 0)
		return num2;
	if (num2 % num1 == 0)
		return num1;
	if (num1 > num2)
		return nod(num1 % num2, num2);
	return nod(num1, num2%num1);
}

int mirror_number(int num) {
	
	int mirror = 0;
	for (int i = 0; i <= num*10; i++) {
		mirror = mirror * 10 + num % 10;
		num /= 10;
	}
	return mirror;
}

template <typename T>
int search_index(T arr[], const int length, T value, int begin = 0) {
	for (int i = begin; i < length; i++)
		if (arr[i] == value)
			return i;
	return -1;
}

template <typename T>
void arrsort(T arr[], const int length, int num) {
	int first_index = 0;
		for (int i = 0; i < length; i++)
			if (arr[i] == num) {
				first_index = i;
				break;
				}
		for (int i = length - 1; i > first_index + 1; i--)
		for (int j = first_index + 1; j < i; j++) 
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}

template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
		std::cout << "\b\b]\n";
	}

template <typename T>
void create_arr(T arr[], int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n, m,k,h,A,B;
	

	std::cout << "Task 1. NOD\n";
	std::cout << "Enter 2 numbers:\n";
	std::cin >> n >> m;
	std::cout << "The maximum common divider of entered numbers = " << nod(n, m) <<"\n\n";
	
	
	std::cout << "Task 2. Mirror Number\n";
	std::cout << "Enter number:\n";
	std::cin >> k;
	std::cout << "The mirror number = " << mirror_number (k) << "\n\n";
	

	std::cout << "Task 3. Search and sort\n";
	std::cout << "Initial array:\n";
	const int size = 6;
	int arr[size]{ 8,2,11,-7,21,1};
	std::cout << '[';
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
	std::cout << "Enter number:\n";
	std::cin >> h;
	search_index(arr, size, h);
	std::cout << "First position of entered number  " << h << " in initial array = " << search_index(arr, size, h) << "\n";
	std::cout << "Sorted array:\n";
	arrsort(arr, size, h);
	show_arr(arr, size);
	std::cout << "\n";

	std::cout << "Task 4. Random array\n";
	const int size4 = 20;
	int arr4[size4];
	std::cout << "Enter 2 numbers (range of array):\n";
	std::cout << "Begin:\n";
	std::cin >> A;
	std::cout << "End:\n";
	std::cin >>B;
	create_arr(arr4, size4, A, B);
	show_arr(arr4, size4);
	std::cout << "\n";
	return 0;
}