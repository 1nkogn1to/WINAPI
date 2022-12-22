#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int ind_min, ind_max, min_num, max_num, avrg, size_of_array;

void min_max(int* arr)
{
	min_num = arr[0];
	max_num = arr[0];

	for (int i = 0; i < size_of_array; i++) {
		if (arr[i] < min_num) {
			min_num = arr[i];
			ind_min = i;
		}
		if (arr[i] > max_num) {
			max_num = arr[i];
			ind_max = i;
		}
		this_thread::sleep_for(chrono::milliseconds(7));
	}
	cout << "\nMin - " << min_num << "\tMax - " << max_num;
	cout << "\nThread min_max ended its work.\n";
}

void average(int* arr)
{
	avrg = 0;
	for (int i = 0; i < size_of_array; i++) {
		avrg += arr[i];
		this_thread::sleep_for(chrono::milliseconds(12));
	}
	avrg /= size_of_array;
	cout << "\nAverage - " << avrg;
	cout << "\nThread Average ended its work.\n";
}

int main() {
	cout << "Enter size of array: ";
	cin >> size_of_array;
	int* arr = new int[size_of_array];
	cout << "Enter elements of array: ";
	for (int i = 0; i < size_of_array; i++) {
		cin >> arr[i];
	}
	thread min_max_thread(min_max, arr), average_thread(average, arr);

	min_max_thread.join();
	average_thread.join();

	arr[ind_max] = avrg;
	arr[ind_min] = avrg;

	cout << "\nFinal array:\n";
	for (int i = 0; i < size_of_array; i++) {
		cout << arr[i] << " ";
	}

	cout << "\nThread main ended its work.\n";
	return 0;
}