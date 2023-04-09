#include "Lab08Utility.h"

// Function to read file 
string read_file(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file " << filename << endl;
        return "";
    }

    string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    file.close();

    return content;
}

// Function to calculate the total of all numbers in a vector
double calculate_total(const vector<int>& numbers) {
    int total = 0;
    for (int i = 0; i < numbers.size(); i++) {
        total += numbers[i];
    }
    return total;
}

// Function to calculate the mean (average) of all numbers in a vector
double calculate_mean(const vector<int>& numbers) {
    double total = calculateTotal(numbers);
    double mean = total / numbers.size();
    return mean;
}

// Function to calculate the median of all numbers in a vector
double calculate_median(vector<int>& numbers) {
    int size = numbers.size();
    double median;
    if (size % 2 == 0) {
        int middleIndex = size / 2;
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (numbers[i] > numbers[j]) {
                    swap(numbers[i], numbers[j]);
                }
            }
        }
        int middleValue1 = numbers[middleIndex - 1];
        int middleValue2 = numbers[middleIndex];
        median = (middleValue1 + middleValue2) / 2.0;
    }
    else {
        int middleIndex = size / 2;
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (numbers[i] > numbers[j]) {
                    swap(numbers[i], numbers[j]);
                }
            }
        }
        median = numbers[middleIndex];
    }
    return median;
}

// Function writes to a file 
void write_numbers_to_file(const vector<int>& numbers, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        return;
    }
    for (int i = 0; i < numbers.size(); i++) {
        outFile << numbers[i] << endl;
    }
    outFile.close();
}