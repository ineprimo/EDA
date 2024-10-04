// INES PRIMO
// GDV61


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> datos, int ini, int fin) {

    if (fin - ini == 1) {
        if (datos[ini] % 2 != 0) return datos[ini];
        return 0;
    }

    int mid = (ini + fin)/2;
    int izq = resolver(datos, ini, mid);
    int der = resolver(datos, mid, fin);

    if (izq != 0)
        return izq;
    else if (der != 0)
        return der;
    else
        return 0;
    
     

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a, b;
    std::cin >> a;
    std::vector<int> datos;

    if (a == 0)
        return false;

    for (int i = 0; i < a; i++) {
        std::cin >> b;
        datos.push_back(b);
    }


    int sol = resolver(datos, 0, a);

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
