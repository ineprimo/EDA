// PAULA SIERRA LUQUE
// EDA-GDV70

#include <iostream>
#include <fstream>
#include <string>

#include "bintree_eda.h"

using namespace std;

// La complejidad es lineal O(n), el recorrido recursivo toca cada nodo una vez 
// y no realiza operaciones costosas adicionales en cada nodo
vector<string> resuelve(const bintree<string>& datos) 
{
    // base
    if (datos.empty()) {
        return { "Ninguno", "0" };
    }
    if (datos.left().empty() && datos.right().empty()) {
        return { datos.root(), "1" };
    }

    // recursion
    vector<string> right = resuelve(datos.right());
    vector<string> left = resuelve(datos.left());

    vector<string> fusion(2);

    if (stoi(right[1]) == stoi(left[1])) 
    {
        if (right[0] < left[0]) {
            fusion[0] = right[0];
        }
        else {
            fusion[0] = left[0];
        }
    }
    else
    {
        if (stoi(right[1]) > stoi(left[1])) {
            fusion[0] = right[0];
        }
        else {
            fusion[0] = left[0];
        }
    }

    fusion[1] = to_string(stoi(left[1]) + stoi(right[1]));

    if (datos.root() == "Orcos") 
    {
        if (stoi(fusion[1]) == 1) return { "Ninguno", "0" };

        fusion[1] = to_string(stoi(fusion[1]) / 2);
    }

    return fusion;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<string> b;

    b = leerArbol((string)"."); 

    vector<string> sol = resuelve(b);

    if (sol[1] == "0")
        cout << sol[0] << endl;
    else
        cout << sol[0] << " " << sol[1] << endl;

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
