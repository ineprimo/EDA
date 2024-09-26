
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool parcialmenteOrdenado(const vector<int>& v, int ini, int fin, int& min, int& max) {

    int resta = fin - ini;

    //Caso base solo hay 2 elementos
    if (resta == 1) {
        //Si esto se cumple está parcialmente ordenado
        return v[ini-1] <= v[fin-1];
    }

    //Calculamos la mitad del segmento
    int mitad = resta / 2;
    if (mitad % 2 != 0) mitad++;

    //Parte izquierda
    if (parcialmenteOrdenado(v, ini, fin - mitad, min, max)) {
        min = v[ini - 1];
        max = v[fin - mitad - 1];
    }
    else return false;

    //Parte derecha
    if (parcialmenteOrdenado(v, fin - mitad + 1, fin, min, max)) {

        if (min > v[fin - mitad] || max > v[fin - 1]) return false;
        else max = v[fin - 1];
    }
    else return false;

    return min <= max;
}

bool parcialmenteOrdenado(const vector<int>& v) {
    int min, max;
    return parcialmenteOrdenado(v, 1, v.size(), min, max);
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
    cout << (parcialmenteOrdenado(sec) ? "SI" : "NO") << endl;
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