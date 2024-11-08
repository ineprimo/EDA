// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

// COMPLEJIDAD: O(n) siendo n el numero de elementos del arbol.
std::pair<int, int> navegables(const bintree<int> tree) // Sease pair.first el numero de rios navgables y pair.second el caudal.
{
	// PAIGRO AQUI: este es el codigo del entregable del anyo pasado. Seguro hay otra solucion.
	// Caso base esta vacio.
	if (tree.empty())
	{
		return { 0, 0 }; // Devuelves 0 rios navegables.
	}
	// Si sus hijos estan vacios entonces empieza un rio nuevo con caudal 1.
	if (tree.left().empty() && tree.right().empty())
	{
		return { 0, 1 }; // Un rio de base lleva 1 de caudal minimo.
	}

	std::pair<int, int> izq = navegables(tree.left());
	std::pair<int, int> der = navegables(tree.right());

	int riosNav = izq.first + der.first;
	int nuevoCaudal = 0;

	if ((izq.second + der.second - tree.root()) >= 3) // Un rio es navegable si su caudal es 3.
	{
		//std::cout << "Navegables++ con caudal: " << izq.second + der.second - tree.root() << std::endl;
		riosNav++;
	}
	if ((izq.second + der.second - tree.root()) >= 0) // Un caudal puede ser igual o mayor a 0.
	{
		nuevoCaudal = izq.second + der.second - tree.root();
	}

	return { riosNav ,nuevoCaudal };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	bintree<int> tree;

	tree = leerArbol(-1); // -1 es la repr. de arbol vacio

	// Se llama a los hijos del arbol base porque sino te cuenta un rio de mas si el caudal final es mayor que 3.
	std::cout << navegables(tree.left()).first + navegables(tree.right()).first << std::endl;
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