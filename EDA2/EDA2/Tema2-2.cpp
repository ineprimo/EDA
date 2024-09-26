// Andres Garcia Navarro
// EDA-GDV27

/*
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función devuelve complementario
int complementario(int datos, int complement) {
	if (datos < 10)
		return (9 - datos);

	complement = 9- (datos % 10);

	return complement + (complementario(datos / 10, complement)*10);

}

// función devuelve complementario inverso
int complementarioInverso(int datos, int complement) {
	if (datos < 10)
		return (complement * 10) + (9 - datos);
	
	complement *= 10;
	complement += 9 - (datos % 10);

	return complementarioInverso(datos / 10, complement);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int datos;
	cin >> datos;

	cout << complementario(datos, 0) << " " << complementarioInverso(datos, 0) << endl;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}*/