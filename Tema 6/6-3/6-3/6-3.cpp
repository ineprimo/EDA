// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"


// COMPLEJIDAD: O(n) siendo n el numero de elementos del arbol.
template <class T>
T minimo(const bintree<T>& tree)
{
	T min = tree.root();

	// Caso es hoja se devuelve min.
	if (tree.left().empty() && tree.right().empty())
	{
		return min;
	}

	// Recorremos el lado izquierdo si tiene.
	if (!tree.left().empty())
	{
		T leftMin = minimo(tree.left());
		if (min > leftMin)
		{
			min = leftMin;
		}
	}

	// Recorremos el lado derecho si tiene.
	if (!tree.right().empty())
	{
		T rightMin = minimo(tree.right());
		if (min > rightMin)
		{
			min = rightMin;
		}
	}

	return min;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	// leer los datos de la entrada
	char tipo;
	std::cin >> tipo;
	if (!std::cin)
	{
		return false;
	}

	if (tipo == 'N')
	{
		bintree<int> tree;
		tree = leerArbol(-1);
		std::cout << minimo(tree) << std::endl;
	}
	else if (tipo == 'P')
	{
		bintree<std::string> tree;
		tree = leerArbol(std::string("#"));
		std::cout << minimo(tree) << std::endl;
	}
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