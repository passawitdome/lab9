#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double loanTerm,interestRate,Payment,Prevbalance,interest,Total,NewBalance;
	int N = 1;
	cout << "Enter initial loan: ";
	cin >> loanTerm;
	cout << "Enter interest rate per year (%): ";
	cin >> interestRate;
	cout << "Enter amount you can pay per year: ";
	cin >> Payment;
	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	

	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	cout << fixed << setprecision(2);
	Prevbalance = loanTerm;
	while (true)
	{
		interest = Prevbalance*interestRate/100;

		Total = Prevbalance + interest;

		double currentPayment;
		if(Total >= Payment) currentPayment = Payment;
		else {
			currentPayment = Total;
		}

		NewBalance = Total - currentPayment;
	
		cout << setw(13) << left << N;
		cout << setw(13) << left << Prevbalance;
		cout << setw(13) << left << interest;
		cout << setw(13) << left << Total;
		cout << setw(13) << left << currentPayment;
		cout << setw(13) << left << NewBalance;
		
		N++;
		Prevbalance = NewBalance;
		cout << "\n";
		if(NewBalance == 0)break;
	}
	
	return 0;
}