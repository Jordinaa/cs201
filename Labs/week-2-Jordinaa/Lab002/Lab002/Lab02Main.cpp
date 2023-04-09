#include <string>
#include <iostream>
using namespace std;


void weights(string name, float homework, float test, float quiz, float attendance){

	homework *= .20;
	test *= .50;
	quiz *= .20;
	attendance *= .10;

	cout << "Grades for: " << name << endl;
	cout << "  homework: " << homework << endl;
	cout << "  test: " << test << endl;
	cout << "  quiz: " << quiz << endl;
	cout << "  attendance: " << attendance << endl;
	cout << "===================" << endl;
	cout << "Total score: " << homework + test + quiz + attendance / 4;

}

int main() {

	float homeworkScore, testScore, quizScore, attendanceScore;
	string name;

	cout << "please enter your name: ";
	cin >> name;

	cout << "please enter your homework score: ";
	cin >> homeworkScore;

	cout << "please enter your test score: ";
	cin >>  testScore;

	cout << "please enter your quiz score: ";
	cin >>  quizScore;

	cout << "please enter your attendance score: ";
	cin >>  attendanceScore;

	weights(name, homeworkScore, testScore, quizScore, attendanceScore);
}