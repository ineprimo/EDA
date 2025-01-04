// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

// Metodo que dado un arbol encuentra sus elementos singulares recursivamente siendo un elemento singular el que la suma de sus padres e hijo es la misma.
// COMPLEJIDAD: O(n) siendo n el numero de elementos del arbol el cual solo recorre 1 vez.
// Sease pair.first el numero de singulares y pair.second la suma de los hijos.
std::pair<int, int> singulares(const bintree<int>& tree, int padreSuma)
{
	// Caso base esta vacio.
	if (tree.empty())
	{
		return { 0, 0 };
	}
	// Caso es hoja entonces comporbamos si es singular y devolvemos el propio valor.
	if (tree.left().empty() && tree.right().empty())
	{
		if (padreSuma == 0) // Si es hoja la suma de sus hijos es 0 entonces solo hay que comprobar que la del padre es 0 tambien.
		{
			return { 1, tree.root() };
		}
		else // Si no lo es no es singular.
		{
			return { 0, tree.root() };
		}
	}

	// Recursion:
	std::pair<int, int> izq = singulares(tree.left(), padreSuma + tree.root()); // Lado izquierdo.
	std::pair<int, int> der = singulares(tree.right(), padreSuma + tree.root()); // Lado derecho.

	int nSingulares = izq.first + der.first; // Numero de singulares de los hijos.
	int sumaHijos = izq.second + der.second; // Suma de los valores de los hijos.

	if (padreSuma == sumaHijos) // Condicion de singularidad.
	{
		nSingulares++;
	}

	return { nSingulares, sumaHijos + tree.root() };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// Lectura:
	bintree<int> tree;

	tree = leerArbol(-1); // -1 es la repr. de arbol vacio


	// Resolucion:
	std::pair<int, int> sol;
	sol = singulares(tree, 0);


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