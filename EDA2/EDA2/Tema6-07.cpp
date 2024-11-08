// andres garcia navarro
// eda-gdv27
#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// algoritmo complejidad lineal O(n) donde n es el numero de elementos que contiene el arbol
template <class T>
void navegables(bintree<T> const& tree, int& tramosNavegables, int& caudal) {
	if (tree.empty()) {
		caudal = 0;
		tramosNavegables = 0;
		return;
	}
	if (tree.left().empty() && tree.right().empty()) {
		tramosNavegables = 0;
		caudal = 1;
		return;
	}
	int caudalL = 0, caudalR = 0,
		navegableL = 0, navegableR = 0;

	navegables(tree.left(), navegableL, caudalL);
	navegables(tree.right(), navegableR, caudalR);
	if (caudalL >= 3) navegableL++;
	if (caudalR >= 3) navegableR++;

	caudal = caudalL + caudalR - tree.root();
	if (caudal < 0) caudal = 0;
	tramosNavegables = navegableL + navegableR;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> arb;
	arb = leerArbol(-1); // -1 es la repr. de arbol vacio
	int tramosNavegables = 0, afluencia = 0;
	navegables(arb, tramosNavegables, afluencia);
	cout << tramosNavegables << endl;
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

