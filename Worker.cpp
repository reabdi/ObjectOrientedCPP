// CIS 554
// By: Reza Abdi
// Assignment 02 

#include <iostream>
#include <string>
#include <iomanip>
#include "Worker.h"	//The header file is included
using namespace std;

//Defination of the constructor of the class 
Worker::Worker(int)
{
	//Initialization for values in constructor
	weeklyPayment = 0;
	hourlyPayment = 0;
	commissionPayment = 0;
	pieceworkerPayment = 0;
	managerSum = 0;
	hourlySum = 0;
	commissionSum = 0;
	pieceworkerSum = 0;
	workersNumber = 0;
}

//The function which calculate the payments for managers. The functions will ask the weekly payment and show that amount as the payment
void Worker::paymentManager()
{
	cout << "Manager worker selected." << endl;
	cout << "Please enter the weekly salary: ";
	cin >> weeklyPayment;												//Asking for the weekly payment for the manager
	cout << "manager worker's pay is: $" << weeklyPayment << endl;		//Showing the final amount for that manager
}

//The function calculate the payments for hourly workers.
//The function will ask hourly wage, working time (which should be less than 40 hours) and the overtime hours and calculate the payment
void Worker::paymentHourly()
{
	double hourlyWage;
	double workingTime;
	double overtimeHours;
	cout << "Hourly worker selected." << endl;;
	cout << "Please enter the hourly Wage: ";	
	cin >> hourlyWage;														//Here we need to enter the hourly wage for each hourly worker
	cout << "Please enter the hours worked up to 40 hours: ";
	cin >> workingTime;														//Working hour should be entered here
	while (workingTime > 40)												//The working hour must be less that 40 hours	
	{
		cout << "Your entered hours workes is more than MAX 40 hours,"
			 << "\nPlease enter the hours worked up to 40 hours: ";
		cin >> workingTime;													//Replacing the amount of working hour
	}
	cout << "Please enter the overtime hours worked: ";
	cin >> overtimeHours;													//Asking for the overtime hours
	hourlyPayment = (hourlyWage * workingTime) + (1.5 * hourlyWage * overtimeHours);	//Calculating the hourly payment for each hourly worker
	cout << "Hourly worker's pay is: $" << hourlyPayment << endl;						//And finally showing the answer
}

//The function will calculate the paymanet for commsion workers
//We need to enter the weekly sales
void Worker::paymentCommission()
{
	double weeklySales;
	cout << "Commission worker selected." << endl;;
	cout << "Please enter the weekly sales: ";
	cin >> weeklySales;														//The function will ask the weekly sales and we need to enter here
	commissionPayment = (250 + (0.057 * weeklySales));						//Calculating the payments
	cout << "Commission worker's pay is: $" << commissionPayment << endl;	//And showing the answer
}

//The function will calcualte the payments for piecworkers
void Worker::paymentPieceworker()
{
	int pieceNumber;
	double pieceWage;
	cout << "Pieceworker selected." << endl;;
	cout << "Please enter the number of pieces: ";
	cin >> pieceNumber;														//The required variable in this function is the number of pieces
	cout << "Please enter the wage per each pieces: ";
	cin >> pieceWage;														//And the other one is the wage amount for each piece
	pieceworkerPayment = pieceNumber*pieceWage;								//Calculating the payment
	cout << "Pieceworker's pay is: $" << pieceworkerPayment << endl;		//And finally showing the result
}

//This is the main function which all of the other function will be called in this one.
void Worker::paymentCalculator()
{
	int paycode;												 
	cout << "Please enter the number of the workers: ";			//First step is asking the number of the workers
	cin >> workersNumber;										//Here we can enter the workers number
	for (int number = 1; number <= workersNumber; number++)		//Statring a for loop for calculating the payments
	{
		cout << "\nEnter paycode (-1 to finish): ";				//AAsking the paycode which is between 1 through 4
		cin >> paycode;
		if (paycode != -1) {									//Starting the if-switch process here for 4 conditions
			switch (paycode)
			{
			case 1:												//Manager worker, 
				paymentManager();								//Calling the relevant function
				managerSum = managerSum + weeklyPayment;		//I need the total amount of payments for creating the chart
				break;
			case 2:												//Hourly worker
				paymentHourly();								//Caling the relevant function with hourly worker
				hourlySum = hourlySum + hourlyPayment;			//The total amount of payments for hoyrly workers for the chart
				break;
			case 3:													//Commission worker
				paymentCommission();								//Calling the function which is created for commission workers
				commissionSum = commissionSum + commissionPayment;	//The total amount of payments for commission workers
				break;
			case 4:														//The pieceworker section
				paymentPieceworker();									//The required function for pieceworker payment calculations
				pieceworkerSum = pieceworkerSum + pieceworkerPayment;	//The total amount of payment for pieceworkers
				break;
			case '\n':													//ignore newlines				
			case '\t':													//tabs
			case ' ':													//and spaces in input
				break;
			default:													//The defualt condition for the switch 
				cout << "Incorrect paycode entered. " << endl;
				cout << "Enter a new paycode. ";
				number = number - 1;									//I need to keep the neumber of workers correct even with entering a wrong input
				break;
			}							//End switch
		}								//ENd If 
		else
			break;
	}									//End of the for loop
	utility();
}

//The function which usin the total amount will create a chart for the payments 
void Worker::utility()
{
	int starManager = managerSum / 100;								//Member functions for creating the required foor loops
	int starHourly = hourlySum / 100;
	int starCommission = commissionSum / 100;
	int starPieceworker = pieceworkerSum / 100;
	cout << "\nManager: " << setw(11);								//The first row will be for managaers including a accurate distance
	for (int counter1 = 1; counter1 <= starManager; counter1++)		//For loop to adding calcualted amoun tof stars for managers
	{
		cout << "*";
	}
	cout << endl;
	cout << "Hourly: " << setw(12);									//The next row will be for hourly workers including a accurate distance
	for (int counter2 = 1; counter2 <= starHourly; counter2++)		//For loop to adding calcualted amoun tof stars for hourly workers
	{
		cout << "*";
	}
	cout << endl;
	cout << "Commission: " << setw(8);								//The 3rd row will be for commission workers including the requred distance
	for (int counter3 = 1; counter3 <= starCommission; counter3++)	//For loop to adding calcualted amoun tof stars for commission workers
	{
		cout << "*";
	}
	cout << endl;
	cout << "Pieceworker: " << setw(7);								//The last row is for the pieceworkers. This on e is the last row for our chart
	for (int counter4 = 1; counter4 <= starPieceworker; counter4++)	//Defining the for loop for adding the stars in front of pieceworker.
	{
		cout << "*";
	}
	cout << endl;
}