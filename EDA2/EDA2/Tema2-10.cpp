// Andres Garcia Navarro
// EDA-GDV27


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// El coste de esta funcion es logaritmica O(log n) se recorre el vector por mitades y nunca completas
// función que resuelve el problema
int buscar(const vector<int>& sec, int ini, int fin) {
	// division por mitades
	int mitad = (ini + fin) / 2;
	// Num elementos
	int dif = fin - ini;

	// ------ casos base ------
	if (dif == 0) {
		return 0;
	}
	if (dif == 1) {
		return sec[ini]; //% 2 != 0 ? sec[ini] : 0;
	}
	// si el primer numero es impar
	if (sec[ini] % 2 != 0)
		return sec[ini];
	// si el numero de la mitad es impar
	if (sec[mitad] % 2 != 0)
		return sec[mitad];



	// Calcula el numero que deberia estar en la mitad
	int numMedio = ((mitad - ini) * 2) + sec[ini];
	// Elimina los numeros impares del numero que deberia estar en esa posicion
	numMedio = numMedio % 2 == 0 ?
		numMedio :
		numMedio - 1;

	// ------ Busqueda binaria ------
	// si la primera mitad esta ordenada buscamos la segunda mitad, si no la primera mitad
	return sec[mitad] == numMedio ?
		buscar(sec, mitad, fin) :
		buscar(sec, ini, mitad);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	if (n == 0) return false;
	vector<int> sec(n);
	for (int& e : sec) cin >> e;
	cout << buscar(sec, 0, n) << endl;
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
	//system("PAUSE");
#endif

	return 0;
}