// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"


// COMPLEJIDAD: O(n) siendo n el numero de elementos del arbol.
template <class T>
bool busqueda(const bintree<T>& tree)
{
	// Caso base esta vacio.
	if (tree.empty())
	{
		return true;
	}

	// Auxiliares. Suponemos que lo son de busqueda.
	bool esBusquedaIzq = true; // Auxiliar para guardar si el brazo izquierdo es de busqueda.
	bool esBusquedaDer = true; // Auxiliar para guardar si el brazo derecho es de busqueda.

	// Rama izquierda. Solo si no esta vacia.
	if (!tree.left().empty())
	{
		// Miramos si su hijo es de busqueda si cumple que el elemento de su hijo izquierdo es menor que el propio.
		if (tree.root() > tree.left().root())
		{
			esBusquedaIzq = busqueda(tree.left());
		}
		else // Sino no lo puede ser.
		{
			esBusquedaIzq = false;
		}
	}

	// Rama derecha. Solo si no esta vacia.
	if (!tree.right().empty())
	{
		// Miramos si su hijo es de busqueda si cumple que el elemento de su hijo derecho es mayor que el propio.
		if (tree.root() < tree.right().root())
		{
			esBusquedaDer = busqueda(tree.right());
		}
		else // Sino no lo puede ser.
		{
			esBusquedaDer = false;
		}
	}

	// Es de busqueda si ambos hijos son de busqueda.
	return esBusquedaIzq && esBusquedaDer;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso()
{
	bintree<int> tree;

	tree = leerArbol(-1);

	if (busqueda(tree))
	{
		std::cout << "SI" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}
}

int main()
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	int n = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
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