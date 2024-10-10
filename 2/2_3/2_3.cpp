// INES PRIMO
// GDV61


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int> datos, int ini, int fin) {
    
    // casos base
    if (fin - ini == 0) 
        return true;
    if (fin - ini == 1) 
        return datos[ini] < datos[fin];


    int mid = (ini + fin) / 2;
    // mitad izquierda
    bool izq = resolver(datos, ini, mid);
    // mitad derecha
    bool der = resolver(datos, mid, fin);

    return izq && der;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int a;
    std::cin >> a;

    if (a == 0)
        return false;

    std::vector<int> datos;

    while (a > 0) {
        datos.push_back(a);
        std::cin >> a;
    }

    bool sol = resolver(datos, 0, datos.size()-1);

    // escribir sol
    if (sol)
        std::cout << "SI" << std::endl;
    else
        std::cout << "NO" << std::endl;

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
