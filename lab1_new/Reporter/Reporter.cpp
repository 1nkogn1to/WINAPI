#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

struct employee {
	int num = 0;
	string name = "";
	double hours = 0.0;
};

int main(int argc, char* argv[])
{
	cout << "Process " << argv[0] << " was started\n";
	ifstream fin(argv[1], ios_base::binary);
	ofstream fout(argv[2]);

	int count, salary_per_hour = atoi(argv[3]);
	fin >> count;
	if (count != 0) {
		fout << "Information about employees according \"" << argv[1] << "\" binary file:\n";
	}
	for (int i = 0; i < count; i++) {
		employee person;
		fin >> person.num >> person.name >> person.hours;
		fout << person.num << " " << person.name << " " << person.hours << " " << person.hours * salary_per_hour << "\n";

	}
	cout << "Process completed its work\n";
	cout << "\nPress any key to finish...";
	char c = _getch();

	return 0;
}