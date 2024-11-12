
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <utility> 
#include "bintree_eda.h"
using namespace std;


//La complejidad es O(n) lineal, siendo n el numero de nodos del arbol
pair <string, int> sobrevive(bintree<string> const& tree) {

    pair <string, int> sol("", 0);
    pair <string, int> _left("", 0);
    pair <string, int> _right("", 0);
    bool l = tree.left().empty();
    bool r = tree.right().empty();

    //Si estamos en una hoja devolvemos el propio arbol
    if (l && r) {

        sol.first = tree.root();
        sol.second = 1;
        return sol;
    }

    //Necesitamos ir recorriendo el árbol
    if (!l) _left = sobrevive(tree.left());
    if (!r) _right = sobrevive(tree.right());
    
    if (!l && !r) {

        //Nos quedamos con el que tenga más gente
        if (_left.second > _right.second) sol.first = _left.first;
        else if (_left.second < _right.second) sol = _right;

        //O si son iguales por el nombre en orden alfabetico
        else if (_left.first < _right.first) sol = _left;
        else sol = _right;
    }
    else if (l) sol = _right;
    else sol = _left;

    //El grupo resultante siempre será la suma de ambos
    sol.second = _left.second + _right.second;

    //A no ser que se enfrenten a ogros
    if (tree.root() == "Orcos") sol.second /= 2;
    
    return sol;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    pair <string, int> sol;
    bintree<string> tree = leerArbol(string("."));

    sol = sobrevive(tree);
    
    if (sol.second == 0) cout << "Ninguno" << endl;
    else cout << sol.first << " " << sol.second << endl;
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
