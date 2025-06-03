#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

template <class T>
ostream& operator<<(ostream& out, const vector<T>& v){
    for (auto e : v) out << e;
    return out;
}


// función que resuelve el problema
void resolver(...){

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a, t;
    cin >> n >> a >> t;
    if (n == 0 && a == 0 && t == 0) return false;
    vector<vector<int>> preferencias(a,vector<int>(n));
    for (int i = 0; i < a ; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> preferencias[i][j];
        }

    resolver(...);
    // Imprimir solucion
    return true;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input1.txt");
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