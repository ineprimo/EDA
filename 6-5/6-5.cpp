// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// O(n) donde n es el numero de nodos del arbol
bool esABB(const bintree<int>& tree, int& min, int& max)
{
	if (tree.empty()) { min = 0; max = 0; return true; }

	int minIz, maxIz, minDr, maxDr;
	bool izq = esABB(tree.left(), minIz, maxIz);
	bool der = esABB(tree.right(), minDr, maxDr);
	bool ordenado = 
		(tree.left().empty() || maxIz < tree.root())
	&&  (tree.right().empty() || tree.root() < minDr);

	min = tree.left().empty() ? tree.root() : minIz;
	max = tree.right().empty() ? tree.root() : maxDr;

	return izq && der && ordenado;
}

void resuelveCaso()
{
	// leer los datos de la entrada
	bintree<int> tree;
	int min = 0, max = 0;
	tree = leerArbol(-1);
	cout << (esABB(tree, min, max) ? "SI\n" : "NO\n");
}


//#define DOMJUDGE
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
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
