// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"

using namespace std;

// función que resuelve el problema
void resolver(list<int>& datos, int const n) {
    auto it = datos.begin();
    while (it != datos.end()) {
        if (*it == n) it = datos.erase(it);
        else ++it;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    list<int> datos;
    int n;
    cin >> n;
    while (n != -1) {
        datos.push_back(n);
        cin >> n;
    }
    cin >> n;
    for (auto it = datos.begin(); it != datos.end(); ++it) cout << *it << " ";
    cout << endl;
    
    resolver(datos, n);

    for (auto it = datos.begin(); it != datos.end(); ++it) cout << *it << " ";
    cout << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}