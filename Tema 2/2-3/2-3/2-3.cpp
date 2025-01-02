// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// Algoritmo que dado un vector dice si esta parcialmente ordenado.
// COMPLEJIDAD: O(n * logn) siendo n  el numero de elementos del vector.
bool parcialmenteOrdenado(const std::vector<int>& sec, int ini, int fin, int& min, int& max)
{
	// Casos base:
	if (fin == ini) // Caso base vector vacio.
	{
		return true;
	}
	if (fin - ini == 1)
	{
		min = sec[ini];
		max = sec[fin];
		return max >= min;
	}

	int mid = ini + ((fin - ini) / 2); // Calcular la mitad.

	int mayorIzq, menorIzq, mayorDer, menorDer;

	bool solIzq = parcialmenteOrdenado(sec, ini, mid, menorIzq, mayorIzq);
	bool solDer = parcialmenteOrdenado(sec, mid + 1, fin, menorDer, mayorDer);

	// Asigna el menor y el mayor.
	min = menorIzq;
	max = mayorDer;

	return solIzq && solDer && (mayorDer >= mayorIzq && menorIzq <= menorDer);
}

bool parcialmenteOrdenado(const std::vector<int>& v)
{
	int min, max;
	return parcialmenteOrdenado(v, 0, v.size() - 1, min, max);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
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