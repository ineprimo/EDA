// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>


using Pelicula = std::string; // Nombre de la pelicula. 
using Actor = std::pair <std::string, int>; // Actor con su tiempo en minutos.
using RepartosPeliculas = std::map <Pelicula, std::vector<Actor>>; // Pelicula con sus actores.

// COMPLEJIDAD: O(n) siendo n el numero de elementos del txt que estas leyendo. Solo lo recorre una vez aunque hay bucles anidados.
void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas)
{
	Pelicula peli;

	std::vector<Actor> actores;

	Actor actor;

	int numActores;
	std::string name;
	int minutos;

	for (int i = 0; i < numPeliculas; ++i)
	{
		std::cin >> peli;
		std::cin >> numActores;

		for (int j = 0; j < numActores; ++j)
		{
			std::cin >> name >> minutos;

			actor.first = name;
			actor.second = minutos;

			actores.push_back(actor); // Guardamos en el vector el nuevo actor.
		}
		peliculas.insert({ peli, actores }); // Metemos a los actores en la pelicula.
	}
}

void procesarEmisiones(RepartosPeliculas const& repartos, std::vector<std::string> const& secEmisiones)
{
	int maxReps = 0;
	std::string filmName;
	int maxMin;
	std::string actorName;


	//------Pelicula mas vista:

	std::map<Pelicula, int> nEmisiones;

	// Complejidad O(n log m) siendo n el numero de elementos de secEmisiones y m el numero de elementos de nEmisiones.
	for (int i = 0; i < secEmisiones.size(); i++)
	{
		auto emIt = nEmisiones.find(secEmisiones[i]); // Buscamos la peli.
		if (emIt == nEmisiones.end()) // Si no esta la guardamos.
		{
			nEmisiones.insert({ secEmisiones[i], 1 });
		}
		else
		{
			emIt->second++;
		}
	}

	// Complejidad: O(n) siendo n el numero de elementos de nEmisions. Recorre cada elemento 1 vez.
	for (auto em : nEmisiones)
	{
		if (maxReps < em.second)
		{
			maxReps = em.second;
			filmName = em.first;
		}
	}

	std::cout << maxReps << " " << filmName << std::endl;


	//------Actor con mas tiempo en pantalla:

	std::map<Actor, int> actores;

	for (auto emIt : nEmisiones)
	{
		auto reparto = repartos.find(emIt.first);

		for (int i = 0; i < reparto->second.size(); i++)
		{
			auto acIt = actores.find(reparto->second[i]);
			if (acIt == actores.end())
			{
				actores.insert({ reparto->second[i], emIt.second });
			}
			else
			{
				actores[reparto->second[i]]+= emIt.second;
			}
			std::cout << emIt.second << std::endl;
		}
	}
	int i = 0;















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