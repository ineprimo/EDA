// Pablo Iglesias Rodrigo.
// EDA-GDV035.


#include <iostream>
#include <fstream>
#include "bintree_eda.h"


template <class T>
bool hijosSimetricos(const bintree<T>& ramaIzq, const bintree<T>& ramaDer)
{
	// Casos:
	// Caso ambas ramas no tienen hijos entonces es simetrico.
	if (ramaIzq.empty() && ramaDer.empty())
	{
		return true;
	}
	// Caso izquiquierda no tiene hijos y derecha si y veciversa no es simetrico.
	if ((ramaIzq.empty() && !ramaDer.empty()) || (!ramaIzq.empty() && ramaDer.empty()))
	{
		return false;
	}

	// Cada rama se comprueba con su simetrico.
	bool hijos = hijosSimetricos(ramaIzq.left(), ramaDer.right()) && hijosSimetricos(ramaIzq.right(), ramaDer.left());

	return hijos;
}

// COMPLEJIDAD: O(n) siendo n el numero de elementos del arbol el cual solo recorre 1 vez.
template <class T>
bool simetrico(const bintree<T>& arbol)
{
	// Casos base:
	// Caso es vacio es simetrico.
	if (arbol.empty())
	{
		return true;
	}

	bool hijos = hijosSimetricos(arbol.left(), arbol.right());

	return hijos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	bintree<char> arbol;

	// Lectura:
	arbol = leerArbol('.'); // '.' es la representacion de arbol vacio


	// Resolucion:
	bool esSimetrico = false;
	esSimetrico = simetrico(arbol);


	// Escritura:
	(esSimetrico) ? std::cout << "SI" : std::cout << "NO";
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