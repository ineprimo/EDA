#include <iostream>
using namespace std;

#include "Date2.h"


Date2::Date2(int d,int m,int y) : day(d), month(m), year(y){ //throws domain_error
	//day = d; month = m; year = y;
	if (!correctDate()) throw domain_error("Invalid date");
}

Date2::Date2(const Date2& date) : day(date.day), month(date.month), year(date.year){
	//day = date.day; month = date.month; year = date.year;
}

void Date2::operator++(){
	// Asumimos que no hay años bisiestos
	day++;
	if (day > daysInMonth(month)){
		day = 1;
		month++;
		if (month > 12){
			month = 1;
			year++;
		}
	}
}

void Date2::operator+=(int n){
	for (int i = 0;i < n;i++)
		operator++(); // ++(*this);
}

int Date2::diff(const Date2& date) const{
	return (calculateValue() - date.calculateValue());
}

bool Date2::operator<(const Date2& other) const{
    if (year < other.year) return true;
    else if (year > other.year) return false;
    else if (month < other.month) return true;
    else if (month > other.month) return false;
    else return day < other.day;
}


/*void Date2::print() const {
	cout << day << "/" << month << "/" << year << endl;
}*/


// Función externa a la clase
ostream& operator<<(ostream& out, const Date2& d){
    out << d.day << "/" << d.month << "/" << d.year;
    return out;
}


// Private operations

int Date2::calculateValue() const{
	// Asumimos que no hay años bisiestos
	int v = 0;
	v += 365 * (year - 1);
	int m = month - 1;
	for (; m > 0; m--)
		v += daysInMonth(m);
	v += day;
	return v;
}

int Date2::daysInMonth(int m) const {
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

bool Date2::correctDate() const {
	bool correct;
	if ((year <= 0) || (month < 1) || (month > 12) || (day < 1) || (day > daysInMonth(month)))
		correct = false;
	else
		correct = true;
	return correct;
}
