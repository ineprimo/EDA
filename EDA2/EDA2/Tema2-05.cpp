// Andres Garcia Navarro
// EDA-GDV27


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
/*
// El coste de la funcion es lineal O(n) ya que se recorren n elementos del vector
// función que resuelve el problema
pair<bool, int> caucasico(const vector<int>& datos, int ini, int fin) {
	int diferencia = fin - ini;
	// caso base
	if (diferencia == 1) {
		if(datos[ini] %2 ==0)
			return { true, 1 };
		return { true, 0 };
	}

	// division del vector en 2
	int mitad = (ini + fin) / 2;

	pair <bool, int> caucasicoIzq = caucasico(datos, ini, mitad);
	pair <bool, int> caucasicoDer = caucasico(datos, mitad, fin);

	return{ 
		// si el numero de elementos pares a ambos lados del vector se diferencia en 2 o menos y pasa lo mismo en las diferentes mitades de mitades, es caucasico
		caucasicoIzq.first && caucasicoDer.first && (abs(caucasicoIzq.second - caucasicoDer.second) <= 2), 
		caucasicoIzq.second + caucasicoDer.second 
	};
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
	cout << (caucasico(sec, 0, sec.size()).first ? "SI" : "NO") << endl;
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
}*/