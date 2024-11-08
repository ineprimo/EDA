// Ines Primo Lopez
// EDA-GDV61


#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


// complejidad O(n) lineal porque hacer un recorrido de todos los nodos del arbol, siento n el numero de elementos del arbol
pair<int, int> resuelve(bintree<int> datos) {

    // casos base
    if (datos.empty()) {
        return { 0, 0 };
    }

    // right tree
    pair<int, int> right = resuelve(datos.right());
    // left tree
    pair<int, int> left = resuelve(datos.left());

    int total = right.second + left.second;

    // merge
    pair<int, int> merge;

    // caudales
    merge.second;

    // tramos recorribles
    merge.first;

    // return
    return merge;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> arb;
    arb = leerArbol(-1); // -1 es la repr. de arbol vacio

    //
    pair<int, int> sol = resuelve(arb);

    cout << sol.first << " " << sol.second << endl;


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

