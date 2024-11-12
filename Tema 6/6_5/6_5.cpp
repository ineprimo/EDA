
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"
using namespace std;



bool Busqueda(bintree<int> const& tree) {

    if (tree.empty()) return true;
    if (tree.left().empty() && tree.right().empty()) return true;

    bool _left = true;
    bool _right = true;

    if (!tree.left().empty())
        _left = tree.left().root() < tree.root() && Busqueda(tree.left());

    if (!tree.right().empty())
        _right = tree.right().root() > tree.root() && Busqueda(tree.right());

    
    return _left && _right;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    bintree<int> tree;
    bool sol = true;
    const bool cosa = false;

    tree = leerArbol(-1);
    int min = 0, max = 0;

    //if (!tree.empty()) min = tree.root();

    

    if (Busqueda(tree)) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
    }

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


