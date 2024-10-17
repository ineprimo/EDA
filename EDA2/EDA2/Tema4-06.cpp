//// Andres Garcia Navarro
//// EDA-GDV27
//
//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <vector>
//
//#include "Set.h"
//using namespace std;
//
//
//// El algoritmo es cuadratico O(n^4) ya que utiliza el metodo removeMin() con complejidad lineal
//Set<int> resuelve(Set<int>& datos, int k) {
//	Set<int> aux(k);
//
//	for (int i = 0; i < k; i++)
//	{
//		aux.add(datos.getMin());
//		datos.removeMin();
//	}
//
//	return aux;
//}
//
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	int n = 0;
//	std::cin >> n;
//	if (n == 0)
//		return false;
//
//	Set<int> set;
//	int c = 0;
//	std::cin >> c;
//	while (c != (-1))
//	{
//		set.add(c);
//		std::cin >> c;
//	}
//
//	cout << resuelve(set, n) << endl;
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
//
//	while (resuelveCaso())
//		;
//
//
//	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	system("PAUSE");
//#endif
//
//	return 0;
//}