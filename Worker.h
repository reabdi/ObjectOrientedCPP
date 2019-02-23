// CIS 554
// By: Reza Abdi
// Assignment 02

#include <iostream>
using namespace std;

// Class defination
class Worker
{
public:
	Worker(int);					//constructor of the code
	void paymentCalculator();		//the main function to use swith and call the payment functions for each kind of worker
private:
	void paymentManager();			//the function for calculating the manager payments
	void paymentHourly();			//the function for calculating the hourly worker payments
	void paymentCommission();		//the function for calculating the commission worker payments
	void paymentPieceworker();		//the function for calculating the pieceworker payments
	void utility();					//the private function which makes the chart of the total payments
	double weeklyPayment;			//the weekly payment for managers
	double hourlyPayment;			//the payment for each hourly worker using the inputs including hourly wage, the working hour and overtime 
	double commissionPayment;		//the payment for each commission worker
	double pieceworkerPayment;		//the payment for each pieceworker 
	double managerSum;				//total amount of payments for managers
	double hourlySum;				//total amount of payments for hourly workers
	double commissionSum;			//total amount of payments for commission workers
	double pieceworkerSum;			//total amount of payments for pieceworkers
	int workersNumber;				//the number of workers which the code will ask as the first question
};



