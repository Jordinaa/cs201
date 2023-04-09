#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

// bubble sort 
vector<double> sortDistances(vector<double>& distances){
    int n = distances.size();
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(distances[j] > distances[j+1]){
                double temp = distances[j];
                distances[j] = distances[j+1];
                distances[j+1] = temp;
            }
        }
    }
    return distances;
}

// distance formula 
double calcDistance(double x1, double x2, double y1, double y2, double z1, double z2){
	double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2) * 1.0);
	cout << " Distance is " << distance;

	return distance;
}

// mian function
int main(){
	// declare and input output file streams
	// declare vector and variables
	ifstream fin("input.txt");
	ofstream fout("output_sorted.txt");
	vector<int> x_vector, y_vector, z_vector;
	vector<double> distance_vec;
	int x, y, z;

	// opens input file
	if (!fin.is_open()){
        cerr << "Error: could not open input file" << endl;
        return 1;
    }
	// opens output file
	if (!fout.is_open()){
        cerr << "Error: could not open input file" << endl;
        return 1;
    }

	// loop to read in each variable then push onto each x y and z vector
	while (fin >> x >> y >> z){
		x_vector.push_back(x);
		y_vector.push_back(y);
		z_vector.push_back(z);
	}

	// closes input file
	fin.close();

	for(int i = 0; i < x_vector.size(); i++){
        if (i+1 < x_vector.size()){
			double distance = calcDistance(x_vector[i], x_vector[i+1], y_vector[i], y_vector[i+1], z_vector[i], z_vector[i+1]);
			fout << distance << endl;
		}
	}
	fout.close();

	return 0;
}