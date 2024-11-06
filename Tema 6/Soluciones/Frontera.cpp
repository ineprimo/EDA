
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
#include "bintree_eda.h"
using namespace std;

template <class T>
int esHoja(bintree<T> const& tree) {
    if (tree.empty()) return false;
    if (tree.left().empty() && tree.right().empty()) return true;
    else return false;
}


// Solución con vector acumulador (en este caso sería más sencilla)
template <class T>
void frontera(bintree<T> const& tree, vector<T>& acu){
    if (tree.empty()) return;
    if (esHoja(tree)) acu.push_back(tree.root());
    else {
        frontera(tree.left(), acu);
        frontera(tree.right(), acu);
    }
}

// Solución con recursión natural (splice es O(1) aunque ojo con posibles copias)
template <class T>
list<T> fronteraL(bintree<T> const& tree){
    if (tree.empty()) return {};
    if (esHoja(tree)) return list<T>(1,tree.root()); // list<T> ret; ret.push_back(tree.raiz()); return ret;
    else {
        list<T> frontIz = fronteraL(tree.left());
        frontIz.splice(frontIz.end(), fronteraL(tree.right()));
        return frontIz;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    bintree<int> tree;
    tree = leerArbol(-1);
    vector<int> result;
    frontera(tree,result);
    //list<int> result = fronteraL(tree);
    for (int e : result) cout << e << " ";
    cout << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("../Tema6/datos.txt");
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
