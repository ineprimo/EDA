// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>

#include "list_eda.h"

using namespace std;
using myIt = list<char>::iterator;

// función que resuelve el problema
list<char> resolver(list<char>& datos, int pos, int lon, int k) {
    if (datos.empty() || lon == 0 || pos == 0 || pos >= datos.size() || pos - k < 0) return datos;

    if (pos + lon > datos.size()) lon = datos.size() - pos;

    myIt lBegin = datos.begin();
    for (int i = 0; i < pos; ++i) ++lBegin;
    myIt lEnd = lBegin;
    for (int i = 0; i < lon; ++i) ++lEnd;

    list<char> listAuxInsert;
    for (auto it = lBegin; it != lEnd;) {
        listAuxInsert.insert(listAuxInsert.end(), *it);
        it = datos.erase(it);
    }

    int insertPos = pos - k;
    myIt lInsert = datos.begin();
    for (int i = 0; i < insertPos; ++i) ++lInsert;

    for (const char& c : listAuxInsert) {
        lInsert = datos.insert(lInsert, c);
        ++lInsert;
    }

    return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int n, pos, lon, k;
    list<char> datos;
    cin >> n >> pos >> lon >> k;

    for (int i = 0; i < n; ++i) {
        char l;
        cin >> l;
        datos.insert(datos.end(), l);
    }

    list<char> sol = resolver(datos, pos, lon, k);
    for (auto it = sol.begin(); it != sol.end(); ++it) {
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