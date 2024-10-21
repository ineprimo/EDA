
#ifndef DATE1A_H_
#define DATE1A_H_

// TAD Fecha representado como <dia,mes,año> sin encapsulación ni privacidad (no orientación a objetos)

struct Date1A {
	int day;
	int month;
	int year;
} ;


// Public operations
Date1A newDate1A(int d, int m, int y);
Date1A incr(const Date1A& date);
int diff(const Date1A& date, const Date1A& date_p);
void print(const Date1A& date);


// Private operations
int calculateValue(const Date1A& date);
int daysInMonth(int m);
bool correctDate1A(int d,int m,int y);


#endif /* DATE1A_H_ */
