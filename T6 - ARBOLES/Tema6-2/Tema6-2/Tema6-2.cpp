// PAULA SIERRA
// EDA-GDV70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;
// función que resuelve el problema
void resolver(bintree<int> const& datos, vector<int>& frontera)
{
    if (datos.empty()) return;
    if (datos.left().empty() && datos.right().empty()) {
        frontera.push_back(datos.root());
    }
    else {
        resolver(datos.left(), frontera);
        resolver(datos.right(), frontera);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree = leerArbol(-1);
    vector<int> frontera;

    resolver(tree, frontera);

    // escribir sol
    for (int i = 0; i < frontera.size(); ++i) {
        cout << frontera[i] << " ";
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
    system("PAUSE");
#endif

    return 0;
}