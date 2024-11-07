// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
#include "bintree_eda.h"


template <class T>
void fronteraAcu(bintree<T> const& tree, std::vector<T>& acu)
{
	// Caso base esta vacio.
	if (tree.empty())
	{
		return;
	}

	// Cuando el arbol dado es hoja nos guardamos la raiz en acu.
	if (tree.left().empty() && tree.right().empty())
	{
		acu.push_back(tree.root());
	}
	else
	{
		fronteraAcu(tree.left(), acu);
		fronteraAcu(tree.right(), acu);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	int n = 0;
	bintree<int> tree;
	tree = leerArbol(-1);
	std::vector<int> result;


	//-----Metodo externo con recursion con acumulador:
	fronteraAcu(tree, result);

	for (int e : result)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
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