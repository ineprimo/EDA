// INES PRIMO
// GDV61


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

// función que resuelve el problema
int resolver(const bintree<int>& datos, int parent, int& count) {

    if (datos.empty()) {
        return 0;
    }
    if (datos.left().empty() && datos.right().empty()) {
        if(parent == 0)
            count++;
        return datos.root();
    }

    int izq = resolver(datos.left(), datos.root(), count);
    int der = resolver(datos.right(), datos.root(), count);

    // comparacion
    if (izq + der == parent)
        count++;

    return izq + der + datos.root();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int>datos;
    datos = leerArbol(-1);
    int sol = 0;
    resolver(datos, 0, sol);

    cout << sol << endl;

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