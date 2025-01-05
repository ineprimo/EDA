// Pablo Iglesias Rodrigo.
// EDA-GDV035.


#include <iostream>
#include <fstream>
#include "bintree_eda.h"


// COMPLEJIDAD:
std::pair<int, int> simetrico(const bintree<int>& arbol)
{
	if (arbol.empty()) 
	{

	}




	/*
	// Caso base: arbol vacio
	if (arbol.empty()) return{ 0, -1 };

	// Caso hoja: Es singular si la suma de los anteriores es 0
	// ya que esa es la suma de sus hijos siempre al ser hoja
	// (es hoja si no tiene hijos)
	if (arbol.left().empty() && arbol.right().empty())
	{
		return{ arbol.root(), 0 };
	}

	// Recursion
	std::pair<int, int> izq = hiperborea(arbol.left()); // evalua por la izq
	std::pair<int, int> der = hiperborea(arbol.right()); // evalua por la der

	//
	int dragon = 0;
	if (arbol.root() == 1)
	{
		dragon++;
	}

	// si el camino de la izq tiene menos dragones o los mismos que el camino de la derecha
	// devolver el camino de la izq
	if ((izq.second <= der.second))
	{
		return { izq.first, izq.second + dragon };
	}
	// devolver el camino de la der
	else
	{
		return { der.first, der.second + dragon };
	}
	*/
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// lee arbol
	bintree<char> arbol;
	arbol = leerArbol('.'); // '.' es la representacion de arbol vacio

	// escribe solucion

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