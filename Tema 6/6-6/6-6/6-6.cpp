// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <fstream>
#include "bintree_eda.h"


// COMPLEJIDAD: O(n) siendo n el numero de elementos del arbol.
// Sease pair.first el numero de hijos zurdos y pair.second si el arbol es zurdo.
std::pair<int, bool> zurdo(const bintree<char> tree)
{
	// Caso base esta vacio.
	if (tree.empty())
	{
		return { 0, true };
	}
	// Caso es hoja entonces por enunciado es zurdo.
	if (tree.left().empty() && tree.right().empty())
	{

		return { 1, true };

	}

	std::pair<int, bool> izq = zurdo(tree.left());
	std::pair<int, bool> der = zurdo(tree.right());

	// Es zurdo si los hijos son zurdos y en el caso del lado derecho, tiene mas hijos en el lado izquierdo.
	if (izq.second && der.second && izq.first > der.first)
	{
		return{ izq.first + der.first + 1,true };
	}
	else
	{
		return { izq.first + der.first + 1,false };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	bintree<char> tree;

	tree = leerArbol('.'); // -1 es la repr. de arbol vacio.

	std::pair<int, bool>  sol = zurdo(tree);

	// Si no hay enanos pues se es
	if (sol.second)
	{
		std::cout << "SI" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}
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