#include "checkingmodule.cpp"

int main(void) {
	float accountValue = 0.0f;
	float depositAmount, withdrawAmount, creditscore, months, interestRate, principleamount, loanamount;
	char choice;

	do{
		choice = MainMenu();
		switch(toupper(choice)){
			case 'D':
                depositAmount = GetValue("How much do you want to deposit? ");
                cout << "Account Summary" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "\tAmount $" << depositAmount << endl;
                break;
            case 'W':
                withdrawAmount = GetValue("How much you want to withdraw? ", depositAmount);
                Withdraw(&depositAmount, withdrawAmount);
                cout <<"Account Summary" << endl;
                cout <<"~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "\tAmount $" << depositAmount << endl;
                break;
            case 'L':
                cout << setprecision(2);
                cout << fixed;
                creditscore = GetCreditRating();
                months = GetLoanMonths();
                interestRate = GetInterestRate(creditscore);
                principleamount = GetValue("How much you want to loan?");
                loanamount = CalculateLoanAmount(principleamount, interestRate, months);
                cout << "Loan Summary"<< endl; 
                cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "Principal Amount = " << principleamount;
                cout << "Months = " << months << endl;
                cout << "Interest Rate = " << interestRate << endl;
                cout << "Your Loan Amount will be: " << loanamount << endl;
                break;
		}
	}
	// quits if user selects q
	while(toupper(choice) != 'Q');
}