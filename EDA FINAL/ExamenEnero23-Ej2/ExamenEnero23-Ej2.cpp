// Javier Tirado Ríos
// GDV-EDA72


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

std::pair<int, int> cuentaDragones(bintree<int> const& tree) {
    // pair<int, int> { 1 --> IdentificadorHoja, 2 --> DragonesAcumulados}

    // CASO BASE HOJA
    if (tree.left().empty() && tree.right().empty()) return { tree.root(), 0 };

    // NODO INTERMEDIO
    std::pair<int, int> infoIzq;
    std::pair<int, int> infoDer;

    // Llamamos a la recursión si existe el arbol del lado
    if (!tree.left().empty()) infoIzq = cuentaDragones(tree.left());
    if (!tree.right().empty()) infoDer = cuentaDragones(tree.right());

    // SI EXISTEN IZQ y DER, devuelvo el mas pequeño
    if (!tree.left().empty() && !tree.right().empty()) {
        if (tree.root() == 1) {
            if (infoDer.second < infoIzq.second) {
                infoDer.second++;
                return infoDer;
            }
            else {
                infoIzq.second++;
                return infoIzq;
            }
        }
        if (tree.root() == 2) {
            if (infoDer.second < infoIzq.second) {
                return infoDer;
            }
            else {
                return infoIzq;
            }
        }
        if (tree.root() == 0) {
            if (infoDer.second < infoIzq.second) {
                return infoDer;
            }
            else {
                return infoIzq;
            }
        }
    }
    // SOLO EXISTE IZQ devuelvo izq
    else if (!tree.left().empty()) {
        if (tree.root() == 1) {
            infoIzq.second++;
            return infoIzq;
        }
        if (tree.root() == 2) {
            return infoIzq;
        }
        if (tree.root() == 0) {
            return infoIzq;
        }
    }
    // Caso restante: SOLO EXISTE DER (der menor por consecuente)
    else {
        if (tree.root() == 1) {
            infoDer.second++;
            return infoDer;
        }
        if (tree.root() == 2) {
            return infoDer;
        }
        if (tree.root() == 0) {
            return infoDer;
        }
    }  
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    if (!std::cin)
        return false;
    bintree<int> tree;
    tree = leerArbol(-1);

    std::pair<int, int> sol = cuentaDragones(tree);

    //if (sol.first == -1) cout << 0  endl;
    cout << sol.first << endl;
    // escribir sol


    return true;

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