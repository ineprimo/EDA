//// Andres Garcia Navarro
//// EDA-GDV27
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include "bintree_eda.h"
//using namespace std;
//
//// complejidad O(n) recorre el arbol una unica vez
//template <class T>
//void frontera(bintree<T> const& tree, vector<T>& front) {
//	if (tree.empty())return;
//	if (tree.left().empty() && tree.right().empty()) {
//		front.push_back(tree.root());
//		return;
//	}
//	frontera(tree.left(), front);
//	frontera(tree.right(), front);
//}
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//void resuelveCaso() {
//	// leer los datos de la entrada
//	int n;
//	bintree<int> tree;
//	tree = leerArbol(-1);
//
//	vector<int> sol;
//	frontera(tree, sol);
//	for (auto e : sol)
//		cout << e << " ";
//	cout << endl;
//}
//
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
