// paula sierra luque
// eda gdv 70

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

pair<int,int> nodosSingulares(bintree<int> const& tree, int antepasados) 
{
    // { singular , acumulado }

    if (tree.empty()) return {0, 0};
    if (tree.left().empty() && tree.right().empty()) 
    {
        if (antepasados == 0) return { 1, tree.root() }; // si encima tengo 0, y abajo (por ser hoja) hay 0, singular
        else return { 0, tree.root() };
    }

    pair<int, int> izq = nodosSingulares(tree.left(), antepasados + tree.root());
    pair<int, int> der = nodosSingulares(tree.right(), antepasados + tree.root());

    int acumulado = izq.second + der.second;
    int singulares = izq.first + der.first;

    if (acumulado == antepasados) ++singulares;

    return { singulares , acumulado + tree.root() };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    bintree<int> tree;
    tree = leerArbol(-1);

    pair<int, int> sol = nodosSingulares(tree, 0);

    // escribe sol
    cout << sol.first << endl;

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
    //system("PAUSE");
#endif

    return 0;
}
