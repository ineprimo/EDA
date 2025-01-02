// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// COMPLEJIDAD: O(...) siendo n ... .
std::pair<std::vector<int>, std::vector<int>> complementarioEInverso(const std::vector<int>& sec)
{
	std::vector<int> complementario(sec.size()); // Vector auxuliar que contiene el complementario.
	std::vector<int> inverso(sec.size()); // Vector auxiliar que contiene el inverso del complementario.


	for (int i = 0; i < sec.size(); i++)
	{
		inverso[i] = (9 - sec[i]); // La secuencia viene invertida.
		complementario[sec.size() - i - 1] = inverso[i];
	}

	return { complementario, inverso };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso()
{
	// Lectura:
	std::vector<int> sec;
	int num = 0;
	std::cin >> num;
	num /= 1; // Para el punto de ruptura.
	if (num > 0)
	{
		while (num > 0)
		{
			sec.push_back(num % 10);
			num /= 10;
		}
	}
	else
	{
		sec.push_back(num);
	}


	// Resolver:
	std::pair<std::vector<int>, std::vector<int>> sol;
	sol = complementarioEInverso(sec);


	// Escribir solucion:
	for (int i = 0; i < sec.size(); i++)
	{
		std::cout << sol.first[i];
	}
	std::cout << " ";
	for (int i = 0; i < sec.size(); i++)
	{
		std::cout << sol.second[i];
	}
	std::cout << std::endl;
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
	std::cin >> numCasos;
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
