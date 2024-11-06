// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"


template <class T>
int nodos(bintree<T> const& tree)
{
	// Caso base esta vacio tiene 0 nodos.
	if (tree.empty())
	{
		return 0;
	}

	// Recursion.
	int ramaIzq = nodos(tree.left());
	int ramaDer = nodos(tree.right());

	return ramaIzq + ramaDer + 1; // El 1 es el propio nodo.
}

template <class T>
int hojas(bintree<T> const& tree)
{
	// Caso base esta vacio.
	if (tree.empty())
	{
		return 0;
	}

	// Si su hijo izquierdo esta vacion y si hijo derecho tambien entonces es hoja.
	if (tree.left().empty() && tree.right().empty())
	{
		return 1;
	}

	// Recursion.
	int ramaIzq = hojas(tree.left());
	int ramaDer = hojas(tree.right());

	return ramaIzq + ramaDer;
}

template <class T>
int altura(bintree<T> const& tree)
{


	return 66;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	int n;
	bintree<char> tree;
	tree = leerArbol('.');
	std::cout << nodos(tree) << " " << hojas(tree) << " " << altura(tree) << std::endl;
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
};