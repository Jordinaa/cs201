#include "Lab08Utility.h"

int main() {

	string filename1 = "input.txt";
	string filename2 = "input1.txt";
	vector<int> numbers;
	vector<string> file;

	file = read_file(filename1);
	cout << file << endl;


	return 0;
}