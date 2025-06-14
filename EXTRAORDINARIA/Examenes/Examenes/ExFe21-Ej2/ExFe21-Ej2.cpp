// Ejercicio 2: Simetricos (3 puntos)
// Tipo: ARBOLES

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

template <class T>
bool doblar(bintree<T> const& izq, bintree<T> const& der)
{
    // caso hoja, simetrico
    if (izq.empty() && der.empty()) return true;

    // caso no son simetricos (solo tienen una de los dos nodos)
    if (!izq.empty() && der.empty() ||  izq.empty() && !der.empty()) return false;

    bool ramasExternas = doblar(izq.left(), der.right());
    bool ramasInternas = doblar(der.left(), izq.right());

    return ramasExternas && ramasInternas;
}

template <class T>
bool simetrico(bintree<T> const& tree)
{
    // caso arbol vacio
    if (tree.empty()) return true;
    bool d = doblar(tree.left(), tree.right());
    return d;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    /// lee arbol
    bintree<char> arbol;
    arbol = leerArbol('.'); // '.' es la representacion de arbol vacio

    // escribe solucion
    bool sol = simetrico(arbol);
    if (sol) std::cout << "SI" << std::endl;
    else std::cout << "NO" << std::endl;
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
    {
        resuelveCaso();
    }

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
