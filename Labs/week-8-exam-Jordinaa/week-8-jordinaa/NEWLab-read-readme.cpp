#include "Lab08Utility.h"
// NEW edited file that works
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
        string label;
        int value;
        parse_line(line, label, value);

        if (label == "DVD") {
            dvd.push_back(value);
        } else if (label == "MUSIC") {
            music.push_back(value);
        } else if (label == "TV") {
            tv.push_back(value);
        } else {
            cerr << "Invalid label in line: " << line << endl;
        }
    }
    inFile.close();

    // Calculate total, mean, and median for each category and output to file
    string output_filename = "output1.txt";
    vector<string> categories = {"DVD", "MUSIC", "TV"};
    vector<vector<int>> data = {dvd, music, tv};

    ofstream outFile(output_filename);
    if (!outFile.is_open()) {
        cerr << "Unable to open file " << output_filename << endl;
        return 1;
    }

    for (size_t i = 0; i < categories.size(); i++) {
        double total = calculate_total(data[i]);
        double mean = calculate_mean(data[i]);
        double median = calculate_median(data[i]);

        outFile << categories[i] << " " << total << " " << mean << " " << median << endl;
    }
    outFile.close();

    return 0;
}
