// Pablo Iglesias Rodrigo
// EDA-GDV35


#include <iostream>
#include <iomanip>
#include <fstream>

#include <functional>
#include <algorithm>
#include <vector>

// COMPLEJIDAD: es de complejidad O(n log n) que es la complejidad que tiene el std::sort.
void comparaListados(std::vector<std::string>& eda,
	std::vector<std::string>& tpv,
	std::vector<std::string>& comunes,
	std::vector<std::string>& soloEda,
	std::vector<std::string>& soloTpv)
{
	// Ordenamos primero los vectores para convertirlo en el ejercicio anterior.
	std::sort(eda.begin(), eda.end());
	std::sort(tpv.begin(), tpv.end());

	int edaI = 0;
	int tpvI = 0;

	while (edaI < eda.size() && tpvI < tpv.size())
	{
		if (eda[edaI] < tpv[tpvI]) // a < b => a esta en EDA solo.
		{
			soloEda.push_back(eda[edaI]);
			edaI++;
		}
		else if (eda[edaI] > tpv[tpvI]) // b > a = > a esta en TPV solo.
		{
			soloTpv.push_back(tpv[tpvI]);
			tpvI++;
		}
		else // Si son iguales pues esta en ambos.
		{
			comunes.push_back(eda[edaI]);
			edaI++;
			tpvI++;
		}
	}

	while (edaI < eda.size()) // Recorremos lo que nos queda de EDA.
	{
		soloEda.push_back(eda[edaI]);
		edaI++;
	}

	while (tpvI < tpv.size()) // Recorremos lo que nos queda de TPV.
	{
		soloTpv.push_back(tpv[tpvI]);
		tpvI++;
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