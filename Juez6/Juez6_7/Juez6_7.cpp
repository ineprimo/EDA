//Denisa Juarranz Berindea
//EDA-GDV37

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

//Este algoritmo tiene complejidad lineal O(n), siendo n el número de nodos del árbol

template <class T> 
void navegables(bintree<T> const& tree, int& navegables, int& caudal) {
    //Si no hay ramas, no hay zonas navegables, ni caudal
    if (tree.empty()) {
        caudal = 0;
        navegables = 0;
        return;
    }
    
    //Si hay derecha e izquierda vacías, habrá un caudal, pero no será navegable
    if (tree.left().empty && tree.right().empty()) {
        caudal = 1;
        navegables = 0;
        return;
    }
    
    //Ahora comprobaremos cada lado, por separado
    int caudalL = 0, caudalR = 0, navegablesL = 0, navegablesR = 0;

    //izquierda
    navegables(tree.left(), navegablesL, caudalL);
    if (caudalL >= 3) navegablesL++;

    //derecha
    navegables(tree.right(), navegablesR, caudalR);
    if (caudalR >= 3) navegablesR++;

    //Caudal total
    caudal = caudalL + caudalR;
    //No puede ser negativo, solo 0
    if (caudal < 0) caudal = 0;
    //Navegables total
    navegables = navegablesL + navegablesR;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> tree;
    tree = leerArbol(-1); // -1 es la repr. de arbol vacio
    int navega = 0, caudal = 0;
    navegables(tree, navega, caudal);
    cout << navega << endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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

