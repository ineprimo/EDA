
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

template <class T>
bool simetrico(bintree<T> const& tree) {
    // Si esta vacio es true
    if (tree.empty()) return true;
    // Si tiene ramas llamamos a la comprobación de todos los simetricos hijos
    return simetrico(tree.left(), tree.right());
}
template <class T>
bool simetrico(bintree<T> const& izq, bintree<T> const& der) {

    // Si los dos estan vacios, es simétricos
    if (izq.empty() && der.empty()) return true;
    // Si uno es empty y el otro no ya no es simetrico
    if ((izq.empty() && !der.empty()) || (!izq.empty() && der.empty())) return false;

    // Si mismo valor / izq del todo simetrico con der del todo e igual con el otro es sim
    return izq.root() == der.root() && simetrico(izq.left(), der.right()) && simetrico(izq.right(), der.left());
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    bintree<char> tree;
    tree = leerArbol('.');

    if(simetrico(tree)) cout << "SI" << endl;
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
