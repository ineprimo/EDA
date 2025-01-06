// PAULA SIERRA LUQUE
// EDA GDV 70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// función que resuelve el problema
template <class T>
bool resolver(bintree<T> const& tree, int min, int max) 
{
    // casos base
    if (tree.empty()) return true;
    if (tree.root() <= min || max <= tree.root()) return false;

    return resolver(tree.left(), min, tree.root()) && resolver(tree.right(), tree.root(), max);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree = leerArbol(-1);

    bool sol = resolver(tree, 0, 5000);

    // escribir sol
    if (sol) cout << "SI" << endl;
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
    system("PAUSE");
#endif

    return 0;
}