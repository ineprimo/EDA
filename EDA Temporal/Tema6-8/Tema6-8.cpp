
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

template <class T>
std::pair<int, int> diametro(bintree<T> const& tree) {

    //      { Acum Lado Mayor ; Posible Maximo }
    
    // CASO BASE
    if (tree.empty()) return {0, 0};
    if (tree.left().empty() && tree.right().empty()) return { 1, 1 };

    std::pair<int, int> izq = diametro(tree.left());
    std::pair<int, int> der = diametro(tree.right());
    int totalNodo = izq.first + der.first + 1;

    if (izq.second > totalNodo) return { std::max(izq.first, der.first) + 1, izq.second };
    else if (der.second > totalNodo) return { std::max(izq.first, der.first) + 1, der.second };
    return { std::max(izq.first, der.first) + 1, totalNodo };
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> tree;
    tree = leerArbol('.');

    std::pair<int, int> sol = diametro(tree);

    cout << sol.second << endl;
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
