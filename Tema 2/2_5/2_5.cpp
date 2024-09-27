
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool caucasico(vector<int>& sec, int ini, int fin) {

    //Casos base
    int elemts = fin - ini;

    if (elemts == 0) return true;

    if (elemts == 1) {

        //Si los dos elementos son pares o son impares es caucásico

        bool primer = sec[ini - 1] % 2 == 0;    //Si devuelve true es par
        bool segundo = sec[fin - 1] % 2 == 0;   //Si devuelve true es par

        return (primer && segundo) || (!primer && !segundo);
    }

    //Hay que contar cuantos pares hay en cada lado


}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0) return false;

    vector<int> sec(n);
    for (int& e : sec) cin >> e;

    cout << (caucasico(sec, 1, n) ? "SI" : "NO") << endl;
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