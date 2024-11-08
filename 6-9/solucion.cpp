
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree.h"

using namespace std;
typedef struct {
	int gruposRescate;
	int caminoMaximo;
}tSolucion;


tSolucion rescate(const bintree <int>& arbol) {
	tSolucion sol;
	if (!arbol.empty()) {
		if (arbol.left().empty() && arbol.right().empty()) {
			if (arbol.root() == 0) {
				sol.gruposRescate = 0;
			}
			else {
				sol.gruposRescate = 1;
			}
			sol.caminoMaximo = arbol.root();
		}
		else {
			tSolucion solDer, solIzq;
			solIzq = rescate(arbol.left());
			solDer = rescate(arbol.right());
			if (solIzq.gruposRescate + solDer.gruposRescate > 0) {
				sol.gruposRescate = solIzq.gruposRescate + solDer.gruposRescate;
			}
			else if (arbol.root() > 0) {
				sol.gruposRescate = 1;
			}
			else {
				sol.gruposRescate = 0;
			}
			sol.caminoMaximo = max(solIzq.caminoMaximo, solDer.caminoMaximo) + arbol.root();
		}
	}
	else {
		sol.caminoMaximo = 0;
		sol.gruposRescate = 0;
	}
	return sol;
}


void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	tSolucion sol = rescate(arbol);
	cout << sol.gruposRescate << ' ' << sol.caminoMaximo << '\n';
}


int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
