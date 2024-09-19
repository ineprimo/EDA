// Andres Garcia Navarro
// EDA-GDV27

/*
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(std::vector<int>& datos) {
	int j = 0;

	for (size_t i = 0; i < datos.size(); i++)
	{
		if (datos[i] % 2 == 0) {
			datos[j] = datos[i];
			j++;
		}
	}

	if (j == 0)
		datos.clear();
	else
		datos.resize(j);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// inicializa las variables
	int size = 0, elemento = 0;
	std::vector<int> datos;

	// leer los datos de la entrada
	std::cin >> size;
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> elemento;
		datos.push_back(elemento);
	}

	resolver(datos);

	// escribir sol
	for (int e : datos) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
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