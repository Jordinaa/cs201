#include <Person.h>

using namespace std;

int Person::totalPeople = 0;


int main(){
    vector <Person> people;
    readFile(people);
    Person peep1("james", "lebron", 38);
    people.push_back(peep1);
    Person::totalPeople ++;
    Person peep2;
    peep2.setfName("Rhanna");
    peep2.setlName("Fenti");
    peep2.setAge(35)
    people.push_back(peep2)
    Person::totalPeople ++;
    printVector(people);

}


