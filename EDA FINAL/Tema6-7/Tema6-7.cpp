#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

std::pair<int, int> navegable(bintree<int> const& tree) {
    //    { CAUDAL ACTUAL , NAVEGABLES ACUM}
    
    // CASOS BASE
    if (tree.empty()) return { 0, 0 };
    if (tree.left().empty() && tree.right().empty()) return {1, 0};

    std::pair<int, int> izq = navegable(tree.left());
    std::pair<int, int> der = navegable(tree.right());

    int caudal = izq.first + der.first - tree.root();
    if (caudal < 0) caudal = 0;
    int navegablesAcum = izq.second + der.second;

    if (caudal >= 3) navegablesAcum++;
    return {caudal, navegablesAcum};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> arb;
    arb = leerArbol(-1); // -1 es la repr. de arbol vacio

    cout << navegable(arb.left()).second + navegable(arb.right()).second << std::endl;
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

