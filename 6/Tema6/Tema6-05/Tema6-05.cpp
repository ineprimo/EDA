#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


// complejidad O(n) lineal porque hacer un recorrido de todos los nodos del arbol, siento n el numero de elementos del arbol
pair<bool, int> resuelve(bintree<int> datos) {
    // casos base
    if (datos.empty()) {
        return { true,  -1 };
    }
    else if (datos.right().empty() && datos.left().empty()) {
        return { true, datos.root() };
    }

    //
    pair<bool, int> right = resuelve(datos.right());
    pair<bool, int> left = resuelve(datos.left());


    pair<bool, int> sol = {true, datos.root()};
    if (right.first && left.first) {
        if (!(left.second < datos.root() < right.second)) {
            sol.first = false;
        }
    }
    else sol.first = false;

    return sol;


}




// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> arb;
    arb = leerArbol(-1); // '.' es la repr. de arbol vacio

    pair<bool, int> sol = resuelve(arb);

    string aux;
    if (sol.first) aux = "SI";
    else aux = "NO";
    std::cout << aux << std::endl;

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

