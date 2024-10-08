#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resuelve(const vector<int>& sec, int ini, int fin, int elem) {

    int dif = fin - ini;

    //Casos base
    if (dif == 0) {
        return false;
    }
    if (dif == 1) {
        if (sec[ini] == elem) {
            return true;
        }
        else return false;

    }

    int mitad = (ini + fin) / 2;

    if (sec[mitad] != elem) {
        int elemMit1 = resuelve(sec, ini, mitad, elem);
        int elemMit2 = resuelve(sec, mitad, fin, elem);
    }
    else return true;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n, elem;
    cin >> n >> elem;
    if (n == -1) return false;

    vector<int> sec(n);
    for (int& e : sec) cin >> e;

    if (resuelve(sec, 0, n, elem)) {
        cout << "SI" << endl;
    }
    else cout << "NO" << endl;

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
    system("PAUSE");
#endif

    return 0;
}
