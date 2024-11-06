
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

template <class T>
int nodos(bintree<T> const& tree) {
	if (tree.empty()) return 0;
	else return nodos(tree.left()) + nodos(tree.right()) + 1;
}

template <class T>
void nodosAcu(bintree<T> const& tree, int& acu) {
	if (tree.empty()) return;
	else {
		nodosAcu(tree.left(), acu);
		nodosAcu(tree.right(), acu);
		++acu;
	}
}


template <class T>
int esHoja(bintree<T> const& tree) {
	if (tree.empty()) return false;
	if (tree.left().empty() && tree.right().empty()) return true;
	else return false;
}

template <class T>
int hojas(bintree<T> const& tree) {
	if (tree.empty()) return 0;
	if (esHoja(tree)) return 1;
	else return hojas(tree.left()) + hojas(tree.right());
}

template <class T>
void hojasAcu(bintree<T> const& tree, int& acu) {
	if (tree.empty()) return;
	if (esHoja(tree)) ++acu;
	else {
		hojasAcu(tree.left(), acu);
		hojasAcu(tree.right(), acu);
	}
}


template <class T>
int altura(bintree<T> const& tree) {
	if (tree.empty()) return 0;
	else return max(altura(tree.left()), altura(tree.right())) + 1;
}

template <class T>
void alturaAcu(bintree<T> const& tree, int prof, int& alturaMax) {
	if (tree.empty()) {
		if (prof > alturaMax) alturaMax = prof;
	}
	else {
		alturaAcu(tree.left(), prof + 1, alturaMax);
		alturaAcu(tree.right(), prof + 1, alturaMax);
	}
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	bintree<char> tree;
	tree = leerArbol('.');
	cout << nodos(tree) << " " << hojas(tree) << " " << altura(tree) << endl;
	/* Código para invocar a las funciones alternativas con acumuladores
	int numNodos = 0;
	nodosAcu(tree,numNodos);
	int numHojas = 0;
	hojasAcu(tree,numHojas);
	int altura = 0;
	alturaAcu(tree,0,altura);
	cout << numNodos << " " << numHojas << " " << altura << endl;*/
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