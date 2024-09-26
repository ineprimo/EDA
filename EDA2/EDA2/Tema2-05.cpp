﻿// Andres Garcia Navarro
// EDA-GDV27

/*
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// El coste de la funcion es lineal O(n) ya que se recorren n elementos del vector
// función que resuelve el problema
pair<bool, int> caucasico(vector<int>& datos, int ini, int fin) {
	int diferencia = fin - ini;
	if (diferencia == 1) {
		if(datos[ini] %2 ==0)
			return { true, 1 };
		return { true, 0 };
	}

	int mitad = (ini + fin) / 2;

	pair <bool, int> caucasicoIzq = caucasico(datos, ini, mitad);
	pair <bool, int> caucasicoDer = caucasico(datos, mitad, fin);

	return{ caucasicoIzq.first && caucasicoDer.first && (abs(caucasicoIzq.second - caucasicoDer.second) <= 2), caucasicoIzq.second + caucasicoDer.second };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int size = 0;
	vector<int> datos;

	cin >> size;

	if (size == 0)
		return false;

	for (int i = 0; i < size; i++)
	{
		int e = 0;
		cin >> e;
		datos.push_back(e);
	}

	// escribir sol
	if (caucasico(datos, 0, size).first)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;

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