
#include <iostream>
#include <iomanip>
#include <fstream>

#include "list_eda.h"
#include "deque_eda.h"

// operacion externa adelantar que adelante un numero de posiciones dado a un segmento
// (elementos en posiciones consecutivas) de la lista pasada como argumento

// Complejidad: O(n) siendo n el numero de elementos de la lista

// n, pos, lon y k -> datos de entrada
list<char> adelantar(int n, int pos, int lon, int k, list<char>& datos)
{
	list<char> sol;

	// no es valida si:
	// - lista vacia
	// - lo quieres mover el mismo num de posiciones que elementos tiene la lista / lon del segmento a mover = 0
	// - pos mayor que la ultima pos de la lista
	// - k == 0
	if(datos.empty() || lon == 0 || pos == 0 || pos >= n || k == 0 || pos - k < 0)
	{
		return datos;
	}

	// si el segmento se sale de la lista
	if (pos + lon > n) 
	{
		// se tomara el segmento de los ultimos n − pos elementos
		lon = n - pos;
	}

	const int dest = pos - k;

	auto itDest = datos.begin();
	auto itPos = datos.begin();
	auto itLon = datos.begin();

	for(int i = 0; i < pos + lon - 1; i++)
	{
		if(i < dest)
		{
			++itDest;
		}
		if(i < pos)
		{
			++itPos;
		}

		++itLon;
	}

	bool segFin = false;
	auto itAct = datos.begin();
	for(int i = 0; i < n-1; i++)
	{
		if ((itAct == itDest) && !segFin) 
		{
			itAct = itPos;
		}

		if ((itAct == itLon) && !segFin) 
		{
			sol.push_back(*itAct);
			itAct = itDest;
			segFin = true;
		}

		if((itAct == itPos) && segFin)
		{
			if (i >= (pos + lon) - 1)
			{
				itAct = ++itLon;
			}
		}

		sol.push_back(*itAct);
		++itAct;
	}

	return sol;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta.
void resuelveCaso()
{
	// leer datos de entrada
	int n, pos, lon, k = 0;
	char letra = ' ';

	list<char> datos;

	std::cin >> n >> pos >> lon >> k;

	for(int j = 0; j < n; j++)
	{
		std::cin >> letra;

		datos.push_back(letra);
	}

	// resolver problema
	list<char> sol = adelantar(n, pos, lon, k, datos);

	// escribir salida
	for(auto e : sol)
	{
		std::cout << e << " ";
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

	int casos = 0;
	std::cin >> casos;

	for (int i = 0; i < casos; i++)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}