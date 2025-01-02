

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


struct Cancion{
    int duracion;
    int puntos;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, duracion;
    cin >> n;
    if (n == 0) return false;
    cin >> duracion;
    vector<int> soluc(n);
    vector<Cancion> canciones(n);
    for (int i = 0; i < n; ++i)
        cin >> canciones[i].duracion >> canciones[i].puntos;
    resolver(...);
    // Salida
    return true;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
