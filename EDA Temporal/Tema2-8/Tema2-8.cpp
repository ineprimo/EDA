// Javier Tirado Ríos
// GDV-EDA72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
int resolver(vector<int>& datos, int ini, int fin) {
    if (fin - ini == 0) return 0;
    if (fin - ini == 1) return datos[ini];

    int mitad = (ini + fin) / 2;
    if (datos[ini] > datos[mitad]) return resolver(datos, mitad, fin);
    return resolver(datos, ini, mitad);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (!std::cin)
        return false;

    vector<int> datos(n);
    for (int i = 0; i < n; ++i) {
        cin >> datos[i];
    }

    int sol = resolver(datos, 0, n);

    // escribir sol
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