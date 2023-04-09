#include "Person.h"
#include "Student.h"

Student::Student() : Person(){
    gpa = 0.0;
    type = 'S';

}

Student::Student(string l, string f, int a, float g) : Person(l, f, a){
    gpa = g;
    type = 'S';

}

Student::Student(string t, string l, string f, int a, float g) : Person(l, f, a){
    type = t[0];
    gpa = g;
}

void Student::print(){
    cout << lname << " " << fname << " " << gpa << endl;
    
}