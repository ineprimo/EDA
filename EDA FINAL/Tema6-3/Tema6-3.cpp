
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <string>
using namespace std;

template <class T>
T minimo(bintree<T> const& tree) 
{
    T m = tree.root();

    if (!tree.left().empty())
    {
        m = min(m, minimo(tree.left()));
    }
    if (!tree.right().empty())
    {
        m = min(m, minimo(tree.right()));
    }

    return m;
}




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char c;
    cin >> c;
    if (!cin) return false;
    if (c == 'N') {
        bintree<int> tree;
        tree = leerArbol(-1);

        cout << minimo(tree) << endl;
    }
    else {
        bintree<string> tree;
        tree = leerArbol(string("#"));

        cout << minimo(tree) << endl;
    }
    return true;
}


int main()
{
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}