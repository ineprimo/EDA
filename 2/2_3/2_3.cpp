// INES PRIMO
// GDV61


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


int resolv(std::vector<int> datos, int ini, int fini) {
        // caso base
        if (datos.size() == 1)
            return datos[0];


}

// función que resuelve el problema
bool resolver(std::vector<int> datos) {
    

    // mitad izquierda
    int max = 0;

    // mitad derecha
    int min = 0;

    return max > min;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int lec;
    std::cin >> lec;

    if (lec == 0)
        return false;

    int in;
    std::vector<int> datos;
    std::cin >> in;

    while (in < 0) {
        datos.push_back(in);
        std::cin >> in;
    }

    bool sol = resolver(datos);

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
