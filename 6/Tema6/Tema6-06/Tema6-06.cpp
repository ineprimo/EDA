#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


// complejidad O(n) lineal porque hacer un recorrido de todos los nodos del arbol, siento n el numero de elementos del arbol
std::pair<bool, int> resuelve(bintree<char> datos) {
    // casos base
    if (datos.empty()) {
        return { true, 0 };
    }
    else if (datos.left().empty() && datos.right().empty()) {
        return{ true, 1};
    }

    std::pair<bool, int> right = resuelve(datos.right());
    std::pair<bool, int> left = resuelve(datos.left());

    // merge
    std::pair<bool, int> sol = {true, 0};

    if (left.first && right.first) sol.first = true;
    else sol.first = false;
    if (right.second >= left.second) sol.first = false;

    sol.second = right.second + left.second + 1;

    return sol;
    

}




// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<char> arb;
    arb = leerArbol('.'); // '.' es la repr. de arbol vacio

    std::pair<bool, int> sol = resuelve(arb);

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

