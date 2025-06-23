// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int>& datos, int ini, int fin) {

    if (ini == fin) {
        if (datos[ini] % 2 != 0)
            return datos[ini];
        else
            return -1;
    }

    int mitad = (ini + fin) / 2;
    if (datos[mitad] % 2 != 0) return datos[mitad];

    int resultado = resolver(datos, ini, mitad);
    if (resultado == -1) resultado = resolver(datos, mitad + 1, fin);

    return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, auxNum;
    cin >> n;
    if (n == 0)
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
