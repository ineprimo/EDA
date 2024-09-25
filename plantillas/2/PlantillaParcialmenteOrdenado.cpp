
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool parcialmenteOrdenado(const vector<int>& v, int ini, int fin, int& min, int& max) {
    ...
}

bool parcialmenteOrdenado(const vector<int>& v) {
    int min, max;
    return parcialmenteOrdenado(v,0,v.size(),min,max);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int e;
    cin >> e;
    if (e == 0) return false;
    vector<int> sec;
    while (e != 0) {
        sec.push_back(e);
        cin >> e;
    }
    cout << (parcialmenteOrdenado(sec)? "SI" : "NO") << endl;
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
    //system("PAUSE");
#endif

    return 0;
}