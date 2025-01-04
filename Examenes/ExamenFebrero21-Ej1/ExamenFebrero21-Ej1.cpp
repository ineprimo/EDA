// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

using namespace std;

// función que resuelve el problema
queue<int> resolver(queue<int> datos, int a, int b) {

    datos.cuela(a, b);
    return datos;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    if (!std::cin)
        return false;

    queue<int> datos;
    int first, second;
    int aux;
    cin >> aux;

    while (aux > -1) {
        datos.push(aux);
        cin >> aux;
    }

    cin >> first;
    cin >> second;

    auto sol = resolver(datos, first, second);

    // escribir sol
    while(!sol.empty()) {
        cout << sol.front() << " ";
        sol.pop();
    }
    cout << endl;

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