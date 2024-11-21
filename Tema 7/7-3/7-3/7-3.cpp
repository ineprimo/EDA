// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <fstream>
#include <cctype>
#include <map>


std::map<std::string, int> resolver(std::string const& primerDeporte)
{
	std::map<std::string, int> deportes; // Guarda los deportes con el numero de alumnos incritos a cada uno.
	std::map<std::string, std::string> alumnos; // Mapa que guarda los alumnos con el deporte en el que estan para las repeticiones.

	std::string deporte;
	std::string alumno;
	int nAlums = 0;
	deporte = primerDeporte;
	while (deporte != "_FIN_")
	{
		std::cin >> alumno;
		while (!isupper(alumno[0]) && alumno != "_FIN_")
		{
			nAlums++;

			// Miramos si el alumno esta en el mapa de alumnos y sino lo metemos.
			auto itALum = alumnos.find(alumno);
			if (itALum == alumnos.end())
			{
				alumnos.insert({ alumno,deporte });
			}
			else // Si ya esta entonces hay que comprobar mas cosas.
			{
				// Si el alumnos se ha puesto dos veces en la misma lista entonces quitamos una repeticion.
				if (deporte == itALum->second)
				{
					nAlums--;
				}
				else if (itALum->second != "No")// Si se ha apuntado a otro deporte entonces lo sacamos de los dos.
				{
					auto itDep = deportes.find(itALum->second); // Buscamos el deporte en el que esta repetido.
					itDep->second -= 1; // Le quitamos un alumno a ese deporte.
					itALum->second = "No";
					nAlums--; // Bajamos la cantidad de veces que aparece ese alumno.
				}
				else
				{
					nAlums--;
				}
			}
			std::cin >> alumno;
		}

		deportes.insert({ deporte,nAlums });
		nAlums = 0;
		deporte = alumno;
	}
	return deportes;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso()
{
	// Leer datos:
	std::string primerDeporte;
	std::cin >> primerDeporte;
	if (!std::cin)
	{
		return false;
	}

	// Comporbar listas de deportes:
	std::map<std::string, int> deportes = resolver(primerDeporte);

	// Guardamos la solucion ordenada, primero los deportes con mas gente.
	std::multimap<int, std::string, std::greater<int>> deportesOrdenados;
	for (auto d : deportes)
	{
		deportesOrdenados.insert({ d.second,d.first });
	}

	// Escribir:
	for (auto d : deportesOrdenados)
	{
		std::cout << d.second << " " << d.first << std::endl;
	}
		std::cout << "---\n";
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
#endif

	return 0;
}