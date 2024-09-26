
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool parcialmenteOrdenado(const vector<int>& v, int ini, int fin, int& min, int& max) {

    //Caso base solo hay 2 elementos
    if (fin - ini == 1) {

        min = v[ini - 1];
        max = v[fin - 1];

        //Si esto se cumple está parcialmente ordenado
        return min <= max;
    }

    //Calculamos la mitad del segmento
    int mitad = (ini + fin) / 2;
    int minI, maxI;
    int minD, maxD;

    //Parte izquierda
    if (parcialmenteOrdenado(v, ini, mitad, minI, maxI) && 
        parcialmenteOrdenado(v, mitad + 1, fin, minD, maxD) &&
        minI <= minD && maxI <= maxD) {

        min = minI;
        max = maxD;
        return true;
    }
    else return false;
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