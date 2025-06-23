// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>

#include "list_eda.h"

using namespace std;

// función que resuelve el problema
void resolver(list<char>& datos, int pos, int lon, int k) {

    if (datos.empty() || pos < 0 || pos > datos.size() ||
        lon == 0 || k == 0 || k > pos) return;

    if (lon + pos > datos.size()) lon = datos.size() - pos;

    auto itSegBegin = datos.begin();
    for (int i = 0; i < pos; ++i) ++itSegBegin;

    auto itSegEnd = itSegBegin;
    for (int i = 1; i < lon; ++i) ++itSegEnd;

    list<char> auxList;
    for (auto it = itSegBegin; it != itSegEnd;) {
        auxList.push_back(*it);
        it = datos.erase(it);
    }
    if (itSegEnd == datos.end()) return;
    auxList.push_back(*itSegEnd);
    datos.erase(itSegEnd);

    int newPos = pos - k;
    auto itPreDestino = datos.begin();
    for (int i = 0; i < newPos; ++i) ++itPreDestino;

    while (!auxList.empty()) {
        itPreDestino = datos.insert(itPreDestino, auxList.back());
        auxList.pop_back();
    }    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int n, pos, lon, k;
    char auxC;
    cin >> n >> pos >> lon >> k;
    list<char> datos;
    for (int i = 0; i < n; ++i) {
        cin >> auxC;
        datos.push_back(auxC);
    }
    resolver(datos, pos, lon, k);
    
    for (auto it = datos.begin(); it != datos.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
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