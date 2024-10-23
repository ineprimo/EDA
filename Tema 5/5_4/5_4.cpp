// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

#include "queue_eda.h"



// función que resuelve el problema
void resolver(queue<int>& datos) {

    datos.duplica();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int d = 0;
    std::cin >> d;

    if (!std::cin)
        return false;

    queue <int> cola;

    while (d != 0) {
        cola.push(d);
        std::cin >> d;
    }

    resolver(cola);

    while (!cola.empty()) {

        std::cout << cola.front() << " ";
        cola.pop();
    }

    std::cout << std::endl;

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
}