// Ejercicio 2: Dragones (3 puntos)
// Tipo: ARBOLES

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;
// pair<camino, dragones>
using camino = pair<int, int>;

// numero de nodos singulares que tiene
template <class T>
camino dragones(bintree<T> const& tree)
{
    if (tree.empty()) return { -1, 0 };

    // caso hoja
    if (tree.left().empty() && tree.right().empty()) return { tree.root(), 0 };

    // recursion
    camino izq = dragones(tree.left());
    camino der = dragones(tree.right());

    // cuantos dragones ha habido
    int dragonesIzq = izq.second;
    int dragonesDer = der.second;

    // en que camino estas
    int caminoIzq = izq.first;
    int caminoDer = der.first;

    // si estas ahora en dragon
    int dragon = 0;
    if (tree.root() == 1) dragon = 1;

    // ----- QUE CAMINO ELEGIR
    // -- caminos invalidos
    if (caminoIzq == -1 && caminoDer != -1) // si el de la izq no es valido y el de la der si -> der
    {
        return { caminoDer, dragonesDer + dragon };
    }
    if (caminoDer == -1 && caminoIzq != -1) // si el de la der no es valido y el de la izq si -> izq
    {
        return { caminoIzq, dragonesIzq + dragon };
    }

    // -- gestion camino mejor
    // si hay menos dragones a la izq -> izq
    if (dragonesIzq < dragonesDer) return { caminoIzq, dragonesIzq + dragon };

    // si hay mismos dragones -> izq
    if (dragonesIzq == dragonesDer) return { caminoIzq, dragonesIzq + dragon };

    // si hay menos dragones a la der -> der
    return  { caminoDer, dragonesDer + dragon };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree;
    tree = leerArbol(-1);
    cout << dragones(tree).first << endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
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