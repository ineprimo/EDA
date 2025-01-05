// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <fstream>
#include "bintree_eda.h"


std::pair<int, int> hiperborea(const bintree<int>& tree)
{
	// Casos base:
	// Caso base es vacio.
	if (tree.empty())
	{
		return { -1, 0 };
	}
	// Caso es hoja devolvemos el numero de camino y 0 dragones.
	if (tree.left().empty() && tree.right().empty())
	{
		return { tree.root(), 0 };
	}

	// Recursion:
	std::pair<int, int> izq = hiperborea(tree.left());
	std::pair<int, int> der = hiperborea(tree.right());

	// Si el nodo tiene un 1 entonces hay dragon.
	int dragones = 0;
	if (tree.root() == 1)
	{
		dragones++;
	}

	// Casos:
	// Si no llega un camido del lado izquierdo (no hay hijo izquierdo) devolvemos el derecho.
	if (izq.first == -1)
	{
		return{ der.first, der.second + dragones };
	}
	// Y si no llega del derecho (no hay hijo derecho) devolvemos el izquierdo.
	if (der.first == -1)
	{
		return{ izq.first, izq.second + dragones };
	}
	// Habiendo los 2 hijos, comprobamos quien tiene menos dragones y en caso de empate se queda con el de la izquierda.
	if (izq.second <= der.second)
	{
		return { izq.first, izq.second + dragones };
	}
	else
	{
		return { der.first, der.second + dragones };
	}
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso()
{
	// Lectura:
	bintree<int> tree;

	tree = leerArbol(-1); // -1 es la repr. de arbol vacio


	// Resolucion:
	std::pair<int, int> sol;
	sol = hiperborea(tree);
	int hola = 0;

	// Escritura:
	std::cout << sol.first << std::endl;
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