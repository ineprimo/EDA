
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

std::pair<bool, int> zurdo(bintree<char> const& tree) {
    // CASO BASE
    if (tree.empty()) return {true, 0};
    if (tree.left().empty() && tree.right().empty()) return { true, 1 };

    std::pair<bool, int> izq = zurdo(tree.left());
    std::pair<bool, int> der = zurdo(tree.right());

    int total = izq.second + der.second + 1;

    if (izq.first && der.first && izq.second > der.second) return { true, total };

    return {false, total};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> tree;
    tree = leerArbol('.');
    std::pair<bool, int> sol = zurdo(tree);
    if (sol.first) cout << "SI" << endl;
    else cout << "NO" << endl;
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