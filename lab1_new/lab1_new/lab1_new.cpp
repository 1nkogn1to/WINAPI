#include <windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

struct employee {
    int num = 0;
    string name = "";
    double hours = 0.0;
};

int main() {
    string creator = "Creator ", name;
    cout << "Enter name of binary file: ";
    cin >> name;
    name += ".bin";
    creator += name;

    _STARTUPINFOA si_creator, si_reporter;
    _PROCESS_INFORMATION pi_creator, pi_reporter;

    ZeroMemory(&si_creator, sizeof(si_creator));
    si_creator.cb = sizeof(si_creator);
    ZeroMemory(&pi_creator, sizeof(pi_creator));

    cout << "Starting process Creator...\n";
    
    this_thread::sleep_for(chrono::milliseconds(1000));

    if (!CreateProcessA(NULL, const_cast<char*>(creator.c_str()), NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si_creator, &pi_creator)) {
        cout << "Creator failed.\n";
        return 0;
    }

    WaitForSingleObject(pi_creator.hProcess, INFINITE);

    this_thread::sleep_for(chrono::milliseconds(500));

    CloseHandle(pi_creator.hProcess);
    CloseHandle(pi_creator.hThread);
    cout << "Creator ended its work.\n====================================\n";

    ifstream fin(name, ios_base::binary);
    int count;
    fin >> count;
    cout << "Number of employees - " << count << "\n";

    if (count != 0) {
        cout << "Information about employees:\n";
    }
    for (int i = 0; i < count; i++) {
        employee person;
        fin >> person.num >> person.name >> person.hours;
        cout << person.num << " " << person.name << " " << person.hours << "\n";
    }

    string reporter = "Reporter ", result_file;
    cout << "====================================\nEnter name of result file: ";
    cin >> result_file;
    result_file += ".txt";

    cout << "Enter salary per hour: ";
    int salary;
    cin >> salary;

    char buffer1[33];
    reporter += name + " " + result_file + " " + itoa(salary, buffer1, 10);

    cout << reporter << "\n";

    ZeroMemory(&si_reporter, sizeof(si_reporter));
    si_reporter.cb = sizeof(si_reporter);
    ZeroMemory(&pi_reporter, sizeof(pi_reporter));

    cout << "Starting process Reporter...\n";
    
    this_thread::sleep_for(chrono::milliseconds(1000));

    if (!CreateProcessA(NULL, const_cast<char*>(reporter.c_str()), NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si_reporter, &pi_reporter)) {
        cout << "Reporter failed.\n";
        return 0;
    }

    WaitForSingleObject(pi_reporter.hProcess, INFINITE);

    this_thread::sleep_for(chrono::milliseconds(500));

    CloseHandle(pi_reporter.hProcess);
    CloseHandle(pi_reporter.hThread);
    cout << "Reporter ended its work.\n====================================\n";

    ifstream fin_res(result_file);

    string str;
    while (getline(fin_res, str)) {
        cout << str << "\n";
    }
    cout << "\nPress any key to finish...";
    char c = _getch();

    return 0;
}