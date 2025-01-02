#pragma once

#include <iostream> // invalid_Argument

class Horas
{
public:

	Horas() {
		h = 0;
		min = 0;
		seg = 0;
	}

	Horas(int hs, int mins, int segs)
	{
		if ((hs < 0 || hs > 23) ||
			(mins < 0 || mins > 59) ||
			(segs < 0 || segs > 59))
		{
			// El método what() de std::invalid_argument devuelve el mensaje
			// en el momento de lanzar la excepción
			throw std::invalid_argument("ERROR");
		}
		else {
			h = hs;
			min = mins;
			seg = segs;
		}
	}

	// other es const porque no lo vamos a modificar
	// el operador es const porque es observador, y porque pertenece a la clase
	bool operator<(const Horas& other) const
	{
		if (h != other.h) {
			return h < other.h;
		}
		if (min != other.min) {
			return min < other.min;
		}
		return seg < other.seg;
	}

	// out no es const porque se modifica el flujo de salida
	// el metodo/operador no es const porque es externo a la clase
	friend std::ostream& operator<<(std::ostream& out, const Horas& hora);
	friend std::istream& operator>>(std::istream& in, Horas& hora);

private:
	int h, min, seg;
};

// cout << hora << endl; 
// se devuelve un ostream para que pueda ser concatenado (se puede seguir con << detras)
std::ostream& operator<<(std::ostream& out, const Horas& hora)
{
	out << (hora.h < 10 ? "0" : "") << hora.h << ":"
		<< (hora.min < 10 ? "0" : "") << hora.min << ":"
		<< (hora.seg < 10 ? "0" : "") << hora.seg;

	return out;
}

std::istream& operator>>(std::istream& in, Horas& hora)
{
	int h, m, s;
	char separador; // para pillar ':' (se supone que el todos los casos sera ese)

	in >> h >> separador >> m >> separador >> s;

	hora = Horas(h, m, s);

	return in;
}

