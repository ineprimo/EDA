//// Andres Garcia Navarro
//// EDA-GDV27
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <algorithm>
//#include "bintree_eda.h"
//using namespace std;
//
//// complejidad O(n) para n=elementos del arbol
//template <class T>
//T minimo(bintree<T> const& tree) {
//	if (tree.right().empty() && tree.left().empty()) return tree.root();
//	T minL, minR, min = tree.root();
//	if (!tree.left().empty())
//	{
//		minL = minimo(tree.left());
//		if (minL < min) min = minL;
//	}
//	if (!tree.right().empty())
//	{
//		minR = minimo(tree.right());
//		if (minR < min) min = minR;
//
//	}
//	return min;
//}
//
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	// leer los datos de la entrada
//	char tipo;
//	cin >> tipo;
//	if (!cin) return false;
//	if (tipo == 'N') {
//		bintree<int> tree = leerArbol(int(-1));
//		cout << minimo(tree) << endl;
//	}
//	else if (tipo == 'P') {
//		bintree<string> tree = leerArbol(string("#"));
//		cout << minimo(tree) << endl;
//	}
//	return true;
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
//	while (resuelveCaso());
//
//	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	//system("PAUSE");
//#endif
//
//	return 0;
//}
