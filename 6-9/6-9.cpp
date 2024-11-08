// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <future>

#include "bintree_eda.h"
using namespace std;
using Par = std::pair<int, int>;
// first es n equipos y second es n excursionistas

// O(n) siendo n el numero de nodos del arbol, dos llamadas recursivas por mitad
template <class T>
Par rescatar(const bintree<T>& tree)
{
	if (tree.empty()) return {0, 0};

	const Par izq = rescatar(tree.left());
	const Par der = rescatar(tree.right());

	if (tree.root() != 0 && izq.first == 0 && der.first == 0)
		return {1, tree.root()};

	return
	{
		izq.first + der.first,
		max(izq.second, der.second) + tree.root()
	};
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	bintree<int> tree;
	tree = leerArbol(-1);
	Par sol = rescatar(tree);
	cout << sol.first << " " << sol.second << endl;
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
