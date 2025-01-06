// PAULA SIERRA LUQUE
// EDA GDV 70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// función que resuelve el problema
template <class T>
pair<bool, int> resolver(bintree<T> const& tree)
{
    // {zurdo, }
    // casos base
    if (tree.empty()) return { true,0 };
    if (tree.left().empty() && tree.right().empty()) return { true,1 };

    pair<bool, int> izq = resolver(tree.left());
    pair<bool, int> dch = resolver(tree.right());

    int total = izq.second + dch.second + 1;

    if (izq.first && dch.first && izq.second > dch.second) return { true, total };
    return { false, total };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> tree = leerArbol('.');

    pair<bool, int> sol = resolver(tree);

    // escribir sol
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
    system("PAUSE");
#endif

    return 0;
}