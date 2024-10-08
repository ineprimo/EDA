// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>


std::pair<bool, int> caucasico(const std::vector<int>& vec, int ini, int fin)
{
	int size = fin - ini;

	// Caso base tiene 1 elemento => es caucasico.
	if (size == 1)
	{
		if ((vec[ini] % 2) == 0)
		{
			return { true, 1 };
		}
		else
		{
			return { true, 0 };
		}
	}

	int mitad = (ini + fin) / 2;

	std::pair<bool, int> izq = caucasico(vec, ini, mitad);

	if (izq.first) // Si no es caucasica la primera mitad el total no lo va a ser.
	{
		std::pair<bool, int> der = caucasico(vec, mitad, fin);

		int dif = abs(izq.second - der.second); // Valor absoluto del numero de pares de una mitad y de la otra.

		// Para que sea caucasico tiene que serlo la primera mitad, la segunda y que el valor absoluto de la diferencia de los pares de cada mitad sea menor o igual a 2.
		return { izq.first && der.first && dif <= 2, izq.second + der.second };
	}
	return izq;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	if (n == 0)
	{
		return false;
	}

	std::vector<int> sec(n);
	for (int& e : sec)
	{
		std::cin >> e;
	}

	std::cout << (caucasico(sec, 0, sec.size()).first ? "SI" : "NO") << std::endl;
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
	//system("PAUSE");
#endif

	return 0;
}