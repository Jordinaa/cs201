#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

void deposit();
char MainMenu(void);
float CalculateLoanAmount(float principleamount, float interestRate, int months);
float GetValue(string message);
float GetValue(string message, float limit);
float GetInterestRate(float creditscore);
void Withdraw(float *balance, float amount);
void Withdraw(float *balance, float amount);
int GetLoanMonths(void);
float GetCreditRating(void);
float CalculateLoanAmount(float principleamount, float interestRate, int months);

