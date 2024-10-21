#ifndef DATE4_H_
#define DATE4_H_


class Date4{
	// Fechas representadas como <day,month,year> y además guardando el "value" para
	// acelerar computos

	private:
		int day;
		int month;
		int year;
		int value;

		int daysInMonth(int m) const;
		int calculateValue() const;
		bool correctDate() const;

	public:
		Date4(int d, int m, int y);
		Date4(const Date4& date);
		Date4& operator++();
		Date4& operator+=(int n);
		int diff(const Date4& date) const;
        bool operator<(const Date4& other) const;
        //void print() const;
        friend ostream& operator<<(ostream& out, const Date4& d);
};

#endif /* DATE4_H_ */
