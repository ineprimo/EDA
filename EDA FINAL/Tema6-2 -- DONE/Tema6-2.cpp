
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

template <class T>
bool hoja(bintree<T> const& tree) {
    if (tree.empty()) return false;
    return tree.left().empty() && tree.right().empty();
}

template <class T>
void frontera(bintree<T> const& tree, vector<int>& front)
{
    if (tree.empty()) return;
    else if (hoja(tree)) front.push_back(tree.root());
    else frontera(tree.left(), front); frontera(tree.right(), front);
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    bintree<int> tree;
    tree = leerArbol(-1);
    
    vector<int> sol;
    frontera(tree, sol);

    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }

    cout << endl;
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
