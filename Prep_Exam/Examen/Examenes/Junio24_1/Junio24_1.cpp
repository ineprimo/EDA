/*#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int nElems = 0, part = 0;
    std::cin >> nElems >> part;

    list<int> lista;
    int dato;
    for (int i = 0; i < nElems; i++) {
        std::cin >> dato;
        lista.push_back(dato);
    }

    if (!std::cin) {
        return false;
    }

    lista.partition(part);

    // escribir sol (y de paso la vacíamos, para optimizar)
    //Primer elemento
    if (!lista.empty()) {
        std::cout << lista.front();
        lista.pop_front();
    }
    //Siguientes
    while (!lista.empty()) {
        std::cout << " " << lista.front();
        lista.pop_front();
    }
    std::cout << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;




    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}*/