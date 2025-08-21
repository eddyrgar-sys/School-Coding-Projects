//This program will compute and display the charges for a patient’s hospital stay. 
//First, the program should ask if the patient was admitted as an In-patient or an Out-patient.
//Programmer: Eddy Garcia

#include <iostream>
#include <iomanip>
using namespace std;

char getPatientType() 
{
	char ch;
	cout << "This program will compute patient hospital charges." << endl;
	cout << "What was the patient type?" << endl;
	cout << "In-patient or Out-patient? (I or O): "; cin >> ch;
	while (ch != 'I' && ch != 'i' && ch != 'O' && ch != 'o') 
	{
		cout << "Enter \'I\' - In-Patient or \'O\' - Out-Patient: "; cin >> ch;
	}
	if (ch == 'i' || ch == 'I') return 'I';
	else return 'O';
}

double patientCharges(int days, double rate, double medCharges, double serviceCharges) 
{
	return days * rate + medCharges + serviceCharges;
}

double patientCharges(double medCharges, double serviceCharges) 
{
	return  medCharges + serviceCharges;
}

int main()
{
	char type;
	int days;
	double dailyRate, medicationCharges, serviceCharges;
	double totalCharges;

	type = getPatientType();
	if (type == 'I')
	{
		cout << "Number of days in the hospital: "; cin >> days;
		while (days < 0)
		{
			cout << "Re-enter the number of days (positive numbers only): "; cin >> days;
		}
		cout << "Daily room rate: "; cin >> dailyRate;
		while (dailyRate < 0)
		{
			cout << "Re-enter daily rate (positive numbers only): "; cin >> dailyRate;
		}
	
		cout << "Medication charges: "; cin >> medicationCharges;
		while (medicationCharges < 0)
		{
			cout << "Re-enter medication charges (positive numbers only): "; cin >> medicationCharges;
		}
		cout << "Lab fees and other service charges: "; cin >> serviceCharges;
		while (serviceCharges < 0)
		{
			cout << "Re-enter service charges (positive numbers only): "; cin >> serviceCharges;
		}
	}
	{
		if (type == 'I') totalCharges = patientCharges(days, dailyRate, medicationCharges, serviceCharges);
		else if (type == 'O') totalCharges = patientCharges(medicationCharges, serviceCharges);

		cout << setprecision(2) << fixed << showpoint;
		cout << "Total charges: $" << totalCharges << endl;
	}
	return 0;
}