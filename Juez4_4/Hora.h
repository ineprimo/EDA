#pragma once

#include <iostream>
#include <vector>

class Hora
{
	int h, m, s;

	bool validate() const
	{
		// returns true if valid time
		return
			0 <= h &&
			h <= 23 &&
			0 <= m &&
			m <= 59 &&
			0 <= s &&
			s <= 59;
	}

public: // constructoras
	Hora(int h = 0, int m = 0, int s = 0) : h(h), m(m), s(s)
	{
		if (!validate())
			throw std::invalid_argument("ERROR");
	}

	Hora(const Hora& hora) : h(hora.h), m(hora.m), s(hora.s)
	{
		if (!validate())
			throw std::invalid_argument("ERROR");
	}

	~Hora() = default;

	// operators
	bool operator<(const Hora& hora) const
	{
		return
			(h < hora.h) ||
			(h == hora.h && m < hora.m) ||
			(h == hora.h && m == hora.m && s < hora.s);
	}

	bool operator>(const Hora& hora) const
	{
		return
			(h > hora.h) ||
			(h == hora.h && m > hora.m) ||
			(h == hora.h && m == hora.m && s > hora.s);
	}

	Hora& operator=(const Hora& other)
	{
		if (this != &other)
		{
			h = other.h;
			m = other.m;
			s = other.s;

			if (!validate())
				throw std::invalid_argument("ERROR");
		}
		return *this;
	}

	bool operator==(const Hora& o) const
	{
		return
			h == o.h &&
			m == o.m &&
			s == o.s;
	}

	Hora operator+(const Hora& hora) const
	{
		Hora resultado;
		int h, m, s;
		s = hora.s + this->s;
		m = hora.m + this->m + (s / 60);
		h = hora.h + this->h + (m / 60);

		resultado.s = s % 60;
		resultado.m = m % 60;
		resultado.h = h;

		if (h > 24) throw std::invalid_argument("ERROR");

		return resultado;
	}

	friend std::ostream& operator<<(std::ostream& out, const Hora& h);
	// friend porque accede a campos privados pero es funcion externa
	friend std::istream& operator>>(std::istream& in, Hora& h);
	// friend porque accede a campos privados pero es funcion externa
	friend bool operator<=(const Hora& a, const Hora& b);
	friend bool operator>=(const Hora& a, const Hora& b);
};

std::ostream& operator<<(std::ostream& out, const Hora& hora)
{
	out << (hora.h < 10 ? "0" : "") << hora.h << ":"
		<< (hora.m < 10 ? "0" : "") << hora.m << ":"
		<< (hora.s < 10 ? "0" : "") << hora.s;

	return out;
}

std::istream& operator>>(std::istream& in, Hora& hora)
{
	int h, m, s;
	in >> h;
	in.ignore(1, ':');
	in >> m;
	in.ignore(1, ':');
	in >> s;
	hora = Hora(h, m, s);
	return in;
}

inline bool operator<=(const Hora& a, const Hora& b)
{
	return a == b || a < b;
}

inline bool operator>=(const Hora& a, const Hora& b)
{
	return a == b || a > b;
}