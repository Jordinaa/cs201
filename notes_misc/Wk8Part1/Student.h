#pragma once
#include "Person.h"

class Student : public Person{
private: 
    float gpa;

public:
    Student();
    Student(string l, string f, int a, float g);
    Student(string t, string l, string f, int a, float g)

    float getGPA (){retur gpa;}
    void setGPA(float g) {gpa = g;}

    void print();

};