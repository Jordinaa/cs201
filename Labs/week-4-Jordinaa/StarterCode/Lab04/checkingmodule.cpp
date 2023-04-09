#include "checkingmodule.h"

void deposit(float& account, float amount){
	account += amount;
}

char MainMenu(void){
    char choice; 
    do{
        cout << endl << "Main Menu (Enter one of the following)";
        cout << endl << "(D)eposit, (W)ithdrawal, (L)oan, or (Q)uit: ";
        cin >> choice;
        cin.ignore();
        if((toupper(choice) != 'D') && (toupper(choice) != 'W') && (toupper(choice) != 'L') && (toupper(choice) != 'Q'))
            cout << endl << "Invalid Choice";
    }

    while((toupper(choice) != 'D') && (toupper(choice) != 'W') &&
          (toupper(choice) != 'L') && (toupper(choice) != 'Q'));
    return choice;
}

float GetValue(string message){
    float val;
    do{
        cout << message << " ~~~> ";
        cin >> val;
        if(val <= 0)
            cout << "Enter a value greater than 0" << endl;
    }
    while(val <= 0);
    return val;
}

float GetValue(string userInput, float UpperLimit){
    float value;
    do{
        cout << userInput << " ~~~> ";
        cin >> value;
        if(value < 0 || value > UpperLimit)
            cout << "Enter a value within range 0 to " << userInput;
    }
    while(value < 0 || value > UpperLimit);
    return value;
}

float GetInterestRate(float creditscore){
    float interest;
    if(creditscore <= 500)
        interest = 0.05;
    else if(creditscore <= 700)
        interest = 0.03;
    else
            interest = 0.01;
    return interest;
}

void Withdraw(float *balance, float amount){
    *balance =* balance - amount;
    return;
}

int GetLoanMonths(void){
    int months;
    do{
        cout << endl << "How many months for the loan (12, 24, 36, 60)? ~~~~~~~> ";
        cin >> months;
        if(months == 0 || months % 12 != 0)
            cout << "You must choose months from 12, 24, 36, 60";
    }
    while(months == 0 || months % 12 != 0);
    return months;
}

float GetCreditRating(){
    float creditrating;
    do{
        cout << endl << "What is your credit rating [300,800]? ~~~~~~~> ";
        cin >> creditrating;
        if(creditrating < 300 || creditrating > 800)
            cout << endl << "You must choose a credit rating from [300,800]";
    }
    while(creditrating < 300 || creditrating > 800);
    return creditrating;
}

float CalculateLoanAmount(float principleAmount, float interest, int months){
    float loanamount;
    loanamount = principleAmount * pow((1 + (interest / 12)), months / 12.0);
    return loanamount;
}

