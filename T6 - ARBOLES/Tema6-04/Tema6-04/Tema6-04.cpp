// PAULA SIERRA
// EDA-GDV70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

bool esPrimo(int num)
{
    if (num < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

// función que resuelve el problema
pair<int, int> resolver(bintree<int> const& tree, int& multiplo, int& nivel) {

    if (tree.empty()) return { -1, -1 };

    // el nodo actual es primo
    if (esPrimo(tree.root())) {
        return { -1, -1 };
    }

    // candidato si es mult de 7 y no primo
    pair<int, int> mejor = { -1, -1 };
    if (tree.root() % 7 == 0) {
        mejor = { tree.root(), nivel };
    }

    pair<int, int> izq = resolver(tree.left(), multiplo, ++nivel);
    pair<int, int> der = resolver(tree.right(), multiplo, ++nivel);

    if (izq.first != -1 && (mejor.first == -1 || izq.second < mejor.second)) {
        mejor = izq;
    }
    if (der.first != -1 && (mejor.first == -1 || der.second < mejor.second)) {
        mejor = der;
    }

    return mejor;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree = leerArbol(-1);

    int nivel = 0;
    int multiplo;
    pair<int, int> sol = resolver(tree, multiplo, nivel);

    // escribir sol
    if (sol.first == -1) {
        cout << "NO HAY" << endl;
    }
    else {
        cout << sol.first << " " << sol.second << endl;
    }
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