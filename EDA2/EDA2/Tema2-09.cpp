// Andres Garcia Navarro
// EDA-GDV27


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// El coste de esta funcion es logaritmica O(log n) se recorre el vector por mitades y nunca completas
// función que resuelve el problema
bool buscar(const vector<int>& sec, int ini, int fin, int num) {
	// Casos base
	int dif = fin - ini;
	if (dif == 0) {
		return false;
	}
	if (dif == 1) {
		return sec[ini] == num;
	}

	// division por mitades
	int mitad = (ini + fin) / 2;

	// si la primera mitad esta ordenada
	if (sec[ini] <= sec[mitad]) {
		// si el numero esta entre el inicio y la mitad buscamos por la izquierda
		if (sec[ini] <= num && sec[mitad] > num)
		{
			return buscar(sec, ini, mitad, num);
		}
		// si no buscamos por la derecha
		else
			return buscar(sec, mitad, fin, num);
	}
	else {
		// si el numero es menor que el inicio pero mayor o igual que la mitad significa que esta en la mitad derecha
		if ( sec[ini] > num && sec [mitad] <= num) 
			return buscar(sec, mitad, fin, num);
		// si no esta en la izquierda
		else
			return buscar(sec, ini, mitad, num);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, num = 0;
	cin >> n;
	if (n == -1) return false;
	cin >> num;
	vector<int> sec(n);
	for (int& e : sec) cin >> e;
	cout << (buscar(sec, 0, n, num) ? "SI" : "NO") << endl;
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