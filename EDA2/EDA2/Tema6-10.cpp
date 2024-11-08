#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// complejidad lineal O(n) para n = numero de elementos en el arbol
template <class T>
// pair<Lider,Miembros>
pair<string, int> enanos(bintree<T> const& tree) {
	if (tree.empty()) return { "", 0 };
	if (tree.left().empty() && tree.right().empty()) return { tree.root(), 1 };

	pair<string, int> enanosL, enanosR, sol;

	enanosL = enanos(tree.left());
	enanosR = enanos(tree.right());

	sol.second = enanosL.second + enanosR.second;
	if (enanosL.second == enanosR.second) {
		sol.first = enanosR.first < enanosL.first ?
			enanosR.first :
			enanosL.first;
	}
	else {
		sol.first = enanosL.second < enanosR.second ?
			enanosR.first :
			enanosL.first;
	}

	if (tree.root() == "Orcos")
		sol.second /= 2;
	if (sol.second <= 0)
		sol = { "", 0 };

	return sol;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<string> arb;
	arb = leerArbol<string>("."); // . es la repr. de arbol vacio
	pair<string, int> sol = enanos(arb);
	if (sol.second == 0) cout << "Ninguno" << endl;
	else cout << sol.first << " " << sol.second << endl;
}

int main() {
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

