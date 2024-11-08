#include <fstream>
#include <iostream>
#include <string>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    string leader;
    int num_dwarves = 0;
};

tSol regreso_enanos(bintree<std::string> const& arbol) {
    if (arbol.empty()) {
        return {"", 0};
    } else if (arbol.left().empty() && arbol.right().empty()) {
        if (arbol.root() == "Orcos")
            return {"", 0};
        else
            return {arbol.root(), 1};
    } else {
        tSol iz = regreso_enanos(arbol.left());
        tSol der = regreso_enanos(arbol.right());
        string leader;
        if (iz.num_dwarves == der.num_dwarves)
            leader = min(iz.leader, der.leader);
        else if (iz.num_dwarves > der.num_dwarves)
            leader = iz.leader;
        else
            leader = der.leader;
        int num_dwarves = iz.num_dwarves + der.num_dwarves;
        if (arbol.root() == "Orcos")
            num_dwarves /= 2;
        return {leader, num_dwarves};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Leer los datos de la entrada
    bintree<string> arbol = leerArbol<string>(".");
    // Resolver problema y escribir solución
    tSol sol = regreso_enanos(arbol);
    if (sol.num_dwarves == 0)
        cout << "Ninguno" << endl;
    else
        cout << sol.leader << " " << sol.num_dwarves << endl;
}

int main() {
    // Ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

        // Para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
