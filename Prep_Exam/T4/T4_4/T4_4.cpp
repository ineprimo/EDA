#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "Hora.h"
#include "Pelicula.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	//Recoge el número de pelis posibles
	int n = 0;
	std::cin >> n;
	if (n == 0)	return false;

	try
	{
		Hora hora, duracion;
		std::string titulo;
		std::vector<Pelicula> peliculas(n);

		//Las leemos
		for (int i = 0; i < n; i++)
		{
			std::cin >> hora >> duracion;
			std::getline(std::cin, titulo);
			peliculas[i] = Pelicula(hora, duracion, titulo);
		}

		//Las ordenamos
		sort(peliculas.begin(), peliculas.end());
		for (int i = 0; i <= peliculas.size(); i++) 
		{
			std::cout << peliculas[i].getFin() << " " << peliculas[i].getTitulo() << std::endl;
		}

		//Fin de caso
		std::cout << "---\n";
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "ERROR" << std::endl;
	}

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


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}