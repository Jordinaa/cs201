#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;

string read_file(string filename);
double calculate_total(const vector<int>& numbers);
double calculate_mean(const vector<int>& numbers);
double calculate_median(vector<int>& numbers);
void write_numbers_to_file(const vector<int>& numbers, const string& filename);
