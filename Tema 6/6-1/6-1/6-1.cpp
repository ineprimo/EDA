// Pablo Iglesias Rodrigo
// EDA-GDV35

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"


//------Recursion normal:

template <class T>
int nodos(bintree<T> const& tree)
{
	// Caso base esta vacio tiene 0 nodos.
	if (tree.empty())
	{
		return 0;
	}

	// Recursion.
	int ramaIzq = nodos(tree.left());
	int ramaDer = nodos(tree.right());

	return ramaIzq + ramaDer + 1; // El 1 es el propio nodo.
}

template <class T>
int hojas(bintree<T> const& tree)
{
	// Caso base esta vacio.
	if (tree.empty())
	{
		return 0;
	}

	// Si su hijo izquierdo esta vacion y si hijo derecho tambien entonces es hoja.
	if (tree.left().empty() && tree.right().empty())
	{
		return 1;
	}

	// Recursion.
	int ramaIzq = hojas(tree.left());
	int ramaDer = hojas(tree.right());

	return ramaIzq + ramaDer;
}

template <class T>
int altura(bintree<T> const& tree)
{
	// Caso base esta vacio entonces no tiene altura.
	if (tree.empty())
	{
		return 0;
	}

	// Recursion.
	int alturaMax = std::max(altura(tree.left()), altura(tree.right())) + 1;
	// Si es una altura entonces (sus hijos son empty), se devuelve 1. 
	// Luego el nivel superior va a comparar el 1 con otro numero y se queda con el mayor y asi no va a dar mal.

	return alturaMax;
}


//------Con acumulador:

template <class T>
void nodosAcu(bintree<T> const& tree, int& acu)
{
	// Caso base esta vacio.
	if (tree.empty())
	{
		return;
	}
	else
	{
		// Recursion con acumulador.
		nodosAcu(tree.left(), acu);
		nodosAcu(tree.right(), acu);
		acu++;
	}
}

template <class T>
void hojasAcu(bintree<T> const& tree, int& acu)
{
	// Caso base esta vacio.
	if (tree.empty())
	{
		return;
	}
	// Si su hijo izquierdo esta vacion y si hijo derecho tambien entonces es hoja.
	if (tree.left().empty() && tree.right().empty())
	{
		acu++;
	}
	else
	{
		// Recursion con acumulador.
		hojasAcu(tree.left(), acu);
		hojasAcu(tree.right(), acu);
	}
}

template <class T>
void alturaAcu(bintree<T> const& tree, int prof, int& acu)
{
	if (tree.empty())
	{
		if (prof > acu)
		{
			acu = prof;
		}
	}
	else
	{
		alturaAcu(tree.left(), prof + 1, acu);
		alturaAcu(tree.right(), prof + 1, acu);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	int n = 0;
	bintree<char> tree;
	tree = leerArbol('.');


	//------Con recursion normal:
	std::cout << nodos(tree) << " " << hojas(tree) << " " << altura(tree) << std::endl;


	/*//------Con recursion con acumulador.

	int acuNodos = 0;
	int acuHojas = 0;
	int acuAltura = 0;

	nodosAcu(tree, acuNodos);
	hojasAcu(tree, acuHojas);
	alturaAcu(tree, 0, acuAltura);

	std::cout << acuNodos << " " << acuHojas << " " << acuAltura << std::endl;*/
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
};