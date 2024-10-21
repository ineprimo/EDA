#include <iostream>
using namespace std;

#include "Date3.h"


Date3::Date3(int day, int month, int year){ //throws domain_error
	// Asumimos que no hay años bisiestos
	if (!correctDate(day,month,year)) throw domain_error("Invalid date");
	value = 0;
	value += 365 * (year - 1);
	int m = month - 1;
	for (; m > 0; m--)
		value += daysInMonth(m);
	value += day;
}

Date3::Date3(const Date3& date) : value(date.value){
}

void Date3::operator++(){
	value++;
}

void Date3::operator+=(int n){
	for (int i = 0;i < n;i++)
		operator++(); // ++(*this);
}

int Date3::diff(const Date3& date) const {
	return (value - date.value);
}

bool Date3::operator<(const Date3& other) const{
    return value < other.value;
}

/*
void Date3::print() const {
	int day, month, year;
	calculateDMY(day,month,year);
	cout << day << "/" << month << "/" << year << endl;
}*/


// Función externa a la clase
ostream& operator<<(ostream& out, const Date3& d){
    int day, month, year;
    d.calculateDMY(day,month,year);
    out << day << "/" << month << "/" << year;
    return out;
}


// Private operations

int Date3::daysInMonth(int m) const {
	// Asumimos que no hay años bisiestos
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

void Date3::calculateDMY(int& day, int& month, int& year) const {
	// Asumimos que no hay años bisiestos
	year = value/365 + 1;
	int v = value%365;
	int m = 1;
	int daysInM = daysInMonth(m);
	while (v > daysInM){
		v = v - daysInM;
		m++;
		daysInM = daysInMonth(m);
	}
	month = m;
	day = v;
}

bool Date3::correctDate(int day, int month, int year) const {
	bool correct;
	if ((year <= 0) || (month < 1) || (month > 12) || (day < 1) || (day > daysInMonth(month)))
		correct = false;
	else
		correct = true;
	return correct;
}
