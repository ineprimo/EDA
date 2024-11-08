// Ines Primo Lopez
// EDA-GDV61


#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


// complejidad O(n) lineal porque hacer un recorrido de todos los nodos del arbol, siento n el numero de elementos del arbol
pair<string, int> resuelve(bintree<string> datos) {
  
    // casos base
    if (datos.empty()) {
        return { "Ninguno", 0 };
    }
    if (datos.right().empty() && datos.left().empty()) {
        // defensiva???
        return { datos.root(), 1 };
    }


    // divide et impera?
    // right tree
    pair<string, int> right = resuelve(datos.right());
    // left tree
    pair<string, int> left = resuelve(datos.left());

    // merge
    pair<string, int> merge;

    // merge del lider
    // si los grupos son iguales se miran los nombres
    if (right.second == left.second) {
        if (right.first < left.first) merge.first = right.first;
        else merge.first = left.first;
    }
    else 
    // si hay uno mas grande ese se proclama lider 
    {
        if (right.second > left.second) merge.first = right.first;
        else merge.first = left.first;
    }

    // merge del team
    merge.second = left.second + right.second;

    // orcos¿?¿?¿?¿
    if (datos.root() == "Orcos") {
        if (merge.second == 1) {
            return { "Ninguno", 0 };
        }

        merge.second = merge.second / 2;
    }

    // return
    return merge;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<string> arb;
    arb = leerArbol((string)"."); // -1 es la repr. de arbol vacio

    //
    pair<string, int> sol = resuelve(arb);

    sol;
    if(sol.second == 0)
        cout << sol.first << endl;
    else
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
    //system("PAUSE");
#endif

    return 0;
}

