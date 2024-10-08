// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


bool parcialmenteOrdenado(const std::vector<int>& v, int ini, int fin, int& min, int& max)
{
	...
}

bool parcialmenteOrdenado(const std::vector<int>& v)
{
	int min, max;
	return parcialmenteOrdenado(v, 0, v.size(), min, max);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	// leer los datos de la entrada
	int e;
	std::cin >> e;
	if (e == 0)
	{
		return false;
	}

	std::vector<int> sec;
	while (e != 0)
	{
		sec.push_back(e);
		std::cin >> e;
	}

	std::cout << (parcialmenteOrdenado(sec) ? "SI" : "NO") << std::endl;
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