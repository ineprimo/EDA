#include <iostream>
using namespace std;

#include "Date4.h"


Date4::Date4(int d, int m, int y) : day(d), month(m), year(y) { //throws domain_error
	// Asumimos que no hay años bisiestos
	if (!correctDate()) throw domain_error("Invalid date");
	value = calculateValue();
}

Date4::Date4(const Date4& date) : day(date.day), month(date.month), year(date.year), value(date.value){
}

int Date4::calculateValue() const{
	// Asumimos que no hay años bisiestos
	int v = 0;
	v += 365 * (year - 1);
	int m = month - 1;
	for (; m > 0; m--)
		v += daysInMonth(m);
	v += day;
	return v;
}

Date4& Date4::operator++(){
	value++;
	day++;
	if (day > daysInMonth(month)){
		day = 1;
		month++;
		if (month > 12){
			month = 1;
			year++;
		}
	}
	return *this;
}

Date4& Date4::operator+=(int n){
	for (int i = 0;i < n;i++)
		operator++();// ++(*this);
	return *this;
}

int Date4::diff(const Date4& date) const {
	return (value - date.value);
}

bool Date4::operator<(const Date4& other) const{
    return value < other.value;
}

/*void Date4::print() const {
	cout << day << "/" << month << "/" << year << endl;
}*/


// Función externa a la clase
ostream& operator<<(ostream& out, const Date4& d){
    out << d.day << "/" << d.month << "/" << d.year;
    return out;
}


// Private operations

int Date4::daysInMonth(int m) const {
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

bool Date4::correctDate() const {
	bool correct;
	if ((year <= 0) || (month < 1) || (month > 12) || (day < 1) || (day > daysInMonth(month)))
		correct = false;
	else
		correct = true;
	return correct;
}

