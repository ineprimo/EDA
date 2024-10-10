// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "Hora.h"
#include "Pelicula.h"

// función que resuelve el problema
//TipoSolucion resolver(TipoDatos datos) {
//    
//    
//}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	int n = 0;
	std::cin >> n;
	if (n == 0)
		return false;

	try
	{
		Hora hora, duracion;
		std::string titulo;
		std::vector<Pelicula> peliculas(n);

		for (int i = 0; i < n; i++)
		{
			std::cin >> hora >> duracion;
			std::getline(std::cin, titulo);
			peliculas[i] = Pelicula(hora, duracion, titulo);
		}

		sort(peliculas.begin(), peliculas.end());
		for (Pelicula& p : peliculas)
			std::cout << p.getFin() << " " << p.getTitulo() << "\n";

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
