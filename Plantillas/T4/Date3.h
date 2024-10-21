#ifndef DATE3_H_
#define DATE3_H_


// TAD Fecha representado como un valor (días pasados desde una fecha origen) con POO (encapsulación+privacidad)

class Date3{
	// Fechas representadas con un solo entero que guarda el nº de días transcurridos
	// desde la fecha 1/1/1

	private:
		int value;

		int daysInMonth(int m) const;
		void calculateDMY(int& day,int& month,int& year) const;
		bool correctDate(int day,int month,int year) const;

	public:
		Date3(int d, int m, int y);
		Date3(const Date3& date);
		void operator++();
		void operator+=(int n);
		int diff(const Date3& date) const;
        bool operator<(const Date3& other) const;
        //void print() const;
        friend ostream& operator<<(ostream& out, const Date3& d);
};


#endif /* DATE3_H_ */
