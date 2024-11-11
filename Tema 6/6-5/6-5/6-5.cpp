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

	// No es de busqueda si el elemento es menor que el minimo anterior o mayor que el maximo anterior.
	if (tree.root() <= min || tree.root() >= max)
	{
		return false;
	}

	// Calcular sus arboles hijos izquierdo y derecho.
	return busquedaAux(tree.left(), min, tree.root()) && busquedaAux(tree.right(), tree.root(), max);
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

	// Normalmente en los ejercios pone suponiendo enteros entre 0 y 5000. Pues ahi estan.
	min = 0;
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