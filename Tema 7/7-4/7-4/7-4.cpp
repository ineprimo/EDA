// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>


int resolver(std::vector<int>& datos)
{
	std::map<int, int> rachaCaps; // Mapa que guarda el capitulo y nada mas.
	int racha = 0;

	for (int i = 0; i < datos.size(); i++)
	{
		// Buscamos si el episodio ya ha salido.
		auto it = rachaCaps.find(datos[i]);
		if (it == rachaCaps.end()) // Si no ha salido lo metemos.
		{
			rachaCaps.insert({ datos[i], 1 });
		}
		else // Si estan repitiendo el episodio entonces se rompe la racha.
		{
			if (rachaCaps.size() > racha)
			{
				racha = rachaCaps.size();
			}
			rachaCaps.clear(); // Lo vaciamos porque se ha roto la racha.
		}
	}
	return rachaCaps.size() > racha ?  rachaCaps.size() : racha;
}

void resuelveCaso()
{
	// Leer:
	int nDatos = 0;
	int dato = 0;
	std::cin >> nDatos;

	std::vector<int> datos;

	for (int i = 0; i < nDatos; i++)
	{
		std::cin >> dato;
		datos.push_back(dato);
	}

	// Resolver y escribir:
	std::cout << resolver(datos) << std::endl;
}


int main()
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	char c;
	std::cin >> numCasos;
	std::cin.get(c);
	for (int i = 0; i < numCasos; ++i)
	{
		resuelveCaso();
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}