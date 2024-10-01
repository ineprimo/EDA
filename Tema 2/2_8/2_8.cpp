#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int minimo(const vector<int>& sec, int ini, int fin) {

    //casos base, tenemos solo dos elementos
    if (fin == ini) return sec[ini];
    if (fin - ini == 1) {

        //Devolvemos el menor de los dos
        if (sec[ini] < sec[fin]) return sec[ini];
        if (sec[fin] < sec[ini]) return sec[fin];
    }

    int mid = 0;
    mid = (ini + fin) / 2;

    //Comparamos para ver si es el número que estamos buscando o no
    if (sec[ini] > sec[mid] && sec[mid] > sec[mid + 1]) {
        //mira la parte derecha
        return minimo(sec, mid, fin);
    }
    else {
        //mira la parte izquierda
        return minimo(sec, ini, mid);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!cin) return false;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    cout << minimo(sec, 0, n - 1) << endl;
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