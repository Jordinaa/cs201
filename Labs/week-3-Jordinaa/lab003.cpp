#include <iostream>
#include <string>
using namespace std;

int main()
{

	const double CHILD_TICKET = 10.95, ADULT_TICKET = 19.99, SENIOR_TICKET = 18.99, VIP_TICKET = 7.99;
	double childTotal, adultTotal, seniorTotal, vipTotal, dayTotal, total = 0;
	char userInput;
	int numInput;

	cout << "Welcome to Fun Park Menu System!!" << endl;
	
	for(int i = 1; i <= 3; i++){
		cout << "Starting day " << i << endl;
		int childCount = 0, adultCount = 0, seniorCount = 0, vipCount = 0;
		bool exit = false;

		//User has not selected the 'Quit' option
		while (exit == false){
			cout << "Enter (C)hild, (A)dult, (S)enior, (V)IP, or (Q)uit ";
			cin >> userInput;
			userInput = toupper(userInput);			//Set letter to Uppercase
			numInput = 0;
			
			switch (userInput){
            // child
				case 'C':
					cout << "How many Children? ";
					cin >> numInput;
					if (numInput < 0 || cin.fail()){
						cout << "Invalid amount of tickets." << endl;
					}
					else
						childCount += numInput;
					break;
            // adult
				case 'A':
					cout << "How many Adults? ";
					cin >> numInput;
					if (numInput < 0 || cin.fail()){
						cout << "Invalid amount of tickets." << endl;
					}
					else
						adultCount += numInput;
					break;
            // senior
				case 'S':
					cout << "How many Seniors? ";
					cin >> numInput;
					if (numInput < 0 || cin.fail()){
						cout << "Invalid amount of tickets." << endl;
					}
					else
						seniorCount += numInput;
					break;
            // vip
				case 'V':
					cout << "How many VIPs? ";
					cin >> numInput;
					if (numInput < 0 || cin.fail()){
						cout << "Invalid amount of tickets." << endl;
					}
					else
						vipCount += numInput;
					break;

				case 'Q':
					exit = true;
					break;
				default:
					cout << "Invalid input" << endl;
					break;}

			cin.clear();
			cin.ignore(10000, '\n');}

		// Cost of all and each ticket
		childTotal = childCount * CHILD_TICKET;
		adultTotal = adultCount * ADULT_TICKET;
		seniorTotal = seniorCount * SENIOR_TICKET;
		vipTotal = vipCount * VIP_TICKET;
		dayTotal = childTotal + adultTotal + seniorTotal + vipTotal; 
		total += dayTotal; 
		
		//User purchases tickets for the day
		if (childCount > 0 || adultCount > 0 || seniorCount > 0 || vipCount > 0) {
			cout << "Day " << i << endl;
			cout << "Child: " << childCount << " @ " << CHILD_TICKET << " = " << childTotal << endl;
			cout << "Adult: " << adultCount << " @ " << ADULT_TICKET << " = " << adultTotal << endl;
			cout << "Senior: " << seniorCount << " @ " << SENIOR_TICKET << " = " << seniorTotal << endl;
			cout << "VIP: " << vipCount << " @ " << VIP_TICKET << " = " << vipTotal << endl;
			cout << endl;
			cout << "Total: " << dayTotal << endl;}
		else
			continue;

	}
	cout << "Total for all days = " << total;	
}