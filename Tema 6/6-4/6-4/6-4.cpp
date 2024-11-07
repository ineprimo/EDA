// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"


bool esPrimo(int num)
{
	if (num < 2)
	{
		return false;
	}

	for (int i = 2; i * i <= num; ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

// COMPLEJIDAD: O(n + raiz m)? siendo n el numero de elementos del arbol y m el numero a saber si es primo.
template <class T>
void barrera(const bintree<T>& tree, int& num, int profAux, int& profAct, bool& encontrado)
{
	// Caso base esta vacio.
	if (tree.empty())
	{
		return;
	}

	// No se sigue si el numero es primo pues es ina barrera.
	if (esPrimo(tree.root()))
	{
		return;
	}

	// Se guarda el numero si es multiplo de 7, todavia no se ha encontrado otro multiplo y estamos mas cerca de la raiz (profAux < profAct).
	if ((tree.root() % 7) == 0 && (!encontrado || profAux < profAct))
	{
		encontrado = true; // Lo hemos encontrado.
		num = tree.root(); // lo guardamos.
		profAct = profAux;
	}

	// Se sigue mirando si no se ha encontrado y estamos mas cerca de la raiz.
	if (!encontrado || profAux + 1 < profAct)
	{
		barrera(tree.left(), num, profAux + 1, profAct, encontrado);
		barrera(tree.right(), num, profAux + 1, profAct, encontrado);
	}

	return;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	bintree<int> tree;
	int num = -1;
	int prof = 1;
	bool encontrado = false;

	tree = leerArbol(-1);

	barrera(tree, num, prof, prof, encontrado);

	if (encontrado)
	{
		std::cout << num << " " << prof << std::endl;
	}
	else
	{
		std::cout << "NO HAY" << std::endl;
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