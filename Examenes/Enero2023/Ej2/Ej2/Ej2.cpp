// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

//
// COMPLEJIDAD: O(...) siendo n ... .
// Sease pair.first el numero del camino y pair.second el numero de dragones de ese camino.
std::pair<int, int> hiperborea(const bintree<int>& tree)
{
	// Caso base esta vacio.
	if (tree.empty())
	{
		return { 0, 0 };
	}
	// Caso es hoja devolvemos el numero de camino y 0 dragones.
	if (tree.left().empty() && tree.right().empty())
	{
		//std::cout << "HOJA: " << tree.root() << std::endl;
		return { tree.root(), 0 };
	}


	std::pair<int, int>izq = hiperborea(tree.left()); // Lado izquierdo.
	std::pair<int, int>der = hiperborea(tree.right()); // Lado derecho. 


	int dragon = 0;
	if (tree.root() == 1)
	{
		dragon++;
	}

	izq.second += dragon;
	der.second += dragon;
	if (izq.second < der.second || (izq.second == der.second && izq.first < der.first)) 
	{
		//std::cout << "Gana izq " << izq.first << " a " << der.first << " con d: " << izq.second << std::endl;
		return izq;
	}
	else {
		//std::cout << "Gana der " << der.first << " a " << izq.first << " con d: " << der.second << std::endl;
		return der;
	}

	/*if (izq.second <= der.second)
	{
		//std::cout << "Gana izq " << izq.first << " a " << der.first << " con d: " << izq.second << std::endl;
		return { izq.first, izq.second + dragon };
	}
	else if (izq.second > der.second)
	{
		//std::cout << "Gana der " << der.first << " a " << izq.first << " con d: " << der.second << std::endl;
		return { der.first, der.second + dragon };
	}*/
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