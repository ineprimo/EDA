// PAULA SIERRA
// EDA-GDV70



#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <string>

using namespace std;

// función que resuelve el problema
template <class T>
void resolver(bintree<T> tree, T& n)
{
    if (tree.empty()) return;
    
    if (n > tree.root()) {
        n = tree.root();
    }

    resolver(tree.left(), n);
    resolver(tree.right(), n);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    char c;
    cin >> c;
    if (!std::cin)
        return false;

    if (c == 'N') {
        bintree<int> tree = leerArbol(-1);
        int i = tree.root();
        resolver(tree, i);
        cout << i << endl;
        
    }
    else
    {
        bintree<string> tree = leerArbol(string("#"));
        string i = tree.root();
        resolver(tree, i);
        cout << i << endl;
    }

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