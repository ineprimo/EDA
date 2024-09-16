// Pablo Iglesias Rodrigo
// EDA-GDV35


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

// función que resuelve el problema
std::vector<int> resolver(std::vector<int> datos)
{
	for (int i = 0; i < datos.size(); i++)
	{
		datos[i] *= 2;
		std::cout << datos[i] << " ";
	}
	return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	// leer los datos de la entrada
	int size = 0;
	std::cin >> size;

	if (!std::cin)
	{
		return false;
	}

	std::vector<int> datos;
	int dato = 0;

	for (int i = 0; i < size; i++)
	{
		std::cin >> dato;
		datos.push_back(dato);
	}

	std::vector<int> sol = resolver(datos);

	// escribir sol

	std::cout << std::endl;

	return true;
}

int main() 
{
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