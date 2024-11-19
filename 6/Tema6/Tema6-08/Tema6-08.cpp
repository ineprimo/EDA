#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


// complejidad O(n) lineal porque hacer un recorrido de todos los nodos del arbol, siento n el numero de elementos del arbol
std::pair<int, int> resuelve(bintree<char> datos) {

    // casos base
    if (datos.empty()) {
        return {0,0};
    }
    else if (datos.right().empty() && datos.left().empty()) {
        return {1,1};
    }

    // right left
    std::pair<int, int> right = resuelve(datos.right());
    std::pair<int, int> left = resuelve(datos.left());

    // comp
    std::pair<int, int> sol = { 0,0 };

    // diametro en este caso
    int dia = right.second + left.second + 1;

    // calcula el diametro actual mas largo
    if (right.first >= dia) sol.first = right.first;
    else if (left.first >= dia) sol.first = left.first;
    else sol.first = dia;

    // calcula el diametro (parcial) mas largo actual
    if (right.second >= left.second) sol.second = right.second + 1;
    else sol.second = left.second + 1;

    // sol
    return sol;

}




// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<char> arb;
    arb = leerArbol('.'); // '.' es la repr. de arbol vacio

    std::pair<int, int> sol = resuelve(arb);

    std::cout << sol.first << std::endl;
    
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

