// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

#include "Set.h"


// COMPLEJIDAD: O(n * n), el remove es O(n).
Set<int> resuelve(int k, std::vector<int> vec)
{
	Set<int> aux(vec.size());
	int elem = 0;

	// Metemos los elementos del vector al set.
	for (int i = 0; i < vec.size(); i++)
	{
		aux.add(vec[i]);
	}

	// Quitamos los elementos maximos dejando los minimos que queremos (k).
	int size = aux.getNelems();
	for (int i = 0; i < (size - k); i++)
	{
		aux.removeMax();
	}

	return aux;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso()
{
	int k = 0;
	int elem = 0;
	std::vector<int> vec;

	cin >> k;
	if (k == 0) { return false; }

	cin >> elem;
	while (elem != -1)
	{
		vec.push_back(elem);
		cin >> elem;
	}

	std::cout << resuelve(k, vec) << std::endl;

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