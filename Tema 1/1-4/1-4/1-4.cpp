// Pablo Iglesias Rodrigo
// EDA-GDV35


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int>& datos)
{
	int nexPos = 0;
	for (int i = 0; i < datos.size(); i++)
	{
		if ((datos[i] % 2) == 0) // Reordenamos el vector solo con los datos pares.
		{
			datos[nexPos] = datos[i];
			nexPos++;
		}
	}
	return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	int size = 0;
	std::cin >> size;

	std::vector<int> datos;
	int dato = 0;

	for (int i = 0; i < size; i++)
	{
		std::cin >> dato;
		datos.push_back(dato);
	}

	bool sol = resolver(datos);

	// escribir sol

	for (int i = 0; i < datos.size(); i++)
	{
		std::cout << datos[i] << " ";
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
}