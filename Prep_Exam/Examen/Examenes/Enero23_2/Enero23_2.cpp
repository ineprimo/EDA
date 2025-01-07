#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// first -> numero del camino
// second -> numero de dragones en ese camino
pair<int, int> camino(const bintree<int>& tree)
{

    // Arbol vacio - no camino, no dragones - nunca será vacío
    if (tree.empty()) return{ 0, 0 };

    // Si es hoja - camino ese, no dragones
    if (tree.left().empty() && tree.right().empty())
    {
        return{ tree.root(), 0 };
    }

    // Miramos cada lado
    pair<int, int> izq = camino(tree.left()); 
    pair<int, int> dcha = camino(tree.right());

    //Contador de dragones
    int dragon = 0;
    if (tree.root() == 1)
    {
        dragon++;
    }

    // si no existe una de las hojas devuelve el otro lado
    if (izq.first == 0)
    {
        return { dcha.first, dcha.second + dragon };
    }
    if (dcha.first == 0)
    {
        return { izq.first, izq.second + dragon };
    }

    // si el camino de la izq tiene menos dragones o los mismos que el camino de la dcha
    if ((izq.second <= dcha.second))
    {
        return { izq.first, izq.second + dragon };
    }
    else
    {
        return { dcha.first, dcha.second + dragon };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	bintree<int> tree;
	tree = leerArbol(-1); // -1 es vacío

    pair<int, int> solucion;
    solucion = camino(tree);

    // escribe solucion
    cout << solucion.first << endl;
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
	for (int i = 0; i < numCasos; ++i) resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}