#include <windows.h>
#include <stdio.h>
#include <conio.h>
#pragma warning(disable : 4996)

struct employee {
	int num;
	char name[10];
	double hours;
};

int main(int argc, char* argv[])
{
	printf("Process %s was started\n", argv[0]);
	FILE *bin = fopen(argv[1], "rb"), *res = fopen(argv[2], "wb");


	int count, salary_per_hour = atoi(argv[3]);
	fscanf(bin, "%d\n", &count);
	if (count != 0) {
		fprintf(res, "Information about employees according \"%s\" binary file:\n", argv[1]);
	}
	for (int i = 0; i < count; i++) {
		employee employees;
		fscanf(bin, "%d %s %lf\n", &employees.num, &employees.name, &employees.hours);
		fprintf(res, "%d %s %lf %lf\n", employees.num, employees.name, employees.hours, employees.hours * salary_per_hour);
	}
	printf("Process completed its work\n");
	printf("\nPress any key to finish...");
	char c = _getch();

	return 0;
}