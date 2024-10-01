
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;




pair<int, bool> caucasico(vector<int> sec, int ini, int fini) {

    // caso base, secuencia de dos elementos
    if (fini - ini <= 2) {

        pair<int, bool> sol;
        sol.first = 0;      // contador de pares
        sol.second = true;  // toda secuencia de dos numeros o menos es caucasica

        if (sec[ini] % 2 == 0) sol.first++;
        if (sec[fini] % 2 == 0) sol.first++;

        return sol;
    }

    // recursion

    // der
    pair<int, bool> cauizq = caucasico(sec, ini, fini/2);

    // izq
    pair<int, bool> cauder = caucasico(sec, fini/2, fini);

    
    pair<int, bool> sol;

    sol.first = cauizq.first + cauder.first;
    sol.second = cauizq.second && cauder.second;

    return sol;

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
    cout << (caucasico(sec, 0, sec.size()-1).second ? "SI" : "NO") << endl;
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