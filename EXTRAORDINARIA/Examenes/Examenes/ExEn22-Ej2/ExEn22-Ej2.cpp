// Ejercicio 2: Singulares (3 puntos)
// Tipo: ARBOLES

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// numero de nodos singulares que tiene
template <class T>
int singulares(bintree<T> const& tree, int sumaAntepasados, int& sing)
{
    // caso arbol vacio
    if (tree.empty()) return 0;

    // caso hoja
    if (tree.left().empty() && tree.right().empty())
    {
        // una hoja solo es singular si sus antepasados son 0
        if (sumaAntepasados == 0) sing++;
    	return tree.root();
    }

    // recursion
    int izq = singulares(tree.left(), tree.root() + sumaAntepasados, sing);
    int der = singulares(tree.right(), tree.root() + sumaAntepasados, sing);

    // si la suma de mis hijos es la de mis antepasados -> es singular
    if (izq + der == sumaAntepasados) sing++;

    // los hijos de mis hijos + mis hijos
    return izq + der + tree.root();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree;
    tree = leerArbol(-1);
    int sing = 0;
    singulares(tree, 0, sing);
    cout << sing << endl;
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
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
