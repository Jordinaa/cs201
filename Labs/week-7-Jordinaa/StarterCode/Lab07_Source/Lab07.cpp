#include "functions.h"

int main(){

    // set choice for vars
    vector<double> miles;
    vector<double> gallons;
    char choice = 'y';

    while(choice == 'y'){
        double mile;
        double gallon;

        cout << "Enter the number of miles: ";
        try{mile = GetMiles();}

        catch(exception& error){
            cerr << "Error: " << error.what() << endl;
            continue;}

        cout << "Enter the number of gallons: ";
        try{gallon = GetGallons();}

        catch(exception& error){
            cerr << "Error: " << error.what() << endl;
            continue;}

        miles.push_back(mile);
        gallons.push_back(gallon);

        cout << "Do you want to enter another tank (y/n)? ";
        cin >> choice;

        while(cin.fail() || (choice != 'y' && choice != 'n')){
            cerr << "Error: Invalid input received, you must enter 'y' or 'n'." << endl;
            cin.clear();

            while(cin.get());
            cout << "Do you want to enter another tank (y/n)? ";
            cin >> choice;}
    }

    try{double mpg = GetMPG(miles, gallons);
        cout << "Your car's average fuel economy is " << mpg << " MPG." << endl;}

    catch(exception& error){
        cerr << "Error: " << error.what() << endl;}

    return 0;
}
