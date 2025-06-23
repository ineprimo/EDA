// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(const vector<int>& datos, int ini, int fin, int k) {
    if (ini > fin) return false; // <- control clave
    if (ini == fin) return datos[ini] == k;

    int mitad = (ini + fin) / 2;
    if (datos[mitad] == k) return true; // encontrado

    // Si la parte izquierda está ordenada
    if (datos[ini] < datos[mitad]) 
    {
        if (datos[ini] <= k && k < datos[mitad])
            return resolver(datos, ini, mitad - 1, k); // buscar en la izquierda
        else
            return resolver(datos, mitad + 1, fin, k); // buscar en la derecha
    }
    // Si la parte derecha está ordenada
    else {
        if (datos[mitad] < k && k <= datos[fin])
            return resolver(datos, mitad + 1, fin, k); // buscar en la derecha
        else
            return resolver(datos, ini, mitad - 1, k); // buscar en la izquierda
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k, auxNum;
    cin >> n;

    if (n == -1)
        return false;

    cin >> k;

    vector<int> datos;
    for (int i = 0; i < n; ++i) {
        cin >> auxNum;
        datos.push_back(auxNum);
    }

    bool sol = resolver(datos, 0, n - 1, k);
    if (sol) cout << "SI" << endl;
    else cout << "NO" << endl;
    // escribir sol

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
