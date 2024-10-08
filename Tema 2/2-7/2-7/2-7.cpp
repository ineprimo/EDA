// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// COMPLEJIDAD: logaritmica O(log n) siendo n el numero de elementos del vector.
int minimo(const std::vector<int>& vec, int ini, int fin)
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

	int mitad = (fin + ini) / 2; // Calculamos el indice de la mitad.

	if (vec[mitad] > vec[mitad - 1]) // Comprobamos en que lado esta el menor para hacer la busqueda a ese lado.
	{
		return minimo(vec, ini, mitad); // Mitad izquierda.
	}
	else
	{
		return minimo(vec, mitad, fin); // Mitad derecha.
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	if (!std::cin)
	{
		return false;
	}

	std::vector<int> sec(n);
	for (int& e : sec)
	{
		std::cin >> e;
	}

	std::cout << minimo(sec, 0, n) << std::endl;
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