// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <fstream>
#include "bintree_eda.h"


// COMPLEJIDAD: O(n) siendo n el numero de elementos del arbol.
// Sease pair.first el lider del grupo y pair.second el numero de enanos.
std::pair<std::string, int> enanos(const bintree<std::string> tree)
{
	// Caso base esta vacio.
	if (tree.empty())
	{
		return{ "", 0 };
	}
	// Caso es hoja, devolvemos, si lo hay, el enano y sumamos integrante.
	if (tree.left().empty() && tree.right().empty())
	{
		// No hace falta esto porque siempre en las hojas hay enenaos pero por si acaso nunca se sabe.
		if (tree.root() != "-")
		{
			return{ tree.root(), 1 };
		}
		else
		{
			return { "", 0 };
		}
	}

	std::pair<std::string, int> izq = enanos(tree.left());
	std::pair<std::string, int> der = enanos(tree.right());

	int sumaEnanos = izq.second + der.second;
	std::string nuevoLider = "";
	std::string liderIzq = izq.first;
	std::string liderDer = der.first;

	// Si los dos grupos son iguales entonces se queda con el lider menor segun < . 
	if (izq.second == der.second)
	{
		if (liderIzq < liderDer)
		{
			nuevoLider = liderIzq;
		}
		else
		{
			nuevoLider = liderDer;
		}
	}
	else // Sino se elige al lider del grupo mas numeroso.
	{
		if (izq.second > der.second)
		{
			nuevoLider = liderIzq;
		}
		else
		{
			nuevoLider = liderDer;
		}
	}
	// Cuando se encuentran con un orco y son mas que 0.
	if (tree.root() == "Orcos" && sumaEnanos > 0)
	{
		sumaEnanos = sumaEnanos / 2; // Reducimos a la mitad los enanos.
		// Si se queda sin enanos no hay lider.
		if (sumaEnanos == 0)
		{
			nuevoLider = "";
		}
	}

	return { nuevoLider, sumaEnanos };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	bintree<std::string> tree;

	tree = leerArbol((std::string)"."); // -1 es la repr. de arbol vacio.

	std::pair<std::string, int> sol = enanos(tree);

	// Si no hay enanos pues se escribe ninguno.
	if (sol.second == 0)
	{
		std::cout << "Ninguno" << std::endl;
	}
	else
	{
		std::cout << sol.first << " " << sol.second << std::endl;
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