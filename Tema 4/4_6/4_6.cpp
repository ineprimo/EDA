// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "Set.h"


// función que resuelve el problema
//TipoSolucion resolver(TipoDatos datos) {
//
//
//}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n = 0;
    int datos = 0;

    std::vector<int> serie;
    Set<int> sol;

    std::cin >> n;

    if (n == 0)
        return false;

    std::cin >> datos;
    while (datos != -1) {
        serie.push_back(datos);
        std::cin >> datos;
    }

    for (int i = 0; i < n; i++) {
        datos = sol.getMin(serie);
        sol.add(serie[datos]);
        sol.removeMin(serie);
    }

    // escribir sol
    std::cout << sol << std::endl;

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
