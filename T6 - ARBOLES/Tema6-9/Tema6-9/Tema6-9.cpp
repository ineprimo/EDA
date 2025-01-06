// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

template <class T>
std::pair<int, int> ruta(bintree<T> const& tree) 
{
    //  { GruposSalvacion , PersonasRescatadas}

    // CASO BASE
    if (tree.empty()) return { 0, 0 };

    // RECURSION
    std::pair<int, int> izq = ruta(tree.left());
    std::pair<int, int> der = ruta(tree.right());

    int gruposTotales = izq.first + der.first;
    int mayorRescatados = max(izq.second, der.second);

    if (tree.root() == 0) return {gruposTotales, mayorRescatados};

    if (izq.first == 0 && der.first == 0) return { gruposTotales + 1, tree.root() };
    else if (izq.first != 0) return { gruposTotales, mayorRescatados + tree.root() };
    else if (der.first != 0) return { gruposTotales, mayorRescatados + tree.root() };
    return { gruposTotales, mayorRescatados + tree.root() };

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree;
    tree = leerArbol(-1);
    std::pair<int, int> sol = ruta(tree);

    cout << sol.first << " " << sol.second << endl;
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