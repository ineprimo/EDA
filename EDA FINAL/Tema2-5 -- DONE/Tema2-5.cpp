// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

using namespace std;

struct caucasico {
    bool caucasico;
    int pares;
};
// función que resuelve el problema
caucasico resolver(vector<int>& datos, int ini, int fin) {

    if (fin - ini == 1) {
        if (datos[ini] % 2 == 0) return { true, 1 };
        else return { true, 0 };
    }
    int mitad = (ini + fin) / 2;

    caucasico izq = resolver(datos, ini, mitad);
    caucasico der = resolver(datos, mitad, fin);

    bool cond = abs(izq.pares - der.pares) <= 2;
    return { cond && izq.caucasico && der.caucasico, izq.pares + der.pares };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;

    vector<int> datos(n);
    for (int i = 0; i < n; ++i) {
        cin >> datos[i];
    }

    caucasico sol = resolver(datos, 0, n);

    if (sol.caucasico) cout << "SI\n";
    else cout << "NO\n";

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
