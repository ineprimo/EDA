﻿// Andres Garcia Navarro
// EDA-GDV27


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
/*
// El coste de la funcion sera lineal O(n) se recorre una unica vez el array de forma lineal
// función que resuelve el problema
bool disperso(vector<int>& datos, int ini, int fin, int dispersion) {
	// Casos base:
	if (fin - ini == 1)
		return true;
	if(fin -ini ==2)
		return abs(datos[ini] - datos[ini+1]) >= dispersion;

	int mitad = ((fin + ini) / 2);

	bool dispersoIzquierda = disperso(datos, ini, mitad, dispersion);
	bool dispersoDerecha = disperso(datos, mitad, fin, dispersion);

	return (abs(datos[ini] - datos[fin-1]) >= dispersion) && dispersoIzquierda && dispersoDerecha;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tiradas = 0, dispersion = 0;
	vector<int> datos;

	cin >> tiradas >> dispersion;

	if (!std::cin)
		return false;
	for (int i = 0; i < tiradas; i++)
	{
		int e = 0;
		cin >> e;
		datos.push_back(e);
	}

	// escribir sol
	if (disperso(datos, 0, tiradas , dispersion))
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
}*/