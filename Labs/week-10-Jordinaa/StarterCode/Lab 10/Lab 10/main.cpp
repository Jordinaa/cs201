//Name: Jordan Taranto	
//Lab: wednesday 7:00 - 9:30
//Date: 04-05-2023
//Partner Name: Brendan Clouston

#include<iostream>
#include<fstream>

using namespace std;

int main() {

	//PT I
	cout << "PART I" << endl;
	int * my_var = nullptr;
	
	cout << my_var << endl; 
	//Prediction: hexidecimal value of 0
	//Actual: lots of 0's
	//Notes: none
	// cout << *my_var << endl;
	//Prediction: seg fault
	//Actual: breaks program 
	//Notes: breaks program becasue you are trying to dereference a null pointer
	cout << &my_var << endl;
	//Prediction: location of my_var
	//Actual: new location of my_var
	//Notes:

	cout << endl;

	//PT II
	cout << "PART II" << endl;
	my_var = new int (27);
	
	cout << my_var << endl;
	//Prediction: hexadecimal address of my_var
	//Actual: hex address
	//Notes: not sure what the difference is between this one and the third one two different addresses
	cout << *my_var << endl;
	//Prediction: the number 27
	//Actual: number 27
	//Notes:
	cout << &my_var << endl;
	//Prediction: location of my_var
	//Actual: hex address new location of my_var
	//Notes: 

	cout << endl;

	//PT III
	cout << "PART III" << endl;
	int * new_var = new int; 
	int twenty_seven = 27;
	*new_var = twenty_seven;

	cout << new_var << endl;
	//Prediction: hex address of new_var
	//Actual: hex address of new_var
	//Notes:
	cout << *new_var << endl;
	//Prediction: 27 
	//Actual: 27
	//Notes:
	cout << &new_var << endl;
	//Prediction: hex address of twenty_seven
	//Actual: hex address 
	//Notes:

	cout << endl;

	//PT IV
	cout << "PART IV" << endl;
	my_var = new_var;

	cout << my_var << endl;
	//Prediction: hex address of new_var
	//Actual: address of new_var
	//Notes:
	cout << *my_var << endl;
	//Prediction: 27
	//Actual: 27
	//Notes:
	cout << &my_var << endl;
	//Prediction: address of new_var 
	//Actual: adress of new_var
	//Notes:
	
	cout << endl;

	//PT IV

	// 1
	cout << "Custom Code" << endl;
	int * jordan_var = new int (25);
	cout << jordan_var << endl;
	//Your Partner's Prediction: memory address
	//Actual: memory address of jordan_var
	//Notes:

	// 2
	cout << *jordan_var << endl;
	//Your Partner's Prediction: 25
	//Actual: value stored at jordan_var
	//Notes:
	
	// 3
	cout << &jordan_var << endl;
	//Your Partner's Prediction: memory address	
	//Actual: memory address of jordan_var pointer itself
	//Notes:

	// 4
	int & jordans_new_var = *jordan_var;
	cout << jordans_new_var << endl;
	//Your Partner's Prediction: 25
	//Actual: prints out value of jordan_new_var which is the same as jordan_var
	//Notes:

	// 5
	cout << &jordans_new_var << endl;
	//Your Partner's Prediction: memory address of jordan_var
	//Actual: memory address of jordan_var
	//Notes:

	// 6
	int* jordan_var1 = new int(15);
	int& jordan_var3 = *jordan_var1;
	int* jordan_var2 = nullptr;
	jordan_var2 = &jordan_var3;
	cout << &jordan_var2 << endl << endl;
	//Your Partner's Prediction: address of jordan_var3 
	//Actual: memory address of jordan_var2
	//Notes:
	

	//Copy & Paste the following at various output points in your code (x6)
	//Your Partner's Prediction: 
	//Actual:
	//Notes:
	return 0;
}