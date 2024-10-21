#include <iostream>
using namespace std;

#include "Date1A.h"
#include "Date1B.h"
#include "Date2.h"
#include "Date3.h"
#include "Date4.h"

void testDate1(){
	Date1A date = newDate1A(31, 12, 1981);
	Date1A date2 = incr(incr(incr(date)));
	print(date2);
	cout << diff(date2,date) << endl;
}

void testDate2(){
	Date2 date(31,12,1981);
	Date2 date2 = date;
	date2 += 2;
	//date2.print();
	cout << date2 << endl;
	cout << date2.diff(date) << endl;
}

void testDate3(){
	Date3 date(31, 12, 1981);
	Date3 date2 = date;
	date2 += 5;
	//date2.print();
	cout << date2 << endl;
	cout << date2.diff(date) << endl;
}

void testDate4(){
	Date4 date(31, 12, 1981);
	Date4 date2 = date;
	date2 += 7;
	++date2;
	//date2.print();
	cout << date2 << endl;
	cout << date2.diff(date) << endl;
}

int main(){
    testDate1();
    testDate2();
    testDate3();
    testDate4();
}
