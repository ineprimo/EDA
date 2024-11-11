// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <fstream>
#include "bintree_eda.h"


// COMPLEJIDAD: O(n) siendo n el numero de elementos del arbol.
// Sease pair.first el diametro y pair.second la altura.
std::pair<int, int> diametro(const bintree<char> tree)
{
	// Caso base esta vacio.
	if (tree.empty())
	{
		return { 0,0 };
	}

	std::pair<int, int> izq = diametro(tree.left());
	std::pair<int, int> der = diametro(tree.right());

	int maxAltura = 0;
	int maxDiametro = 0;

	// Para quedarnos con la altura mayor.
	if (izq.second > der.second)
	{
		maxAltura = izq.second + 1; // +1 porque estamos en la siguiente altura.
	}
	else
	{
		maxAltura = der.second + 1;
	}

	// Para quedarnos con el mayor diametro.
	if (izq.first > der.first)
	{
		maxDiametro = izq.first + 1;
	}
	else
	{
		maxDiametro = der.first + 1;
	}

	/*return
	{
		std::max(izq.first, der.first) + 1,
		std::max(std::max(izq.second, der.second),
			izq.first + der.first + 1)
	};*/

	return{ maxDiametro, maxAltura };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioon, y escribiendo la respuesta
void resuelveCaso()
{
	bintree<char> tree;

	tree = leerArbol('.'); // '.' es la representacion de arbol vacio.

	std::cout << diametro(tree).first << std::endl;
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