#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

using namespace std;

double GetMiles();
double GetGallons();
double GetMPG(vector<double> miles, vector<double> gallons);
