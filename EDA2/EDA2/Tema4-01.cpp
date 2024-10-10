// Andres Garcia Navarro
// EDA-GDV27


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "Set.h"
using namespace std;

// función que resuelve el problema, complegidad O(n*log(n))
bool esFeliz(Set<int>& secFel, int dato) {
	if (dato == 1) {
		return true;
	}


	int suma = 0;
	int num = 0;

	// hace la suma del cuadrado de sus digitos
	while (dato > 0) {
		num = (dato % 10);
		suma += num * num;
		dato /= 10;
	}

	cout << suma << " ";

	// si se contiene suma  se retorna false
	if (secFel.contains(suma)) {
		//cout << suma << " ";
		return false;
	}
	else
	{
		// si no se añade suma y se hacen los calculos para el siguiente
		secFel.add(suma);
		return esFeliz(secFel, suma);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int d;
	std::cin >> d;
	if (!std::cin)
		return false;
	cout << d << " ";
	Set<int> secFel(1);
	secFel.add(d);
	cout << (esFeliz(secFel, d) ? "1" : "0") << endl;
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