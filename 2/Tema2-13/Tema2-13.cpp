
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int> vec, int ini, int fin) {
    
    // base
    if (fin - ini == 0) return ini;
    else if (fin - ini == 1) {
        // TODO
    }
    if (fin - ini == 2) {
        if (vec[ini + 1] == vec[fin]) return ini;
        else return fin;
    }


    // rec
    int mid = (ini + fin) / 2;

    // esta a la izquierda
    if (vec[mid] == vec[mid - 1]) {
        // TODO

    }
    // esta a la derecha
    else if (vec[mid] == vec[mid + 1]) {
        // TODO

    }

    



}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& e : v) cin >> e;

    // Llamada a la función resolver


    // Mostrar el resultado
}


//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}