#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Hora.h"

// devuelve la hora del siguiente tren segun la consultada
bool siguiente(const std::vector<Hora>& trenes, const Hora& consulta, Hora& sig, int ini, int fin)
{
	// busca justo la hora siguiente
	int i = 0;
	while (i < trenes.size())
	{
		if (consulta <= trenes[i])
		{
			sig = trenes[i];
			return true;
		}
		i++;
	}
	return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	int horas = 0, nTrenes = 0;
	std::cin >> horas >> nTrenes;

	if (horas == 0 && nTrenes == 0) return false;

	std::vector<Hora> trenes(horas);
	for (auto& tren : trenes) std::cin >> tren;

	Hora sig, consulta;
	for (int i = 0; i < nTrenes; i++)
	{
		try
		{
			//Horarios posibles
			std::cin >> consulta;
			if (siguiente(trenes, consulta, sig, 0, trenes.size())) 
			{
				std::cout << sig << std::endl;
			}
			//Horarios imposibles
			else 
			{
				std::cout << "NO\n";
			}

		}
		//Error al introducir hora
		catch (const std::invalid_argument& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "ERROR" << std::endl;
		}
	}
	//Fin de caso
	std::cout << "---" << std::endl;
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