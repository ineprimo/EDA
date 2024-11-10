// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

// COMPLEJIDAD: O(n) siendo n el numero de elementos del arbol.
std::pair<int, int> atrapados(const bintree<int> tree) // Sease pair.first el numero de equipos de rescate y pair.second el mayor numero de excursionistas rescatados por un equipo.
{
	// Caso base esta vacio.
	if (tree.empty())
	{
		return { 0, 0 };
	}
	// Caso es base de la montanya, los hijos estan vacios.
	if (tree.left().empty() && tree.right().empty())
	{
		if (tree.root() == 0)
		{
			return{ 0, 0 };
		}
		else
		{
			return{ 1, tree.root() };
		}
	}

	std::pair<int, int> izq = atrapados(tree.left());
	std::pair<int, int> der = atrapados(tree.right());

	int sumaRescates = izq.first + der.first;
	int excursionistasTotal = 0;
	int excursionistasIzq = izq.second;
	int excursionistasDer = der.second;

	// Si hay excursionistas en el nodo y todavia no han sido rescatados.
	if (tree.root() != 0 && sumaRescates == 0)
	{
		sumaRescates += 1;
		excursionistasTotal = tree.root();
	}

	// Para quedarnos con el mayor numero de excursionistas que ha rescatado un equipo de rescate.
	if (excursionistasIzq > excursionistasDer)
	{
		excursionistasTotal = excursionistasIzq;
	}
	else
	{
		excursionistasTotal = excursionistasDer;
	}
	excursionistasTotal += tree.root(); // Por si se encuentran mas excursionistas.

	return{ sumaRescates, excursionistasTotal };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	bintree<int> tree;

	tree = leerArbol(-1); // -1 es la repr. de arbol vacio

	std::pair<int, int> sol = atrapados(tree);
	std::cout << sol.first << " " << sol.second << std::endl;
}

int main()
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
	{
		resuelveCaso();
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}