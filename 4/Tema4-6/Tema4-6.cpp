// INES PRIMO
// GDV61


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set.h"
#include <vector>


    // función que resuelve el problema
    Set<int> resolver(vector<int>& vec, int n) {

        Set<int> a;
        for (int i = 0; i < n; i++) {
            int min = a.getMin(vec);    // devuelve el menor
            a.add(vec[min]);            // lo mete en el set
            a.removeMin(vec);           // quita el menor del vector

        }

        return a;
    }

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    Set<int> a;
    vector<int> b;
    int aux, num;

    std::cin >> num;

    if (num == 0)
        return false;

    std::cin >> aux;
    while(aux != -1) {
        b.push_back(aux);
        std::cin >> aux;
    }

    Set<int> sol = resolver(b, num);

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
