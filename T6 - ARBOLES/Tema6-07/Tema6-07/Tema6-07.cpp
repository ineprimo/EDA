// PAULA SIERRA LUQUE
// EDA GDV 70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// función que resuelve el problema
template <class T>
int resolver(bintree<T> const& tree, int& caudal, int& cuenta)
{
    // devuelve caudal

    if (tree.empty()) return 0;
    if (tree.left().empty() && tree.right().empty()) return 1; // si es hoja, caudal=1

    int caudalIzq = resolver(tree.left(), caudal, cuenta);
    int caudalDch = resolver(tree.right(), caudal, cuenta);

    if (caudal >= 3) {
        ++cuenta;
    }

    caudal = caudalIzq + caudalDch - tree.root();
    if (caudal < 0) caudal = 0; // el caudal no puede ser negativo pero si 0

    return caudal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree = leerArbol(-1);

    int cont = 0;
    int caudal = 0;
    int sol = resolver(tree, caudal, cont);

    // escribir sol
    cout << cont << endl;
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