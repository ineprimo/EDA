//// andres garcia navarro
//// eda-gdv27
//#include <iostream>
//#include <fstream>
//#include "bintree_eda.h"
//using namespace std;
//
//// algoritmo complejidad lineal O(n) donde n es el numero de elementos que contiene el arbol
//template <class T>
//// pair <equipos, excursionistas>
//pair<int, int> rescate(bintree<T> const& tree) {
//	if (tree.empty()) {
//		return{ 0,0 };
//	}
//	if (tree.left().empty() && tree.right().empty()) {
//		if (tree.root() > 0)
//			return{ 1, tree.root() };
//		return{ 0,0 };
//	}
//	pair<int, int> rescateL, rescateR, sol = { 0, tree.root() };
//
//	rescateL = rescate(tree.left());
//	rescateR = rescate(tree.right());
//
//	if (tree.root() > 0 && !(rescateL.first > 0 || rescateR.first > 0)) {
//		sol.first = 1;
//		return sol;
//	}
//
//	sol.first = rescateL.first + rescateR.first;
//	sol.second += rescateL.second < rescateR.second ?
//		rescateR.second : rescateL.second;
//
//	return sol;
//}
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//void resuelveCaso() {
//	bintree<int> arb;
//	arb = leerArbol(-1); // -1 es la repr. de arbol vacio
//	pair<int, int> sol = rescate(arb);
//	cout << sol.first << " " << sol.second << endl;
//}
//
//int main() {
//	// Para la entrada por fichero.
//	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif
//
//	int numCasos;
//	std::cin >> numCasos;
//	for (int i = 0; i < numCasos; ++i)
//		resuelveCaso();
//
//	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	//system("PAUSE");
//#endif
//
//	return 0;
//}
//
