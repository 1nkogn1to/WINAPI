#include <windows.h>
#include <stdio.h>
#include <conio.h>
#pragma warning(disable : 4996)

struct employee {
    int num;
    char name[10];
    double hours;
};

int main() {
	char s1[20];
	int k = 0;
	printf("Enter name of binary file: ");
	do {
		char c = getchar();
		if (c == '\n' || c == ' ') break;
		s1[k] = c; k++;
	} while (true);
    s1[k++] = '\0';
    

    char* info = new char[40], *creator = new char[10], *name_of_bin_file = new char[k];
    creator = strcpy(creator, "Creator ");
    name_of_bin_file = strcpy(name_of_bin_file, s1);
    name_of_bin_file = strcat(name_of_bin_file, ".bin");
    info = strcpy(info, creator);
    info = strcat(info, name_of_bin_file);


    _STARTUPINFOA si_creator, si_reporter;
    _PROCESS_INFORMATION pi_creator, pi_reporter;

    ZeroMemory(&si_creator, sizeof(si_creator));
    si_creator.cb = sizeof(si_creator);
    ZeroMemory(&pi_creator, sizeof(pi_creator));

    printf("Starting process Creator...\n");
    Sleep(1000);

    if (!CreateProcessA(NULL, info, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si_creator, &pi_creator)) {
        printf("Creator failed.\n");
        return 0;
    }

    WaitForSingleObject(pi_creator.hProcess, INFINITE);

    Sleep(500);

    CloseHandle(pi_creator.hProcess);
    CloseHandle(pi_creator.hThread);
    printf("Creator ended its work.\n====================================\n");

    FILE* bin = fopen(name_of_bin_file, "rb");

    int count;
    fscanf(bin, "%d\n", &count);
    printf("Number of employees - %d\n", count);

    if (count != 0) {
        printf("Information about employees:\n");
    }
    for (int i = 0; i < count; i++) {
        employee employees;
        fscanf(bin, "%d %s %lf\n", &employees.num, &employees.name, &employees.hours);
        printf("%d %s %lf\n", employees.num, employees.name, employees.hours);
    }
    
    char s2[20];
    k = 0;
    printf("====================================\nEnter name of result file: ");
    do {
        char c = getchar();
        if (c == '\n' || c == ' ') break;
        s2[k] = c; k++;
    } while (true);
    s2[k] = '\0';

    printf("Enter salary per hour: ");
    int salary;
    scanf("%d", &salary);

    char buffer1[33];
    char *reporter = new char[0], *name_of_result_file = new char[0];
    reporter = strcpy(reporter, "Reporter ");
    name_of_result_file = strcpy(name_of_result_file, s2);
    name_of_result_file = strcat(name_of_result_file, ".txt");
    info = strcpy(info, reporter);
    info = strcat(info, name_of_bin_file);
    info = strcat(info, " ");
    info = strcat(info, name_of_result_file);
    info = strcat(info, " ");
    info = strcat(info, itoa(salary, buffer1, 10));

    printf("%s\n", info);
    
    ZeroMemory(&si_reporter, sizeof(si_reporter));
    si_reporter.cb = sizeof(si_reporter);
    ZeroMemory(&pi_reporter, sizeof(pi_reporter));

    printf("Starting process Reporter...\n");
    Sleep(1000);

    if (!CreateProcessA(NULL, info, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si_reporter, &pi_reporter)) {
        printf("Reporter failed.\n");
        return 0;
    }

    WaitForSingleObject(pi_reporter.hProcess, INFINITE);

    Sleep(500);

    CloseHandle(pi_reporter.hProcess);
    CloseHandle(pi_reporter.hThread);
    printf("Reporter ended its work.\n====================================\n");

    FILE* res = fopen(name_of_result_file, "r");

    char* buffer2 = new char[1000];
    int i = 0;
    while (fgets(buffer2, 100, res) != NULL) {
        printf("%s", buffer2);
        i++;
    }
    printf("\nPress any key to finish...");
    char c = _getch();

	return 0;
}