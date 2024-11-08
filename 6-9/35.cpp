#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int num_equipos, num_excursionistas;
};

tSol rescate(bintree<int> const& arbol) {
    if (arbol.empty())
        return {0, 0};
    else {
        // Dos llamadas recursivas, cada una me devuelve su número de grupos y el máximo de excursionistas por sus ramas
        tSol izq = rescate(arbol.left());
        tSol der = rescate(arbol.right());

        if (izq.num_equipos == 0 && der.num_equipos == 0 && arbol.root() != 0)
            return {1, arbol.root()};
        else
            return {izq.num_equipos + der.num_equipos,
                    max(izq.num_excursionistas, der.num_excursionistas) +
                        arbol.root()};
    }
}

inline std::ostream& operator<<(std::ostream& out, tSol const& sol) {
    out << sol.num_equipos << " " << sol.num_excursionistas;
    return out;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Leer datos de entrada
    bintree<int> arbol = leerArbol(-1);
    // Resolver
    cout << rescate(arbol) << endl;
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
