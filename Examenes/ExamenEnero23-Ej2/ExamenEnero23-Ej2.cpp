// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;
// función que resuelve el problema
//<id, dragones>
pair<int, int> resolver(bintree<int> datos) {

    if (datos.empty()) {
        return { -1, 0 };
    }
    if (datos.right().empty() && datos.left().empty()) {
        return { datos.root(), 0 };
    }

    pair<int, int> izq = resolver(datos.left());
    pair<int, int> der = resolver(datos.right());

    int dragones = 0;
    if (datos.root() == 1) {
        dragones++;
    }

    // caso en el que uno no sea una hoja
    if (izq.first == -1) 
        return { der.first, der.second + dragones };
    else if(der.first == -1) 
        return { izq.first, izq.second + dragones };


    // comparacion
    if (izq.second > der.second) {

        return {der.first, der.second + dragones};
    }
    else { 
        return { izq.first, izq.second + dragones };
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    bintree<int> datos;
    datos = leerArbol(-1);
    int dragones =  0;
    pair<int, int> sol;
    sol = resolver(datos);

    // escribir sol
    if(sol.first < 3)
        cout << endl;
    else
        cout << sol.first << endl;

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