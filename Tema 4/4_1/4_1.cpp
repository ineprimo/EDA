// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set.h"


// función que resuelve el problema
Set <int> resolver(int datos, Set<int>& sol) {
    
    if (datos == 1) {
        return sol; //El número es feliz
    }
    
    int n = 0;
    int s = 0;

    while (datos > 0) {
        n = datos % 10;
        s += n * n;
        datos /= 10;
    }
    
    std::cout << s << " ";

    if (sol.contains(s)) return sol;

    sol.add(s);
    resolver(s, sol);
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int datos = 0;

    std::cin >> datos;
    Set <int> sol(1);

    if (!std::cin)
        return false;

    std::cout << datos << " ";
    sol.add(datos);
    resolver(datos, sol);

    // escribir sol

    //Si contiene el 1 es que el número es feliz
    if (sol.contains(1)) std::cout << "1" << std::endl;
    else std::cout << "0" << std::endl;

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