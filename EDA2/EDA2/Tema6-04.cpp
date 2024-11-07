// Andres Garcia Navarro
// EDA-GDV27
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"
using namespace std;

bool esPrimo(int num, int divisor) {
	if (num <= 1) return false;
	if (divisor * divisor > num) return true;
	if (num % divisor == 0)return false;
	return esPrimo(num, divisor + 1);
}

// complejidad O(n) para n=elementos del arbol
template <class T>
T mult7(bintree<T> const& tree, int& prof) {
	if (tree.empty())return 0;
	if (tree.right().empty() && tree.left().empty())
	{
		return  (tree.root() > 7 && tree.root() % 7 == 0) ? tree.root() : 0;
	}
	if (esPrimo(tree.root(), 2)) return 0;

	T m7 = (tree.root() > 7 && tree.root() % 7 == 0) ? tree.root() : 0;
	int rightProf = prof + 1, leftProf = prof + 1;

	if (!tree.left().empty()) {
		T leftMult7 = mult7(tree.left(), leftProf);
		if (leftMult7 != 0 && (m7 == 0 || leftProf < prof)) {
			prof = leftProf;
			m7 = leftMult7;
		}
	}
	if (!tree.right().empty()) {
		T rightMul7 = mult7(tree.right(), rightProf);
		if (rightMul7 != 0 && (m7 == 0 || rightProf < prof)) {
			prof = rightProf;
			m7 = rightMul7;
		}
	}
	return  m7;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	char tipo;

	bintree<int> tree = leerArbol(int(-1));
	int profundidad = 0;
	int multiplo = mult7(tree, profundidad);
	if (multiplo != 0)
		cout << multiplo << " " << profundidad << endl;
	else
		cout << "NO HAY" << endl;

	return true;
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
