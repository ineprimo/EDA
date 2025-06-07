// Ejercicio 2: Nodos acumuladores (2,5 puntos)
// Tipo: ARBOLES

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

//En un árbol binario con números enteros (no negativos) en sus nodos, llamamos nodo acumulador a aquel cuyo valor
//es igual a la suma de los valores de todos sus descendientes.
//Por ejemplo, de los siguientes árboles, el de la izquierda tiene dos nodos acumuladores (el 3 y el 21),
//mientras que el de la derecha tiene tres nodos acumuladores (los dos 7 y el nodo interno con valor 1).
template <class T>
int acumuladores(bintree<T> const& tree, int& acumul)
{
    // caso arbol vacio
    if (tree.empty()) return 0;

    // caso hoja
    if (tree.left().empty() && tree.right().empty()) 
    {
        if (tree.root() == 0) acumul++;
        return tree.root();
    }

    int totalDescendiente = 0;
    // --- Mirar en la izq
    if (!tree.left().empty() && tree.right().empty())
    {
        totalDescendiente = acumuladores(tree.left(), acumul);
    }

    // --- Mirar en la der
    if (tree.left().empty() && !tree.right().empty())
    {
        totalDescendiente = acumuladores(tree.right(), acumul);
    }

    // --- Mirar en ambas
    if (!tree.left().empty() && !tree.right().empty())
    {
        totalDescendiente = acumuladores(tree.right(), acumul) +  // der
            acumuladores(tree.left(), acumul);  // izq
    }

    if (tree.root() == totalDescendiente) acumul++; // es acumulador?
    return totalDescendiente + tree.root(); // suma descendientes + root
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    bintree<int> tree;
    tree = leerArbol(-1);

    int acum = 0;
    acumuladores(tree, acum);
    cout << acum << endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
