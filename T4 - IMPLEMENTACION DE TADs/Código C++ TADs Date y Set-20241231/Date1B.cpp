#include <iostream>
using namespace std;

#include "Date1B.h"

Date1B newDate1B(int day,int month,int year){ //throws domain_error
	// Asumimos que no hay años bisiestos
	if (!correctDate1B(day,month,year)) throw domain_error("Invalid date");
	Date1B date;
	date.value = 0;
	date.value += 365 * (year - 1);
	int m = month - 1;
	for (; m > 0; m--)
		date.value += daysInMonth1B(m);
	date.value += day;
	return date;
}

Date1B incr(const Date1B& date){
	Date1B date_p = date;
	date_p.value++;
	return date_p;
}

int diff(const Date1B& date,const Date1B& date_p){
	return date.value - date_p.value;
}

void print(const Date1B& date) {
	int day, month, year;
	calculateDMY(date,day,month,year);
	cout << day << "/" << month << "/" << year << endl;
}


// Private operations

int daysInMonth1B(int m) {
	int numDays = 0;
	switch (m) {
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
			numDays = 31;
			break;
		case 4:case 6:case 9:case 11:
			numDays = 30;
			break;
		case 2:
			numDays = 28;
			break;
		default:
			numDays = 0;
	}//switch
	return numDays;
}

void calculateDMY(const Date1B& date,int& day,int& month,int& year) {
	// Asumimos que no hay años bisiestos
	year = date.value/365 + 1;
	int v = date.value%365;
	int m = 1;
	int daysInM = daysInMonth1B(m);
	while (v > daysInM){
		v = v - daysInM;
		m++;
		daysInM = daysInMonth1B(m);
	}
	month = m;
	day = v;
}

bool correctDate1B(int d,int m,int y){
	bool correct;
	if ((y <= 0) || (m < 1) || (m > 12) || (d < 1) || (d > daysInMonth1B(m)))
		correct = false;
	else
		correct = true;
	return correct;
}

