#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

struct employee {
	int num = 0;
	string name = "";
	double hours = 0.0;
};

int main(int argc, char* argv[]) {
	cout << "Process " << argv[0] <<  " was started\n";
	cout << "Enter number of employees: ";

	ofstream fout(argv[1], ios_base::binary);
	int count;
	cin >> count;

	fout << count << "\n";

	if (count == 0) {
		cout << "\nPress any key finish...";
		char ch = _getch();
		return 0;
	}

	for (int k = 0; k < count; k++) {
		employee person;
		cin >> person.num >> person.name >> person.hours;

		fout << person.num << " " << person.name << " " << person.hours << "\n";
	}

	printf("\nPress any key to finish...");
	char c = _getch();

	return 0;
}