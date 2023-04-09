#include "Lab08Utility.h"
// Computer did not run correctly first 35 mins of lab
int main() {
    string filename = "input.txt";
    vector<int> numbers, dvd, music, tv;

    // Read numbers from file and add them to vector
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        return 1;
    }
    string line;
    while (getline(inFile, line)) {
        string name = line.substr();
        cout << name << endl;
        string valueStr = line.substr(line.find_last_of(' ') + 1);
        // cout << valueStr;
        try {
            int value = stoi(valueStr);
            numbers.push_back(value);
        } catch (const invalid_argument& e) {
            cerr << "Invalid integer value in line: " << line << endl;
        }
    }
    // if i could seperate first and second value of text file i would push back if DVD if MUSIC if TV and then run the mean, median, and total. Only issue I had. 
    // Calculate total, mean, and median of numbers
    double total, mean, median;
    string title;

    total = calculate_total(numbers);
    mean = calculate_mean(numbers);
    median = calculate_median(numbers);

    cout << "Total: " << total << endl;
    cout << "Mean: " << mean << endl;
    cout << "Median: " << median << endl;
    // write_numbers_to_file(title, total, mean, median, "output1.txt")
    return 0;
}