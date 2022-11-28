#include <stdio.h>
#include <conio.h>
#pragma warning(disable : 4996)

struct employee {
	int num;
	char name[10];
	double hours;
};

int main(int argc, char* argv[]) {
	printf("Process %s was started\n", argv[0]);
	printf("Enter number of employees: ");

	FILE* outbin = fopen(argv[1], "wb");
	int count;
	scanf("%d", &count);

	fprintf(outbin, "%d\n", count);

	if (count == 0) {
		printf("\nPress any key finish...");
		char ch = _getch();
		return 0;
	}

	employee* arr = new employee[count];
	for (int k = 0; k < count; k++) {
		scanf("%d ", &arr[k].num);
		int i = 0;
		do {
			arr[k].name[i] = getchar();
			if (arr[k].name[i] == '\n' || arr[k].name[i] == ' ') break;
			i++;
		} while (true);

		if (k == count - 1) {
			scanf("%lf", &arr[k].hours);
		}
		else {
			scanf("%lf ", &arr[k].hours);
		}

		fprintf(outbin, "%d ", arr[k].num);
		for (int j = 0; j < i; j++) {
			fprintf(outbin, "%c", arr[k].name[j]);
		}
		fprintf(outbin, " %lf\n", arr[k].hours);
	}

	printf("\nPress any key to finish...");
	char c = _getch();

	return 0;
}