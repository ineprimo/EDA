// Andres Garcia Navarro
// EDA-GDV27

/*
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
bool resolver(std::vector<int> v, int siz) {

	bool derecha = true, izquierda = true;
	int i = 1;

	while (i < siz && (derecha || izquierda)) {
		if (v[i] <= v[i - 1] )
			derecha = false;
		if (v[siz - i] >= v[siz - (i + 1)])
			izquierda = false;
		i++;
	}

	return derecha || izquierda;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int d, e;
	std::vector<int> v;
	std::cin >> d;

	if (d == 0)
		return false;

	for (int i = 0; i < d; i++) {

		std::cin >> e;

		v.push_back(e);
	}


	if (resolver(v, d))
		std::cout << "DALTON" << std::endl;
	else
		std::cout << "DESCONOCIDOS" << std::endl;



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