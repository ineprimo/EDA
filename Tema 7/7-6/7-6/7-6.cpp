// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using Pelicula = std::map <std::string, std::pair<int, int>>; // Sease map.first el nombre y map.second un par siendo pair.first las apariciones de la pelicula y pair.second la antiguedad.
using Actor = std::map <std::string, int>; // Sease map.first el nombre y map.second el tiempo en pantalla.
using RepartosPeliculas = std::map <std::string, Actor>; // Sease map.first el nombre de la pelicula y map.second sus actores.

// COMPLEJIDAD: O(n * m) siendo n el numero de peliculas y m el numero de actores.
void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas)
{
	std::string peli;
	std::string actor;
	int numActores = 0;
	int minutos = 0;

	for (int i = 0; i < numPeliculas; ++i)
	{
		std::cin >> peli;
		std::cin >> numActores;

		Actor actores;

		for (int j = 0; j < numActores; ++j)
		{
			std::cin >> actor;
			std::cin >> minutos;

			actores.insert({ actor, minutos }); // Guardamos el actor con sus minutos.
		}
		peliculas.insert({ peli, actores }); // Metemos a los actores en la pelicula.
	}
}

// COMPLEJIDAD: O((n * log n) + (m * log m) + (n * k * (log r + log a) + (a) + (a * log a))
// que se puede simplificar tendiendo a n = O(n * (log n) + n * (log r + log a) + a * log a)
// y creo que se puede simplificar mas? = O(n * (log n + log r + log a) + a * log a)?????
void procesarEmisiones(RepartosPeliculas const& repartos, std::vector<std::string> const& secEmisiones)
{
	int maxReps = 0; // Maximas veces que ha aparecido una pelicula.
	std::string filmName; // Nombre de dicha pelicula.
	int maxMin = 0; // Maximo tiempo que ha/han aparecido un actor/actores en pantalla.
	std::vector<std::string> actorsNames; // Vector con los dicho nombres.


	//------Saber cual es la pelicula que mas ha salido:

	Pelicula peliculas;

	// Cmplejidad O(n * log m) / O(n * log n) siendo n la cantidad de elementos de secEmisiones y m el numero de elementos de peliculas que en el caso peor es n.
	for (size_t i = 0; i < secEmisiones.size(); i++)
	{
		// Si ya esta actualizamos su numero de apariciones y cambiamos su antiguedad.
		if (peliculas.count(secEmisiones[i]))
		{
			peliculas[secEmisiones[i]].first++; // Numero de apariciones++.
			peliculas[secEmisiones[i]].second = i; // Actualizamos la antiguedad por el indice.
		}
		else
		{
			peliculas.insert({ secEmisiones[i], {1, i} }); // Se mete en nombre, que ha aparecido una vez y su antiguedad.
		}
	}

	// Complejidad: O(m * log m) siendo me el numero de elementos de peliculas. En el peor de los casos es n.
	auto peliIt = peliculas.begin(); // Iterador para recorrer el mapa de peliculas.
	filmName = (*peliIt).first; // Cojemos el primero para ir comparando.
	while (peliIt != peliculas.end())
	{
		std::pair<std::string, std::pair<int, int>> actPeli = (*peliIt);

		if (peliculas[filmName].first < actPeli.second.first || // Compara apariciones.
			(peliculas[filmName].first == actPeli.second.first && // Si tiene el mismo numero de apariciones,
				peliculas[filmName].second < actPeli.second.second)) // comparamos antiguedades. 
		{
			filmName = actPeli.first;
		}
		peliIt++;
	}
	maxReps = peliculas[filmName].first;

	// Escribimos solucion.
	std::cout << maxReps << " " << filmName << std::endl;


	//------Saber cual es el actor o actores con mas tiempo en pantalla:

	// Complejidad: O(n * k * (log r + log a)) siendo n el numero de elementos de secEmisiones, k el de actores de una pelicula,
	// r el de repartos y a el de actores. Son n iteraciones del primer bucle por k del segundo bucle que a su vez su complejidad es de (log r + log a).
	Actor actores;
	for (int i = 0; i < secEmisiones.size(); i++)
	{
		auto repIt = repartos.find(secEmisiones[i]); // Iterador de repartos para recorrer su mapa de qctores que tiene dentro.
		for (auto repActores : (*repIt).second)
		{
			if (actores.count(repActores.first)) // Si el acotor ya esta actualizamos su tiempo en pantalla.
			{
				actores[repActores.first] += repActores.second;
			}
			else // Sino lo metemos con su tiempo en pantalla.
			{
				actores.insert({ repActores.first, repActores.second });
			}
		}
	}

	// Complejidad: O(a) siendo a el numero de elementos del vector.
	auto actIt = actores.begin();
	while (actIt != actores.end())
	{
		std::string name = (*actIt).first;
		int tPantalla = (*actIt).second;
		if (maxMin < tPantalla) // Hemos encontrado un actor con mas tiempo de pantalla que el que ya habia.
		{
			actorsNames.clear(); // Vaciamos el vector.
			maxMin = tPantalla; // Actualizamos el mayor tiempo en pantalla.
			actorsNames.push_back(name); // Metemos el nuevo actor.
		}
		else if (maxMin == tPantalla)
		{
			actorsNames.push_back(name); // Metemos otro actor.
		}
		actIt++;
	}

	// Complejidad: O(a * log a) siendo a el numero de elementos del vector.
	// Ordenar alfabeticamente el vector de actores.
	std::sort(actorsNames.begin(), actorsNames.end(), [](const std::string& a, const std::string& b) {return a < b;});

	// Escribimos los actores.
	std::cout << maxMin;
	for (auto act : actorsNames)
	{
		std::cout << " " << act;
	}
	std::cout << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso()
{
	// leer los datos de la entrada.
	int numPelis, numEmisiones;
	std::cin >> numPelis;
	if (numPelis == 0)
	{
		return false;
	}

	// Lectura de los repartos de las peliculas.
	RepartosPeliculas repartos;
	leerRepartos(numPelis, repartos);

	// Lectura de la secuencia de peliculas emitidas en vector<string>.
	std::cin >> numEmisiones;
	std::vector<std::string> secEmisiones(numEmisiones);
	for (std::string& s : secEmisiones)
	{
		std::cin >> s;
	}
	procesarEmisiones(repartos, secEmisiones);

	return true;
}

//#define DOMJUDGE
int main() {
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
#endif

	return 0;
}