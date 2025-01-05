// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int>& datos, int ini, int fin) {
    if ((fin - ini <= 1) && datos[ini] <= datos[fin]) {
        return true;
    }

    int mitad = (ini + fin) / 2,
        minIzq = datos[ini],
        minDer = datos[ini],
        maxIzq = datos[mitad],
        maxDer = datos[mitad];

    // Actualizar variables Izq
    for (int i = ini + 1; i <= mitad; ++i) {
        if (datos[i] > maxIzq) maxIzq = datos[i];
        else if (datos[i] < minIzq) minIzq = datos[i];
    }

    // Actualizar variables Der
    for (int i = mitad + 1; i <= fin; ++i) {
        if (datos[i] > maxDer) maxDer = datos[i];
        else if (datos[i] < minDer) minDer = datos[i];
    }

    // Parcialmente ordenado
    if (maxDer >= maxIzq && minIzq <= minDer) {
        return (resolver(datos, ini, mitad) && resolver(datos, mitad + 1, fin));
    }
    else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int aux;
    cin >> aux;

    if (aux == 0)
        return false;

    while (aux != 0) {
        datos.push_back(aux);
        cin >> aux;
    }

    // Depuración
    /*for (int i = 0; i < datos.size(); ++i) {
        cout << datos[i];
    }*/

    bool sol = resolver(datos, 0, datos.size() - 1);

    // escribir sol

    if (sol) cout << "SI" << endl;
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
