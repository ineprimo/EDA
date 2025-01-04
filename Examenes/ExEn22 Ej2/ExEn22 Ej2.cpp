#include <iostream>
#include <fstream>
#include "bintree_eda.h"

// un nodo se dice que es singular si la suma de los valores almacenados en sus nodos antepasados
// es igual a la suma de los valores almacenados en sus nodos descendientes

// Complejidad: O(n) siendo n el numero de elementos del arbol

// first -> num de singulares
// second -> suma de los hijos
std::pair<int,int> singulares(const bintree<int>& arbol, int padreSuma)
{
    // Caso base: arbol vacio
    if (arbol.empty()) return{ 0, 0 };

    // Caso hoja: Es singular si la suma de los anteriores es 0
    // ya que esa es la suma de sus hijos siempre al ser hoja
    // (es hoja si no tiene hijos)
    if(arbol.left().empty() && arbol.right().empty())
    {
        if(padreSuma == 0)
        {
            // devuelve 1 singular en caso de serlo
            return{ 1, arbol.root() };
        }
        else
        {
            return{ 0, arbol.root() };
        }
    }

    // Recursion
    // evalua por la izq -> le pasas la rama & la suma acumulada + tu propio valor para el siguiente
    std::pair<int,int> izq = singulares(arbol.left(), padreSuma + arbol.root());
    // evalua por la der -> le pasas la rama & la suma acumulada + tu propio valor para el siguiente
    std::pair<int, int> der = singulares(arbol.right(), padreSuma + arbol.root());

    int numSing = izq.first + der.first;        // conteo de singulares hasta ahora
    int sumaHijos = izq.second + der.second;    // suma de todos los hijos

    // si la suma de los antecesores es igual a la suma de todos los descendientes
    if(padreSuma == sumaHijos)
    {
        // es singular
        numSing++;
    }

    // devuelves el num de singulares, la suma de tus hijos + tu mismo
    return { numSing, sumaHijos + arbol.root() };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // lee arbol
    bintree<int> arbol;
    arbol = leerArbol(-1); // '-1' es la representacion de arbol vacio.

    // escribe solucion
    std::cout << singulares(arbol, 0).first << std::endl;
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