#include <windows.h>
#include <stdio.h>
#pragma warning(disable : 4996)

int ind_min, ind_max, min, max, average, size;

void min_max_thread(LPVOID* param)
{
	int* arr = (int*)param;
	min = arr[0], max = arr[0];

	for (int i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
			ind_min = i;
		}
		if (arr[i] > max) {
			max = arr[i];
			ind_max = i;
		}
		Sleep(7);
	}
	printf("\nMin - %d\tMax - %d", min, max);
	printf("\nThread min_max ended its work.\n");
}

void average_thread(LPVOID* param) {
	int* arr = (int*)param;
	average = 0;
	for (int i = 0; i < size; i++) {
		average += arr[i];
		Sleep(12);
	}
	average /= size;

	printf("\nAverage - %d", average);
	printf("\nThread Average ended its work.\n");
}

void main_thread() {
	printf("Enter size of array: ");
	scanf("%d", &size);
	int* arr = new int[size];

	printf("Enter elements of array: ");
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	HANDLE min_max, Average;
	DWORD IDmin_max, IDaverage;

	min_max = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)min_max_thread, (void*)arr, 0, &IDmin_max);
	Average = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)average_thread, (void*)arr, 0, &IDaverage);

	if (min_max == NULL || Average == NULL) {
		return (void)GetLastError();
	}

	WaitForSingleObject(min_max, INFINITE);
	WaitForSingleObject(Average, INFINITE);

	CloseHandle(min_max);
	CloseHandle(Average);

	arr[ind_min] = average;
	arr[ind_max] = average;

	printf("\nFinal array:\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	printf("\nThread main ended its work..\n");
}

int main() {
	HANDLE main; DWORD IDmain;

	main = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)main_thread, NULL, 0, &IDmain);

	if (main == NULL) {
		return GetLastError();
	}
	WaitForSingleObject(main, INFINITE);

	CloseHandle(main);

	return 0;
}