/*
Nombre completo: Nuria Bango Iglesias
Usuario del juez: VJ05
*/

/*
El coste depende de la altura del arbol y la cantidad de nodos.
En el caso de árboles equilibrados es O(n), donde n es el numero de nodos.
En el peor caso, donde el arbol es una cadena lineal, es O(n^2) debido a la busqueda en cada nivel del arbol. O(h) segun la altura.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

void caminoEnanos(const bintree<string>& arbol, string& lider, int& numSeguidores) {
	// caso base: vacio
	if (arbol.empty()) {
		lider = "Ninguno";
		numSeguidores = 0;
		return;
	}

	// nodo hoja
	if (arbol.left().empty() && arbol.right().empty()) {
		lider = arbol.root();
		numSeguidores = 1;
		return;
	}

	string liderIz, liderDr;
	int seguidoresIz, seguidoresDr;
	caminoEnanos(arbol.left(), liderIz, seguidoresIz);
	caminoEnanos(arbol.right(), liderDr, seguidoresDr);

	// si hay una rama que no tiene lider, sera lider el de la otra rama
	if (liderIz == "Niguno" && liderDr != "Ninguno")
		lider = liderDr;
	else if (liderIz != "Niguno" && liderDr == "Ninguno")
		lider = liderIz;
	// el que mas seguidores tiene se convierte en lider
	else if (seguidoresDr > seguidoresIz)
		lider = liderDr;
	else if (seguidoresIz > seguidoresDr)
		lider = liderIz;
	else // si mismo numero de seguidores, eligen al que tiene nombre menor en orden alfabético
		lider = (liderIz > liderDr) ? liderDr : liderIz;

	numSeguidores = seguidoresDr + seguidoresIz;

	if (arbol.root() == "Orcos") {
		numSeguidores /= 2;
		if (numSeguidores == 0)
			lider = "Ninguno";
	}
}

void resuelveCaso() {
	bintree<string> a = leerArbol(string("."));

	string lider = " ";
	int numSeguidores = 0;
	caminoEnanos(a, lider, numSeguidores);
	if (lider == "Ninguno")
		cout << lider << "\n";
	else
		cout << lider << " " << numSeguidores << "\n";
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("input1.txt");
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