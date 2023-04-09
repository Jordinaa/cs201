#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <sstream>

using namespace std;

void printi(vector<int> avector);
void prints(vector<string> avector);
vector<string> read_lines(string filename);
vector<string> read_first_words(string filename);
double calculate_total(const vector<int>& numbers);
double calculate_mean(const vector<int>& numbers);
vector<int> mergeSort(vector<int> avector);
double calculate_median(vector<int>& numbers);
void write_numbers_to_file(const vector<int>& numbers, const string& filename);
void parse_line(const string& line, string& label, int& value);