
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"
using namespace std;


template <class T>
T minimo(bintree<T> const& tree){

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo;
    cin >> tipo;
    if (!cin) return false;
    if (tipo == 'N'){
        bintree<int> tree = leerArbol(int(-1));
        cout << minimo(tree) << endl;
    } else if (tipo == 'P'){
        bintree<string> tree = leerArbol(string("#"));
        cout << minimo(tree) << endl;
    }
    return true;
}

int main() {
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
