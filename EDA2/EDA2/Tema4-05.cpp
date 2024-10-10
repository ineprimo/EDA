// Andres Garcia Navarro
// EDA-GDV27


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "Set.h"
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int d;
	std::cin >> d;
	if (!std::cin)
		return false;
	Set<int> set1(d);
	for (int i = 0; i < d; i++) {
		int n = 0;
		cin >> n;
		set1.add(n);
	}

	std::cin >> d;
	Set<int> set2(d);
	for (int i = 0; i < d; i++) {
		int n = 0;
		cin >> n;
		set2.add(n);
	}
	cout << (set1 || set2) << endl << (set1 && set2) << endl;
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}