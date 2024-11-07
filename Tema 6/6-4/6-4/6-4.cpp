// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"


// COMPLEJIDAD: .
template <class T>
std::pair<int, int> barrera(const bintree<T>& tree)
{
	// Caso base esta vacio.
	if (tree.empty())
		return { -1, 0 };


	std::pair<int, int> sol = { 0, 0 };











	return { 66, 66 };
}

bool esPrimo(int num)
{
	if (num < 2)
		return false;

	for (int i = 2; i < (num / 2); i++)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	std::pair<int, int> brr = { 0,0 };
	bintree<int> tree;

	tree = leerArbol(-1);

	brr = barrera(tree);

	if (brr.first != -1)
	{
		std::cout << brr.first << " " << brr.second << std::endl;
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