// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;
using Par = std::pair<int, int>; // first son los tramos navegables y second el caudal total

// O(n) donde n es el numero de nodos del arbol
// 
Par tramosNavegables(const bintree<int>& arbol)
{
	if (arbol.empty()) return {0, 0}; // arbol vacio
	if (arbol.left().empty() && arbol.right().empty()) return {0, 1}; // arbol raiz

	Par izq = tramosNavegables(arbol.left());
	Par der = tramosNavegables(arbol.right());

	if (izq.second >= 3) izq.first++;
	if (der.second >= 3) der.first++;

	int caudalTramo = izq.second + der.second - arbol.root();
	if (caudalTramo < 0) caudalTramo = 0;

	return {izq.first + der.first, caudalTramo};
}

void resuelveCaso()
{
	bintree<int> arb;
	arb = leerArbol(-1);
	cout << tramosNavegables(arb).first << "\n";
}

int main()
{
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}
