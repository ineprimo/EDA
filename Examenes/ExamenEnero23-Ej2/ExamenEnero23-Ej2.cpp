// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

// función que resuelve el problema
int resolver(bintree<int> datos, int& dragones) {

    if (datos.empty()) {
        return -1;
    }
    if (datos.right().empty() && datos.left().empty()) {
        return datos.root();
    }

    int dragonesDER = 0;
    int dragonesIZQ = 0;

    int izq = resolver(datos.left(), dragonesIZQ);
    int der = resolver(datos.right(), dragonesDER);

    if (datos.root() == 1) {
        dragones++;
    }
    // caso en el que uno no sea una hoja
    if (izq == -1) 
        return der;
    else if(der == -1) 
        return izq;

    // comparacion
    if (dragonesIZQ > dragonesDER) {
        dragones += dragonesDER;
        return der;
    }
    else { 
        dragones += dragonesIZQ;
        return izq; 
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    bintree<int> datos;
    datos = leerArbol(-1);
    int dragones =  0;
    int sol = 0;
    sol = resolver(datos, dragones);

    // escribir sol
    if(sol < 3)
        cout << endl;
    else
        cout << sol << endl;

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
    {
        resuelveCaso();
    }

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}