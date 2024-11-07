// andres garcia navarro
// eda-gdv27
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"
using namespace std;

// complejidad o(n) para n=elementos del arbol
template <class T>
bool esArbol(bintree<T> const& tree) {
	if (tree.empty())return true;
	if (tree.left().empty() && tree.right().empty()) return true;

	bool arbolL = true, arbolR = true;
	if (!tree.left().empty())
		arbolL = tree.root() > tree.left().root() && esArbol(tree.left());
	if (!tree.right().empty())
		arbolR = tree.root() < tree.right().root() && esArbol(tree.right());

	return arbolL && arbolR;
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelvecaso() {
	// leer los datos de la entrada

	bintree<int> tree = leerArbol(int(-1));
	if (esArbol(tree))
		cout << "SI" << endl;
	else
		cout << "NO" << endl;

	return true;
}

int main() {
	// para la entrada por fichero.
	// comentar para acepta el reto
#ifndef domjudge
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelvecaso();

	// para restablecer entrada. comentar para acepta el reto
#ifndef domjudge // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("pause");
#endif

	return 0;
}
