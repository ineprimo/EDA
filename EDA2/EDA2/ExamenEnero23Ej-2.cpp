//// Andres Garcia Navarro
//// EDA-GDV27
//#include <iostream>
//#include <fstream>
//#include "bintree_eda.h"
//using namespace std;
//
//// complejidad lineal O(n) para n = numero de elementos en el arbol
//// devuelve el numero de dragones
//int mejorRuta(bintree<int> const& tree, int& rutMenosDragones) {
//	if (tree.empty()) return 0;
//	if (tree.right().empty() && tree.left().empty()) {
//		rutMenosDragones = tree.root();
//		return 0;
//	}
//
//	int rutDer = 0, rutIzq = 0;
//	int right = mejorRuta(tree.right(), rutDer);
//	int left = mejorRuta(tree.left(), rutIzq);
//	int dragones = 0;
//
//	if ((right < left || rutIzq == 0) && rutDer != 0) {
//		rutMenosDragones = rutDer;
//		dragones = right;
//	}
//	else {
//		rutMenosDragones = rutIzq;
//		dragones = left;
//	}
//	dragones += tree.root() == 1 ? 1 : 0;
//	return dragones;
//}
//
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//void resuelveCaso() {
//	bintree<int> arb;
//	arb = leerArbol<int>(-1); // -1 es la repr. de arbol vacio
//	int ruta = 0;
//	mejorRuta(arb, ruta);
//	cout << ruta << endl;
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
