#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

class Hora
{
	int h, m, s;

	bool validate() const
	{
		// returns true if valid time
		return
			0 <= h && h < 24 &&
			0 <= m && m < 60 &&
			0 <= s && s < 60;
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

	friend std::ostream& operator<<(std::ostream& out, const Hora& h);
	friend std::istream& operator>>(std::istream& in, Hora& h);
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

bool operator<=(const Hora& a, const Hora& b)
{
	return a == b || a < b;
}

bool operator>=(const Hora& a, const Hora& b)
{
	return a == b || a > b;
}

// devuelve la hora del siguiente tren segun la consultada
bool siguiente(const std::vector<Hora>& trenes, const Hora& consulta, Hora& sig,
	int ini, int fin)
{
	int n = fin - ini;
	int mit = (ini + fin) / 2;


	// busqueda convencinal
	unsigned int i = 0;
	while (i < trenes.size())
	{
		if (consulta <= trenes[i])
		{
			sig = trenes[i];
			return true;
		}
		i++;
	}
	return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	int n = 0, m = 0;
	std::cin >> n >> m;

	if (n == 0 && m == 0)
		return false;

	std::vector<Hora> trenes(n);
	for (auto& tren : trenes)
		std::cin >> tren;

	Hora sig, consulta;
	for (int i = 0; i < m; i++)
	{
		try
		{
			std::cin >> consulta;
			if (siguiente(trenes, consulta, sig, 0, trenes.size()))
				std::cout << sig << std::endl;
			else
				std::cout << "NO\n";
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "ERROR" << std::endl;
		}
	}
	std::cout << "---\n";
	return true;
}

int main()
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}