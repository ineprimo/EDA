// Pablo Iglesias Rodrigo
// EDA-GDV35


#include <iostream>
#include <iomanip>
#include <fstream>


#include <vector>
//using namespace std;

// COMPLEJIDAD: esto es una prueba, de momento es cuadratico. O(n^2).
void comparaListados(std::vector<std::string> const& eda,
	std::vector<std::string> const& tpv,
	std::vector<std::string>& comunes,
	std::vector<std::string>& soloEda,
	std::vector<std::string>& soloTpv)
{
	for (std::string aux : eda)
	{
		int i = 0; bool encontrado = false;
		while (!encontrado && i < tpv.size())
		{
			if (aux == tpv[i])
			{
				comunes.push_back(aux);
				encontrado = true;
				i = 0;
			}
			i++;
		}

		if (!encontrado)
		{
			soloEda.push_back(aux);
		}
	}

	for (std::string aux : tpv)
	{
		int i = 0; bool valido = true;
		while (valido && i < comunes.size())
		{
			if (aux == comunes[i])
			{
				valido = false;
			}
			i++;
		}
		if (valido)
		{
			soloTpv.push_back(aux);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso()
{
	// Leer entrada:
	int n;
	std::cin >> n;
	std::vector<std::string> eda(n);
	std::vector<std::string> comunes;
	std::vector<std::string> soloEda;
	std::vector<std::string> soloTpv;

	for (std::string& e : eda)
	{
		std::cin >> e;
	}

	std::cin >> n;
	std::vector<std::string> tpv(n);

	for (std::string& e : tpv)
	{
		std::cin >> e;
	}

	// Comprobar.
	comparaListados(eda, tpv, comunes, soloEda, soloTpv);

	// Escribir salida:
	for (std::string& e : comunes)
	{
		std::cout << e << " ";
	}

	std::cout << std::endl;

	for (std::string& e : soloEda)
	{
		std::cout << e << " ";
	}

	std::cout << std::endl;

	for (std::string& e : soloTpv)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

//#define DOMJUDGE
int main()
{
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
	//system("PAUSE");
#endif

	return 0;
}