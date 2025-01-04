// Pablo Iglesias Rodrigo
// EDA-GDV35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// Algorimo que dados dos vectores casi iguales saca el numero que falta en b que esta en a.
// COMPLEJIDAD: O(log n) siendo n el numero de elementos del vector, el cual no recorre entero.
int perdido(const std::vector<int>& secPrim, const std::vector<int>& secSeg, int ini, int fin)
{
	int diff = fin - ini;
	int mid = ((ini + fin) / 2);

	// Casos base:
	if (diff == 0) // Si es vacio devolver 0.
	{
		return 0;
	}
	if (diff == 1) // Si es 1 elemento devolver el elemento.
	{
		return secPrim[ini];
	}
	if (diff == 2) // Si son 2 elementos. 
	{
		if (secPrim[ini] == secSeg[ini]) // Si son iguales, devolver el siguiente.
		{
			return secPrim[ini + 1];
		}
		else // Si no son iguales entonces devolver ese elemento.
		{
			return secPrim[ini];
		}
	}

	// Como estan ordenados, si secPrim[mid] != secSeg[mid] entonces sabemos que esta en la izquierda, 
	if (secPrim[mid] != secSeg[mid])
	{
		return perdido(secPrim, secSeg, ini, mid + 1);
	}
	else // y si son iguales en la derecha.
	{
		return perdido(secPrim, secSeg, mid, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso()
{
	// Lectura:
	int nElems = 0; // Numero de elementos del primer vector;
	std::cin >> nElems;
	std::vector<int> secPrim(nElems); // Primer vector de enteros ordenados.
	std::vector<int> secSeg(nElems - 1); // Segundo vector de enteros ordenados.

	for (int i = 0; i < nElems; i++)
	{
		std::cin >> secPrim[i];
	}
	for (int i = 0; i < nElems - 1; i++)
	{
		std::cin >> secSeg[i];
	}


	// Resolucion:
	int sol = 0;
	sol = perdido(secPrim, secSeg, 0, nElems);


	// Escritura:
	std::cout << sol << std::endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	int nCasos = 0;
	std::cin >> nCasos;
	for (int i = 0; i < nCasos; i++)
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