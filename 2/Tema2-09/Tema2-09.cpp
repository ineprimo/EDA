#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resuelve(const vector<int>& sec, int ini, int fin, int a) {

    // caso basico
    if (fin - ini == 1) {
        if (sec[ini] == a) return true;
        return false;
    }

    int mid = (ini + fin)/2;

    // recursion
    bool c = resuelve(sec, ini, mid, a);
    bool b = resuelve(sec, mid, fin, a);

    return c || b;


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a;
    cin >> n;
    cin >> a;
    if (!cin) return false;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    cout << (resuelve(sec, 0, n, a) ? "SI" : "NO") << endl;
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