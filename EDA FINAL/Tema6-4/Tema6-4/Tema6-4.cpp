// Javier Tirado Ríos
// EDA-GDV72

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <cmath>

using namespace std;

bool esPrimo(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i <= sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

pair<int, int> resolver(bintree<int> const& tree, int profundidad, bool caminoBloqueado) {
    if (tree.empty()) return { -1, -1 };

    // Si ya hay un primo en el camino, este nodo y sus hijos no son accesibles
    if (caminoBloqueado) return { -1, -1 };

    // Si el nodo actual es primo, a partir de aquí el camino queda bloqueado
    bool bloqueado = caminoBloqueado || esPrimo(tree.root());

    // Si el nodo es accesible y múltiplo de 7, lo consideramos candidato
    pair<int, int> mejor = { -1, -1 };
    if (!bloqueado && tree.root() % 7 == 0) {
        mejor = { tree.root(), profundidad };
    }

    // Buscamos en los hijos
    pair<int, int> izq = resolver(tree.left(), profundidad + 1, bloqueado);
    pair<int, int> der = resolver(tree.right(), profundidad + 1, bloqueado);

    // Seleccionamos el mejor candidato: el más cercano a la raíz, y en caso de empate, el de la izquierda
    if (mejor.second != -1 &&
        (izq.second == -1 || mejor.second < izq.second ||
            (mejor.second == izq.second && mejor.first <= izq.first)) &&
        (der.second == -1 || mejor.second < der.second ||
            (mejor.second == der.second && mejor.first <= der.first))) {
        return mejor;
    }
    if (izq.second != -1 &&
        (der.second == -1 || izq.second < der.second ||
            (izq.second == der.second && izq.first <= der.first))) {
        return izq;
    }
    return der;
}

void resuelveCaso() {
    bintree<int> datos = leerArbol(-1);
    pair<int, int> sol = resolver(datos, 1, false);

    if (sol.second == -1) cout << "NO HAY" << endl;
    else cout << sol.first << " " << sol.second << endl;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}