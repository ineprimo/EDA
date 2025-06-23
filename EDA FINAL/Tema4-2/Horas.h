#pragma once

class Horas
{
public:
	Horas() {
		horas = 0;
		minutos = 0;
		segundos = 0;
	};
	Horas(int h, int min, int segs) {
		if (0 <= h && h <= 23 &&
			0 <= min && min <= 59 &&
			0 <= segs && segs <= 59) 
		{
			horas = h;
			minutos = min;
			segundos = segs;
		}
		else {
			//throw std::invalid_argument("ERROR");
		}
	}

	const bool operator<(const Horas other) {
		return (horas < other.horas) ||
			(horas == other.horas && minutos < other.minutos) ||
			(horas == other.horas && minutos == other.minutos && segundos < other.segundos);
	}


	const bool operator==(const Horas other) {

		return horas == other.horas && minutos == other.minutos && segundos == other.segundos;
	}

	friend std::ostream& operator<<(std::ostream& out, const Horas& h);
	friend std::istream& operator>>(std::istream& in, Horas& h);

private:
	int horas;
	int minutos;
	int segundos;
};


// cout
std::ostream& operator<<(std::ostream& out, const Horas& h) 
{
	if (h.horas < 10) out << "0" << h.horas;
	else out << h.horas;
	out << ":";
	if (h.minutos < 10) out << "0" << h.minutos;
	else out << h.minutos;
	out << ":";
	if (h.segundos < 10) out << "0" << h.segundos;
	else out << h.segundos;

	return out;
}

// cin
std::istream& operator>>(std::istream& in, Horas& hora)
{
	int h, m, s;

	in >> h;
	in.ignore(1, ':');
	in >> m;
	in.ignore(1, ':');
	in >> s;

	hora = Horas(h, m, s);

	return in;
}

