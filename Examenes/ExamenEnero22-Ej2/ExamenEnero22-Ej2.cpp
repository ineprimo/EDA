// INES PRIMO
// GDV61


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;


// función que resuelve el problema
pair<int, int> resolver(const bintree<int>& datos, int parent, int& count) {

    if (datos.empty()) {
        return {0, 0};
    }
    if (datos.left().empty() && datos.right().empty()) {
        if(parent == 0)
            return { 1, datos.root() };
        else
            return { 0, datos.root() };
    }

    pair<int, int> izq = resolver(datos.left(), parent + datos.root(), count);
    pair<int, int> der = resolver(datos.right(), parent + datos.root(), count);

    int sing = izq.first + der.first; // Numero de singulares de los hijos.
    int sum = izq.second + der.second; // Suma de los valores de los hijos.

    // comparacion
    if (sum == parent)
        sing++;

    return { sing, sum + datos.root()};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int>datos;
    datos = leerArbol(-1);
    int sol = 0;
    auto a = resolver(datos, 0, sol);

    cout << a.first << endl;

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