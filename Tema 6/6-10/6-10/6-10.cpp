// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <fstream>
#include "bintree_eda.h"


// COMPLEJIDAD: O(n) siendo n el numero de elementos del arbol.
void navegables(const bintree<std::string> tree)
{



}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	bintree<std::string> tree;

	tree = leerArbol((std::string)"."); // -1 es la repr. de arbol vacio

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