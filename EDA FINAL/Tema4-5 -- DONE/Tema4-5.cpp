// Javier Tirado Ríos
// GDV-EDA72


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set.h"

using namespace std;

// función que resuelve el problema
void resolver(Set<int> set1, Set<int> set2) {

    cout << (set1 || set2) << endl << (set1 && set2) << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n, auxNum;
    Set<int> set1, set2;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> auxNum;
        set1.add(auxNum);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> auxNum;
        set2.add(auxNum);
    }

    if (!std::cin)
        return false;


    resolver(set1, set2);

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
}