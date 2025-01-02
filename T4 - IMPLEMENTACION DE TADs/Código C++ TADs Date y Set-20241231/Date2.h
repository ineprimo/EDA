#ifndef DATE2_H_
#define DATE2_H_

// TAD Fecha representado como <dia,mes,año> con POO (encapsulación+privacidad)

class Date2{
	private:
		int day;
		int month;
		int year;

		int daysInMonth(int m) const;
		int calculateValue() const;
		bool correctDate() const;

	public:
		Date2(int d,int m,int y); // throws Error
		Date2(const Date2& date);
		void operator++();
		void operator+=(int n);
		int diff(const Date2& date) const;
		bool operator<(const Date2& other) const;
		//void print() const;
        friend ostream& operator<<(ostream& out, const Date2& d);
};


#endif /* DATE2_H_ */
