// INES PRIMO
// GDV61


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;



// función que resuelve el problema
bool resolver(const bintree<char>& left, const bintree<char>& right) {

    if (left.empty() && right.empty()) {
        return true;
    }
    // mira las ramas de fuera y las de dentro
    if ((right.empty() && !left.empty()) || (left.empty() && !right.empty())) {
        return false;
    }

    bool out = resolver(left.left(), right.right());
    bool in = resolver(left.right(), right.left());

    return in && out;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    bintree<char> datos;
    datos = leerArbol('.');

    bool sol = resolver(datos.left(), datos.right());

    // escribir sol
    if (sol)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
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