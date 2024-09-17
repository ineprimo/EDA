// Andres Garcia Navarro
// EDA - GDV27
/*

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::pair<int, int> resolver(std::vector<int> vect) {

	std::pair<int, int> picoValle = { 0,0 };

	for (size_t i = 1; i < vect.size() - 1; i++)
	{
		if (vect[i - 1]<vect[i] && vect[i] >vect[i + 1])
			picoValle.first += 1;
		else if (vect[i - 1] > vect[i] && vect[i] < vect[i + 1])
			picoValle.second += 1;
	}

	return picoValle;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	//variabes locales
	int size, dato;
	std::vector<int> vect;

	// leer los datos de la entrada
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cin >> dato;
		vect.push_back(dato);
	}

	std::pair<int, int> sol = resolver(vect);
	// escribir sol
	std::cout << sol.first << " " << sol.second << std::endl;

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