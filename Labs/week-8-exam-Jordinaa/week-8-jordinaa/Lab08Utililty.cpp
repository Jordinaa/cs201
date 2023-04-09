#include "Lab08Utility.h"

void printi(vector<int> avector) {
    for (unsigned int i = 0; i < avector.size(); i++) {
        cout << avector[i] << " " << endl;
    }
    cout << endl;
}

void prints(vector<string> avector) {
    for (unsigned int i = 0; i < avector.size(); i++) {
        cout << avector[i] << " " << endl;
    }
    cout << endl;
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
    double total = calculate_total(numbers);
    double mean = total / numbers.size();
    return mean;
}

//function sorts using mergesort.
vector<int> mergeSort(vector<int> avector) {
    cout << "sorting ";
    printi(avector);
    if (avector.size() > 1) {
        int mid = avector.size() / 2;

        //C++ Equivalent to using Python Slices

        vector<int> lefthalf(avector.begin(), avector.begin() + mid);
        vector<int> righthalf(avector.begin() + mid, avector.begin() + avector.size());

        lefthalf = mergeSort(lefthalf);
        righthalf = mergeSort(righthalf);

        unsigned i = 0;
        unsigned j = 0;
        unsigned k = 0;
        while (i < lefthalf.size() && j < righthalf.size()) {
            if (lefthalf[i] < righthalf[j]) {
                avector[k] = lefthalf[i];
                i++;
            }
            else {
                avector[k] = righthalf[j];
                j++;
            }
            k++;
        }

        while (i < lefthalf.size()) {
            avector[k] = lefthalf[i];
            i++;
            k++;
        }

        while (j < righthalf.size()) {
            avector[k] = righthalf[j];
            j++;
            k++;
        }
    }
    cout << "Merging ";
    printi(avector);
    return avector;
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
void write_numbers_to_file(vector<string>& title, vector<int>& total, vector<int>& mean, vector<int>& median, string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        return;
    }
    for (int i = 0; i < total.size(); i++) {
        outFile << title[i]  << total[i] << mean[i] << median[i] << endl;

    }
    outFile.close();
}

void parse_line(const string& line, string& label, int& value) {
    stringstream ss(line);
    ss >> label >> value;
}
