// Andres Garcia Navarro
// EDA-GDV27

/*
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// el coste de esta funcion es logaritmico O(n*log(n)) ya que el problema se divide en mitades y cada una de las mitades realiza un trabajo lineal.
bool parcialmenteOrdenado(const vector<int>& v, int ini, int fin, int& min, int& max) {
	// casos base
	if (fin == ini)
		return true;
	if (fin - ini == 1) {
		if (v[fin] >= v[ini])
		{
			max = v[fin]; min = v[ini];
			return true;
		}

		max = v[ini]; min = v[fin];
		return false;
	}

	// reserva el espacio de la memoria
	int mayorI, menorI, mayorD, menorD;

	// comprueba los lados derecho e izquierdo
	int mid = ini + ((fin - ini) / 2);
	bool ordenadoIzq = parcialmenteOrdenado(v, ini, mid, mayorI, menorI);
	bool ordenadoDer = parcialmenteOrdenado(v, mid +1, fin, mayorD, menorD);

	// Asigna mayor y menor
	max = mayorD;
	min = menorI;

	return ordenadoIzq && ordenadoDer && (mayorD >= mayorI && menorI <= menorD);
}

bool parcialmenteOrdenado(const vector<int>& v) {
	int min, max;
	return parcialmenteOrdenado(v, 0, v.size()-1, min, max);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int e;
	cin >> e;
	if (e == 0) return false;
	vector<int> sec;
	while (e != 0) {
		sec.push_back(e);
		cin >> e;
	}
	cout << (parcialmenteOrdenado(sec) ? "SI" : "NO") << endl;
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
*/