// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>

#include "list_eda.h"


// Gracias Miki.
// COMPLEJIDAD: O(n) siendo n el numero de elementos de la lista, la cual recorre 1 vez. Creo que insert y erase son O(1)???
template <class T>
void adelantar(list<T>& datos, int pos, int lon, int newPos)
{
	// Casos base si no se cumplen fuera.
	if (datos.empty() || pos < 0 || pos >= datos.size() || newPos < 0 || newPos >= pos)
	{
		return;
	}
	// Si el segmento es mas largo que el numero de elementos acortamos el segmento.
	if ((pos + lon) > datos.size())
	{
		lon = datos.size() - pos;
	}

	auto itDest = datos.begin(); // Iterador que apunta a la posicion de destino.
	for (int i = 0; i < newPos; ++i)
	{
		++itDest;
	}
	auto itPos = itDest; // Iterador que apunta al elemento que hay que mover.
	for (int i = 0; i < pos - newPos; ++i)
	{
		++itPos;
	}

	// Muevo los elementos haciendo insert+erase usando itNewPos y itPos que se hace en un bucle for con dos líneas!
	for (int i = 0; i < lon; ++i)
	{
		datos.insert(itDest, (*itPos)); // Insert inserta antes que el destino entonces perfecto.
		itPos = datos.erase(itPos); // Eliminar el elemento y actualizar el iterador al siguiente.
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta.
void resuelveCaso()
{
	// Lectura:
	int nElems = 0; // Numero de elementos de la lista.
	int pos = 0; // Posicion del elemento que hay que mover.
	int segLon = 0; // Longitud del segmento que hay que mover.
	int kPos = 0; // Numero de posiciones que hay que adelantar el segmento.

	//list_eda_plus<char> datos;
	list<char> datos; // Lista con los datos.

	std::cin >> nElems;
	std::cin >> pos;
	std::cin >> segLon;
	std::cin >> kPos;

	for (int i = 0; i < nElems; i++)
	{
		char elem;
		std::cin >> elem;
		datos.push_back(elem);
	}


	// Resolucion:
	adelantar(datos, pos, segLon, pos - kPos);


	// Escritura:
	for (auto e : datos)
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


	int cases;
	std::cin >> cases;
	for (int i = 0; i < cases; i++)
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