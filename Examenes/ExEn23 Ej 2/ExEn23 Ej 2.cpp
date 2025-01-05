#include <iostream>
#include <fstream>
#include "bintree_eda.h"

// un nodo se dice que es singular si la suma de los valores almacenados en sus nodos antepasados
// es igual a la suma de los valores almacenados en sus nodos descendientes

// Complejidad: O(n) siendo n el numero de elementos del arbol

// first -> numero del camino
// second -> numero de dragones en ese camino

std::pair<int, int> hiperborea(const bintree<int>& arbol)
{
    // Caso base: arbol vacio
    if (arbol.empty()) return{ -1, 0 };

    // Caso hoja: devolvemos el num del camino y 0 dragones
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
    if(arbol.root() == 1)
    {
        dragon++;
    }

    // cuando solo tiene un hijo
    // si no existe uno de los hijos devuelves el contrario
    if(izq.first == -1)
    {
        return { der.first, der.second + dragon };
    }
    if(der.first == -1)
    {
        return { izq.first, izq.second + dragon };
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
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // lee arbol
    bintree<int> arbol;
    arbol = leerArbol(-1); // '-1' es la representacion de arbol vacio

    // escribe solucion
    std::cout << hiperborea(arbol).first << std::endl;
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