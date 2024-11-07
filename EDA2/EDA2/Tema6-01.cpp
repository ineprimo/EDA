//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include "bintree_eda.h"
//using namespace std;
//
//// O(n) lineal recorre el arbol entero 1 vez
//template <class T>
//int nodos(bintree<T> const& tree) {
//	if (tree.empty())
//		return 0;
//	return nodos(tree.left()) + nodos(tree.right()) + 1;
//}
//
//// O(n) lineal recorre el arbol entero 1 vez
//template <class T>
//int hojas(bintree<T> const& tree) {
//	if (tree.empty()) return 0;
//	if (tree.left().empty() && tree.right().empty()) return 1;
//	return hojas(tree.left()) + hojas(tree.right());
//}
//
//// O(n) lineal recorre el arbol entero 1 vez
//template <class T>
//int altura(bintree<T> const& tree) {
//	if (tree.empty()) return 0;
//	return max(altura(tree.left()), altura(tree.right()) )+ 1;
//}
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//void resuelveCaso() {
//	// leer los datos de la entrada
//	int n;
//	bintree<char> tree;
//	tree = leerArbol('.');
//	cout << nodos(tree) << " " << hojas(tree) << " " << altura(tree) << endl;
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
