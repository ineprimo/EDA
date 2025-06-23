// Javier Tirado Ríos
// GDV-EDA72


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int>& datos, int ini, int fin) {

    if (ini == fin) return datos[ini];
    //if (fin - ini == 1)
    int mitad = (fin + ini) / 2;

    if (datos[ini] < datos[mitad] && datos[mitad] > datos[fin]) return resolver(datos, ini, mitad);
    if (datos[mitad] > datos[mitad + 1]) return resolver(datos, mitad + 1, fin);
    else return resolver(datos, ini, mitad);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n, auxNum;
    cin >> n;

    if (!std::cin)
        return false;

    vector<int> datos;

    for (int i = 0; i < n; ++i) {
        cin >> auxNum;
        datos.push_back(auxNum);
    }

    int sol = resolver(datos, 0, n - 1);

    cout << sol << endl;

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