// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

#include "Set.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    Set<int> set1;
    Set<int> set2;

    int n1 = 0;
    int n2 = 0;
    int datos = 0;

    //Rellenamos el set1
    std::cin >> n1;
    for (int i = 0; i < n1; i++) {
        std::cin >> datos;
        set1.add(datos);
    }

    std::cin >> n2;
    for (int i = 0; i < n2; i++) {
        std::cin >> datos;
        set2.add(datos);
    }

    if (!std::cin)
        return false;

    // escribir sol
    std::cout << (set1 || set2) << std::endl << (set1 && set2) << std::endl;

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
