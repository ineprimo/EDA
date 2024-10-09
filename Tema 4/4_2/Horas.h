#pragma once

class Horas {
public:
	//operator <

	Horas() {

		horas = 0;
		min = 0;
		seg = 0;
	}

	Horas(int h, int m, int s) {

		if (0 <= h && h <= 23 &&
			0 <= m && m <= 59 &&
			0 <= s && s <= 59)
		{
			horas = h;
			min = m;
			seg = s;
		}
		else throw std::invalid_argument("ERROR");
	}

	const bool operator< (const Horas otro) {

		return
			(horas < otro.horas) ||
			(horas == otro.horas && min < otro.min) ||
			(horas == otro.horas && min == otro.min && seg < otro.seg);
		
	}

	const bool operator== (const Horas otro) {

		return horas == otro.horas && min == otro.min && seg == otro.seg;
	}

	//Operadores de escritura, son amigos porque es externa a la clase
	friend std::ostream& operator<<(std::ostream& out, const Horas& h);
	friend std::istream& operator>>(std::istream& in, Horas& h);


protected:

	int horas;
	int min;
	int seg;

};

//Definicion de los operadores de escritura y lectura

std::ostream& operator<<(std::ostream& out, const Horas& h) {
	
	//Escribimos las horas
	/*if (h.horas < 10) out << "0" << h.horas << ":";
	else out << h.horas << ":";*/

	//Hacemos lo mismo con los minutos con una nomenclatura mas corta
	out << (h.horas < 10 ? "0" : "") << h.horas << ":"
		<< (h.min < 10 ? "0" : "") << h.min << ":"
		<< (h.seg < 10 ? "0" : "") << h.seg;

	return out;
}

std::istream& operator>>(std::istream& in, Horas& hor) {

	int h, m, s;

	in >> h;
	in.ignore(1, ':');

	in >> m;
	in.ignore(1, ':');

	in >> s;
	hor = Horas(h, m, s);

	return in;
}
