//// Andres Garcia Navarro
//// EDA-GDV27
//#include <iostream>
//#include <fstream>
//#include "bintree_eda.h"
//using namespace std;
//
//// complejidad lineal O(n) para n = numero de elementos en el arbol
//int calculoSingulares(bintree<int> const& tree, int& singulares, int padre) {
//	if (tree.empty()) return 0;
//
//	int right = calculoSingulares(tree.right(), singulares, tree.root()+ padre);
//	int left = calculoSingulares(tree.left(), singulares, tree.root()+ padre);
//
//	if (right + left == padre ) singulares++;
//
//	return right + left + tree.root();
//}
//
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//void resuelveCaso() {
//	bintree<int> arb;
//	arb = leerArbol<int>(-1); // -1 es la repr. de arbol vacio
//	int singulares = 0;
//	calculoSingulares(arb, singulares, 0);
//	cout << singulares << endl;
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
