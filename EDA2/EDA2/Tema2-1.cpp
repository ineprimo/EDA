﻿// Andres Garcia Navarro
// EDA-GDV27

/*
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


// función que resuelve el problema
void escribePolidivisibles(long long raiz, int maxDigitos) {
    int size = (std::to_string(raiz)).size();

    recPolidivisible(raiz, size, maxDigitos);
}

void recPolidivisible(long long raiz, int digitos, int maxdigitos) {
    if (digitos > maxdigitos)
        return;
    if (raiz %10 == 9)
        recPolidivisible()
    
    raiz
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    if (!std::cin)
        return false;

    TipoSolucion sol = resolver(datos);

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


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}*/