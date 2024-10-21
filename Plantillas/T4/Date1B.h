
#ifndef DATE1B_H_
#define DATE1B_H_

// TAD Fecha representado con un valor (días pasados desde una fecha origen) sin encapsulación
// ni privacidad (no orientación a objetos)


typedef struct {
	int value;
} Date1B;


// Public operations
Date1B newDate1B(int day, int month, int year);
Date1B incr(const Date1B& date);
int diff(const Date1B& date, const Date1B& date_p);
void print(const Date1B& date);


// Private operations
void calculateDMY(const Date1B& date, int& day, int& month, int& year);
int daysInMonth1B(int m);
bool correctDate1B(int d,int m,int y);

#endif /* DATE1B_H_ */
