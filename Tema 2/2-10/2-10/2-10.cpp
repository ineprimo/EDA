// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// COMPLEJIDAD: logartimica O(log n) siendo n el numero de elementos del vector, el cual no recorre entero.
int buscar(std::vector<int>& vec, int ini, int fin)
{
	int size = fin - ini;

	// Casos base:
	if (size == 0) // Caso base 0 elementos edvolvemos 0.
	{
		return 0;
	}
	if (size == 1) // Caso base 1 elemento devolvemos el elemento.
	{
		return vec[ini];
	}
	if ((vec[ini] % 2) != 0) // Caso base ini es el que buscamos
	{
		return vec[ini];
	}

	int mitad = (fin + ini) / 2; // Calculamos el indice de la mitad.

	if ((vec[mitad] % 2) != 0) { return vec[mitad]; } // Caso base mitad es el que buscamos.

	int numIzq = buscar(vec, ini, mitad);
	int numDer = buscar(vec, mitad, fin);

	if ((numIzq % 2) != 0)
	{
		return numIzq;
	}
	else
	{
		if ((numDer % 2) != 0)
		{
			return numDer;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	int n = 0;
	std::cin >> n;
	if (n == 0)
	{
		return false;
	}

	std::vector<int> datos(n);
	for (int& d : datos)
	{
		std::cin >> d;
	}

	int sol = buscar(datos, 0, datos.size());
	std::cout << sol << std::endl;

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