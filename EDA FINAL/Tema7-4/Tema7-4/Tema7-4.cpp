// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <unordered_map>
//#include "set.h"

using namespace std;
using episodio = int;

// función que resuelve el problema
int resolver(vector<int>& datos) {
    unordered_map<episodio, int> ultimaAparicion;
    int maxTotal = 0;
    int ini = 0;

    for (int i = 0; i < datos.size(); ++i) {
        if (ultimaAparicion.count(datos[i]) && ultimaAparicion[datos[i]] >= ini) {
            ini = ultimaAparicion[datos[i]] + 1;
        }
        ultimaAparicion[datos[i]] = i;
        maxTotal = max(maxTotal, i - ini + 1);
    }

    return maxTotal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int n, auxNum;
    cin >> n;
    vector<int> datos;
    for (int i = 0; i < n; ++i) {
        cin >> auxNum;
        datos.push_back(auxNum);
    }
    int sol = resolver(datos);
    // escribir sol
    cout << sol << endl;
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