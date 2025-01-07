#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


// función que resuelve el problema
int resolver(bintree<int> tree, int& singular, int ant) {

	if (tree.empty()) return 0;
	else {
		int sumIzq = resolver(tree.left(), singular, ant + tree.root());
		int sumDer = resolver(tree.right(), singular, ant + tree.root());
		if (ant == (sumIzq + sumDer)) singular++;
		return sumIzq + sumDer + tree.root();
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	bintree<int> tree;
	tree = leerArbol(-1); // -1 es vacío

	int singulares = 0;
	//Sumatorios de los nodos anteriores
	int sumaAnt = 0;

	resolver(tree, singulares, sumaAnt);

	// escribir sol
	cout << singulares << endl;
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
	for (int i = 0; i < numCasos; ++i) resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}