#include "functions.h"

double GetMiles(){
    double miles;
    cin >> miles;

    while(cin.fail()){
        cerr << "Error: Invalid input received, you must enter a decimal number." << endl;
        cin.clear();

        while(cin.get() != '\n');
        cin >> miles;}

    if(miles <= 0){
        throw runtime_error("Miles cannot be less than 0.");}

    return miles;}

double GetGallons(){
    double gallons;
    cin >> gallons;

    while(cin.fail()){
        cerr << "Error: Invalid input received, you must enter a decimal number." << endl;
        cin.clear();

        // discards all chars from input stream until it reaches newline char \n
        while(cin.get() != '\n');
        cin >> gallons;}

    if(gallons <= 0){
        throw runtime_error("Gallons cannot be less than 0.");}

    return gallons;}

double GetMPG(vector<double> miles, vector<double> gallons){
    if(miles.size() == 0 || gallons.size() == 0){
        throw runtime_error("No values recorded, MPG is nan.");}

    double total_miles = 0;
    double total_gallons = 0;

    // cool for loop the colon says we are iterating over each element in the vector
    // then add its to the total miles var its similiar to this but way easier.
    // I work with python mostly at my job but someone at work showed me this way to loop.
    // for(size_t i = 0; i < gallons.size(); i++){
    // total_gallons += gallons[i];

    for(auto mile : miles){
        total_miles += mile;}

    for(auto gallon : gallons){
        total_gallons += gallon;
    }

    return total_miles / total_gallons;
}