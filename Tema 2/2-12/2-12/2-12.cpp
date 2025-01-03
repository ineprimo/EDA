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

	// Casos:
	switch (diff)
	{
	case 0: // Si es vacio devolver 0.
		return 0;
	case 1: // Si hay 1 elemento delvolver ese elemento.
		return secPrim[ini];
	case 2: // Si hay 2 elementos delvolver el emlemento si es el que le falta a secSeg y sino el siguiente.
		return (secPrim[ini] == secSeg[ini]) ? secPrim[ini + 1] : secPrim[ini];
	default: // Si los elementos de la mitad son diferentes sabemos que esta en el lado izquierdo y sino en el derecho.
		return (secPrim[mid] != secSeg[mid]) ? perdido(secPrim, secSeg, ini, mid + 1) : perdido(secPrim, secSeg, mid, fin);
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