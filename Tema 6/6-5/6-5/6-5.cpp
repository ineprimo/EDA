// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"



// COMPLEJIDAD: O(n) siendo n el numero de elementos del arbol.
template <class T>
bool busquedaAux(const bintree<T>& tree, int min, int max)
{
	// Caso base esta vacio.
	if (tree.empty())
	{
		return true;
	}

	if (tree.root() <= min || tree.root() >= max)
	{
		return false;
	}

	return busquedaAux(tree.left(), min, tree.root()) && busquedaAux(tree.right(), tree.root(), max);



	/*// Auxiliares. Suponemos que lo son de busqueda.
	bool esBusquedaIzq = true; // Auxiliar para guardar si el brazo izquierdo es de busqueda.
	bool esBusquedaDer = true; // Auxiliar para guardar si el brazo derecho es de busqueda.

	// Rama izquierda. Solo si no esta vacia.
	if (!tree.left().empty())
	{
		// Miramos si su hijo es de busqueda si cumple que es menor que sus elemento anteriores y que el elemento de su hijo izquierdo es menor que el propio.
		if (tree.root() <= min && tree.root() > tree.left().root())
		{
			esBusquedaIzq = busquedaAux(tree.left(), min, max);
		}
		else // Sino no lo puede ser.
		{
			esBusquedaIzq = false;
			std::cout << "Mentira: " << tree.root() << " <= " << min << " && " << tree.root() << " > " << tree.left().root() << std::endl;
		}
	}

	// Rama derecha. Solo si no esta vacia.
	if (!tree.right().empty())
	{
		// Miramos si su hijo es de busqueda si cumple que es mayor que sus elemento anteriores y que el elemento de su hijo derecho es mayor que el propio.
		if (tree.root() >= max && tree.root() < tree.right().root())
		{
			esBusquedaDer = busquedaAux(tree.right(), min, max);
		}
		else // Sino no lo puede ser.
		{
			//std::cout << "Mentira: " << tree.root() << " >= " << max << " && " << tree.root() << " < " << tree.right().root() << std::endl;
			esBusquedaDer = false;
		}
	}

	// Es de busqueda si ambos hijos son de busqueda.
	return esBusquedaIzq && esBusquedaDer;*/
}

// COMPLEJIDAD: O(1) solo se llama la primera vez.
template <class T>
bool busqueda(const bintree<T>& tree, int min, int max)
{
	// Caso base esta vacio.
	if (tree.empty())
	{
		return true;
	}

	// Normalmente en los ejercios pone suponiendo enteros entre 1 y 5000. Pues ahi estan.
	min = 1;
	max = 5000;

	return busquedaAux(tree, min, max);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso()
{
	bintree<int> tree;

	tree = leerArbol(-1);

	if (busqueda(tree, 0, 0))
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